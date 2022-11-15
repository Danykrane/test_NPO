#ifndef TO_BINARY_FUNC_LAYER_H
#define TO_BINARY_FUNC_LAYER_H

#include <string>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <memory>

using namespace std;

string inspect(string &); //исследование строки ТМ кадра

unsigned short int val_years(string &); //выделение из строки кол-ва дней
unsigned int val_mseconds(string &);    //выделение из строки кол-ва мсекунд
string val_TMshot_str(string &);
string simple_str_to_hex(string &);

string hexToBin_2_dig(char &, char &);
string changetoBinary(string &);             //перевод в двоичную ТМ (hex)
string changetoBinary(unsigned short int &); //перевод в двоичную года
string changetoBinary(unsigned int &);       //перевод в двоичную миллисекунд

#endif