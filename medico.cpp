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
    Medico(int _id, const string& _nombre, const string& _especialidad)
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

    static void guardarMedicos(const vector<Medico>& medicos, const string& filename) {
        ofstream archivo(filename, ios::out | ios::trunc);
        if (!archivo.is_open()) {
            cerr << "Error al abrir el archivo para guardar médicos.\n";
            return;
        }

        for (const auto& medico : medicos) {
            archivo << medico.id << "|" << medico.nombre << "|" << medico.especialidad << "\n";
        }

        archivo.close();
        if (archivo.fail()) {
            cerr << "Error al guardar los datos en el archivo.\n";
        }
    }

    static vector<Medico> abrirFicheroMedicos(const string& filename) {
        vector<Medico> medicos;
        ifstream archivo(filename);
        if (!archivo.is_open()) {
            cerr << "Error al abrir el archivo para cargar médicos.\n";
            return medicos;
        }

        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string idStr, nombre, especialidad;

            getline(ss, idStr, '|');
            getline(ss, nombre, '|');
            getline(ss, especialidad, '|');

            if (!idStr.empty() && !nombre.empty() && !especialidad.empty()) {
                int id = stoi(idStr);
                medicos.emplace_back(id, nombre, especialidad);
            }
        }

        archivo.close();
        return medicos;
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
    cout << "9. Salir\n";
    cout << "Seleccione una opción: ";
}

// Función principal
int main() {
    const string FILENAME_PACIENTES = "pacientes.txt";
    const string FILENAME_MEDICOS = "medicos.txt";
    const string FILENAME_CITAS = "citas.txt";

    vector<Paciente> pacientes = cargarDesdeArchivo<Paciente>(FILENAME_PACIENTES);
    vector<Medico> medicos = Medico::abrirFicheroMedicos(FILENAME_MEDICOS);
    vector<Cita> citas = cargarDesdeArchivo<Cita>(FILENAME_CITAS);

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
        case 1: {
            // Registrar un paciente
            int id;
            string nombre, telefono;
            cout << "Ingrese el ID del paciente: ";
            cin >> id;
            cin.ignore();
            cout << "Ingrese el nombre del paciente: ";
            getline(cin, nombre);
            cout << "Ingrese el teléfono del paciente: ";
            getline(cin, telefono);
            pacientes.emplace_back(id, nombre, telefono);
            guardarEnArchivo(pacientes, FILENAME_PACIENTES);
            cout << "Paciente registrado exitosamente.\n";
            break;
        }
        case 2: {
            // Registrar un médico
            int id;
            string nombre, especialidad;
            cout << "Ingrese el ID del médico: ";
            cin >> id;
            cin.ignore();
            cout << "Ingrese el nombre del médico: ";
            getline(cin, nombre);
            cout << "Ingrese la especialidad del médico: ";
            getline(cin, especialidad);
            medicos.emplace_back(id, nombre, especialidad);
            Medico::guardarMedicos(medicos, FILENAME_MEDICOS);
            cout << "Médico registrado exitosamente.\n";
            break;
        }
        case 3: {
            // Crear una cita
            int idCita, idPaciente, idMedico;
            string fecha;
            cout << "Ingrese el ID de la cita: ";
            cin >> idCita;
            cout << "Ingrese el ID del paciente: ";
            cin >> idPaciente;
            cout << "Ingrese el ID del médico: ";
            cin >> idMedico;
            cin.ignore();
            cout << "Ingrese la fecha de la cita (YYYY-MM-DD): ";
            getline(cin, fecha);

            auto pacienteIt = find_if(pacientes.begin(), pacientes.end(), [idPaciente](const Paciente& p) {
                return p.getId() == idPaciente;
                });
            auto medicoIt = find_if(medicos.begin(), medicos.end(), [idMedico](const Medico& m) {
                return m.getId() == idMedico;
                });

            if (pacienteIt != pacientes.end() && medicoIt != medicos.end()) {
                citas.emplace_back(idCita, idPaciente, idMedico, fecha);
                guardarEnArchivo(citas, FILENAME_CITAS);
                cout << "Cita creada exitosamente.\n";
            }
            else {
                cout << "Error: Paciente o médico no encontrado.\n";
            }
            break;
        }
        case 4: {
            // Mostrar todos los pacientes
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
        case 5: {
            // Mostrar todos los médicos
            if (medicos.empty()) {
                cout << "No hay médicos registrados.\n";
            }
            else {
                cout << "Listado de médicos:\n";
                for (const auto& medico : medicos) {
                    medico.mostrarInfo();
                }
            }
            break;
        }
        case 6: {
            // Mostrar todas las citas
            if (citas.empty()) {
                cout << "No hay citas registradas.\n";
            }
            else {
                cout << "Listado de citas:\n";
                for (const auto& cita : citas) {
                    cita.mostrarInfo();
                }
            }
            break;
        }
        case 7: {
            // Eliminar un paciente
            int idPaciente;
            cout << "Ingrese el ID del paciente a eliminar: ";
            cin >> idPaciente;
            auto it = find_if(pacientes.begin(), pacientes.end(), [idPaciente](const Paciente& p) {
                return p.getId() == idPaciente;
                });
            if (it != pacientes.end()) {
                pacientes.erase(it);
                guardarEnArchivo(pacientes, FILENAME_PACIENTES);
                cout << "Paciente eliminado exitosamente.\n";
            }
            else {
                cout << "Paciente no encontrado.\n";
            }
            break;
        }
        case 8: {
            // Eliminar un médico
            int idMedico;
            cout << "Ingrese el ID del médico a eliminar: ";
            cin >> idMedico;
            auto it = find_if(medicos.begin(), medicos.end(), [idMedico](const Medico& m) {
                return m.getId() == idMedico;
                });
            if (it != medicos.end()) {
                medicos.erase(it);
                Medico::guardarMedicos(medicos, FILENAME_MEDICOS);
                cout << "Médico eliminado exitosamente.\n";
            }
            else {
                cout << "Médico no encontrado.\n";
            }
            break;
        }
        case 9:
            cout << "Saliendo del programa. ¡Hasta luego!\n";
            break;
        default:
            cout << "Opción inválida. Inténtelo de nuevo.\n";
        }
    } while (opcion != 9);

    return 0;
}
