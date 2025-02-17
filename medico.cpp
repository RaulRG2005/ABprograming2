#include "medico.h"
#include <iostream>

// Inicialización de la lista estática
std::vector<Medico> Medico::listaMedicos;

Medico::Medico(int id, const std::string& nombre, const std::string& especialidad)
    : id(id), nombre(nombre), especialidad(especialidad) {}

void Medico::mostrarInfo() const {
    std::cout << "ID: " << id << ", Nombre: " << nombre << ", Especialidad: " << especialidad << std::endl;
}

void Medico::listarMedicos() {
    if (listaMedicos.empty()) {
        std::cout << "No hay médicos registrados.\n";
    }
    else {
        for (const auto& medico : listaMedicos) {
            medico.mostrarInfo();
        }
    }
}

