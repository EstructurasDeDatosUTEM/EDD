#include <iostream>
#include "Cola.h"

using namespace std;

    void mostrarCola(Cola c) {
        Cola aux;
        int valor;
        while (!c.vacia() ) {
            valor = c.extraer();
            cout << valor << endl;
            aux.agregar(valor);
        }
        while (!aux.vacia())
            c.agregar(aux.extraer());
    }

    int contarElementosCola(Cola c) {
        int cantidad = 0;
        Cola aux;

        while(!c.vacia()) {
            cantidad++;
            aux.agregar(c.extraer());
        }

       while(!aux.vacia())
            c.agregar(aux.extraer());

        return cantidad;
    }

    int contarRecursivo(Cola c) {
        if(c.vacia())
            return 0;
        else {
            c.extraer();
            return 1 + contarRecursivo(c);
        }
    }

int main() {
    cout << "Colas (Queue) Implementación Simple" << endl;

    Cola c;
    c.agregar(1);
    c.agregar(2);
    c.agregar(3);
    c.agregar(4);
    c.agregar(5);

    cout << "Mostrar Cola" << endl;
    mostrarCola(c);

    cout << "Mostrar Cola" << endl;
    mostrarCola(c);

    cout << endl <<"Contar Elementos:" <<contarElementosCola(c);

    cout << endl <<"Contar Recursivo:" <<contarRecursivo(c);


    return 0;
}
