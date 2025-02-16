#include "paciente.h"

vector<Paciente> Paciente::listaPacientes;

Paciente::Paciente(int id, string nombre, string fechaIngreso) : id(id), nombre(nombre), fechaIngreso(fechaIngreso) {}

void Paciente::menuPacientes() {
    int opcion;
    do {
        cout << "=== Gestión de Pacientes ===\n";
        cout << "1. Alta de Paciente\n";
        cout << "2. Baja de Paciente\n";
        cout << "3. Listar Pacientes\n";
        cout << "4. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: altaPaciente(); break;
        case 2: bajaPaciente(); break;
        case 3: listarPacientes(); break;
        case 4: break;
        default: cout << "Opción no válida\n";
        }
    } while (opcion != 4);
}

void Paciente::altaPaciente() {
    int id;
    string nombre, fechaIngreso;
    cout << "Ingrese ID del paciente: ";
    cin >> id;
    cout << "Ingrese nombre del paciente: ";
    cin >> nombre;
    cout << "Ingrese fecha de ingreso: ";
    cin >> fechaIngreso;

    listaPacientes.push_back(Paciente(id, nombre, fechaIngreso));
    cout << "Paciente registrado con éxito.\n";
}

void Paciente::bajaPaciente() {
    int id;
    cout << "Ingrese ID del paciente a eliminar: ";
    cin >> id;

    for (auto it = listaPacientes.begin(); it != listaPacientes.end(); ++it) {
        if (it->id == id) {
            listaPacientes.erase(it);
            cout << "Paciente eliminado correctamente.\n";
            return;
        }
    }
    cout << "Paciente no encontrado.\n";
}

void Paciente::listarPacientes() {
    if (listaPacientes.empty()) {
        cout << "No hay pacientes registrados.\n";
    }
    else {
        for (const auto& paciente : listaPacientes) {
            cout << "ID: " << paciente.id << " | Nombre: " << paciente.nombre << " | Fecha de ingreso: " << paciente.fechaIngreso << "\n";
        }
    }
}
