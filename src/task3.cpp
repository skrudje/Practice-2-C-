#include "tasks.h"
#include "crypto_math.h"

void runTask3() {
    cout << "\n--- Task 3: Обратный элемент (C^-1 mod m) ---\n";
    mpz_class c, m;
    cout << "Введите число C: "; cin >> c;
    cout << "Введите модуль m: "; cin >> m;

    mpz_class inv = modInverse(c, m);

    if (inv == -1) {
        cout << "Обратного элемента не существует (НОД != 1).\n\n\n";
    } else {
        cout << "Обратный элемент: " << inv << endl;
        cout << "Проверка (" << c << " * " << inv << " mod " << m << "): " << (c * inv) % m << "\n\n" << endl;
    }
}