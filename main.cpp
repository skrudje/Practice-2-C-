#include <iostream>
#include "tasks.h"

using namespace std;

int main() {
    int choice;
    while (true) {
        cout << "1. Ферма (mod pow)\n";
        cout << "2. Евклид (ax+by)\n";
        cout << "3. Обратный элемент\n";
        cout << "4. Диффи-Хеллман\n";
        cout << "5. Диофантово уравнение\n";
        cout << "6. Эмуляция атаки на базе программы 4 таска\n";
        cout << "0. Выход\n> ";
        cin >> choice;

        switch(choice) {
            case 1: Ferma(); break;
            case 2: Evklid(); break;
            case 3: ReverseElement(); break;
            case 4: Hellman(); break;
            case 5: Diofantovo(); break;
            case 6: Attack(); break;
            case 0: return 0;
            default: cout << "Неверный ввод.\n";
        }
    }
}