#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

void readf(string &, string &); //для работы через консоль (вводим пути к папкам)
void check_wr(string &);        // при вставке папки в vscode появляются '/Users/artemgudzenko/Desktop'
string inspect(string &);
string hexToBin_2_dig(char &, char &);
string changetoBinary(string &);             //перевод в двоичную ТМ (hex)
string changetoBinary(unsigned short int &); //перевод в двоичную года
string changetoBinary(unsigned int &);       //перевод в двоичную миллисекунд
void st_change(string &, string &);
void add_ext(string &, string &);

int main()
{
    string stri, stro;
    // readf(stri, stro);
    // check_wr(stri);
    // check_wr(stro);
    stri = "/Users/artemgudzenko/Desktop/Less_1/c++/test_NPO/input";
    stro = "/Users/artemgudzenko/Desktop/Less_1/c++/test_NPO/ouutput";
    st_change(stri, stro);
}

void readf(string &stri, string &stro) //для работы через консоль (вводим пути к папкам)
{
    cout << "Введите пусть к папке исходного файла\n=> ";
    cin >> stri;

    cout << "Введите путь для выходного файла\n=> ";
    cin >> stro;
}

void check_wr(string &str1) // при вставке папки в vscode появляются '/Users/artemgudzenko/Desktop'
// такие символы нам не нужны, поэтому убираем их
{
    if (str1.find('\''))
        str1.erase(remove(str1.begin(), str1.end(), '\''), str1.end());
}

void st_change(string &stri, string &stro)
{
    cout << "Открытие файла и его редактирование" << endl;
    add_ext(stri, stro);                          //из входного пути добавили название вхо
    ifstream file(stri);                          //на чтение (исходный каталог)
    ofstream mfile(stro, ios::binary | ios::out); //на запись (выходной каталог)
    string str;
    int cnt = 0;
    while (getline(file, str)) //получение строки и ее изменение
    {
        str = inspect(str); //обработка строки
        mfile << cnt << "строка: " << str << " /";
        cnt++;
    }
    file.close();
}

void add_ext(string &stri, string &stro)
{
    stri += "/acsii_tmi.txt";
    stro += "/out.bin";
}

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
