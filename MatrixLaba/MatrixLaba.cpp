#include "Matrix.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "rus");

    Matrix A(5, 5);
    Matrix B(5, 5);

    A.fillWithRandom();
    B.fillWithRandom();

    std::cout << "A:\n" << A << std::endl;
    std::cout << "B:\n" << B << std::endl;

    Matrix addition = A + B;
    std::cout << "Сумма матриц:\n" << addition << std::endl;

    Matrix subtraction = A - B;
    std::cout << "Разность матриц:\n" << subtraction << std::endl;

    Matrix multiplication = A * B;
    std::cout << "Произведение матриц:\n" << multiplication << std::endl;

    if (A == B) {
        std::cout << "A и B равны.\n";
    }
    else {
        std::cout << "A и B не равны.\n";
    }

    return 0;
}
