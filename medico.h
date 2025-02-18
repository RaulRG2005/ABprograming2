#ifndef MEDICO_H
#define MEDICO_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Medico {
public:
    int id;
    string nombre;
    string especialidad;

    static vector<Medico> listaMedicos;

    Medico(int id, string nombre, string especialidad);

    // Menú y operaciones
    static void menuMedicos();
    static void altaMedico();
    static void bajaMedico();
    static void modificarMedico();
    static void buscarMedico();
    static void listarMedicos();

    // Funciones de manejo de archivos
    static void guardarMedicos();
    static void cargarMedicos();  // Declarar la función de carga
};

#endif


