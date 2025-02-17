#include "medico.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<Medico> Medico::listaMedicos;  // Vector estático para almacenar los médicos

// Alta de un médico
void Medico::altaMedico() {
    string nombre, especialidad;
    cout << "Ingrese nombre del medico: ";
    cin >> nombre;
    cin.ignore();

    cout << "Ingrese especialidad del medico: ";
    cin >> especialidad;
    cin.ignore();

    Medico nuevoMedico;
    nuevoMedico.nombre = nombre;
    nuevoMedico.especialidad = especialidad;
    listaMedicos.push_back(nuevoMedico);

    cout << "Medico registrado con exito.\n";
    guardarMedicos();  // Guardar datos al archivo
}

// Baja de un médico
void Medico::bajaMedico() {
    string nombre;
    cout << "Ingrese el nombre del medico a dar de baja: ";
    cin >> nombre;
    cin.ignore();

    for (auto it = listaMedicos.begin(); it != listaMedicos.end(); ++it) {
        if (it->nombre == nombre) {
            listaMedicos.erase(it);
            cout << "Medico " << nombre << " dado de baja exitosamente.\n";
            guardarMedicos();  // Guardar datos al archivo
            return;
        }
    }
    cout << "Medico no encontrado.\n";
}

// Listar médicos
void Medico::listarMedicos() {
    if (listaMedicos.empty()) {
        cout << "No hay medicos registrados.\n";
    }
    else {
        cout << "=== Listado de Medicos ===\n";
        for (const auto& medico : listaMedicos) {
            cout << "Nombre: " << medico.nombre << ", Especialidad: " << medico.especialidad << "\n";
        }
    }
}

// Menú de opciones para gestionar médicos
void Medico::menuMedicos() {
    int opcion;
    do {
        cout << "=== Gestion de Medicos ===\n";
        cout << "1. Alta de Medico\n";
        cout << "2. Baja de Medico\n";
        cout << "3. Listar Medicos\n";
        cout << "4. Volver\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            altaMedico();
            break;
        case 2:
            bajaMedico();
            break;
        case 3:
            listarMedicos();
            break;
        case 4:
            break;
        default:
            cout << "Opcion no valida.\n";
        }
    } while (opcion != 4);
}

// Guardar médicos en archivo
void Medico::guardarMedicos() {
    ofstream archivo("medicos.txt");
    if (archivo.is_open()) {
        for (const auto& medico : listaMedicos) {
            archivo << medico.nombre << "," << medico.especialidad << "\n";
        }
        archivo.close();
    }
    else {
        cout << "Error al abrir el archivo de medicos.\n";
    }
}

// Cargar médicos desde archivo
void Medico::cargarMedicos() {
    ifstream archivo("medicos.txt");
    if (archivo.is_open()) {
        listaMedicos.clear();
        string nombre, especialidad;
        while (getline(archivo, nombre, ',') && getline(archivo, especialidad)) {
            Medico medico;
            medico.nombre = nombre;
            medico.especialidad = especialidad;
            listaMedicos.push_back(medico);
        }
        archivo.close();
    }
    else {
        cout << "No hay datos previos de medicos.\n";
    }
}



