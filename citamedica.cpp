#include "citamedica.h"

void CitaMedica::menuCitas() {
    int opcion;
    do {
        cout << "=== Gestión de Citas Médicas ===\n";
        cout << "1. Asignar Cita\n";
        cout << "2. Cancelar Cita\n";
        cout << "3. Modificar Cita\n";
        cout << "4. Listar Citas\n";
        cout << "5. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch (opcion) {
        case 1: asignarCita(); break;
        case 2: cancelarCita(); break;
        case 3: modificarCita(); break;
        case 4: listarCitas(); break;
        case 5: break;
        default: cout << "Opción no válida\n";
        }
    } while (opcion != 5);
}

void CitaMedica::asignarCita() {
    cout << "Asignación de Cita Médica.\n";
}

void CitaMedica::cancelarCita() {
    cout << "Cancelación de Cita Médica.\n";
}

void CitaMedica::modificarCita() {
    cout << "Modificación de Cita Médica.\n";
}

void CitaMedica::listarCitas() {
    cout << "Listado de Citas Médicas.\n";
}




