#include "To_binary_layer.h"

string inspect(string &str)
{
    string res = "";
    string tmshot;
    // подсчет кол-во дней с 1900 года
    unsigned short int years = (stoi(str.substr(0, 4)) - 1900);
    // перевод значения дней в бинарнуб строку размерности 2 байта
    res += changetoBinary(years);

    // количесвто миллисекунд с начала суток
    unsigned int time_m = (stoi(str.substr(14, 2)) * 60 + stoi(str.substr(17, 2))) * 1000;
    // перевод значения милисекунд в бинарнуб строку размерности 4 байта
    res += changetoBinary(time_m);

    size_t pos = str.find("1ACFFC1D");
    //получпние TM кадра без 1ACFFC1D
    tmshot = str.find("1ACFFC1D") != string::npos ? str.substr(pos + 8) : str.substr(25);
    // перевод ТМ кадра в бинарную строку
    res += changetoBinary(tmshot);
    return res;
}

string changetoBinary(string &str)
{
    string rez;
    int cnt = 0;
    int i = str.length() / 2;

    for (int i = 0; i < str.length(); i += 2)
    {
        rez += hexToBin_2_dig(str[i], str[i + 1]);
    }
    return rez;
}

string changetoBinary(unsigned short &years)
{
    return bitset<16>(years).to_string();
}

string changetoBinary(unsigned int &time)
{
    return bitset<32>(time).to_string();
}

string hexToBin_2_dig(char &a, char &b)
{
    string binaryString = "";
    string str;
    str = a;
    str += b;
    for (char &it : str)
    {
        binaryString += bitset<4>(it).to_string();
    }
    return binaryString;
}