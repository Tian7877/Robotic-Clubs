#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

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
    float r;  // Wheelbase radius (distance from the center of the chassis to each wheel)

    // Robot pose data
    float x;  // X-coordinate of the robot's center
    float y;  // Y-coordinate of the robot's center
    float theta;  // Orientation of the robot

public:
    // Constructor
    Swerve(float wheelbaseRadius)
        : r(wheelbaseRadius), x(0.0), y(0.0), theta(0.0) {
        transformationMatrix = Matrix({
            {1, 0, -r, 0},
            {0, 1, 0, -r},
            {1, 0, r, 0},
            {0, 1, 0, r}
        });
    }

    void velocityCommand(float vx, float vy, float omega) {
        Matrix velocityMatrix({{vx, vy, omega}});
        velocities = transformationMatrix * velocityMatrix;
    }

    void updatePose(float deltaTime) {
        float vx = velocities(0, 0);
        float vy = velocities(0, 1);
        float omega = velocities(0, 2);
        x += vx * deltaTime;
        y += vy * deltaTime;
        theta += omega * deltaTime;
    }

    std::vector<float> calculateResultantVelocities() {
        std::vector<float> resultantVelocities;
        float vx1 = 48 * cos(theta) * pow(sin(theta), 2);
        float vy1 = 4 * sin(4 * theta) + 6 * sin(3 * theta) + 10 * sin(2 * theta) - 13 * sin(theta);
        float vResultan1 = sqrt(vx1 * vx1 + vy1 * vy1);
        resultantVelocities.push_back(vResultan1);
        return resultantVelocities;
    }

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
    Swerve mySwerveRobot(0.26363);
    float t_0 = 0;
    float t_final = 6.3;
    float delta_t = 0.01;

    std::ofstream csvFile("simulation_data.csv");
    csvFile << "Time,X,Y,Theta,V1,V2,V3,V4\n";

    for (float t = t_0; t <= t_final; t += delta_t) {
        float v_x = 48 * cos(t) * pow(sin(t), 2);
        float v_y = 4 * sin(4 * t) + 6 * sin(3 * t) + 10 * sin(2 * t) - 13 * sin(t);
        float omega = 0;

        mySwerveRobot.velocityCommand(v_x, v_y, omega);
        mySwerveRobot.updatePose(delta_t);

        std::vector<float> resultantVelocities = mySwerveRobot.calculateResultantVelocities();

        csvFile << t << "," << mySwerveRobot.getX() << "," << mySwerveRobot.getY() << ","
                << mySwerveRobot.getTheta() << "," << resultantVelocities[0] << ","
                << resultantVelocities[1] << "," << resultantVelocities[2] << ","
                << resultantVelocities[3] << "\n";
    }

    csvFile.close();

    return 0;
}
