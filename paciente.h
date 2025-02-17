#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <vector>

class Paciente {
private:
    int id;
    std::string nombre;
    std::string fechaIngreso;

public:
    // Lista est�tica de pacientes
    static std::vector<Paciente> listaPacientes;

    // Constructor
    Paciente(int id, std::string nombre, std::string fechaIngreso);

    // M�todos
    void menuPacientes();
    void altaPaciente();
    void bajaPaciente();
    void listarPacientes();
};

#endif

