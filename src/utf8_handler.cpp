#include "utf8_handler.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

string unicodeToUtf8(wint_t code) {
    string result;
    if (code <= 0x7F) {
        result += (char)code;
    }
    else if (code <= 0x7FF) {
        result += (char)(0xC0 | ((code >> 6) & 0x1F));
        result += (char)(0x80 | (code & 0x3F));
    }
    else if (code <= 0xFFFF) {
        result += (char)(0xE0 | ((code >> 12) & 0x0F));
        result += (char)(0x80 | ((code >> 6) & 0x3F));
        result += (char)(0x80 | (code & 0x3F));
    }
    else if (code <= 0x10FFFF) {
        result += (char)(0xF0 | ((code >> 18) & 0x07));
        result += (char)(0x80 | ((code >> 12) & 0x3F));
        result += (char)(0x80 | ((code >> 6) & 0x3F));
        result += (char)(0x80 | (code & 0x3F));
    }
    return result;
}

void handleUtf8Conversion() {
    wcout << L"Введите один символ (любой Unicode): ";
    wint_t wch = getwchar();
    fflush(stdin);
    string utf8bytes = unicodeToUtf8(wch);
    wcout << L"Символ '" << wch << L"' код 0x" << hex << wch << dec << L" → UTF‑8: ";
    for (unsigned char b : utf8bytes) {
        cout << "0x" << hex << (int)b << " ";
    }
    cout << dec << endl;
}