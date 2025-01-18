#ifndef MEDICO_H
#define MEDICO_H

#include <string>
#include <iostream>

class Medico {
private:
    int id;
    std::string nombre;
    std::string especialidad;

public:
    // Constructor
    Medico(int _id, const std::string& _nombre, const std::string& _especialidad)
        : id(_id), nombre(_nombre), especialidad(_especialidad) {}

    // M�todos para obtener y modificar datos
    int getId() const { return id; }
    std::string getNombre() const { return nombre; }
    std::string getEspecialidad() const { return especialidad; }
    void setNombre(const std::string& nuevoNombre) { nombre = nuevoNombre; }
    void setEspecialidad(const std::string& nuevaEspecialidad) { especialidad = nuevaEspecialidad; }

    // Mostrar informaci�n del m�dico
    void mostrarInfo() const {
        std::cout << "ID: " << id << ", Nombre: " << nombre << ", Especialidad: " << especialidad << "\n";
    }

    // M�todos para guardar y cargar datos
    static void guardarMedicos(const std::vector<Medico>& medicos, const std::string& filename) {
        std::ofstream archivo(filename, std::ios::out | std::ios::trunc);
        if (!archivo.is_open()) {
            std::cerr << "Error al abrir el archivo para guardar m�dicos.\n";
            return;
        }

        for (const auto& medico : medicos) {
            archivo << medico.id << "|" << medico.nombre << "|" << medico.especialidad << "\n";
        }

        archivo.close();
        if (archivo.fail()) {
            std::cerr << "Error al guardar los datos en el archivo.\n";
        }
    }

    static std::vector<Medico> abrirFicheroMedicos(const std::string& filename) {
        std::vector<Medico> medicos;
        std::ifstream archivo(filename);
        if (!archivo.is_open()) {
            std::cerr << "Error al abrir el archivo para cargar m�dicos.\n";
            return medicos;
        }

        std::string linea;
        while (std::getline(archivo, linea)) {
            std::stringstream ss(linea);
            std::string idStr, nombre, especialidad;

            std::getline(ss, idStr, '|');
            std::getline(ss, nombre, '|');
            std::getline(ss, especialidad, '|');

            if (!idStr.empty() && !nombre.empty() && !especialidad.empty()) {
                int id = std::stoi(idStr);
                medicos.emplace_back(id, nombre, especialidad);
            }
        }

        archivo.close();
        return medicos;
    }
};

#endif // MEDICO_H
