#ifndef CITA_H
#define CITA_H

#include <string>
#include <iostream>

class Cita {
private:
    int id;
    std::string fecha;
    std::string descripcion;

public:
    // Constructor
    Cita(int _id, const std::string& _fecha, const std::string& _descripcion)
        : id(_id), fecha(_fecha), descripcion(_descripcion) {}

    // Métodos para obtener y modificar datos
    int getId() const { return id; }
    std::string getFecha() const { return fecha; }
    std::string getDescripcion() const { return descripcion; }
    void setFecha(const std::string& nuevaFecha) { fecha = nuevaFecha; }
    void setDescripcion(const std::string& nuevaDescripcion) { descripcion = nuevaDescripcion; }

    // Mostrar información de la cita
    void mostrarInfo() const {
        std::cout << "ID: " << id << ", Fecha: " << fecha << ", Descripción: " << descripcion << "\n";
    }

    // Métodos para guardar y cargar datos
    static void guardarCitas(const std::vector<Cita>& citas, const std::string& filename) {
        std::ofstream archivo(filename, std::ios::out | std::ios::trunc);
        if (!archivo.is_open()) {
            std::cerr << "Error al abrir el archivo para guardar citas.\n";
            return;
        }

        for (const auto& cita : citas) {
            archivo << cita.id << "|" << cita.fecha << "|" << cita.descripcion << "\n";
        }

        archivo.close();
        if (archivo.fail()) {
            std::cerr << "Error al guardar los datos en el archivo.\n";
        }
    }

    static std::vector<Cita> abrirFicheroCitas(const std::string& filename) {
        std::vector<Cita> citas;
        std::ifstream archivo(filename);
        if (!archivo.is_open()) {
            std::cerr << "Error al abrir el archivo para cargar citas.\n";
            return citas;
        }

        std::string linea;
        while (std::getline(archivo, linea)) {
            std::stringstream ss(linea);
            std::string idStr, fecha, descripcion;

            std::getline(ss, idStr, '|');
            std::getline(ss, fecha, '|');
            std::getline(ss, descripcion, '|');

            if (!idStr.empty() && !fecha.empty() && !descripcion.empty()) {
                int id = std::stoi(idStr);
                citas.emplace_back(id, fecha, descripcion);
            }
        }

        archivo.close();
        return citas;
    }
};

#endif // CITA_H
