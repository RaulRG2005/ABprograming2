#include "citamedica.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <regex>

using namespace std;

vector<CitaMedica> CitaMedica::listaCitas;

CitaMedica::CitaMedica(int id, int idPaciente, int idMedico, string fecha, string hora, string motivo)
    : id(id), idPaciente(idPaciente), idMedico(idMedico), fecha(fecha), hora(hora), motivo(motivo) {}

int leerEnteroPositivo(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail() || valor <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Ingrese un numero valido y positivo. Intente de nuevo.\n";
        }
        else {
            cin.ignore(1000, '\n');
            return valor;
        }
    }
}

string leerMotivo(const string& mensaje) {
    string motivo;
    bool valido;
    do {
        valido = true;
        cout << mensaje;
        cin >> motivo;

        if (motivo.find(' ') != string::npos) {
            cout << "Error: El motivo no puede contener espacios. Intente de nuevo.\n";
            valido = false;
        }


        for (char c : motivo) {
            if (isdigit(c)) {
                cout << "Error: El motivo no puede contener numeros. Intente de nuevo.\n";
                valido = false;
                break;
            }
        }

    } while (!valido);
    return motivo;
}


bool validarFecha(const string& fecha) {
    regex fechaRegex("^\\d{4}-\\d{2}-\\d{2}$");
    return regex_match(fecha, fechaRegex);
}


bool validarHora(const string& hora) {
    regex horaRegex("^([01][0-9]|2[0-3]):([0-5][0-9])$");
    return regex_match(hora, horaRegex);
}

void CitaMedica::menuCitas() {
    int opcion;
    do {
        cout << "=== Gestion de Citas Medicas ===\n";
        cout << "1. Asignar Cita\n";
        cout << "2. Cancelar Cita\n";
        cout << "3. Listar Citas\n";
        cout << "4. Volver\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: asignarCita(); break;
        case 2: cancelarCita(); break;
        case 3: listarCitas(); break;
        case 4: break;
        default: cout << "Opcion no valida.\n";
        }
    } while (opcion != 4);
}

void CitaMedica::asignarCita() {
    int id = leerEnteroPositivo("Ingrese el ID de la cita: ");
    int idPaciente = leerEnteroPositivo("Ingrese el ID del paciente: ");
    int idMedico = leerEnteroPositivo("Ingrese el ID del medico: ");

    string fecha;
    do {
        cout << "Ingrese la fecha de la cita (formato: YYYY-MM-DD): ";
        cin >> fecha;
        if (!validarFecha(fecha)) {
            cout << "Error: El formato de la fecha es incorrecto. Intente de nuevo.\n";
        }
    } while (!validarFecha(fecha));

    string hora;
    do {
        cout << "Ingrese la hora de la cita (formato: HH:MM): ";
        cin >> hora;
        if (!validarHora(hora)) {
            cout << "Error: El formato de la hora es incorrecto. Intente de nuevo.\n";
        }
    } while (!validarHora(hora));

    string motivo = leerMotivo("Ingrese el motivo de la cita (sin espacios): ");

    
    listaCitas.push_back(CitaMedica(id, idPaciente, idMedico, fecha, hora, motivo));
    cout << "Cita asignada con exito.\n";
    guardarCitas(); 
}

void CitaMedica::cancelarCita() {
    int id = leerEnteroPositivo("Ingrese el ID de la cita a cancelar: ");

    
    auto it = find_if(listaCitas.begin(), listaCitas.end(), [id](const CitaMedica& cita) {
        return cita.id == id;
        });

    if (it != listaCitas.end()) {
        listaCitas.erase(it);
        cout << "Cita cancelada con exito.\n";
        guardarCitas();  
    }
    else {
        cout << "Cita no encontrada.\n";
    }
}

void CitaMedica::listarCitas() {
    cout << "=== Listado de Citas ===\n";
    if (listaCitas.empty()) {
        cout << "No hay citas registradas.\n";
    }
    else {
        for (const CitaMedica& cita : listaCitas) {
            cout << "ID: " << cita.id << ", Paciente ID: " << cita.idPaciente
                << ", Medico ID: " << cita.idMedico << ", Fecha: " << cita.fecha
                << ", Hora: " << cita.hora << ", Motivo: " << cita.motivo << "\n";
        }
    }
}

void CitaMedica::guardarCitas() {
    ofstream archivo("citas.txt");
    if (archivo.is_open()) {
        for (const auto& cita : listaCitas) {
            archivo << cita.id << " "
                << cita.idPaciente << " "
                << cita.idMedico << " "
                << cita.fecha << " "
                << cita.hora << " "
                << cita.motivo << "\n";
        }
        archivo.close();
        cout << "Citas guardadas con exito.\n";
    }
    else {
        cout << "Error al abrir el archivo para guardar las citas.\n";
    }
}

void CitaMedica::cargarCitas() {
    ifstream archivo("citas.txt");
    if (archivo.is_open()) {
        int id, idPaciente, idMedico;
        string fecha, hora, motivo;
        while (archivo >> id >> idPaciente >> idMedico >> fecha >> hora >> motivo) {
            listaCitas.push_back(CitaMedica(id, idPaciente, idMedico, fecha, hora, motivo));
        }
        archivo.close();
        cout << "Citas cargadas con exito.\n";
    }
    else {
        cout << "No se encontraron citas guardadas.\n";
    }
}
