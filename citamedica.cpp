#include "cita.h"

// Inicializaci�n del vector est�tico
std::vector<CitaMedica> CitaMedica::citas;

// Constructor
CitaMedica::CitaMedica(int _id, int _idPaciente, int _idMedico, std::string _fecha)
    : id(_id), idPaciente(_idPaciente), idMedico(_idMedico), fecha(_fecha), activa(true) {}

// M�todo para cancelar la cita
bool CitaMedica::cancelarCita(int idCita) {
    auto it = std::find_if(citas.begin(), citas.end(), [idCita](CitaMedica& c) { return c.id == idCita; });

    if (it != citas.end() && it->activa) {
        it->activa = false;
        std::cout << "Cita con ID " << idCita << " ha sido cancelada.\n";
        return true;
    }
    std::cout << "Cita no encontrada o ya estaba cancelada.\n";
    return false;
}

// M�todo para agregar una nueva cita al sistema
void CitaMedica::agregarCita(CitaMedica cita) {
    citas.push_back(cita);
    std::cout << "Cita con ID " << cita.id << " creada exitosamente.\n";
}

// Mostrar todas las citas
void CitaMedica::mostrarCitas() {
    std::cout << "Listado de citas:\n";
    for (const auto& cita : citas) {
        std::cout << "- ID: " << cita.id << ", Paciente: " << cita.idPaciente
            << ", M�dico: " << cita.idMedico << ", Fecha: " << cita.fecha
            << ", Activa: " << (cita.activa ? "S�" : "No") << "\n";
    }
}

