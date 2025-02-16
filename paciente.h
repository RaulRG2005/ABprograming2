#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <vector>

using namespace std;

class Paciente {
private:
    int id;
    string nombre, fechaIngreso;
    static vector<Paciente> listaPacientes;
public:
    Paciente(int id, string nombre, string fechaIngreso);
    static void menuPacientes();
    static void altaPaciente();
    static void bajaPaciente();
    static void listarPacientes();
};

#endif
