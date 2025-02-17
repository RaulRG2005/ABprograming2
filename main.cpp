#include <iostream>
#include "paciente.h"
#include "medico.h"
#include "citamedica.h"  // Incluye el encabezado de CitaMedica

using namespace std;

int main() {
    // Cargar los datos de pacientes, médicos y citas al iniciar el programa
    Paciente::cargarPacientes();
    Medico::cargarMedicos();
    CitaMedica::cargarCitas();  // Cargar las citas médicas

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
            Paciente::menuPacientes();  // Menú de gestión de pacientes
            break;
        case 2:
            Medico::menuMedicos();  // Menú de gestión de médicos
            break;
        case 3:
            CitaMedica::menuCitas();  // Menú de gestión de citas médicas
            break;
        case 4:
            // Guardar los datos antes de salir
            Paciente::guardarPacientes();
            Medico::guardarMedicos();
            CitaMedica::guardarCitas();  // Guardar las citas médicas
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opción no válida.\n";
        }
    } while (opcion != 4);

    return 0;
}

