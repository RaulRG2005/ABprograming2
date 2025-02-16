#ifndef MEDICO_H
#define MEDICO_H

#include <iostream>
#include <vector>

using namespace std;

class Medico {
private:
    int id;
    string nombre, especialidad;
    static vector<Medico> listaMedicos; // Lista de médicos
public:
    Medico(int id, string nombre, string especialidad);
    static void menuMedicos();
    static void altaMedico();
    static void bajaMedico();
    static void listarMedicos();
};

#endif
