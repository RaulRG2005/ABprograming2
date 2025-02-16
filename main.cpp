#include <iostream>
#include "medico.h"
#include "paciente.h"
#include "citamedica.h"

using namespace std;

void mostrarMenuPrincipal() {
    cout << "=== Sistema de Gesti�n Hospitalaria ===\n";
    cout << "1. Gesti�n de M�dicos\n";
    cout << "2. Gesti�n de Pacientes\n";
    cout << "3. Gesti�n de Citas M�dicas\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opci�n: ";
}

int main() {
    int opcion;

    do {
        mostrarMenuPrincipal();
        cin >> opcion;

        switch (opcion) {
        case 1:
            Medico::menuMedicos();
            break;
        case 2:
            Paciente::menuPacientes();
            break;
        case 3:
            CitaMedica::menuCitas();
            break;
        case 4:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opci�n no v�lida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}

