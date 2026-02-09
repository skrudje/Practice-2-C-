#include "tasks.h"
#include "crypto_math.h"

void runTask4() {
    cout << "\n--- Task 4: Диффи-Хеллман (вариант 1) ---\n";
    
    mpz_class p, g, a_priv, b_priv;
    
    cout << "Введите общее простое число p: "; cin >> p;
    cout << "Введите основание g: "; cin >> g;

    cout << "[Alice] Введите секретный ключ: "; cin >> a_priv;
    cout << "[Bob] Введите секретный ключ: "; cin >> b_priv;

    mpz_class A_pub = powerMod(g, a_priv, p);
    mpz_class B_pub = powerMod(g, b_priv, p);

    cout << "Публичный ключ Alice: " << A_pub << endl;
    cout << "Публичный ключ Bob: " << B_pub << "\n" << endl;

    // вычисление общего секрета
    mpz_class sec_A = powerMod(B_pub, a_priv, p);
    mpz_class sec_B = powerMod(A_pub, b_priv, p);

    cout << "Секрет Alice: " << sec_A << endl;
    cout << "Секрет Bob:   " << sec_B << "\n" << endl;

    if (sec_A == sec_B) cout << "Ключи совпали. Канал защищен.\n\n\n";
    else cout << "Ошибка. Ключи разные.\n\n\n";
}