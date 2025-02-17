#include <iostream>
#include "paciente.h"
#include "medico.h"
#include "citamedica.h"  // Incluye el encabezado de CitaMedica

using namespace std;

int main() {
    // Cargar los datos de pacientes, m�dicos y citas al iniciar el programa
    Paciente::cargarPacientes();
    Medico::cargarMedicos();
    CitaMedica::cargarCitas();  // Cargar las citas m�dicas

    int opcion;
    do {
        cout << "=== Menu Principal ===\n";
        cout << "1. Gestion de Pacientes\n";
        cout << "2. Gestion de Medicos\n";
        cout << "3. Gestion de Citas Medicas\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            Paciente::menuPacientes();  // Men� de gesti�n de pacientes
            break;
        case 2:
            Medico::menuMedicos();  // Men� de gesti�n de m�dicos
            break;
        case 3:
            CitaMedica::menuCitas();  // Men� de gesti�n de citas m�dicas
            break;
        case 4:
            // Guardar los datos antes de salir
            Paciente::guardarPacientes();
            Medico::guardarMedicos();
            CitaMedica::guardarCitas();  // Guardar las citas m�dicas
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opci�n no v�lida.\n";
        }
    } while (opcion != 4);

    return 0;
}

