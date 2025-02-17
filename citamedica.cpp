#include "citamedica.h"
#include <iostream>
#include <string>  // Aseg�rate de incluir esta l�nea para usar getline

using namespace std;

// Inicializaci�n de la lista est�tica
std::vector<CitaMedica> CitaMedica::listaCitas;

CitaMedica::CitaMedica(int id, int idPaciente, int idMedico, const std::string& fecha, const std::string& hora, const std::string& motivo)
    : id(id), idPaciente(idPaciente), idMedico(idMedico), fecha(fecha), hora(hora), motivo(motivo) {}

void CitaMedica::menuCitas() {
    int opcion;
    do {
        cout << "=== Gesti�n de Citas M�dicas ===\n";
        cout << "1. Asignar Cita\n";
        cout << "2. Cancelar Cita\n";
        cout << "3. Listar Citas\n";
        cout << "4. Volver\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        switch (opcion) {
        case 1: asignarCita(); break;
        case 2: cancelarCita(); break;
        case 3: listarCitas(); break;
        case 4: break;
        default: cout << "Opci�n no v�lida. Intente de nuevo.\n";
        }
    } while (opcion != 4);
}

void CitaMedica::asignarCita() {
    int id, idPaciente, idMedico;
    string fecha, hora, motivo;

    cout << "Ingrese ID de la cita: ";
    cin >> id;
    cout << "Ingrese ID del paciente: ";
    cin >> idPaciente;
    cout << "Ingrese ID del m�dico: ";
    cin >> idMedico;
    cout << "Ingrese fecha de la cita (DD/MM/AAAA): ";
    cin >> fecha;
    cout << "Ingrese hora de la cita (HH:MM): ";
    cin >> hora;

    cin.ignore();  // Soluci�n para evitar problemas con getline
    cout << "Ingrese motivo de la cita: ";
    getline(cin, motivo);

    listaCitas.push_back(CitaMedica(id, idPaciente, idMedico, fecha, hora, motivo));
    cout << "Cita registrada con �xito.\n";
}

void CitaMedica::cancelarCita() {
    int id;
    cout << "Ingrese ID de la cita a cancelar: ";
    cin >> id;

    for (auto it = listaCitas.begin(); it != listaCitas.end(); ++it) {
        if (it->id == id) {
            listaCitas.erase(it);
            cout << "Cita cancelada correctamente.\n";
            return;
        }
    }
    cout << "Cita no encontrada.\n";
}

void CitaMedica::listarCitas() {
    if (listaCitas.empty()) {
        cout << "No hay citas registradas.\n";
    }
    else {
        for (const auto& cita : listaCitas) {
            cout << "ID Cita: " << cita.id
                << " | Paciente ID: " << cita.idPaciente
                << " | M�dico ID: " << cita.idMedico
                << " | Fecha: " << cita.fecha
                << " | Hora: " << cita.hora
                << " | Motivo: " << cita.motivo << endl;
        }
    }
}




