#include "../include/headers/data_layer.h"
using namespace std;
#include <memory>

Path::Path(string inputF_location, string output_Folder) : inputF_location(inputF_location), output_Folder(output_Folder)
{
}

void Path::read_info_of_folders() // функция на случай ручной вставки пути к папке
{
    cout << "Введите пусть к папке исходного файла\n=> ";
    cin >> inputF_location;
    valid_folder_name(inputF_location);
    cout << "Путь отформатирован" << endl;

    cout << "Введите путь для выходного файла\n=> ";
    cin >> output_Folder;
    valid_folder_name(output_Folder);
    cout << "Путь отформатирован" << endl;

    add_ext_to_str_locations();
}

void Path::add_ext_to_str_locations() //добавляем название исходника и то, имя файла, который будет на выводе
{
    inputF_location += "/acsii_tmi.txt";
    output_Folder += "/out.bin";
}

string Path::get_input()
{
    return inputF_location;
}

string Path::get_output()
{
    return output_Folder;
}

void TMshot::input()
{
    way.read_info_of_folders(); //считываем расположение папок
}

bool TMshot::file_edit()
{
    bool flag = false; //флаг проверки нахождения исходного файла
    ifstream file;     //на чтение (исходный каталог)
    file.open(way.get_input());
    string str;

    if (!file)
    {
        flag = true;
        cout << "\nФайл не найден!!!!!!!\n"
             << endl;
    }

    else
    {
        ofstream mfile(way.get_output(), ios::binary | ios::out); //на запись (выходной каталог)m
        while (getline(file, str))                                //получение строки и ее изменение
        {
            str = inspect(str); //обработка строки
            mfile << str;
        }
        file.close();
    }

    return flag;
}

void TMshot::StartProcess()
{
    input();
    cout << "\nОткрытие файла и его редактирование" << endl;
    file_edit() == true ? cout << "Проблема с открытием файла: неправильно указан исходный путь к фалу" << endl : cout << " Данные успешно записаны!!! \n Расположение файла: " << way.get_output() << endl;
}

void valid_folder_name(string &str1)
{
    if (str1.find('\''))
        str1.erase(remove(str1.begin(), str1.end(), '\''), str1.end());
}