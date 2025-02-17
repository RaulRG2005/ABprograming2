#include <iostream>
#include "medico.h"
#include "citamedica.h"

int main() {
    // Men� principal
    int opcion;
    do {
        std::cout << "=== Men� Principal ===\n";
        std::cout << "1. Gestionar M�dicos\n";
        std::cout << "2. Gestionar Citas M�dicas\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opci�n: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            int opcionMedico;
            do {
                std::cout << "\n=== Gesti�n de M�dicos ===\n";
                std::cout << "1. Listar M�dicos\n";
                std::cout << "2. Volver\n";
                std::cout << "Seleccione una opci�n: ";
                std::cin >> opcionMedico;

                switch (opcionMedico) {
                case 1:
                    Medico::listarMedicos();
                    break;
                case 2:
                    break;
                default:
                    std::cout << "Opci�n no v�lida. Intente de nuevo.\n";
                }
            } while (opcionMedico != 2);
            break;
        }
        case 2:
            CitaMedica::menuCitas();
            break;
        case 3:
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opci�n no v�lida. Intente de nuevo.\n";
        }
    } while (opcion != 3);

    return 0;
}
