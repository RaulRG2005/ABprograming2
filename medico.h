#ifndef MEDICO_H
#define MEDICO_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Medico {
public:
    string nombre;
    string especialidad;

    static vector<Medico> listaMedicos;

    Medico() {}
    Medico(string nombre, string especialidad) : nombre(nombre), especialidad(especialidad) {}

    static void menuMedicos();
    static void altaMedico();
    static void bajaMedico();
    static void listarMedicos();

    // Funciones para manejo de archivos
    static void guardarMedicos();
    static void cargarMedicos();
};

#endif
