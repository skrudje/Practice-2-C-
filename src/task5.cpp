#include "tasks.h"
#include "crypto_math.h"

// 143a + 169b = 5
void runTask5() {
    cout << "\n--- Task 5: Диофантово уравнение (вариант 1) ---\n";
    cout << "Уравнение: Ax + By = C\n";
    
    mpz_class A, B, C;
    int choice;
    cout << "1. Использовать Вариант 1 (143x + 169y = 5)\n";
    cout << "2. Ввести свои числа\nВыбор: ";
    cin >> choice;

    if (choice == 1) {
        A = 143; B = 169; C = 5;
    } else {
        cout << "Введите A: "; cin >> A;
        cout << "Введите B: "; cin >> B;
        cout << "Введите C: "; cin >> C;
    }

    mpz_class x, y;
    mpz_class g = gcdExtended(A, B, x, y);

    cout << "\nНОД(" << A << ", " << B << ") = " << g << "\n" << endl;

    if (C % g != 0) {
        cout << "Решений в целых числах НЕТ (C не делится на НОД).\n\n";
    } else {
        mpz_class mult = C / g;
        x *= mult;
        y *= mult;
        cout << "Частное решение:\n x = " << x << "\n y = " << y << endl;
        cout << "Проверка: " << A * x + B * y << " = " << C << "\n\n" << endl;
    }
}