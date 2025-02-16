#ifndef CITAMEDICA_H
#define CITAMEDICA_H

#include <iostream>
#include <vector>
#include "medico.h"
#include "paciente.h"

using namespace std;

class CitaMedica {
private:
    int id;
    int idPaciente;
    int idMedico;
    string fecha;
    string hora;
    string motivo;
    static vector<CitaMedica> listaCitas;

public:
    CitaMedica(int id, int idPaciente, int idMedico, string fecha, string hora, string motivo);

    static void menuCitas();
    static void asignarCita();
    static void cancelarCita();
    static void listarCitas();
};

#endif
