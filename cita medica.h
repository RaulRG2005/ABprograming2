#ifndef CITA_H
#define CITA_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class CitaMedica {
private:
    static std::vector<CitaMedica> citas; // Vector que almacena todas las citas
    int id;
    int idPaciente;
    int idMedico;
    std::string fecha;
    bool activa;

public:
    // Constructor
    CitaMedica(int _id, int _idPaciente, int _idMedico, std::string _fecha);

    // Métodos para gestionar las citas
    static bool cancelarCita(int idCita);
    static void agregarCita(CitaMedica cita);
    static void mostrarCitas();
};

#endif // CITA_H
