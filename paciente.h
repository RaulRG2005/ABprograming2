#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

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

    static std::vector<Paciente> cargarPacientes(const std::string& filename) {
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
