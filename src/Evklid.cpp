#include "tasks.h"
#include "crypto_math.h"

void Evklid() {
    cout << "\n    Task 2: Алгоритм Евклида (ax + by = gcd)    \n";
    mpz_class a, b, x, y;
    cout << "Введите a: "; cin >> a;
    cout << "Введите b: "; cin >> b;

    mpz_class d = gcdExtended(a, b, x, y);

    cout << "НОД(" << a << ", " << b << ") = " << d << endl;
    cout << "Коэффициенты: x = " << x << ", y = " << y << endl;
    cout << "Проверка: " << a << "*" << x << " + " << b << "*" << y << " = " << (a * x + b * y) << "\n\n" << endl;
}