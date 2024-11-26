#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Paciente {
public:
    int id;
    string nombre;
    vector<int> historialCitas;

    Paciente(int _id, string _nombre) : id(_id), nombre(_nombre) {}

    void mostrarHistorial() {
        cout << "Historial de citas para " << nombre << ":\n";
        for (int cita : historialCitas)
            cout << "- Cita ID: " << cita << "\n";
    }
};

class Medico {
public:
    int id;
    string nombre;
    bool disponible;

    Medico(int _id, string _nombre) : id(_id), nombre(_nombre), disponible(true) {}

    void modificarDisponibilidad(bool estado) {
        disponible = estado;
    }
};

// Clase CitaMedica
class CitaMedica {
private:
    static vector<CitaMedica> citas; // Vector que almacena todas las citas
    int id;
    int idPaciente;
    int idMedico;
    string fecha;
    bool activa;

public:
    CitaMedica(int _id, int _idPaciente, int _idMedico, string _fecha)
        : id(_id), idPaciente(_idPaciente), idMedico(_idMedico), fecha(_fecha), activa(true) {}

    // Método para cancelar la cita
    static bool cancelarCita(int idCita) {
        auto it = find_if(citas.begin(), citas.end(), [idCita](CitaMedica& c) { return c.id == idCita; });

        if (it != citas.end() && it->activa) {
            it->activa = false;
            cout << "Cita con ID " << idCita << " ha sido cancelada.\n";
            return true;
        }
        cout << "Cita no encontrada o ya estaba cancelada.\n";
        return false;
    }

    // Método para agregar una nueva cita al sistema
    static void agregarCita(CitaMedica cita) {
        citas.push_back(cita);
        cout << "Cita con ID " << cita.id << " creada exitosamente.\n";
    }

    // Mostrar todas las citas
    static void mostrarCitas() {
        cout << "Listado de citas:\n";
        for (const auto& cita : citas) {
            cout << "- ID: " << cita.id << ", Paciente: " << cita.idPaciente
                << ", Médico: " << cita.idMedico << ", Fecha: " << cita.fecha
                << ", Activa: " << (cita.activa ? "Sí" : "No") << "\n";
        }
    }
};

vector<CitaMedica> CitaMedica::citas;

// Main para probar el programa
int main() {
    Paciente paciente1(1, "Juan Perez");
    Medico medico1(1, "Dra. Ana Lopez");

    CitaMedica::agregarCita(CitaMedica(1, 1, 1, "2024-12-01"));
    CitaMedica::agregarCita(CitaMedica(2, 1, 1, "2024-12-15"));

    cout << "\nCitas iniciales:\n";
    CitaMedica::mostrarCitas();

    cout << "\nCancelando la cita con ID 1:\n";
    CitaMedica::cancelarCita(1);

    cout << "\nCitas después de la cancelación:\n";
    CitaMedica::mostrarCitas();

    return 0;
}


