#include "medico.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

vector<Medico> Medico::listaMedicos;

Medico::Medico(int id, string nombre, string especialidad)
    : id(id), nombre(nombre), especialidad(especialidad) {}

int leerEntero(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Ingrese un numero valido. Intente de nuevo.\n";
        }
        else {
            cin.ignore(1000, '\n');
            return valor;
        }
    }
}

string leerTexto(const string& mensaje) {
    string texto;
    bool valido;
    do {
        valido = true;
        cout << mensaje;
        cin >> texto;  // Usamos cin para leer el texto

        for (char c : texto) {
            if (isdigit(c)) {
                cout << "Error: El texto no puede contener numeros. Intente de nuevo.\n";
                valido = false;
                break;
            }
        }

        if (texto.empty() || all_of(texto.begin(), texto.end(), ::isspace)) {
            cout << "Error: El campo no puede estar vacio.\n";
            valido = false;
        }

    } while (!valido);
    return texto;
}

string leerEspecialidad(const string& mensaje) {
    string especialidad;
    bool valido;
    do {
        valido = true;
        cout << mensaje;
        cin >> especialidad;  // Usamos cin para leer la especialidad

        for (char c : especialidad) {
            if (isdigit(c)) {
                cout << "Error: La especialidad no puede contener numeros. Intente de nuevo.\n";
                valido = false;
                break;
            }
        }

        if (especialidad.empty() || all_of(especialidad.begin(), especialidad.end(), ::isspace)) {
            cout << "Error: El campo no puede estar vacio.\n";
            valido = false;
        }

    } while (!valido);
    return especialidad;
}

void Medico::menuMedicos() {
    int opcion;
    do {
        cout << "\n=== Gestión de Medicos ===\n";
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
        default: cout << "Opcion no valida.\n";
        }
    } while (opcion != 6);
}

void Medico::altaMedico() {
    int id = leerEntero("Ingrese el ID del medico: ");
    string nombre = leerTexto("Ingrese el nombre del medico: ");
    string especialidad = leerEspecialidad("Ingrese la especialidad del medico: ");

    listaMedicos.push_back(Medico(id, nombre, especialidad));
    cout << "Medico registrado con exito.\n";
}

void Medico::bajaMedico() {
    int id = leerEntero("Ingrese el ID del medico a eliminar: ");
    auto it = find_if(listaMedicos.begin(), listaMedicos.end(), [id](const Medico& m) {
        return m.id == id;
        });

    if (it != listaMedicos.end()) {
        listaMedicos.erase(it);
        cout << "Medico eliminado con exito.\n";
    }
    else {
        cout << "Medico no encontrado.\n";
    }
}

void Medico::modificarMedico() {
    int id = leerEntero("Ingrese el ID del medico a modificar: ");
    auto it = find_if(listaMedicos.begin(), listaMedicos.end(), [id](const Medico& m) {
        return m.id == id;
        });

    if (it != listaMedicos.end()) {
        cout << "Medico encontrado: " << it->nombre << ", Especialidad: " << it->especialidad << "\n";
        it->nombre = leerTexto("Ingrese el nuevo nombre del medico: ");
        it->especialidad = leerEspecialidad("Ingrese la nueva especialidad del medico: ");
        cout << "Medico modificado con exito.\n";
    }
    else {
        cout << "Medico no encontrado.\n";
    }
}

void Medico::buscarMedico() {
    int id = leerEntero("Ingrese el ID del medico a buscar: ");
    auto it = find_if(listaMedicos.begin(), listaMedicos.end(), [id](const Medico& m) {
        return m.id == id;
        });

    if (it != listaMedicos.end()) {
        cout << "Medico encontrado: " << it->nombre << ", Especialidad: " << it->especialidad << "\n";
    }
    else {
        cout << "Medico no encontrado.\n";
    }
}

void Medico::listarMedicos() {
    cout << "\n=== Lista de Medicos ===\n";
    if (listaMedicos.empty()) {
        cout << "No hay medicos registrados.\n";
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
        cout << "Medicos guardados con exito.\n";
    }
    else {
        cout << "Error al abrir el archivo para guardar los medicos.\n";
    }
}

void Medico::cargarMedicos() {
    ifstream archivo("medicos.txt");
    if (archivo.is_open()) {
        string idStr, nombre, especialidad;
        while (archivo >> idStr) {
            archivo.ignore(1, ',');  // Ignora la coma después del ID
            archivo >> nombre;  // Lee el nombre
            archivo.ignore(1, ',');  // Ignora la coma después del nombre
            archivo >> especialidad;  // Lee la especialidad
            listaMedicos.push_back(Medico(stoi(idStr), nombre, especialidad));
            archivo.ignore(1, '\n'); // Ignora el salto de línea
        }
        archivo.close();
        cout << "Medicos cargados con exito.\n";
    }
    else {
        cout << "No se pudo abrir el archivo para cargar los medicos.\n";
    }
}

