#include "paciente.h"

void Paciente::menuPacientes() {
    int opcion;
    do {
        cout << "=== Gestión de Pacientes ===\n";
        cout << "1. Alta de Paciente\n";
        cout << "2. Baja de Paciente\n";
        cout << "3. Modificar Datos\n";
        cout << "4. Buscar Paciente\n";
        cout << "5. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch (opcion) {
        case 1: altaPaciente(); break;
        case 2: bajaPaciente(); break;
        case 3: modificarDatos(); break;
        case 4: buscarPaciente(); break;
        case 5: break;
        default: cout << "Opción no válida\n";
        }
    } while (opcion != 5);
}

void Paciente::altaPaciente() {
    cout << "Alta de Paciente.\n";
}

void Paciente::bajaPaciente() {
    cout << "Baja de Paciente.\n";
}

void Paciente::modificarDatos() {
    cout << "Modificación de Datos del Paciente.\n";
}

void Paciente::buscarPaciente() {
    cout << "Búsqueda de Paciente.\n";
}
