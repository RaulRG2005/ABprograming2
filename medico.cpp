#include "medico.h"

void Medico::menuMedicos() {
    int opcion;
    do {
        cout << "=== Gesti�n de M�dicos ===\n";
        cout << "1. Alta de M�dico\n";
        cout << "2. Baja de M�dico\n";
        cout << "3. Listar M�dicos\n";
        cout << "4. Volver\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;
        switch (opcion) {
        case 1: altaMedico(); break;
        case 2: bajaMedico(); break;
        case 3: listarMedicos(); break;
        case 4: break;
        default: cout << "Opci�n no v�lida\n";
        }
    } while (opcion != 4);
}

void Medico::altaMedico() {
    cout << "Alta de M�dico.\n";
}

void Medico::bajaMedico() {
    cout << "Baja de M�dico.\n";
}

void Medico::listarMedicos() {
    cout << "Listado de M�dicos.\n";
}
