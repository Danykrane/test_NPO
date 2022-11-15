#ifndef DATA_LAYER_H
#define DATA_LAYER_H

#include <fstream>
#include <vector>
#include <string>

#include "To_binary_func_layer.h"
#include "read_config_str_layer.h"

void valid_folder_name(string &);

class Path //создание класса, где есть путь входного и выходного пути
{
    string inputF_location; //путь исходного файла
    string output_Folder;   //путь для создания выходного бинарника
public:
    Path(string inputF_location = "", string output_Folder = "");

    void read_from_config_file();

    void read_info_of_folders(); // функция на случай ручной вставки пути к папке

    void add_ext_to_str_locations(); //добавляем название исходника и то, имя файла, который будет на выводе

    void setInp(string &);
    void setOutp(string &);
    string get_input();
    string get_output();
};

class TMshot
{
    Path way;
    unsigned short int date_from_1900; // 2 байта под кол-во дней с 1900 года
    unsigned int time_from_begining;   //миллисекунды
    string TMshot_string;              // hex строка

    void input();
    bool file_edit();

public:
    void StartProcess();
    void SetWay();
};

#endif