#include "paciente.h"
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

vector<Paciente> Paciente::listaPacientes;

Paciente::Paciente(int id, string nombre, string fechaIngreso) : id(id), nombre(nombre), fechaIngreso(fechaIngreso) {}

void Paciente::menuPacientes() {
    int opcion;
    do {
        cout << "=== Gestion de Pacientes ===\n";
        cout << "1. Alta de Paciente\n";
        cout << "2. Baja de Paciente\n";
        cout << "3. Modificar Datos\n";
        cout << "4. Buscar Paciente\n";
        cout << "5. Registrar Historial Clinico\n";
        cout << "6. Generar Reporte de Historial\n";
        cout << "7. Listar Pacientes\n";
        cout << "8. Guardar y Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: altaPaciente(); break;
        case 2: bajaPaciente(); break;
        case 3: modificarPaciente(); break;
        case 4: buscarPaciente(); break;
        case 5: {
            int idPaciente;
            string fecha, enfermedad, tratamiento;
            cout << "ID del paciente: ";
            cin >> idPaciente;
            cout << "Fecha del registro: ";
            cin >> fecha;
            cout << "Enfermedad diagnosticada: ";
            cin >> enfermedad;
            cout << "Tratamiento: ";
            cin >> tratamiento;
            registrarHistorial(idPaciente, fecha, enfermedad, tratamiento);
            break;
        }
        case 6: {
            int idPaciente;
            cout << "ID del paciente para el reporte: ";
            cin >> idPaciente;
            generarReporteHistorial(idPaciente);
            break;
        }
        case 7: listarPacientes(); break;
        case 8: guardarPacientes(); break;
        default: cout << "Opción no válida.\n";
        }
    } while (opcion != 8);
}

void Paciente::guardarPacientes() {
    ofstream archivo("pacientes.txt");
    for (const auto& p : listaPacientes) {
        archivo << p.id << "," << p.nombre << "," << p.fechaIngreso << "\n";
    }
    archivo.close();
    cout << "Datos guardados correctamente.\n";
}

void Paciente::cargarPacientes() {
    ifstream archivo("pacientes.txt");
    if (!archivo) return;

    listaPacientes.clear();
    int id;
    string nombre, fechaIngreso;
    while (archivo >> id) {
        archivo.ignore();
        getline(archivo, nombre, ',');
        getline(archivo, fechaIngreso);
        listaPacientes.push_back(Paciente(id, nombre, fechaIngreso));
    }
    archivo.close();
}

void Paciente::altaPaciente() {
    int id;
    string nombre, fechaIngreso;
    cout << "Ingrese el ID del paciente: ";
    cin >> id;
    cout << "Ingrese el nombre del paciente: ";
    cin.ignore();  // Limpiar el buffer
    getline(cin, nombre);
    cout << "Ingrese la fecha de ingreso (formato: YYYY-MM-DD): ";
    cin >> fechaIngreso;

    // Agregar al vector de pacientes
    listaPacientes.push_back(Paciente(id, nombre, fechaIngreso));
    cout << "Paciente agregado con éxito.\n";
}

void Paciente::bajaPaciente() {
    int id;
    cout << "Ingrese el ID del paciente a eliminar: ";
    cin >> id;

    // Buscar el paciente por ID y eliminarlo
    auto it = find_if(listaPacientes.begin(), listaPacientes.end(), [id](const Paciente& paciente) {
        return paciente.id == id;
        });

    if (it != listaPacientes.end()) {
        listaPacientes.erase(it);
        cout << "Paciente eliminado con éxito.\n";
    }
    else {
        cout << "Paciente no encontrado.\n";
    }
}

void Paciente::modificarPaciente() {
    int id;
    cout << "Ingrese el ID del paciente a modificar: ";
    cin >> id;

    // Buscar el paciente por ID
    auto it = find_if(listaPacientes.begin(), listaPacientes.end(), [id](const Paciente& paciente) {
        return paciente.id == id;
        });

    if (it != listaPacientes.end()) {
        cout << "Paciente encontrado: " << it->nombre << ", " << it->fechaIngreso << "\n";
        cout << "Ingrese el nuevo nombre: ";
        cin.ignore();  // Limpiar el buffer
        getline(cin, it->nombre);
        cout << "Ingrese la nueva fecha de ingreso (formato: YYYY-MM-DD): ";
        cin >> it->fechaIngreso;
        cout << "Paciente modificado con éxito.\n";
    }
    else {
        cout << "Paciente no encontrado.\n";
    }
}

void Paciente::buscarPaciente() {
    int id;
    cout << "Ingrese el ID del paciente a buscar: ";
    cin >> id;

    // Buscar el paciente por ID
    auto it = find_if(listaPacientes.begin(), listaPacientes.end(), [id](const Paciente& paciente) {
        return paciente.id == id;
        });

    if (it != listaPacientes.end()) {
        cout << "Paciente encontrado: " << it->nombre << ", " << it->fechaIngreso << "\n";
    }
    else {
        cout << "Paciente no encontrado.\n";
    }
}

void Paciente::listarPacientes() {
    cout << "=== Listado de Pacientes ===\n";
    if (listaPacientes.empty()) {
        cout << "No hay pacientes registrados.\n";
    }
    else {
        for (const Paciente& p : listaPacientes) {
            cout << "ID: " << p.id << ", Nombre: " << p.nombre << ", Fecha de Ingreso: " << p.fechaIngreso << "\n";
        }
    }
}

void Paciente::registrarHistorial(int idPaciente, const string& fecha, const string& enfermedad, const string& tratamiento) {
    auto it = find_if(listaPacientes.begin(), listaPacientes.end(), [idPaciente](const Paciente& paciente) {
        return paciente.id == idPaciente;
        });

    if (it != listaPacientes.end()) {
        it->historialClinico.push_back(HistorialClinico(fecha, enfermedad, tratamiento));
        cout << "Historial registrado con éxito.\n";
    }
    else {
        cout << "Paciente no encontrado.\n";
    }
}

void Paciente::generarReporteHistorial(int idPaciente) {
    auto it = find_if(listaPacientes.begin(), listaPacientes.end(), [idPaciente](const Paciente& paciente) {
        return paciente.id == idPaciente;
        });

    if (it != listaPacientes.end()) {
        cout << "=== Reporte de Historial Clínico ===\n";
        for (const HistorialClinico& h : it->historialClinico) {
            cout << "Fecha: " << h.fecha << ", Enfermedad: " << h.enfermedad << ", Tratamiento: " << h.tratamiento << "\n";
        }
    }
    else {
        cout << "Paciente no encontrado.\n";
    }
}

