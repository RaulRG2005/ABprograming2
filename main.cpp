#include <iostream>
#include "paciente.h"
#include "medico.h"
#include "citamedica.h"  // Cambiado a citamedica.h

using namespace std;

int main() {
    int opcion;
    do {
        cout << "=== Menu Principal ===\n";
        cout << "1. Gesti�n de Pacientes\n";
        cout << "2. Gesti�n de M�dicos\n";
        cout << "3. Gesti�n de Citas M�dicas\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            Paciente::menuPacientes();  // Men� de gesti�n de pacientes
            break;
        case 2:
            Medico::menuMedicos();  // Men� de gesti�n de m�dicos
            break;
        case 3:
            CitaMedica::menuCitas();  // Cambiado a CitaMedica
            break;
        case 4:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opci�n no v�lida.\n";
        }
    } while (opcion != 4);

    return 0;
}

