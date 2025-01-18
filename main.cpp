#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "paciente.h"
#include "cita.h"
#include "medico.h"

int main() {
    const std::string FILENAME_PACIENTES = "pacientes.txt";
    const std::string FILENAME_CITAS = "citas.txt";
    const std::string FILENAME_MEDICOS = "medicos.txt";

    std::vector<Paciente> pacientes = Paciente::abrirFicheroPacientes(FILENAME_PACIENTES);  // Cargar pacientes desde archivo al inicio
    std::vector<Cita> citas = Cita::abrirFicheroCitas(FILENAME_CITAS);                      // Cargar citas desde archivo al inicio
    std::vector<Medico> medicos = Medico::abrirFicheroMedicos(FILENAME_MEDICOS);            // Cargar m�dicos desde archivo al inicio

    int opcion;
    do {
        std::cout << "\nGesti�n de Pacientes - Opciones disponibles:\n";
        std::cout << "1. Registrar un nuevo paciente\n";
        std::cout << "2. Registrar una nueva cita\n";
        std::cout << "3. Registrar un nuevo m�dico\n";
        std::cout << "4. Listar todos los pacientes\n";
        std::cout << "5. Listar todas las citas\n";
        std::cout << "6. Listar todos los m�dicos\n";
        std::cout << "7. Salir\n";
        std::cout << "Seleccione una opci�n: ";
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
            std::cout << "Ingrese el tel�fono del paciente: ";
            std::getline(std::cin, telefono);

            pacientes.emplace_back(id, nombre, telefono);
            Paciente::guardarPacientes(pacientes, FILENAME_PACIENTES); // Guardar despu�s de registrar
            std::cout << "Paciente registrado exitosamente.\n";
            break;
        }
        case 2: {
            int id;
            std::string fecha, descripcion;
            std::cout << "Ingrese el ID de la cita: ";
            std::cin >> id;
            std::cin.ignore(); // Limpiar buffer
            std::cout << "Ingrese la fecha de la cita: ";
            std::getline(std::cin, fecha);
            std::cout << "Ingrese la descripci�n de la cita: ";
            std::getline(std::cin, descripcion);

            citas.emplace_back(id, fecha, descripcion);
            Cita::guardarCitas(citas, FILENAME_CITAS); // Guardar despu�s de registrar
            std::cout << "Cita registrada exitosamente.\n";
            break;
        }
        case 3: {
            int id;
            std::string nombre, especialidad;
            std::cout << "Ingrese el ID del m�dico: ";
            std::cin >> id;
            std::cin.ignore(); // Limpiar buffer
            std::cout << "Ingrese el nombre del m�dico: ";
            std::getline(std::cin, nombre);
            std::cout << "Ingrese la especialidad del m�dico: ";
            std::getline(std::cin, especialidad);

            medicos.emplace_back(id, nombre, especialidad);
            Medico::guardarMedicos(medicos, FILENAME_MEDICOS); // Guardar despu�s de registrar
            std::cout << "M�dico registrado exitosamente.\n";
            break;
        }
        case 4: {
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
        case 5: {
            if (citas.empty()) {
                std::cout << "No hay citas registradas.\n";
            }
            else {
                std::cout << "Listado de citas:\n";
                for (const auto& cita : citas) {
                    cita.mostrarInfo();
                }
            }
            break;
        }
        case 6: {
            if (medicos.empty()) {
                std::cout << "No hay m�dicos registrados.\n";
            }
            else {
                std::cout << "Listado de m�dicos:\n";
                for (const auto& medico : medicos) {
                    medico.mostrarInfo();
                }
            }
            break;
        }
        case 7:
            std::cout << "Saliendo del programa. �Hasta luego!\n";
            Paciente::guardarPacientes(pacientes, FILENAME_PACIENTES); // Guardar antes de salir
            Cita::guardarCitas(citas, FILENAME_CITAS); // Guardar antes de salir
            Medico::guardarMedicos(medicos, FILENAME_MEDICOS); // Guardar antes de salir
            break;
        default:
            std::cout << "Opci�n inv�lida. Int�ntelo de nuevo.\n";
        }
    } while (opcion != 7);

    return
