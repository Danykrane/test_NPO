#ifndef TO_BINARY_LAYER_H
#define TO_BINARY_LAYER_H

#include <string>
#include <bitset>
#include <algorithm>
using namespace std;

string inspect(string &);
string hexToBin_2_dig(char &, char &);
string changetoBinary(string &);             //перевод в двоичную ТМ (hex)
string changetoBinary(unsigned short int &); //перевод в двоичную года
string changetoBinary(unsigned int &);       //перевод в двоичную миллисекунд

#endif