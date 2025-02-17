#ifndef CITAMEDICA_H
#define CITAMEDICA_H

#include <string>
#include <vector>

class CitaMedica {
private:
    int id;
    int idPaciente;
    int idMedico;
    std::string fecha;
    std::string hora;
    std::string motivo;

public:
    static std::vector<CitaMedica> listaCitas;  // Lista estática de citas

    CitaMedica(int id, int idPaciente, int idMedico, const std::string& fecha, const std::string& hora, const std::string& motivo);

    static void menuCitas();
    static void asignarCita();
    static void cancelarCita();
    static void listarCitas();
};

#endif


