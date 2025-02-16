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
            cout << "Opci�n no v�lida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}

