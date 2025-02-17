#ifndef MEDICO_H
#define MEDICO_H

#include <string>
#include <vector>

class Medico {
private:
    int id;
    std::string nombre;
    std::string especialidad;

public:
    static std::vector<Medico> listaMedicos;  // Lista estática de médicos

    Medico(int id, const std::string& nombre, const std::string& especialidad);
    void mostrarInfo() const;
    static void listarMedicos();  // Método estático para listar médicos
};

#endif
