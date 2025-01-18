#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <vector>

class Paciente {
private:
    int id;
    std::string nombre;
    std::string telefono;

public:
    // Constructor
    Paciente(int _id, const std::string& _nombre, const std::string& _telefono);

    // M�todos para obtener y modificar datos
    int getId() const;
    std::string getNombre() const;
    std::string getTelefono() const;
    void setNombre(const std::string& nuevoNombre);
    void setTelefono(const std::string& nuevoTelefono);

    // Mostrar informaci�n del paciente
    void mostrarInfo() const;

    // M�todos para guardar y cargar datos
    static void guardarPacientes(const std::vector<Paciente>& pacientes, const std::string& filename);
    static std::vector<Paciente> cargarPacientes(const std::string& filename);
};

#endif // PACIENTE_H
