#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Paciente {
private:
    int id;
    string nombre;
    vector<int> historialCitas; 

public:
    
    Paciente(int _id, string _nombre) : id(_id), nombre(_nombre) {}

   
    void agregarCita(int idCita) {
        historialCitas.push_back(idCita);
        cout << "Cita con ID " << idCita << " registrada en el historial de " << nombre << ".\n";
    }

    void cancelarCita(int idCita) {
        auto it = find(historialCitas.begin(), historialCitas.end(), idCita);
        if (it != historialCitas.end()) {
            historialCitas.erase(it);
            cout << "Cita con ID " << idCita << " eliminada del historial de " << nombre << ".\n";
        }
        else {
            cout << "Cita con ID " << idCita << " no encontrada en el historial de " << nombre << ".\n";
        }
    }


    void mostrarHistorial() const {
        cout << "Historial de citas para " << nombre << ":\n";
        if (historialCitas.empty()) {
            cout << "- No hay citas registradas.\n";
        }
        else {
            for (int idCita : historialCitas)
                cout << "- Cita ID: " << idCita << "\n";
        }
    }

    string getNombre() const {
        return nombre;
    }

  
    int getId() const {
        return id;
    }
};


int main() {rear un pac
   
    Paciente paciente1(1, "Juan Perez");


    cout << "\nHistorial inicial:\n";
    paciente1.mostrarHistorial();


    cout << "\nAgregando citas al historial:\n";
    paciente1.agregarCita(101);
    paciente1.agregarCita(102);

 
    cout << "\nHistorial actualizado:\n";
    paciente1.mostrarHistorial();

    cout << "\nCancelando una cita:\n";
    paciente1.cancelarCita(101);

   
    cout << "\nHistorial después de cancelar una cita:\n";
    paciente1.mostrarHistorial();

 
    cout << "\nIntentando cancelar una cita inexistente:\n";
    paciente1.cancelarCita(999);

    return 0;
}
