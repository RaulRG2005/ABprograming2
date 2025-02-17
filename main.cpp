#include <iostream>
#include "paciente.h"
#include "medico.h"
#include "citamedica.h"  // Cambiado a citamedica.h

using namespace std;

int main() {
    int opcion;
    do {
        cout << "=== Menu Principal ===\n";
        cout << "1. Gestión de Pacientes\n";
        cout << "2. Gestión de Médicos\n";
        cout << "3. Gestión de Citas Médicas\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            Paciente::menuPacientes();  // Menú de gestión de pacientes
            break;
        case 2:
            Medico::menuMedicos();  // Menú de gestión de médicos
            break;
        case 3:
            CitaMedica::menuCitas();  // Cambiado a CitaMedica
            break;
        case 4:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opción no válida.\n";
        }
    } while (opcion != 4);

    return 0;
}

