#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

// Clase Paciente
class Paciente {
private:
    int id;
    string nombre;
    string telefono;

public:
    Paciente(int _id, string _nombre, string _telefono)
        : id(_id), nombre(_nombre), telefono(_telefono) {}

    int getId() const { return id; }
    string getNombre() const { return nombre; }
    string getTelefono() const { return telefono; }

    void setNombre(const string& nuevoNombre) { nombre = nuevoNombre; }
    void setTelefono(const string& nuevoTelefono) { telefono = nuevoTelefono; }

    void mostrarInfo() const {
        cout << "ID: " << id << ", Nombre: " << nombre << ", Teléfono: " << telefono << "\n";
    }

    string serializar() const {
        return to_string(id) + "|" + nombre + "|" + telefono + "\n";
    }

    static Paciente deserializar(const string& linea) {
        stringstream ss(linea);
        string idStr, nombre, telefono;
        getline(ss, idStr, '|');
        getline(ss, nombre, '|');
        getline(ss, telefono, '|');
        return Paciente(stoi(idStr), nombre, telefono);
    }
};

// Clase Médico
class Medico {
private:
    int id;
    string nombre;
    string especialidad;

public:
    Medico(int _id, string _nombre, string _especialidad)
        : id(_id), nombre(_nombre), especialidad(_especialidad) {}

    int getId() const { return id; }
    string getNombre() const { return nombre; }
    string getEspecialidad() const { return especialidad; }

    void setNombre(const string& nuevoNombre) { nombre = nuevoNombre; }
    void setEspecialidad(const string& nuevaEspecialidad) { especialidad = nuevaEspecialidad; }

    void mostrarInfo() const {
        cout << "ID: " << id << ", Nombre: " << nombre << ", Especialidad: " << especialidad << "\n";
    }

    string serializar() const {
        return to_string(id) + "|" + nombre + "|" + especialidad + "\n";
    }

    static Medico deserializar(const string& linea) {
        stringstream ss(linea);
        string idStr, nombre, especialidad;
        getline(ss, idStr, '|');
        getline(ss, nombre, '|');
        getline(ss, especialidad, '|');
        return Medico(stoi(idStr), nombre, especialidad);
    }
};

// Clase Cita
class Cita {
private:
    int id;
    int idPaciente;
    int idMedico;
    string fecha;

public:
    Cita(int _id, int _idPaciente, int _idMedico, string _fecha)
        : id(_id), idPaciente(_idPaciente), idMedico(_idMedico), fecha(_fecha) {}

    int getId() const { return id; }
    int getIdPaciente() const { return idPaciente; }
    int getIdMedico() const { return idMedico; }
    string getFecha() const { return fecha; }

    void mostrarInfo() const {
        cout << "ID Cita: " << id << ", Paciente ID: " << idPaciente
            << ", Médico ID: " << idMedico << ", Fecha: " << fecha << "\n";
    }

    string serializar() const {
        return to_string(id) + "|" + to_string(idPaciente) + "|" + to_string(idMedico) + "|" + fecha + "\n";
    }

    static Cita deserializar(const string& linea) {
        stringstream ss(linea);
        string idStr, idPacienteStr, idMedicoStr, fecha;
        getline(ss, idStr, '|');
        getline(ss, idPacienteStr, '|');
        getline(ss, idMedicoStr, '|');
        getline(ss, fecha, '|');
        return Cita(stoi(idStr), stoi(idPacienteStr), stoi(idMedicoStr), fecha);
    }
};

// Funciones para manejo de archivos
template <typename T>
void guardarEnArchivo(const vector<T>& elementos, const string& filename) {
    ofstream archivo(filename, ios::out | ios::trunc);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo " << filename << " para guardar.\n";
        return;
    }

    for (const auto& elemento : elementos) {
        archivo << elemento.serializar();
    }

    archivo.close();
}

template <typename T>
vector<T> cargarDesdeArchivo(const string& filename) {
    vector<T> elementos;
    ifstream archivo(filename);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo " << filename << " para cargar.\n";
        return elementos;
    }

    string linea;
    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            elementos.push_back(T::deserializar(linea));
        }
    }

    archivo.close();
    return elementos;
}

// Función para mostrar el menú principal
void mostrarMenu() {
    cout << "\nOpciones disponibles:\n";
    cout << "1. Registrar un paciente\n";
    cout << "2. Registrar un médico\n";
    cout << "3. Crear una cita\n";
    cout << "4. Mostrar todos los pacientes\n";
    cout << "5. Mostrar todos los médicos\n";
    cout << "6. Mostrar todas las citas\n";
    cout << "7. Eliminar un paciente\n";
    cout << "8. Eliminar un médico\n";
    cout << "9. Eliminar una cita\n";
    cout << "10. Salir\n";
    cout << "Seleccione una opción: ";
}

// Función principal
int main() {
    const string FILENAME_PACIENTES = "pacientes.txt";
    const string FILENAME_MEDICOS = "medicos.txt";
    const string FILENAME_CITAS = "citas.txt";

    vector<Paciente> pacientes = cargarDesdeArchivo<Paciente>(FILENAME_PACIENTES);
    vector<Medico> medicos = cargarDesdeArchivo<Medico>(FILENAME_MEDICOS);
    vector<Cita> citas = cargarDesdeArchivo<Cita>(FILENAME_CITAS);

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
        case 1: {
            // Código para registrar paciente
            break;
        }
        case 2: {
            // Código para registrar médico
            break;
        }
        case 3: {
            // Código para crear cita
            break;
        }
        case 9: {
            int idCita;
            cout << "Ingrese el ID de la cita a eliminar: ";
            cin >> idCita;
            auto it = find_if(citas.begin(), citas.end(), [idCita](const Cita& c) {
                return c.getId() == idCita;
                });
            if (it != citas.end()) {
                citas.erase(it);
                guardarEnArchivo(citas, FILENAME_CITAS);
                cout << "Cita eliminada exitosamente.\n";
            }
            else {
                cout << "Cita no encontrada.\n";
            }
            break;
        }
        case 10:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 10);

    return 0;
}
