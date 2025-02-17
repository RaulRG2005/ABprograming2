#include "medico.h"
#include <iostream>
#include <vector>

using namespace std;

vector<Medico> Medico::listaMedicos;  // Vector estático para almacenar los médicos

// Alta de un médico
void Medico::altaMedico() {
    string nombre, especialidad;
    cout << "Ingrese nombre del medico: ";
    cin >> nombre;  // Leer nombre (solo hasta el primer espacio)
    cin.ignore();  // Limpiar el buffer de entrada

    cout << "Ingrese especialidad del medico: ";
    cin >> especialidad;  // Leer especialidad (solo hasta el primer espacio)
    cin.ignore();  // Limpiar el buffer de entrada

    // Crear un nuevo objeto Medico y agregarlo al vector
    Medico nuevoMedico;
    nuevoMedico.nombre = nombre;
    nuevoMedico.especialidad = especialidad;
    listaMedicos.push_back(nuevoMedico);

    cout << "Medico registrado con exito.\n";
}

// Baja de un médico
void Medico::bajaMedico() {
    string nombre;
    cout << "Ingrese el nombre del medico a dar de baja: ";
    cin >> nombre;  // Leer el nombre del medico a dar de baja
    cin.ignore();  // Limpiar el buffer de entrada

    // Buscar al médico en la lista y eliminarlo
    for (auto it = listaMedicos.begin(); it != listaMedicos.end(); ++it) {
        if (it->nombre == nombre) {
            listaMedicos.erase(it);
            cout << "Medico " << nombre << " dado de baja exitosamente.\n";
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
            altaMedico();  // Llamada para dar de alta
            break;
        case 2:
            bajaMedico();  // Llamada para dar de baja
            break;
        case 3:
            listarMedicos();  // Listado de médicos
            break;
        case 4:
            break;
        default:
            cout << "Opcion no valida.\n";
        }
    } while (opcion != 4);
}



