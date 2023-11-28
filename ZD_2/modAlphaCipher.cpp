#include "modAlphaCipher.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string modAlphaCipher::encrypt(const string& open_stroka)                              //зашифровка
{
    string ocs = open_stroka;
    int dlina, kolvostrok, pozitsiya, a;                                               
    dlina = open_stroka.size();                                                        
    kolvostrok = (dlina - 1) / kolvostolbov + 1;                                       
    a = 0;
    for (int nomerstolba = kolvostolbov; nomerstolba > 0; nomerstolba--) {             
        for (int line_number = 0; line_number < kolvostrok; line_number++) {           
            pozitsiya = nomerstolba + kolvostolbov * line_number;
            if (pozitsiya-1 < dlina) {
                ocs[a] = open_stroka[pozitsiya-1];
                a++;
            }
        }
    }
    return ocs;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string modAlphaCipher::decrypt(const std::string& cipher_stroka)                        //расшифровка
{
    string ocs = cipher_stroka;
    int dlina, kolvostrok, pozitsiya, a; 
    dlina = cipher_stroka.size(); 
    kolvostrok = (dlina - 1) / kolvostolbov + 1;
    a = 0;
    for (int nomerstolba = kolvostolbov; nomerstolba > 0; nomerstolba--) { 
        for (int line_number = 0; line_number < kolvostrok; line_number++) {
            pozitsiya = kolvostolbov * line_number + nomerstolba; 
            if (pozitsiya - 1 < dlina) {
                ocs[pozitsiya - 1] = cipher_stroka[a];
                a++;
            }
        }
    }
    return ocs;
}
