#include <iostream>
#include "Stack.h"

using namespace std;

typedef Stack<int> StackInt;

void mostrarStack(StackInt);
void mostrarStackMinimal(StackInt);
int contarElementos(StackInt);
int contarRecursivo(StackInt &);
int sumarElementos(StackInt);
int sumarRecursivo(StackInt &);
void clonarStack(StackInt &, StackInt &);

int main() {

    StackInt s;
    StackInt s2;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
     clonarStack(s, s2);
    mostrarStack(s);
   /* mostrarStack(s);

    clonarStack(s, s2);
    /*cout << "\nContar Elementos: "  << contarElementos(s);
    cout << "\nContar Elementos R: "<< contarRecursivo(s);
    cout << "\nSumar Elementos R: "<< sumarRecursivo(s);
    cout << "\nCantidad Elementos: "  << contarElementos(s);
    cout << "\nCantidad Elementos S2: "  << contarElementos(s2);*/
    cout << "\nClonar ";
   // clonarStack(s2, s);
    cout << "\nMostrar S";
    mostrarStack(s);
    cout << "\nMostrar S2";
    mostrarStack(s2);
    /*cout << "\nSumar Elementos: "  << sumarElementos(s);
    cout << "\nSumar Recursivo: "  << sumarRecursivo(s);
*/
    return 0;
}

void mostrarStack(StackInt s) {
    StackInt aux;
    int e;
    cout <<"\nMostrar Stack sin perder los elementos: \n";
    while (!s.empty()) {
        e = s.pop();
        cout << "valor : "<< e << endl;
        /**guardo el valor en otro stack**/
        aux.push(e);
    }

    /**como quedo en orden inverso lo reorganizo**/
    while (!aux.empty()) {
        e = aux.pop();
        s.push(e);
    }
}


void mostrarStackMinimal(StackInt s) {
    StackInt aux;
    while (!s.empty()) {
        int e = s.pop();
        cout << "valor : "<< e << endl;
        aux.push(e);
    }

    while (!aux.empty())
        s.push(aux.pop());
}


int contarElementos(StackInt s) {
    int cantidad = 0;
    StackInt aux;

    while (!s.empty()) {
        aux.push(s.pop());
        cantidad++;
    }

    while (!aux.empty())
        s.push(aux.pop());

    return cantidad;
}

int contarRecursivo(StackInt &s) {
    if(!s.empty()) {
        int e = s.pop();
        return 1 + contarRecursivo(s);
    }
    else
        return 0;
}


    int sumarElementos(StackInt s) {
        StackInt aux;
        int e, suma = 0;
        while (!s.empty()) {
            e = s.pop();
            aux.push(e);
            suma = suma + e;
        }

        while (!aux.empty())
            s.push(aux.pop());

        return suma;
    }



    int sumarRecursivo(StackInt &s) {
        if(s.empty())
            return 0;
        else
            return s.pop() + sumarRecursivo(s);
    }

    void clonarStack(StackInt &actual, StackInt &nuevo) {
        StackInt aux;
        while(!actual.empty())
            aux.push(actual.pop());

        /**recupero el original**/
        while (!aux.empty()) {
            int valor = aux.pop();
            nuevo.push(valor);
            actual.push(valor);
        }
    }



