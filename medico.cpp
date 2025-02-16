#include "medico.h"

void Medico::menuMedicos() {
#include "medico.h"

    vector<Medico> Medico::listaMedicos; // Inicializar lista de m�dicos

    Medico::Medico(int id, string nombre, string especialidad) : id(id), nombre(nombre), especialidad(especialidad) {}

    void Medico::menuMedicos() {
        int opcion;
        do {
            cout << "=== Gesti�n de M�dicos ===\n";
            cout << "1. Alta de M�dico\n";
            cout << "2. Baja de M�dico\n";
            cout << "3. Listar M�dicos\n";
            cout << "4. Volver\n";
            cout << "Seleccione una opci�n: ";
            cin >> opcion;

            switch (opcion) {
            case 1: altaMedico(); break;
            case 2: bajaMedico(); break;
            case 3: listarMedicos(); break;
            case 4: break;
            default: cout << "Opci�n no v�lida\n";
            }
        } while (opcion != 4);
    }

    void Medico::altaMedico() {
        int id;
        string nombre, especialidad;
        cout << "Ingrese ID del m�dico: ";
        cin >> id;
        cout << "Ingrese nombre del m�dico: ";
        cin >> nombre;
        cout << "Ingrese especialidad del m�dico: ";
        cin >> especialidad;

        listaMedicos.push_back(Medico(id, nombre, especialidad));
        cout << "M�dico registrado con �xito.\n";
    }

    void Medico::bajaMedico() {
        int id;
        cout << "Ingrese ID del m�dico a eliminar: ";
        cin >> id;

        for (auto it = listaMedicos.begin(); it != listaMedicos.end(); ++it) {
            if (it->id == id) {
                listaMedicos.erase(it);
                cout << "M�dico eliminado correctamente.\n";
                return;
            }
        }
        cout << "M�dico no encontrado.\n";
    }

    void Medico::listarMedicos() {
        if (listaMedicos.empty()) {
            cout << "No hay m�dicos registrados.\n";
        }
        else {
            for (const auto& medico : listaMedicos) {
                cout << "ID: " << medico.id << " | Nombre: " << medico.nombre << " | Especialidad: " << medico.especialidad << "\n";
            }
        }
    }

