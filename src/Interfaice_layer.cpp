#include "../include/headers/Interfaice_layer.h"

void Application::begin_execution()
{
    showMess();
    cin >> button;
    check();
}

void Application::showMess()
{
    cout << "\nПрограмма начинает работу" << endl;
    cout << "Введите: \n1 - Путь указан \n2 - введете путь сами" << endl;
}

void Application::check()
{
    switch (button)
    {
    case 1:
        program.SetWay("/Users/artemgudzenko/Desktop/Less_1/c++/ref_npo/ref_NPO/input", "/Users/artemgudzenko/Desktop/Less_1/c++/ref_npo/ref_NPO/ouutput");
        program.StartProcess();
        break;
    case 2:
        program.StartProcess();
        break;
    default:
        cout << "\nВведено неверное число, введите еще раз!!!!" << endl;
        begin_execution();
        break;
    }
}