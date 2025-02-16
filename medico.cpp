#include "medico.h"

void Medico::menuMedicos() {
    int opcion;
    do {
        cout << "=== Gestión de Médicos ===\n";
        cout << "1. Alta de Médico\n";
        cout << "2. Baja de Médico\n";
        cout << "3. Listar Médicos\n";
        cout << "4. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch (opcion) {
        case 1: altaMedico(); break;
        case 2: bajaMedico(); break;
        case 3: listarMedicos(); break;
        case 4: break;
        default: cout << "Opción no válida\n";
        }
    } while (opcion != 4);
}

void Medico::altaMedico() {
    cout << "Alta de Médico.\n";
}

void Medico::bajaMedico() {
    cout << "Baja de Médico.\n";
}

void Medico::listarMedicos() {
    cout << "Listado de Médicos.\n";
}
