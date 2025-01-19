#include <iostream>
#include <fstream>
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
    string historialClinico;

public:
    Paciente(int _id, string _nombre, string _telefono, string _historialClinico = "")
        : id(_id), nombre(_nombre), telefono(_telefono), historialClinico(_historialClinico) {}

    int getId() const { return id; }
    string getNombre() const { return nombre; }
    string getTelefono() const { return telefono; }
    string getHistorialClinico() const { return historialClinico; }

    void setNombre(const string& nuevoNombre) { nombre = nuevoNombre; }
    void setTelefono(const string& nuevoTelefono) { telefono = nuevoTelefono; }
    void setHistorialClinico(const string& nuevoHistorial) { historialClinico = nuevoHistorial; }

    void mostrarInfo() const {
        cout << "ID: " << id << ", Nombre: " << nombre << ", Teléfono: " << telefono << "\n";
        cout << "Historial Clínico: " << historialClinico << "\n";
    }

    void guardar(ofstream& archivo) const {
        archivo << id << "|" << nombre << "|" << telefono << "|" << historialClinico << "\n";
    }

    static Paciente cargar(const string& linea) {
        size_t pos1 = linea.find('|');
        size_t pos2 = linea.find('|', pos1 + 1);
        size_t pos3 = linea.find('|', pos2 + 1);

        int id = stoi(linea.substr(0, pos1));
        string nombre = linea.substr(pos1 + 1, pos2 - pos1 - 1);
        string telefono = linea.substr(pos2 + 1, pos3 - pos2 - 1);
        string historial = linea.substr(pos3 + 1);

        return Paciente(id, nombre, telefono, historial);
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

    void guardar(ofstream& archivo) const {
        archivo << id << "|" << nombre << "|" << especialidad << "\n";
    }

    static Medico cargar(const string& linea) {
        size_t pos1 = linea.find('|');
        size_t pos2 = linea.find('|', pos1 + 1);

        int id = stoi(linea.substr(0, pos1));
        string nombre = linea.substr(pos1 + 1, pos2 - pos1 - 1);
        string especialidad = linea.substr(pos2 + 1);

        return Medico(id, nombre, especialidad);
    }
};

// Clase Cita
class Cita {
private:
    int id;
    int idPaciente;
    int idMedico;
    string fecha;
    string estado; // "Pendiente" o "Completada"

public:
    Cita(int _id, int _idPaciente, int _idMedico, string _fecha, string _estado = "Pendiente")
        : id(_id), idPaciente(_idPaciente), idMedico(_idMedico), fecha(_fecha), estado(_estado) {}

    int getId() const { return id; }
    int getIdPaciente() const { return idPaciente; }
    int getIdMedico() const { return idMedico; }
    string getFecha() const { return fecha; }
    string getEstado() const { return estado; }

    void setEstado(const string& nuevoEstado) { estado = nuevoEstado; }

    void mostrarInfo() const {
        cout << "ID Cita: " << id << ", Paciente ID: " << idPaciente
            << ", Médico ID: " << idMedico << ", Fecha: " << fecha
            << ", Estado: " << estado << "\n";
    }

    void guardar(ofstream& archivo) const {
        archivo << id << "|" << idPaciente << "|" << idMedico << "|" << fecha << "|" << estado << "\n";
    }

    static Cita cargar(const string& linea) {
        size_t pos1 = linea.find('|');
        size_t pos2 = linea.find('|', pos1 + 1);
        size_t pos3 = linea.find('|', pos2 + 1);
        size_t pos4 = linea.find('|', pos3 + 1);

        int id = stoi(linea.substr(0, pos1));
        int idPaciente = stoi(linea.substr(pos1 + 1, pos2 - pos1 - 1));
        int idMedico = stoi(linea.substr(pos2 + 1, pos3 - pos2 - 1));
        string fecha = linea.substr(pos3 + 1, pos4 - pos3 - 1);
        string estado = linea.substr(pos4 + 1);

        return Cita(id, idPaciente, idMedico, fecha, estado);
    }
};

