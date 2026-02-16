#include "tasks.h"
#include "crypto_math.h"

void Ferma() {
    cout << "\n    Task 1: Теорема Ферма    \n";
    mpz_class a, x, p;
    cout << "Введите a: "; cin >> a;
    cout << "Введите степень x: "; cin >> x;
    cout << "Введите модуль p: "; cin >> p;

    if (!isPrime(p)) {
        cout << "Ошибка: Модуль p не является простым.\n\n";
        return;
    }
    if (a % p == 0) {
         cout << "Число 'a' кратно 'p', теорема не применима в стандартном виде.\n";
    } else {
        mpz_class check = powerMod(a, p - 1, p);
        if (check == 1) cout << "Теорема Ферма выполняется: " << a << "^(" << p-1 << ") mod " << p << " = 1\n";
        else cout << "Ошибка: теорема не выполняется.\n\n\n";
    }
    mpz_class result = powerMod(a, x, p);
    cout << "Результат: " << result << "\n\n" << endl;
}