#include "console_utils.h"
#include "latin_handler.h"
#include "russian_handler.h"
#include "digit_handler.h"
#include "utf8_handler.h"
#include <iostream>

using namespace std;

int main() {
    setupConsoleEncoding();
    while (true) {
        cout << "\n1. Разница ASCII (латиница)\n"
            << "2. Разница CP1251 (русские буквы)\n"
            << "3. Код десятичной цифры\n"
            << "4. Выход\n"
            << "5. UTF‑8 представление символа\n"
            << "Выбор: ";
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1: handleLatinDifference(); break;
        case 2: handleRussianDifference(); break;
        case 3: handleDigitCode(); break;
        case 4: cout << "Программа завершена.\n"; return 0;
        case 5: handleUtf8Conversion(); break;
        default: cout << "Неверный пункт. Повторите ввод.\n";
        }
    }
}