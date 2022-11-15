#include "../include/headers/read_config_str_layer.h"

string way_of_path(string &str) //Строка конфига пути
{
    return str.substr(str.find("/"));
}