#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void readf(string &, string &); //для работы через консоль (вводим пути к папкам)
void check_wr(string &);        // при вставке папки в vscode появляются '/Users/artemgudzenko/Desktop'
string inspect(string &);
void st_chage(string &, string &);

int main()
{
    string stri, stro;
    // readf(stri, stro);
    // check_wr(stri);
    // check_wr(stro);
    stri = "/Users/artemgudzenko/Desktop/Less_1/c++/test_NPO/input";
    stro = "/Users/artemgudzenko/Desktop/Less_1/c++/test_NPO/ouutput";
    st_chage(stri, stro);
}

void readf(string &stri, string &stro) //для работы через консоль (вводим пути к папкам)
{
    cout << "Введите пусть к папке исходного файла\n=> ";
    cin >> stri;

    cout << "Введите путь для выходного файла\n=> ";
    cin >> stro;

    stri += "/acsii_tmi.txt";
    stro += "/out.bin";
}

void check_wr(string &str1) // при вставке папки в vscode появляются '/Users/artemgudzenko/Desktop'
// такие символы нам не нужны, поэтому убираем их
{
    if (str1.find('\''))
        str1.erase(remove(str1.begin(), str1.end(), '\''), str1.end());
}

void st_chage(string &stri, string &stro)
{
    cout << "Открытие файла и его редактирование" << endl;
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

string inspect(string &str)
{
    string res;
    string tmshot;
    unsigned short int years = (stoi(str.substr(0, 4)) - 1900);                            // кол-во дней с 1900 года
    unsigned int time_m = (stoi(str.substr(14, 2)) * 60 + stoi(str.substr(17, 2))) * 1000; // количесвто миллисекунд с начала суток

    size_t pos = str.find("1ACFFC1D");
    tmshot = str.find("1ACFFC1D") != string::npos ? str.substr(pos + 8) : str.substr(25);
    // TM кадр
    res += to_string(years) + ' ' + to_string(time_m) + ' ' + tmshot;
    return res;
}
