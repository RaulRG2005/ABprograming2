#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Clase Paciente
class Paciente {
private:
    int id;
    string nombre;
    string telefono;

public:
    // Constructor
    Paciente(int _id, string _nombre, string _telefono)
        : id(_id), nombre(_nombre), telefono(_telefono) {}

    // Métodos para obtener datos
    int getId() const { return id; }
    string getNombre() const { return nombre; }
    string getTelefono() const { return telefono; }

    // Métodos para modificar datos
    void setNombre(const string& nuevoNombre) { nombre = nuevoNombre; }
    void setTelefono(const string& nuevoTelefono) { telefono = nuevoTelefono; }

    // Mostrar información del paciente
    void mostrarInfo() const {
        cout << "ID: " << id << ", Nombre: " << nombre << ", Teléfono: " << telefono << "\n";
    }
};

// Menú interactivo
void mostrarMenu() {
    cout << "\nGestión de Pacientes - Opciones disponibles:\n";
    cout << "1. Registrar un nuevo paciente\n";
    cout << "2. Actualizar datos de un paciente\n";
    cout << "3. Buscar un paciente por ID\n";
    cout << "4. Listar todos los pacientes\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opción: ";
}

// Función principal
int main() {
    vector<Paciente> pacientes; // Lista de pacientes
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1: {
            // Registrar un nuevo paciente
            int id;
            string nombre, telefono;
            cout << "Ingrese el ID del paciente: ";
            cin >> id;
            cout << "Ingrese el nombre del paciente: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Ingrese el teléfono del paciente: ";
            getline(cin, telefono);

            // Verificar si el paciente ya existe
            auto it = find_if(pacientes.begin(), pacientes.end(), [id](const Paciente& p) {
                return p.getId() == id;
                });

            if (it == pacientes.end()) {
                pacientes.emplace_back(id, nombre, telefono);
                cout << "Paciente registrado exitosamente.\n";
            }
            else {
                cout << "Ya existe un paciente con ese ID.\n";
            }
            break;
        }
        case 2: {
            // Actualizar datos de un paciente
            int id;
            cout << "Ingrese el ID del paciente a actualizar: ";
            cin >> id;

            auto it = find_if(pacientes.begin(), pacientes.end(), [id](const Paciente& p) {
                return p.getId() == id;
                });

            if (it != pacientes.end()) {
                string nuevoNombre, nuevoTelefono;
                cout << "Ingrese el nuevo nombre del paciente: ";
                cin.ignore();
                getline(cin, nuevoNombre);
                cout << "Ingrese el nuevo teléfono del paciente: ";
                getline(cin, nuevoTelefono);

                it->setNombre(nuevoNombre);
                it->setTelefono(nuevoTelefono);
                cout << "Datos actualizados correctamente.\n";
            }
            else {
                cout << "Paciente no encontrado.\n";
            }
            break;
        }
        case 3: {
            // Buscar un paciente por ID
            int id;
            cout << "Ingrese el ID del paciente a buscar: ";
            cin >> id;

            auto it = find_if(pacientes.begin(), pacientes.end(), [id](const Paciente& p) {
                return p.getId() == id;
                });

            if (it != pacientes.end()) {
                cout << "Información del paciente:\n";
                it->mostrarInfo();
            }
            else {
                cout << "Paciente no encontrado.\n";
            }
            break;
        }
        case 4: {
            // Listar todos los pacientes
            if (pacientes.empty()) {
                cout << "No hay pacientes registrados.\n";
            }
            else {
                cout << "Listado de pacientes:\n";
                for (const auto& paciente : pacientes) {
                    paciente.mostrarInfo();
                }
            }
            break;
        }
        case 5:
            cout << "Saliendo del programa. ¡Hasta luego!\n";
            break;
        default:
            cout << "Opción inválida. Inténtelo de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}
