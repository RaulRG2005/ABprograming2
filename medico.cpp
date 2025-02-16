#include "medico.h"

void Medico::menuMedicos() {
#include "medico.h"

    vector<Medico> Medico::listaMedicos; // Inicializar lista de médicos

    Medico::Medico(int id, string nombre, string especialidad) : id(id), nombre(nombre), especialidad(especialidad) {}

    void Medico::menuMedicos() {
        int opcion;
        do {
            cout << "=== Gestión de Médicos ===\n";
            cout << "1. Alta de Médico\n";
            cout << "2. Baja de Médico\n";
            cout << "3. Listar Médicos\n";
            cout << "4. Volver\n";
            cout << "Seleccione una opción: ";
            cin >> opcion;

            switch (opcion) {
            case 1: altaMedico(); break;
            case 2: bajaMedico(); break;
            case 3: listarMedicos(); break;
            case 4: break;
            default: cout << "Opción no válida\n";
            }
        } while (opcion != 4);
    }

    void Medico::altaMedico() {
        int id;
        string nombre, especialidad;
        cout << "Ingrese ID del médico: ";
        cin >> id;
        cout << "Ingrese nombre del médico: ";
        cin >> nombre;
        cout << "Ingrese especialidad del médico: ";
        cin >> especialidad;

        listaMedicos.push_back(Medico(id, nombre, especialidad));
        cout << "Médico registrado con éxito.\n";
    }

    void Medico::bajaMedico() {
        int id;
        cout << "Ingrese ID del médico a eliminar: ";
        cin >> id;

        for (auto it = listaMedicos.begin(); it != listaMedicos.end(); ++it) {
            if (it->id == id) {
                listaMedicos.erase(it);
                cout << "Médico eliminado correctamente.\n";
                return;
            }
        }
        cout << "Médico no encontrado.\n";
    }

    void Medico::listarMedicos() {
        if (listaMedicos.empty()) {
            cout << "No hay médicos registrados.\n";
        }
        else {
            for (const auto& medico : listaMedicos) {
                cout << "ID: " << medico.id << " | Nombre: " << medico.nombre << " | Especialidad: " << medico.especialidad << "\n";
            }
        }
    }

