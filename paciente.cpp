#include "paciente.h"
#include <iostream>
#include <algorithm>
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
        cout << "8. Volver\n";
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
        case 8: break;
        default: cout << "Opción no válida.\n";
        }
    } while (opcion != 8);
}

void Paciente::altaPaciente() {
    int id;
    string nombre, fechaIngreso;
    bool fechaValida = false;

    cout << "Ingrese el ID del paciente: ";
    cin >> id;
    cout << "Ingrese el nombre del paciente: ";
    cin >> nombre;

    // Validar fecha de ingreso
    while (!fechaValida) {
        cout << "Ingrese la fecha de ingreso (formato: YYYY-MM-DD): ";
        cin >> fechaIngreso;

        // Comprobar si el formato es el esperado (YYYY-MM-DD)
        if (fechaIngreso.size() == 10 &&
            fechaIngreso[4] == '-' && fechaIngreso[7] == '-' &&
            isdigit(fechaIngreso[0]) && isdigit(fechaIngreso[1]) && isdigit(fechaIngreso[2]) && isdigit(fechaIngreso[3]) &&
            isdigit(fechaIngreso[5]) && isdigit(fechaIngreso[6]) &&
            isdigit(fechaIngreso[8]) && isdigit(fechaIngreso[9])) {
            fechaValida = true;
        }
        else {
            cout << "Fecha no válida. Asegúrese de usar el formato YYYY-MM-DD.\n";
        }
    }

    listaPacientes.push_back(Paciente(id, nombre, fechaIngreso));
    cout << "Paciente dado de alta con éxito.\n";
}

void Paciente::bajaPaciente() {
    int id;
    cout << "Ingrese el ID del paciente a dar de baja: ";
    cin >> id;

    auto it = find_if(listaPacientes.begin(), listaPacientes.end(), [id](const Paciente& p) {
        return p.id == id;
        });

    if (it != listaPacientes.end()) {
        listaPacientes.erase(it);
        cout << "Paciente dado de baja con éxito.\n";
    }
    else {
        cout << "Paciente no encontrado.\n";
    }
}

void Paciente::modificarPaciente() {
    int id;
    cout << "Ingrese el ID del paciente a modificar: ";
    cin >> id;

    auto it = find_if(listaPacientes.begin(), listaPacientes.end(), [id](const Paciente& p) {
        return p.id == id;
        });

    if (it != listaPacientes.end()) {
        cout << "Modificando paciente " << it->nombre << "\n";
        cout << "Ingrese nuevo nombre: ";
        cin >> it->nombre;
        cout << "Ingrese nueva fecha de ingreso: ";
        cin >> it->fechaIngreso;
        cout << "Datos modificados con éxito.\n";
    }
    else {
        cout << "Paciente no encontrado.\n";
    }
}

void Paciente::buscarPaciente() {
    int id;
    cout << "Ingrese el ID del paciente a buscar: ";
    cin >> id;

    auto it = find_if(listaPacientes.begin(), listaPacientes.end(), [id](const Paciente& p) {
        return p.id == id;
        });

    if (it != listaPacientes.end()) {
        cout << "Paciente encontrado: " << it->nombre << ", Fecha de ingreso: " << it->fechaIngreso << "\n";
    }
    else {
        cout << "Paciente no encontrado.\n";
    }
}

void Paciente::listarPacientes() {
    cout << "=== Listado de Pacientes ===\n";
    for (const Paciente& p : listaPacientes) {
        cout << "ID: " << p.id << ", Nombre: " << p.nombre << ", Fecha de ingreso: " << p.fechaIngreso << "\n";
    }
}

void Paciente::registrarHistorial(int idPaciente, const string& fecha, const string& enfermedad, const string& tratamiento) {
    for (Paciente& paciente : listaPacientes) {
        if (paciente.id == idPaciente) {
            paciente.historialClinico.push_back(HistorialClinico(fecha, enfermedad, tratamiento));
            cout << "Historial clínico registrado con éxito.\n";
            return;
        }
    }
    cout << "Paciente no encontrado.\n";
}

void Paciente::generarReporteHistorial(int idPaciente) {
    for (const Paciente& paciente : listaPacientes) {
        if (paciente.id == idPaciente) {
            cout << "=== Reporte de Historial Clínico ===\n";
            cout << "Paciente: " << paciente.nombre << "\n";
            cout << "Fecha de ingreso: " << paciente.fechaIngreso << "\n";
            cout << "Historial clínico:\n";
            for (const HistorialClinico& historial : paciente.historialClinico) {
                cout << "Fecha: " << historial.fecha << ", Enfermedad: " << historial.enfermedad
                    << ", Tratamiento: " << historial.tratamiento << "\n";
            }
            return;
        }
    }
    cout << "Paciente no encontrado.\n";
}

