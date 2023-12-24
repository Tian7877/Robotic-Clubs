#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    int rows;
    int cols;

public:
    Matrix(const std::vector<std::vector<int>>& input_data)
        : data(input_data), rows(input_data.size()), cols(input_data[0].size()) {}

    Matrix(int numRows, int numCols)
        : rows(numRows), cols(numCols),
          data(std::vector<std::vector<int>>(numRows, std::vector<int>(numCols, 0))) {}

    Matrix(const Matrix& other)
        : data(other.data), rows(other.rows), cols(other.cols) {}

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "The matrix dimension is not valid!" << std::endl;
            return Matrix(1, 1);  // Return matrix 1x1 dengan isi cell bernilai 0
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];

        return result;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "The matrix dimension is not valid!" << std::endl;
            return Matrix(1, 1);  // Return matrix 1x1 dengan isi cell bernilai 0
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] - other.data[i][j];

        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            std::cerr << "Multiplication cannot be done. The number of columns in the first matrix should be equal to the number of rows in the second." << std::endl;
            return Matrix(1, 1);  // Return matrix 1x1 dengan isi cell bernilai 0
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];

        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
};

Matrix getMatrixFromUser() {
    int numRows, numCols;
    std::cout << "Masukkan jumlah baris matriks: ";
    std::cin >> numRows;
    std::cout << "Masukkan jumlah kolom matriks: ";
    std::cin >> numCols;

    std::vector<std::vector<int>> matrixData(numRows, std::vector<int>(numCols, 0));

    std::cout << "Masukkan elemen matriks:" << std::endl;
    for (int i = 0; i < numRows; ++i)
        for (int j = 0; j < numCols; ++j)
            std::cin >> matrixData[i][j];

    return Matrix(matrixData);
}

int main() {
    std::cout << "Masukkan matriks pertama:" << std::endl;
    Matrix matrix1 = getMatrixFromUser();

    std::cout << "\nMasukkan matriks kedua:" << std::endl;
    Matrix matrix2 = getMatrixFromUser();

    std::cout << "\nMatrix 1:" << std::endl << matrix1 << std::endl;
    std::cout << "Matrix 2:" << std::endl << matrix2 << std::endl;

    Matrix result_addition = matrix1 + matrix2;
    std::cout << "Penjumlahan Matriks:" << std::endl << result_addition << std::endl;

    Matrix result_subtraction = matrix1 - matrix2;
    std::cout << "Pengurangan Matriks:" << std::endl << result_subtraction << std::endl;

    Matrix result_multiplication = matrix1 * matrix2;
    std::cout << "Perkalian Matriks:" << std::endl << result_multiplication << std::endl;

    return 0;
}
//Mohon maaf jika tidak dapat menginput matrix secara langsung saya mwnggunakan looping untuk menginput nya 