#ifndef CITAMEDICA_H
#define CITAMEDICA_H

#include <string>
#include <vector>
using namespace std;

class CitaMedica {
public:
    int id;
    int idPaciente;
    int idMedico;
    string fecha;
    string hora;
    string motivo;
    static vector<CitaMedica> listaCitas;

    CitaMedica(int id, int idPaciente, int idMedico, string fecha, string hora, string motivo);

    static void menuCitas();
    static void asignarCita();
    static void cancelarCita();
    static void listarCitas();

    // Métodos para guardar y cargar las citas
    static void guardarCitas();
    static void cargarCitas();
};

#endif




