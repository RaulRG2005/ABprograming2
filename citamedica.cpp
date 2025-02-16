#include "citamedica.h"

void CitaMedica::menuCitas() {
    int opcion;
    do {
        cout << "=== Gesti�n de Citas M�dicas ===\n";
        cout << "1. Asignar Cita\n";
        cout << "2. Cancelar Cita\n";
        cout << "3. Modificar Cita\n";
        cout << "4. Listar Citas\n";
        cout << "5. Volver\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;
        switch (opcion) {
        case 1: asignarCita(); break;
        case 2: cancelarCita(); break;
        case 3: modificarCita(); break;
        case 4: listarCitas(); break;
        case 5: break;
        default: cout << "Opci�n no v�lida\n";
        }
    } while (opcion != 5);
}

void CitaMedica::asignarCita() {
    cout << "Asignaci�n de Cita M�dica.\n";
}

void CitaMedica::cancelarCita() {
    cout << "Cancelaci�n de Cita M�dica.\n";
}

void CitaMedica::modificarCita() {
    cout << "Modificaci�n de Cita M�dica.\n";
}

void CitaMedica::listarCitas() {
    cout << "Listado de Citas M�dicas.\n";
}




