#pragma once
#include <iostream>
#include <cstring>
#include <cctype>
#include <locale>
#include <codecvt>
#include <vector>
#include <string>
#include <map>
using namespace std;
class modAlphaCipher
{
private:
    int kolvostolbov;         
public:
   modAlphaCipher() = delete;                               //запрет конструктора без параметров
   modAlphaCipher(const int& key) :kolvostolbov(key) {};    //конструктор для установки ключа
   string encrypt(const string& open_stroka);               //зашифрование
   string decrypt(const string& cipher_stroka);             //расшифрование
};