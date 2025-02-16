#include <iostream>
#include "medico.h"
#include "paciente.h"
#include "citamedica.h"

using namespace std;

void mostrarMenuPrincipal() {
    cout << "=== Sistema de Gestión Hospitalaria ===\n";
    cout << "1. Gestión de Médicos\n";
    cout << "2. Gestión de Pacientes\n";
    cout << "3. Gestión de Citas Médicas\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    int opcion;
    Medico medico;
    Paciente paciente;
    CitaMedica cita;

    do {
        mostrarMenuPrincipal();
        cin >> opcion;

        switch (opcion) {
        case 1:
            medico.menuMedicos();
            break;
        case 2:
            paciente.menuPacientes();
            break;
        case 3:
            cita.menuCitas();
            break;
        case 4:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}

