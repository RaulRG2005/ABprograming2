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
    Paciente(int _id, string _nombre, string _telefono)
        : id(_id), nombre(_nombre), telefono(_telefono) {}
    int getId() const { return id; }
    string getNombre() const { return nombre; }
    string getTelefono() const { return telefono; }
    void setNombre(const string& nuevoNombre) { nombre = nuevoNombre; }
    void setTelefono(const string& nuevoTelefono) { telefono = nuevoTelefono; }
    void mostrarInfo() const {
        cout << "ID: " << id << ", Nombre: " << nombre << ", Tel�fono: " << telefono << "\n";
    }
};
// Clase M�dico
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
            << ", M�dico ID: " << idMedico << ", Fecha: " << fecha << "\n";
    }
};
// Funci�n para mostrar el men� principal
void mostrarMenu() {
    cout << "\nOpciones disponibles:\n";
    cout << "1. Registrar un paciente\n";
    cout << "2. Registrar un m�dico\n";
    cout << "3. Crear una cita\n";
    cout << "4. Mostrar todos los pacientes\n";
    cout << "5. Mostrar todos los m�dicos\n";
    cout << "6. Mostrar todas las citas\n";
    cout << "7. Eliminar un paciente\n";
    cout << "8. Salir\n";
    cout << "Seleccione una opci�n: ";
}
// Funci�n principal
int main() {
    vector<Paciente> pacientes; // Lista de pacientes
    vector<Medico> medicos;     // Lista de m�dicos
    vector<Cita> citas;         // Lista de citas
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
            cout << "Ingrese el nombre del paciente: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Ingrese el tel�fono del paciente: ";
            getline(cin, telefono);
            pacientes.emplace_back(id, nombre, telefono);
            cout << "Paciente registrado exitosamente.\n";
            break;
        }
        case 2: {
            // Registrar un m�dico
            int id;
            string nombre, especialidad;
            cout << "Ingrese el ID del m�dico: ";
            cin >> id;
            cout << "Ingrese el nombre del m�dico: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Ingrese la especialidad del m�dico: ";
            getline(cin, especialidad);
            medicos.emplace_back(id, nombre, especialidad);
            cout << "M�dico registrado exitosamente.\n";
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
            cout << "Ingrese el ID del m�dico: ";
            cin >> idMedico;
            cout << "Ingrese la fecha de la cita (YYYY-MM-DD): ";
            cin.ignore();
            getline(cin, fecha);
            // Verificar si el paciente y el m�dico existen
            auto pacienteIt = find_if(pacientes.begin(), pacientes.end(), [idPaciente](const Paciente& p) {
                return p.getId() == idPaciente;
                });
            auto medicoIt = find_if(medicos.begin(), medicos.end(), [idMedico](const Medico& m) {
                return m.getId() == idMedico;
                });
            if (pacienteIt != pacientes.end() && medicoIt != medicos.end()) {
                citas.emplace_back(idCita, idPaciente, idMedico, fecha);
                cout << "Cita creada exitosamente.\n";
            }
            else {
                cout << "Error: Paciente o m�dico no encontrado.\n";
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
            // Mostrar todos los m�dicos
            if (medicos.empty()) {
                cout << "No hay m�dicos registrados.\n";
            }
            else {
                cout << "Listado de m�dicos:\n";
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
                cout << "Paciente eliminado exitosamente.\n";
            }
            else {
                cout << "Paciente no encontrado.\n";
            }
            break;
        }
        case 8:
            cout << "Saliendo del programa. �Hasta luego!\n";
            break;
        default:
            cout << "Opci�n inv�lida. Int�ntelo de nuevo.\n";
        }
    } while (opcion != 8);
    return 0;
}