#include <iostream>
#include <string>
#include <fstream>
#include "../include/headers/To_binary_layer.h"

using namespace std;

void readf(string &, string &);
void check_wr(string &);
void st_change(string &, string &);
void add_ext(string &, string &);

int main()
{
    string stri, stro;
    readf(stri, stro);
    check_wr(stri);
    check_wr(stro);
    // stri = "/Users/artemgudzenko/Desktop/Less_1/c++/ref_npo/ref_NPO/input";
    // stro = "/Users/artemgudzenko/Desktop/Less_1/c++/ref_npo/ref_NPO/ouutput";
    st_change(stri, stro);
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

void readf(string &stri, string &stro)
{
    cout << "Введите пусть к папке исходного файла\n=> ";
    cin >> stri;

    cout << "Введите путь для выходного файла\n=> ";
    cin >> stro;
}

void check_wr(string &str1)
{
    if (str1.find('\''))
        str1.erase(remove(str1.begin(), str1.end(), '\''), str1.end());
}
