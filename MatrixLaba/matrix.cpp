#include "matrix.h"
#include <random>

Matrix::Matrix(unsigned int rows, unsigned int columns) : m(rows), n(columns) {
    data = new int* [m];
    for (unsigned int i = 0; i < m; ++i) {
        data[i] = new int[n];
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < m; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

int* Matrix::operator[](unsigned int i)
{
    return data[i];
}

Matrix Matrix::operator+(const Matrix& operand)
{
    if (m != operand.m || n != operand.n) {
        throw std::invalid_argument("Неправильные размеры матриц!");
    }

    Matrix result(n, m);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            result.data[i][j] = data[i][j] + operand.data[i][j];
        }
    }

    return result;
}

Matrix& Matrix::operator+=(const Matrix& operand)
{
    if (m != operand.m || n != operand.n) {
        throw std::invalid_argument("Неправильные размеры матриц!");
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] += operand.data[i][j];
        }
    }

    return *this;
}

Matrix Matrix::operator-(const Matrix& operand)
{
    if (m != operand.m || n != operand.n) {
        throw std::invalid_argument("Неправильные размеры матриц!");
    }

    Matrix result(m, n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            result.data[i][j] = data[i][j] - operand.data[i][j];
        }
    }

    return result;
}

Matrix& Matrix::operator-=(const Matrix& operand)
{
    if (m != operand.m || n != operand.n) {
        throw std::invalid_argument("Неправильные размеры матриц!");
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] -= operand.data[i][j];
        }
    }

    return *this;
}

Matrix Matrix::operator*(const Matrix& operand)
{
    if (n != operand.m) {
        throw std::invalid_argument("Неправильные размеры матриц!");
    }

    Matrix result(m, operand.n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < operand.n; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                result.data[i][j] += data[i][k] * operand.data[k][j];
            }
        }
    }

    return result;
}

bool Matrix::operator==(const Matrix& other) const
{
    if (m != other.m || n != other.n) {
        return false;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool Matrix::operator!=(const Matrix& other) const
{
    return !(*this == other);
}

void Matrix::fillWithRandom()
{
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> distribution(0, 9);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = distribution(generator);
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
    for (int i = 0; i < matrix.m; ++i) {
        for (int j = 0; j < matrix.n; ++j) {
            os << matrix.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
