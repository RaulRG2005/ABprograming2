#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class HistorialClinico {
public:
    string fecha;
    string enfermedad;
    string tratamiento;

    HistorialClinico(string fecha, string enfermedad, string tratamiento)
        : fecha(fecha), enfermedad(enfermedad), tratamiento(tratamiento) {}
};

class Paciente {
public:
    int id;
    string nombre;
    string fechaIngreso;
    vector<HistorialClinico> historialClinico;  // Historial médico del paciente

    static vector<Paciente> listaPacientes;

    Paciente(int id, string nombre, string fechaIngreso);

    static void menuPacientes();
    static void altaPaciente();
    static void bajaPaciente();
    static void modificarPaciente();
    static void buscarPaciente();
    static void listarPacientes();
    static void registrarHistorial(int idPaciente, const string& fecha, const string& enfermedad, const string& tratamiento);
    static void generarReporteHistorial(int idPaciente);
};

#endif


