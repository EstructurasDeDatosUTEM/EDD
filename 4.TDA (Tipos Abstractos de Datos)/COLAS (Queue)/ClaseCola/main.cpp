using namespace std;
#include <iostream>
#include "ClaseCola.h"

typedef int Tipo;
typedef ClaseCola<Tipo> Cola;
/*prototipos*/
void mostrar(Cola c);
void copia(Cola &origen, Cola &copia);
void reset(Cola &c);


int main() {
    cout << "Colas (Queue)" << endl;

    Cola c;
    c.Agregar(4);
    c.Agregar(5);
    c.Agregar(6);
    c.Agregar(7);
    //c.Reset();
    cout <<"Mostrar"<<endl;
    mostrar(c);

    Cola d;
    copia(c, d);
    cout <<"Mostrar Copia"<<endl;
    mostrar(d);


    cout <<"Mostrar"<<endl;
    mostrar(c);


    /*while (!c.Vacio()){
        cout <<endl <<c.Extraer();
    }*/
    return 0;
}

void mostrar(Cola c){
    while(!c.Vacio())
        cout <<c.Extraer()<<endl;
}

void copia(Cola &origen, Cola &destino){
    Tipo t;
    Cola aux;
    while(!origen.Vacio()){
        t = origen.Extraer();
        destino.Agregar(t);
        aux.Agregar(t);
    }
    while(!aux.Vacio())
        origen.Agregar(aux.Extraer());
}

void reset(Cola &c){
    while(!c.Vacio())
        c.Extraer();
}
