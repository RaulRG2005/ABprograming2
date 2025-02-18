#include "medico.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

vector<Medico> Medico::listaMedicos;

Medico::Medico(int id, string nombre, string especialidad)
    : id(id), nombre(nombre), especialidad(especialidad) {}

// Función para validar entrada numérica
int leerEntero(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Ingrese un número válido. Intente de nuevo.\n";
        }
        else {
            cin.ignore(1000, '\n');
            return valor;
        }
    }
}

// Función para validar entrada de texto (sin números)
string leerTexto(const string& mensaje) {
    string texto;
    bool valido;
    do {
        valido = true;
        cout << mensaje;
        cin >> texto;
        for (char c : texto) {
            if (isdigit(c)) {
                cout << "Error: El texto no puede contener números. Intente de nuevo.\n";
                valido = false;
                break;
            }
        }
    } while (!valido);
    return texto;
}

void Medico::menuMedicos() {
    int opcion;
    do {
        cout << "\n=== Gestión de Médicos ===\n";
        cout << "1. Alta de Medico\n";
        cout << "2. Baja de Medico\n";
        cout << "3. Modificar Medico\n";
        cout << "4. Buscar Medico\n";
        cout << "5. Listar Medicos\n";
        cout << "6. Guardar y Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1: altaMedico(); break;
        case 2: bajaMedico(); break;
        case 3: modificarMedico(); break;
        case 4: buscarMedico(); break;
        case 5: listarMedicos(); break;
        case 6: guardarMedicos(); break;
        default: cout << "Opción no válida.\n";
        }
    } while (opcion != 6);
}

void Medico::altaMedico() {
    int id = leerEntero("Ingrese el ID del médico: ");
    string nombre = leerTexto("Ingrese el nombre del médico: ");
    string especialidad = leerTexto("Ingrese la especialidad del médico: ");

    listaMedicos.push_back(Medico(id, nombre, especialidad));
    cout << "Médico registrado con éxito.\n";
}

void Medico::bajaMedico() {
    int id = leerEntero("Ingrese el ID del médico a eliminar: ");
    auto it = find_if(listaMedicos.begin(), listaMedicos.end(), [id](const Medico& m) {
        return m.id == id;
        });

    if (it != listaMedicos.end()) {
        listaMedicos.erase(it);
        cout << "Médico eliminado con éxito.\n";
    }
    else {
        cout << "Médico no encontrado.\n";
    }
}

void Medico::modificarMedico() {
    int id = leerEntero("Ingrese el ID del médico a modificar: ");
    auto it = find_if(listaMedicos.begin(), listaMedicos.end(), [id](const Medico& m) {
        return m.id == id;
        });

    if (it != listaMedicos.end()) {
        cout << "Médico encontrado: " << it->nombre << ", Especialidad: " << it->especialidad << "\n";
        it->nombre = leerTexto("Ingrese el nuevo nombre del médico: ");
        it->especialidad = leerTexto("Ingrese la nueva especialidad del médico: ");
        cout << "Médico modificado con éxito.\n";
    }
    else {
        cout << "Médico no encontrado.\n";
    }
}

void Medico::buscarMedico() {
    int id = leerEntero("Ingrese el ID del médico a buscar: ");
    auto it = find_if(listaMedicos.begin(), listaMedicos.end(), [id](const Medico& m) {
        return m.id == id;
        });

    if (it != listaMedicos.end()) {
        cout << "Médico encontrado: " << it->nombre << ", Especialidad: " << it->especialidad << "\n";
    }
    else {
        cout << "Médico no encontrado.\n";
    }
}

void Medico::listarMedicos() {
    cout << "\n=== Lista de Médicos ===\n";
    if (listaMedicos.empty()) {
        cout << "No hay médicos registrados.\n";
    }
    else {
        for (const Medico& m : listaMedicos) {
            cout << "ID: " << m.id << ", Nombre: " << m.nombre << ", Especialidad: " << m.especialidad << "\n";
        }
    }
}

void Medico::guardarMedicos() {
    ofstream archivo("medicos.txt");
    if (archivo.is_open()) {
        for (const auto& m : listaMedicos) {
            archivo << m.id << "," << m.nombre << "," << m.especialidad << "\n";
        }
        archivo.close();
        cout << "Médicos guardados con éxito.\n";
    }
    else {
        cout << "Error al abrir el archivo para guardar los médicos.\n";
    }
}

// Implementación de cargarMedicos
void Medico::cargarMedicos() {
    ifstream archivo("medicos.txt");
    if (archivo.is_open()) {
        int id;
        string nombre, especialidad;
        while (getline(archivo, nombre, ',') && archivo >> id) {
            archivo.ignore(); // Ignorar la coma
            getline(archivo, especialidad);
            listaMedicos.push_back(Medico(id, nombre, especialidad));
        }
        archivo.close();
        cout << "Médicos cargados con éxito.\n";
    }
    else {
        cout << "No se pudo abrir el archivo para cargar los médicos.\n";
    }
}
