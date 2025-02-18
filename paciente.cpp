#include "paciente.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <regex>
#include <sstream>
using namespace std;

vector<Paciente> Paciente::listaPacientes;

Paciente::Paciente(int id, string nombre, string fechaIngreso) : id(id), nombre(nombre), fechaIngreso(fechaIngreso) {}

bool esFechaValida(const string& fecha) {
    regex formatoFecha("\\d{4}-\\d{2}-\\d{2}");
    return regex_match(fecha, formatoFecha);
}

bool esNumero(const string& str) {
    return all_of(str.begin(), str.end(), ::isdigit);
}

bool contieneSoloEspacios(const string& str) {
    return str.find_first_not_of(" ") == string::npos;
}

bool contieneSoloLetras(const string& str) {
    return all_of(str.begin(), str.end(), ::isalpha);
}

bool estaVacia(const string& str) {
    return str.empty() || contieneSoloEspacios(str);
}

void Paciente::menuPacientes() {
    int opcion;
    do {
        cout << "=== Gestion de Pacientes ===\n";
        cout << "1. Alta de Paciente\n";
        cout << "2. Baja de Paciente\n";
        cout << "3. Modificar Datos\n";
        cout << "4. Buscar Paciente\n";
        cout << "5. Listar Pacientes\n";
        cout << "6. Guardar y Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion no valida. Intente de nuevo.\n";
            continue;
        }

        switch (opcion) {
        case 1: altaPaciente(); break;
        case 2: bajaPaciente(); break;
        case 3: modificarPaciente(); break;
        case 4: buscarPaciente(); break;
        case 5: listarPacientes(); break;
        case 6: guardarPacientes(); break;
        default: cout << "Opcion no valida.\n";
        }
    } while (opcion != 6);
}

void Paciente::altaPaciente() {
    string idStr, nombre, fechaIngreso;
    int id;

    do {
        cout << "Ingrese el ID del paciente: ";
        cin >> idStr;
        if (!esNumero(idStr)) {
            cout << "Error: El ID solo debe contener numeros.\n";
        }
        else if (idStr.find(' ') != string::npos) {
            cout << "Error: El ID no debe contener espacios.\n";
        }
    } while (!esNumero(idStr) || idStr.find(' ') != string::npos);
    id = stoi(idStr);

    do {
        cout << "Ingrese el nombre del paciente: ";
        cin >> nombre;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (estaVacia(nombre)) {
            cout << "Error: El nombre no puede estar vacio.\n";
        }
        else if (!contieneSoloLetras(nombre)) {
            cout << "Error: El nombre debe contener solo letras.\n";
        }
    } while (estaVacia(nombre) || !contieneSoloLetras(nombre));

    do {
        cout << "Ingrese la fecha de ingreso (YYYY-MM-DD): ";
        cin >> fechaIngreso;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (estaVacia(fechaIngreso)) {
            cout << "Error: La fecha no puede estar vacia.\n";
        }
        else if (!esFechaValida(fechaIngreso)) {
            cout << "Error: Formato de fecha incorrecto.\n";
        }
    } while (estaVacia(fechaIngreso) || !esFechaValida(fechaIngreso));

    listaPacientes.push_back(Paciente(id, nombre, fechaIngreso));
    cout << "Paciente agregado con exito.\n";
}

void Paciente::bajaPaciente() {
    string idStr;
    int id;

    do {
        cout << "Ingrese el ID del paciente a eliminar: ";
        cin >> idStr;
        if (idStr.find(' ') != string::npos) {
            cout << "Error: El ID no debe contener espacios.\n";
        }
    } while (!esNumero(idStr) || idStr.find(' ') != string::npos);
    id = stoi(idStr);

    auto it = find_if(listaPacientes.begin(), listaPacientes.end(), [id](const Paciente& p) { return p.id == id; });
    if (it != listaPacientes.end()) {
        listaPacientes.erase(it);
        cout << "Paciente eliminado con exito.\n";
    }
    else {
        cout << "Paciente no encontrado.\n";
    }
}

