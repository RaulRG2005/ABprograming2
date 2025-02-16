#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <vector>

using namespace std;

class Paciente {
private:
    string nombre, fechaIngreso;
    int id;
public:
    void menuPacientes();
    void altaPaciente();
    void bajaPaciente();
    void modificarDatos();
    void buscarPaciente();
};

#endif
