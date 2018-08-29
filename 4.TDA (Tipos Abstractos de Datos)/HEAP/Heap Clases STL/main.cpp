#include <iostream>
#include <queue>

using namespace std;

class Paciente {
public:
    Paciente() {};
    Paciente(int urgencia, int edad, string nombre) {
        _urgencia = urgencia;
        _edad = edad;
        _nombre = nombre;
    }
    int getUrgencia() {
        return _urgencia;
    }

    void setUrgencia(int valor) {
        _urgencia = valor;
    }

    int getEdad();
    void setEdad(int valor);

    string getNombre() {
        return _nombre;
    }

private:
    int _urgencia;
    int _edad;
    string _nombre;
};

int Paciente::getEdad() {
        return _edad;
    }

void Paciente::setEdad(int valor) {
        _edad = valor;
    }




class ComparacionUrgenciaClass {
    public:
    bool operator() (Paciente a, Paciente b) {
        return a.getUrgencia() > b.getUrgencia();
    }
};

class ComparacionEdadClass {
    public:
    bool operator() (Paciente a, Paciente b) {
        return a.getEdad() > b.getEdad();
    }
};


int main() {

    priority_queue<Paciente, vector<Paciente>, ComparacionUrgenciaClass> h;

    Paciente p1(4,37, "David");
    Paciente p2(6,27, "Maria");
    Paciente p3(5,17, "Juan");
    Paciente p4(1, 7, "Rosa");
    Paciente p5(5,57, "Roberto");

    h.push(p1);
    h.push(p2);
    h.push(p3);
    h.push(p4);
    h.push(p5);


    while(!h.empty()) {
        Paciente paciente = h.top();
        h.pop();
        cout <<endl << " Paciente:";
        cout <<endl << " Nombre:"   << paciente.getNombre();
        cout <<endl << " Edad:"     << paciente.getEdad();
        cout <<endl << " Urgencia:" << paciente.getUrgencia();
        cout <<endl;
    }

    return 0;
}
