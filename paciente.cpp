int main() {
    const std::string FILENAME = "pacientes.txt";
    std::vector<Paciente> pacientes = Paciente::cargarPacientes(FILENAME); // Cargar pacientes desde archivo

    int opcion;
    do {
        std::cout << "\nGestión de Pacientes - Opciones disponibles:\n";
        std::cout << "1. Registrar un nuevo paciente\n";
        std::cout << "2. Listar todos los pacientes\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            int id;
            std::string nombre, telefono;
            std::cout << "Ingrese el ID del paciente: ";
            std::cin >> id;
            std::cin.ignore(); // Limpiar buffer
            std::cout << "Ingrese el nombre del paciente: ";
            std::getline(std::cin, nombre);
            std::cout << "Ingrese el teléfono del paciente: ";
            std::getline(std::cin, telefono);

            pacientes.emplace_back(id, nombre, telefono);
            Paciente::guardarPacientes(pacientes, FILENAME); // Guardar después de registrar
            std::cout << "Paciente registrado exitosamente.\n";
            break;
        }
        case 2: {
            if (pacientes.empty()) {
                std::cout << "No hay pacientes registrados.\n";
            }
            else {
                std::cout << "Listado de pacientes:\n";
                for (const auto& paciente : pacientes) {
                    paciente.mostrarInfo();
                }
            }
            break;
        }
        case 3:
            std::cout << "Saliendo del programa. ¡Hasta luego!\n";
            Paciente::guardarPacientes(pacientes, FILENAME); // Guardar antes de salir
            break;
        default:
            std::cout << "Opción inválida. Inténtelo de nuevo.\n";
        }
    } while (opcion != 3);

    return 0;
}

