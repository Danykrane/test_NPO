#include "../include/headers/data_layer.h"
using namespace std;

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
}

void Path::add_ext_to_str_locations() //добавляем название исходника и то, имя файла, который будет на выводе
{
    // inputF_location += "/acsii_tmi.txt";
    output_Folder += "/out.bin";
}
void Path::setInp(string &stri)
{
    inputF_location = stri;
}
void Path::setOutp(string &stro)
{
    output_Folder = stro;
}

string Path::get_input()
{
    return inputF_location;
}

string Path::get_output()
{
    return output_Folder;
}

void Path::read_from_config_file()
{
    vector<string> res_vec_str(2);
    ifstream config_file; //открываем на чтение из файла конфига для пути
    string str;
    config_file.open("Configure_way.txt");

    if (!config_file) //проверка нахождения данного файла
    {
        cout << "\nФайл конфига пути на найден!!\n"
             << endl;
    }
    else
    {
        int cnt = 0;
        while (getline(config_file, str)) //получение строки из файла Config_way.txt
        {
            res_vec_str[cnt] = way_of_path(str);
            cnt++;
        }
        config_file.close();
    }
    inputF_location = res_vec_str[0];
    output_Folder = res_vec_str[1];

    // cout << "\n"
    //      << inputF_location << " " << output_Folder << " \n";
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
        // unsigned short int date_from_1900;                                   // 2 байта под кол-во дней с 1900 года
        // unsigned int time_from_begining;                                     //миллисекунды

        int cnt = 0;

        ofstream mfile(way.get_output(), ios::trunc | ios::out | ios::binary); //на запись (выходной каталог)m
        while (getline(file, str))                                             //получение строки и ее изменение
        {
            date_from_1900 = val_years(str);                  // получение кол-ва дней
            time_from_begining = val_mseconds(str);           // получение кол-ва милисекунд
            TMshot_string = val_TMshot_str(str);              //получение кадра без начальной последовательности
            TMshot_string = simple_str_to_hex(TMshot_string); //взятие одного символа по Hex

            mfile.write(reinterpret_cast<const char *>(&date_from_1900), sizeof(date_from_1900));
            mfile.write(reinterpret_cast<const char *>(&time_from_begining), sizeof(time_from_begining));
            mfile << TMshot_string;
        }
        file.close();
    }

    return flag;
}

void TMshot::StartProcess()
{
    // cout << "Протестируем файл конфига" << endl;
    // way.read_from_config_file();
    // cout << endl;
    // --------------------------------------------------------
    if (way.get_input() == "", way.get_output() == "") //если путь к файлу не указан
        input();

    way.add_ext_to_str_locations(); //добавляем расширение файлам

    cout << "\nОткрытие файла и его редактирование" << endl;
    file_edit() == true ? cout << "Проблема с открытием файла: неправильно указан исходный путь к фалу" << endl : cout << " Данные успешно записаны!!! \n Расположение файла: " << way.get_output() << endl;
}

// void TMshot::SetWay(string stri, string stro)
// {
//     way.setInp(stri);
//     way.setOutp(stro);
// }

void TMshot::SetWay()
{
    way.read_from_config_file();
}

void valid_folder_name(string &str1)
{
    if (str1.find('\''))
        str1.erase(remove(str1.begin(), str1.end(), '\''), str1.end());
}