// Funciones para manejo de archivos
template <typename T>
void guardarDatos(const vector<T>& datos, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << "\n";
        return;
    }
    for (const auto& dato : datos) {
        dato.guardar(archivo);
    }
    archivo.close();
}

template <typename T>
vector<T> cargarDatos(const string& nombreArchivo) {
    vector<T> datos;
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << "\n";
        return datos;
    }
    string linea;
    while (getline(archivo, linea)) {
        datos.push_back(T::cargar(linea));
    }
    archivo.close();
    return datos;
}

// Función para mostrar el menú principal
void mostrarMenu() {
    cout << "\nOpciones disponibles:\n";
    cout << "1. Registrar paciente\n";
    cout << "2. Baja de paciente\n";
    cout << "3. Modificar paciente\n";
    cout << "4. Registrar medico\n";
    cout << "5. Baja de medico\n";
    cout << "6. Modificar medico\n";
    cout << "7. Registrar cita\n";
    cout << "8. Eliminar cita\n";
    cout << "9. Modificar cita\n";
    cout << "10. Mostrar paciente\n";
    cout << "11. Mostrar medico\n";
    cout << "12. Mostrar todas las citas\n";
    cout << "13. Salir\n";
    cout << "Seleccione una opción: ";
}


// Función principal
int main() {
    const string archivoPacientes = "pacientes.txt";
    const string archivoMedicos = "medicos.txt";
    const string archivoCitas = "citas.txt";

    vector<Paciente> pacientes = cargarDatos<Paciente>(archivoPacientes);
    vector<Medico> medicos = cargarDatos<Medico>(archivoMedicos);
    vector<Cita> citas = cargarDatos<Cita>(archivoCitas);

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
        case 1: {
            int id;
            string nombre, telefono, historial;
            cout << "Ingrese el ID del paciente: ";
            cin >> id;
            cout << "Ingrese el nombre del paciente: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Ingrese el teléfono del paciente: ";
            getline(cin, telefono);
            cout << "Ingrese el historial clínico del paciente: ";
            getline(cin, historial);
            pacientes.emplace_back(id, nombre, telefono, historial);
            guardarDatos(pacientes, archivoPacientes);
            cout << "Paciente registrado exitosamente.\n";
            break;
        }
        case 2: {
            int idPaciente;
            cout << "Ingrese el ID del paciente a eliminar: ";
            cin >> idPaciente;
            auto it = remove_if(pacientes.begin(), pacientes.end(), [idPaciente](const Paciente& p) {
                return p.getId() == idPaciente;
                });
            if (it != pacientes.end()) {
                pacientes.erase(it, pacientes.end());
                guardarDatos(pacientes, archivoPacientes);
                cout << "Paciente eliminado exitosamente.\n";
            }
            else {
                cout << "Paciente no encontrado.\n";
            }
            break;
        }
        case 3: {
            int idPaciente;
            cout << "Ingrese el ID del paciente a modificar: ";
            cin >> idPaciente;
            auto it = find_if(pacientes.begin(), pacientes.end(), [idPaciente](const Paciente& p) {
                return p.getId() == idPaciente;
                });
            if (it != pacientes.end()) {
                string nuevoNombre, nuevoTelefono, nuevoHistorial;
                cout << "Ingrese el nuevo nombre del paciente: ";
                cin.ignore();
                getline(cin, nuevoNombre);
                cout << "Ingrese el nuevo teléfono del paciente: ";
                getline(cin, nuevoTelefono);
                cout << "Ingrese el nuevo historial clínico del paciente: ";
                getline(cin, nuevoHistorial);
                it->setNombre(nuevoNombre);
                it->setTelefono(nuevoTelefono);
                it->setHistorialClinico(nuevoHistorial);
                guardarDatos(pacientes, archivoPacientes);
                cout << "Paciente modificado exitosamente.\n";
            }
            else {
                cout << "Paciente no encontrado.\n";
            }
            break;
        }
        case 4: {
            int id;
            string nombre, especialidad;
            cout << "Ingrese el ID del médico: ";
            cin >> id;
            cout << "Ingrese el nombre del médico: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Ingrese la especialidad del médico: ";
            getline(cin, especialidad);
            medicos.emplace_back(id, nombre, especialidad);
            guardarDatos(medicos, archivoMedicos);
            cout << "Médico registrado exitosamente.\n";
            break;
        }
        case 5: {
            int idMedico;
            cout << "Ingrese el ID del médico a eliminar: ";
            cin >> idMedico;
            auto it = remove_if(medicos.begin(), medicos.end(), [idMedico](const Medico& m) {
                return m.getId() == idMedico;
                });
            if (it != medicos.end()) {
                medicos.erase(it, medicos.end());
                guardarDatos(medicos, archivoMedicos);
                cout << "Médico eliminado exitosamente.\n";
            }
            else {
                cout << "Médico no encontrado.\n";
            }
            break;
        }
        case 6: {
            int idMedico;
            cout << "Ingrese el ID del médico a modificar: ";
            cin >> idMedico;
            auto it = find_if(medicos.begin(), medicos.end(), [idMedico](const Medico& m) {
                return m.getId() == idMedico;
                });
            if (it != medicos.end()) {
                string nuevoNombre, nuevaEspecialidad;
                cout << "Ingrese el nuevo nombre del médico: ";
                cin.ignore();
                getline(cin, nuevoNombre);
                cout << "Ingrese la nueva especialidad del médico: ";
                getline(cin, nuevaEspecialidad);
                it->setNombre(nuevoNombre);
                it->setEspecialidad(nuevaEspecialidad);
                guardarDatos(medicos, archivoMedicos);
                cout << "Médico modificado exitosamente.\n";
            }
            else {
                cout << "Médico no encontrado.\n";
            }
            break;
        }
        case 7: {
            int id;
            int idPaciente, idMedico;
            string fecha;
            cout << "Ingrese el ID de la cita: ";
            cin >> id;
            cout << "Ingrese el ID del paciente: ";
            cin >> idPaciente;
            cout << "Ingrese el ID del médico: ";
            cin >> idMedico;
            cout << "Ingrese la fecha de la cita (YYYY-MM-DD): ";
            cin >> fecha;
            citas.emplace_back(id, idPaciente, idMedico, fecha);
            guardarDatos(citas, archivoCitas);
            cout << "Cita registrada exitosamente.\n";
            break;
        }
        case 8: {
            int idCita;
            cout << "Ingrese el ID de la cita a eliminar: ";
            cin >> idCita;
            auto it = remove_if(citas.begin(), citas.end(), [idCita](const Cita& c) {
                return c.getId() == idCita;
                });
            if (it != citas.end()) {
                citas.erase(it, citas.end());
                guardarDatos(citas, archivoCitas);
                cout << "Cita eliminada exitosamente.\n";
            }
            else {
                cout << "Cita no encontrada.\n";
            }
            break;
        }
        case 9: {
            int idCita;
            cout << "Ingrese el ID de la cita a modificar: ";
            cin >> idCita;
            auto it = find_if(citas.begin(), citas.end(), [idCita](const Cita& c) {
                return c.getId() == idCita;
                });
            if (it != citas.end()) {
                string nuevoEstado;
                cout << "Ingrese el nuevo estado de la cita (Pendiente/Completada): ";
                cin.ignore();
                getline(cin, nuevoEstado);
                it->setEstado(nuevoEstado);
                guardarDatos(citas, archivoCitas);
                cout << "Cita modificada exitosamente.\n";
            }
            else {
                cout << "Cita no encontrada.\n";
            }
            break;
        }
        case 10: {
            for (const auto& p : pacientes) {
                p.mostrarInfo();
            }
            break;
        }
        case 11: {
            for (const auto& m : medicos) {
                m.mostrarInfo();
            }
            break;
        }
        case 12: {
            for (const auto& c : citas) {
                c.mostrarInfo();
            }
            break;
        }
        case 13:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opción inválida, por favor intente nuevamente.\n";
            break;
        }
    } while (opcion != 13);

    return 0;
}
