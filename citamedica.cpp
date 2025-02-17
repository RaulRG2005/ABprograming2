#include "citamedica.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

vector<CitaMedica> CitaMedica::listaCitas;

CitaMedica::CitaMedica(int id, int idPaciente, int idMedico, string fecha, string hora, string motivo)
    : id(id), idPaciente(idPaciente), idMedico(idMedico), fecha(fecha), hora(hora), motivo(motivo) {}

void CitaMedica::menuCitas() {
    int opcion;
    do {
        cout << "=== Gestion de Citas Medicas ===\n";
        cout << "1. Asignar Cita\n";
        cout << "2. Cancelar Cita\n";
        cout << "3. Listar Citas\n";
        cout << "4. Volver\n";
        cout << "Seleccione una opcion: ";
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
    getline(cin, motivo);  // Leer el motivo completo

    // Crear la nueva cita y agregarla a la lista
    listaCitas.push_back(CitaMedica(id, idPaciente, idMedico, fecha, hora, motivo));
    cout << "Cita asignada con éxito.\n";
    guardarCitas();  // Guardar citas después de asignar
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
        guardarCitas();  // Guardar citas después de cancelar
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

void CitaMedica::guardarCitas() {
    ofstream archivo("citas.txt");
    if (archivo.is_open()) {
        for (const auto& cita : listaCitas) {
            archivo << cita.id << " "
                << cita.idPaciente << " "
                << cita.idMedico << " "
                << cita.fecha << " "
                << cita.hora << " "
                << cita.motivo << "\n";
        }
        archivo.close();
        cout << "Citas guardadas con éxito.\n";
    }
    else {
        cout << "Error al abrir el archivo para guardar las citas.\n";
    }
}

void CitaMedica::cargarCitas() {
    ifstream archivo("citas.txt");
    if (archivo.is_open()) {
        int id, idPaciente, idMedico;
        string fecha, hora, motivo;

        while (archivo >> id >> idPaciente >> idMedico >> fecha >> hora) {
            cin.ignore();  // Limpiar buffer antes de leer el motivo
            getline(archivo, motivo);  // Leer el motivo completo
            listaCitas.push_back(CitaMedica(id, idPaciente, idMedico, fecha, hora, motivo));
        }
        archivo.close();
        cout << "Citas cargadas con éxito.\n";
    }
    else {
        cout << "No se encontraron citas guardadas.\n";
    }
}

