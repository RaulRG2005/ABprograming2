#include "citamedica.h"
#include <iostream>
#include <algorithm>
using namespace std;

vector<CitaMedica> CitaMedica::listaCitas;

CitaMedica::CitaMedica(int id, int idPaciente, int idMedico, string fecha, string hora, string motivo)
    : id(id), idPaciente(idPaciente), idMedico(idMedico), fecha(fecha), hora(hora), motivo(motivo) {}

void CitaMedica::menuCitas() {
    int opcion;
    do {
        cout << "=== Gestión de Citas Médicas ===\n";
        cout << "1. Asignar Cita\n";
        cout << "2. Cancelar Cita\n";
        cout << "3. Listar Citas\n";
        cout << "4. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: asignarCita(); break;
        case 2: cancelarCita(); break;
        case 3: listarCitas(); break;
        case 4: break;
        default: cout << "Opción no válida.\n";
        }
    } while (opcion != 4);
}

void CitaMedica::asignarCita() {
    int id, idPaciente, idMedico;
    string fecha, hora, motivo;

    cout << "Ingrese el ID de la cita: ";
    cin >> id;
    cout << "Ingrese el ID del paciente: ";
    cin >> idPaciente;
    cout << "Ingrese el ID del médico: ";
    cin >> idMedico;
    cout << "Ingrese la fecha de la cita (formato: YYYY-MM-DD): ";
    cin >> fecha;
    cout << "Ingrese la hora de la cita (formato: HH:MM): ";
    cin >> hora;

    cout << "Ingrese el motivo de la cita: ";
    cin.ignore();  // Limpiar el buffer
    cin >> motivo;  // Leer una palabra sin saltar espacios

    // Crear la nueva cita y agregarla a la lista
    listaCitas.push_back(CitaMedica(id, idPaciente, idMedico, fecha, hora, motivo));
    cout << "Cita asignada con éxito.\n";
}

void CitaMedica::cancelarCita() {
    int id;
    cout << "Ingrese el ID de la cita a cancelar: ";
    cin >> id;

    // Buscar la cita por ID y eliminarla
    auto it = find_if(listaCitas.begin(), listaCitas.end(), [id](const CitaMedica& cita) {
        return cita.id == id;
        });

    if (it != listaCitas.end()) {
        listaCitas.erase(it);
        cout << "Cita cancelada con éxito.\n";
    }
    else {
        cout << "Cita no encontrada.\n";
    }
}

void CitaMedica::listarCitas() {
    cout << "=== Listado de Citas ===\n";
    if (listaCitas.empty()) {
        cout << "No hay citas registradas.\n";
    }
    else {
        for (const CitaMedica& cita : listaCitas) {
            cout << "ID: " << cita.id << ", Paciente ID: " << cita.idPaciente
                << ", Médico ID: " << cita.idMedico << ", Fecha: " << cita.fecha
                << ", Hora: " << cita.hora << ", Motivo: " << cita.motivo << "\n";
        }
    }
}

