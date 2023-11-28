#include "modAlphaCipher.h"
bool isValid(const string& s)
{
    for(const auto &c:s) {                               //цикл проходит по массиву и выдает объект массива
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    int key;
    string stroka;
    unsigned operation;
    cout << "Введите ключ в виде числа: ";
    cin >> key;
    if (!cin.good()) {
        clog << "Некорректный ключ \n";
        return 1;
    }
    modAlphaCipher cipher(key);
    do {
        cout << "Введите операцию (1-зашифровать, 2-расшифровать): ";
        cin >> operation;
        if (operation > 2) {
            cout << "Неизвестная операция \n";
        } else if (operation > 0) {
            cout << "Введите текст: ";
            cin >> stroka;
            if (isValid(stroka)) {
                if (operation == 1) {
                    cout << "Зашифрованная строка: " << cipher.encrypt(stroka) << endl;
                } else {
                    cout << "Расшифрованная строка: " << cipher.decrypt(stroka) << endl;
                }
            } else {
                cout << "Операция прервана: некорректная строка. \n";

            }
        }
    } while (operation != 0);
    
    return 0;
}