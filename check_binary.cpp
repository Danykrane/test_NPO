#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

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

void test(string &stri, string &stro)
{
    cout << "Открытие файла и его редактирование" << endl;
    stri += "/acsii_tmi.txt";
    stro += "/out.txt";
    ifstream file(stri);  //на чтение (исходный каталог)
    ofstream mfile(stro); //на запись (выходной каталог)
    string str;
    int cnt = 0;
    while (getline(file, str)) //получение строки и ее изменение
    {
        // str = inspect(str); //обработка строки
        mfile << cnt << "строка: " << str << " /";
        cnt++;
    }
    file.close();
}
int main()
{
    string stri, stro;
    readf(stri, stro);
    check_wr(stri);
    check_wr(stro);
    test(stri, stro);
}
