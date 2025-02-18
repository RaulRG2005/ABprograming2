#include <iostream>
#include "paciente.h"
#include "medico.h"
#include "citamedica.h"  

using namespace std;

int main() {
    
    Paciente::cargarPacientes();
    Medico::cargarMedicos();
    CitaMedica::cargarCitas();  

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
            Paciente::menuPacientes();  
            break;
        case 2:
            Medico::menuMedicos();  
            break;
        case 3:
            CitaMedica::menuCitas();  
            break;
        case 4:
            
            Paciente::guardarPacientes();
            Medico::guardarMedicos();
            CitaMedica::guardarCitas();  
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opción no válida.\n";
        }
    } while (opcion != 4);

    return 0;
}

