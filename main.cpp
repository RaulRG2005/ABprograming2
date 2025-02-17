#include <iostream>
#include "medico.h"
#include "citamedica.h"

int main() {
    // Menú principal
    int opcion;
    do {
        std::cout << "=== Menú Principal ===\n";
        std::cout << "1. Gestionar Médicos\n";
        std::cout << "2. Gestionar Citas Médicas\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            int opcionMedico;
            do {
                std::cout << "\n=== Gestión de Médicos ===\n";
                std::cout << "1. Listar Médicos\n";
                std::cout << "2. Volver\n";
                std::cout << "Seleccione una opción: ";
                std::cin >> opcionMedico;

                switch (opcionMedico) {
                case 1:
                    Medico::listarMedicos();
                    break;
                case 2:
                    break;
                default:
                    std::cout << "Opción no válida. Intente de nuevo.\n";
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
            std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 3);

    return 0;
}
