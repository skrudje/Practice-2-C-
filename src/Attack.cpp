#include "tasks.h"
#include "crypto_math.h"

void Attack() {
    cout << "\n    Task 6: Атака Man-In-The-Middle (MITM)    \n";
    cout << "Сценарий: Алиса и Боб пытаются обменяться ключами.\n";
    cout << "Ева перехватывает их сообщения и подменяет ключи.\n\n";

    mpz_class p, g;
    cout << "Введите общее простое число p: "; cin >> p;
    cout << "Введите основание g: "; cin >> g;

    mpz_class a_priv, A_pub;
    cout << "\n[Alice] Генерирует ключи...\n";
    cout << "Введите секретный ключ Алисы: "; cin >> a_priv;
    A_pub = powerMod(g, a_priv, p);
    cout << "[Alice] Отправляет публичный ключ A = " << A_pub << " Бобу...\n";

    cout << "\n!!! [Eva] ПЕРЕХВАТИЛА сообщение от Алисы !!!\n";
    mpz_class e_priv, E_pub;
    cout << "[Eva] Введите секретный ключ Евы: "; cin >> e_priv;
    E_pub = powerMod(g, e_priv, p);
    cout << "[Eva] Подменяет ключ A на свой ключ E = " << E_pub << " и отправляет Бобу.\n";

    mpz_class b_priv, B_pub;
    cout << "\n[Bob] Получил ключ (думает, что от Алисы). Генерирует свои...\n";
    cout << "Введите секретный ключ Боба: "; cin >> b_priv;
    B_pub = powerMod(g, b_priv, p);
    
    mpz_class secret_Bob_Eve = powerMod(E_pub, b_priv, p);
    cout << "[Bob] Отправляет публичный ключ B = " << B_pub << " Алисе...\n";
    cout << "[Bob] Вычислил общий секрет (с Евой): " << secret_Bob_Eve << endl;

    cout << "\n!!! [Eva] ПЕРЕХВАТИЛА сообщение от Боба !!!\n";
    cout << "[Eva] Подменяет ключ B на свой ключ E = " << E_pub << " и отправляет Алисе.\n";

    mpz_class secret_Eve_Alice = powerMod(A_pub, e_priv, p);
    mpz_class secret_Eve_Bob = powerMod(B_pub, e_priv, p); 

    cout << "\n[Alice] Получила ключ (думает что от Боба).\n";
    mpz_class secret_Alice_Eve = powerMod(E_pub, a_priv, p);
    cout << "[Alice] Вычислила общий секрет (с Евой): " << secret_Alice_Eve << endl;

    cout << "\n\n--- РЕЗУЛЬТАТ АТАКИ ---\n";
    cout << "Секрет Алисы: " << secret_Alice_Eve << endl;
    cout << "Секрет Евы (для Алисы): " << secret_Eve_Alice << endl;
    cout << "-------------------------" << endl;
    cout << "Секрет Боба:  " << secret_Bob_Eve << endl;
    cout << "Секрет Евы (для Боба):  " << secret_Eve_Bob << endl;

    if (secret_Alice_Eve == secret_Eve_Alice && secret_Bob_Eve == secret_Eve_Bob) {
        cout << "\n[УСПЕХ] Атака прошла успешно! Ева полностью контролирует канал.\n";
        cout << "Алиса и Боб имеют РАЗНЫЕ секреты, но думают, что говорят друг с другом.\n\n";
    } else {
        cout << "\n\n[FAIL] Что-то пошло не так.\n\n";
    }
}