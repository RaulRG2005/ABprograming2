#include "medico.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

vector<Medico> Medico::listaMedicos;

Medico::Medico(int id, string nombre, string especialidad)
    : id(id), nombre(nombre), especialidad(especialidad) {}

// Funci�n para validar entrada num�rica
int leerEntero(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Ingrese un n�mero v�lido. Intente de nuevo.\n";
        }
        else {
            cin.ignore(1000, '\n');
            return valor;
        }
    }
}

// Funci�n para validar entrada de texto (sin n�meros)
string leerTexto(const string& mensaje) {
    string texto;
    bool valido;
    do {
        valido = true;
        cout << mensaje;
        cin >> texto;
        for (char c : texto) {
            if (isdigit(c)) {
                cout << "Error: El texto no puede contener n�meros. Intente de nuevo.\n";
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
        cout << "\n=== Gesti�n de M�dicos ===\n";
        cout << "1. Alta de Medico\n";
        cout << "2. Baja de Medico\n";
        cout << "3. Modificar Medico\n";
        cout << "4. Buscar Medico\n";
        cout << "5. Listar Medicos\n";
        cout << "6. Guardar y Salir\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1: altaMedico(); break;
        case 2: bajaMedico(); break;
        case 3: modificarMedico(); break;
        case 4: buscarMedico(); break;
        case 5: listarMedicos(); break;
        case 6: guardarMedicos(); break;
        default: cout << "Opci�n no v�lida.\n";
        }
    } while (opcion != 6);
}

void Medico::altaMedico() {
    int id = leerEntero("Ingrese el ID del m�dico: ");
    string nombre = leerTexto("Ingrese el nombre del m�dico: ");
    string especialidad = leerTexto("Ingrese la especialidad del m�dico: ");

    listaMedicos.push_back(Medico(id, nombre, especialidad));
    cout << "M�dico registrado con �xito.\n";
}

void Medico::bajaMedico() {
    int id = leerEntero("Ingrese el ID del m�dico a eliminar: ");
    auto it = find_if(listaMedicos.begin(), listaMedicos.end(), [id](const Medico& m) {
        return m.id == id;
        });

    if (it != listaMedicos.end()) {
        listaMedicos.erase(it);
        cout << "M�dico eliminado con �xito.\n";
    }
    else {
        cout << "M�dico no encontrado.\n";
    }
}

void Medico::modificarMedico() {
    int id = leerEntero("Ingrese el ID del m�dico a modificar: ");
    auto it = find_if(listaMedicos.begin(), listaMedicos.end(), [id](const Medico& m) {
        return m.id == id;
        });

    if (it != listaMedicos.end()) {
        cout << "M�dico encontrado: " << it->nombre << ", Especialidad: " << it->especialidad << "\n";
        it->nombre = leerTexto("Ingrese el nuevo nombre del m�dico: ");
        it->especialidad = leerTexto("Ingrese la nueva especialidad del m�dico: ");
        cout << "M�dico modificado con �xito.\n";
    }
    else {
        cout << "M�dico no encontrado.\n";
    }
}

void Medico::buscarMedico() {
    int id = leerEntero("Ingrese el ID del m�dico a buscar: ");
    auto it = find_if(listaMedicos.begin(), listaMedicos.end(), [id](const Medico& m) {
        return m.id == id;
        });

    if (it != listaMedicos.end()) {
        cout << "M�dico encontrado: " << it->nombre << ", Especialidad: " << it->especialidad << "\n";
    }
    else {
        cout << "M�dico no encontrado.\n";
    }
}

void Medico::listarMedicos() {
    cout << "\n=== Lista de M�dicos ===\n";
    if (listaMedicos.empty()) {
        cout << "No hay m�dicos registrados.\n";
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
        cout << "M�dicos guardados con �xito.\n";
    }
    else {
        cout << "Error al abrir el archivo para guardar los m�dicos.\n";
    }
}

// Implementaci�n de cargarMedicos
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
        cout << "M�dicos cargados con �xito.\n";
    }
    else {
        cout << "No se pudo abrir el archivo para cargar los m�dicos.\n";
    }
}