void Paciente::modificarPaciente() {
    string idStr, nuevoNombre, nuevaFecha;
    int id;

    do {
        cout << "Ingrese el ID del paciente a modificar: ";
        cin >> idStr;
        if (idStr.find(' ') != string::npos) {
            cout << "Error: El ID no debe contener espacios.\n";
        }
    } while (!esNumero(idStr) || idStr.find(' ') != string::npos);
    id = stoi(idStr);

    auto it = find_if(listaPacientes.begin(), listaPacientes.end(), [id](const Paciente& p) { return p.id == id; });
    if (it != listaPacientes.end()) {

        do {
            cout << "Ingrese el nuevo nombre del paciente: ";
            cin >> nuevoNombre;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (estaVacia(nuevoNombre)) {
                cout << "Error: El nombre no puede estar vacío.\n";
            }
            else if (!contieneSoloLetras(nuevoNombre)) {
                cout << "Error: El nombre debe contener solo letras.\n";
            }
        } while (estaVacia(nuevoNombre) || !contieneSoloLetras(nuevoNombre));

        do {
            cout << "Ingrese la nueva fecha de ingreso (YYYY-MM-DD): ";
            cin >> nuevaFecha;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (estaVacia(nuevaFecha)) {
                cout << "Error: La fecha no puede estar vacía.\n";
            }
            else if (!esFechaValida(nuevaFecha)) {
                cout << "Error: Formato de fecha incorrecto.\n";
            }
        } while (estaVacia(nuevaFecha) || !esFechaValida(nuevaFecha));

        it->nombre = nuevoNombre;
        it->fechaIngreso = nuevaFecha;
        cout << "Paciente modificado con éxito.\n";
    }
    else {
        cout << "Paciente no encontrado.\n";
    }
}

void Paciente::buscarPaciente() {
    string idStr;
    int id;

    do {
        cout << "Ingrese el ID del paciente a buscar: ";
        cin >> idStr;
        if (idStr.find(' ') != string::npos) {
            cout << "Error: El ID no debe contener espacios.\n";
        }
    } while (!esNumero(idStr) || idStr.find(' ') != string::npos);
    id = stoi(idStr);

    auto it = find_if(listaPacientes.begin(), listaPacientes.end(), [id](const Paciente& p) { return p.id == id; });
    if (it != listaPacientes.end()) {
        cout << "Paciente encontrado: ID: " << it->id << ", Nombre: " << it->nombre << ", Fecha de Ingreso: " << it->fechaIngreso << "\n";
    }
    else {
        cout << "Paciente no encontrado.\n";
    }
}

void Paciente::listarPacientes() {
    if (listaPacientes.empty()) {
        cout << "No hay pacientes registrados.\n";
        return;
    }
    cout << "Lista de Pacientes:\n";
    for (const auto& paciente : listaPacientes) {
        cout << "ID: " << paciente.id << ", Nombre: " << paciente.nombre << ", Fecha de Ingreso: " << paciente.fechaIngreso << "\n";
    }
}

void Paciente::guardarPacientes() {
    ofstream file("pacientes.txt");  
    if (!file) {
        cout << "Error al guardar los pacientes.\n";
        return;
    }
    for (const auto& paciente : listaPacientes) {
        file << paciente.id << "," << paciente.nombre << "," << paciente.fechaIngreso << "\n";
    }
    file.close();
    cout << "Pacientes guardados exitosamente.\n";
}

void Paciente::cargarPacientes() {
    ifstream file("pacientes.txt");  
    if (!file) {
        cout << "No hay pacientes registrados previamente.\n";
        return;
    }
    listaPacientes.clear();
    string linea;
    while (getline(file, linea)) {  
        stringstream ss(linea);
        string idStr, nombre, fechaIngreso;
        getline(ss, idStr, ',');  
        getline(ss, nombre, ',');  
        getline(ss, fechaIngreso); 
        listaPacientes.push_back(Paciente(stoi(idStr), nombre, fechaIngreso));
    }
    file.close();
    cout << "Pacientes cargados exitosamente.\n";
}
