<iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#ifndef PACIENTE_H
#define PACIENTE_H

class Paciente {
private:
    int id;
    std::string nombre;
    std::string telefono;

public:
    // Constructor
    Paciente(int _id, const std::string& _nombre, const std::string& _telefono)
        : id(_id), nombre(_nombre), telefono(_telefono) {}

    // Métodos para obtener y modificar datos
    int getId() const { return id; }
    std::string getNombre() const { return nombre; }
    std::string getTelefono() const { return telefono; }
    void setNombre(const std::string& nuevoNombre) { nombre = nuevoNombre; }
    void setTelefono(const std::string& nuevoTelefono) { telefono = nuevoTelefono; }

    // Mostrar información del paciente
    void mostrarInfo() const {
        std::cout << "ID: " << id << ", Nombre: " << nombre << ", Teléfono: " << telefono << "\n";
    }

    // Métodos para guardar y cargar datos
    static void guardarPacientes(const std::vector<Paciente>& pacientes, const std::string& filename) {
        std::ofstream archivo(filename, std::ios::out | std::ios::trunc);
        if (!archivo.is_open()) {
            std::cerr << "Error al abrir el archivo para guardar pacientes.\n";
            return;
        }

        for (const auto& paciente : pacientes) {
            archivo << paciente.id << "|" << paciente.nombre << "|" << paciente.telefono << "\n";
        }

        archivo.close();
        if (archivo.fail()) {
            std::cerr << "Error al guardar los datos en el archivo.\n";
        }
    }

    static std::vector<Paciente> abrirFicheroPacientes(const std::string& filename) {
        std::vector<Paciente> pacientes;
        std::ifstream archivo(filename);
        if (!archivo.is_open()) {
            std::cerr << "Error al abrir el archivo para cargar pacientes.\n";
            return pacientes;
        }

        std::string linea;
        while (std::getline(archivo, linea)) {
            std::stringstream ss(linea);
            std::string idStr, nombre, telefono;

            std::getline(ss, idStr, '|');
            std::getline(ss, nombre, '|');
            std::getline(ss, telefono, '|');

            if (!idStr.empty() && !nombre.empty() && !telefono.empty()) {
                int id = std::stoi(idStr);
                pacientes.emplace_back(id, nombre, telefono);
            }
        }

        archivo.close();
        return pacientes;
    }
};

#endif // PACIENTE_H

int main() {
    const std::string FILENAME = "pacientes.txt";
    std::vector<Paciente> pacientes = Paciente::abrirFicheroPacientes(FILENAME); // Cargar pacientes desde archivo al inicio

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