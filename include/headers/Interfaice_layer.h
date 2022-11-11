#ifndef INTERFAICE_LAYER_H
#define INTERFAICE_LAYER_H
#include "data_layer.h"

class Application
{
    int button;
    TMshot program;

public:
    void begin_execution();
    void showMess();
    void check();
    // program.StartProcess();
};

#endif