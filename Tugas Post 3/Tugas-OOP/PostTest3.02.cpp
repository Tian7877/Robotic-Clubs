#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<float>> data;
    int rows;
    int cols;

public:
    Matrix(const std::vector<std::vector<float>>& input_data)
        : data(input_data), rows(input_data.size()), cols(input_data[0].size()) {}

    float operator()(int row, int col) const {
        return data[row][col];
    }

    Matrix operator*(const Matrix& other) const {
        int resultRows = rows;
        int resultCols = other.cols;
        Matrix result(std::vector<std::vector<float>>(resultRows, std::vector<float>(resultCols, 0.0)));

        for (int i = 0; i < resultRows; ++i)
            for (int j = 0; j < resultCols; ++j)
                for (int k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];

        return result;
    }
};

class Swerve {
private:
    Matrix velocities;  // [vx1, vy1, vx2, vy2, vx3, vy3, vx4, vy4]
    Matrix transformationMatrix;  // Transformation matrix
    float r;  

    // Robot pose data
    float x;  
    float y;  
    float theta;  // Orientation of the robot

public:
    // Constructor
    Swerve(float wheelbaseRadius)
        : r(wheelbaseRadius), x(0.0), y(0.0), theta(0.0) {
        // Initialize the transformation matrix
        transformationMatrix = Matrix({
            {1, 0, -r, 0},
            {0, 1, 0, -r},
            {1, 0, r, 0},
            {0, 1, 0, r}
        });
    }

    // Member function to calculate wheel velocities based on linear and angular velocities
    void velocityCommand(float vx, float vy, float omega) {
        
        Matrix velocityMatrix({{vx, vy, omega}});

        
        velocities = transformationMatrix * velocityMatrix;
    }

    // Member function to update the robot's pose based on velocities over a small time interval
    void updatePose(float deltaTime) {
        
        float vx = velocities(0, 0);
        float vy = velocities(0, 1);
        float omega = velocities(0, 2);

        
        x += vx * deltaTime;
        y += vy * deltaTime;
        theta += omega * deltaTime;
    }

    // Getter functions for the robot's pose
    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }

    float getTheta() const {
        return theta;
    }
};

int main() {
    
    Swerve mySwerveRobot(0.26363);  // Inisialisasi objek Swerve dengan radius wheelbase 0.26363 meter

    // Memberikan perintah kecepatan pada robot
    mySwerveRobot.velocityCommand(1.0, 0.0, 0.5);  // vx=1.0 m/s, vy=0.0 m/s, omega=0.5 rad/s

    // Mengupdate posisi robot berdasarkan kecepatan selama interval waktu tertentu
    mySwerveRobot.updatePose(1.0);  // Mengupdate posisi selama 1 detik

    // Mendapatkan posisi dan orientasi robot setelah update
    std::cout << "X: " << mySwerveRobot.getX() << " meters" << std::endl;
    std::cout << "Y: " << mySwerveRobot.getY() << " meters" << std::endl;
    std::cout << "Theta: " << mySwerveRobot.getTheta() << " radians" << std::endl;

    return 0;
}
#include <iostream>
