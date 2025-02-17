// medico.h
#ifndef MEDICO_H
#define MEDICO_H

#include <string>
#include <vector>

class Medico {
public:
    std::string nombre;
    std::string especialidad;

    // Métodos estáticos para la gestión de médicos
    static void altaMedico();
    static void bajaMedico();
    static void listarMedicos();
    static void menuMedicos();

private:
    static std::vector<Medico> listaMedicos;
};

#endif
