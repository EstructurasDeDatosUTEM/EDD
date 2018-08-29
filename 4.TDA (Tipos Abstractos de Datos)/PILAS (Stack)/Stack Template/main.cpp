#include <iostream>
#include "Stack.h"

using namespace std;

typedef Stack<string> StackString;
typedef Stack<int>    StackInteger;
typedef Stack<float>  StackFloat;


/*Generica*/
template <class T>
void mostrarStack(Stack<T> s) {
    while(!s.empty()) {
        cout << endl << s.pop();
    }
}

template <class T>
void mostrarStack2(Stack<T> s) {
    Stack<T> aux;
    while(!s.empty()) {
        T valor = s.pop();
        aux.push(valor);
        cout << endl << valor;
    }

    while (!aux.empty())
        s.push(aux.pop());
}


/*Especializada*/
void mostrarStackString(StackString s) {
    while(!s.empty()) {
        cout << endl << s.pop();
    }
}



int main() {

    cout << "Stack Template Simple" << endl;
    Stack<int>   s;
    StackString  s2;
    StackInteger s3;
    StackFloat   s4;

    s.push(5);
    s.push(6);
    s.push(7);

    s2.push("David");
    s2.push("Marilyn");
    s2.push("Programacion");

    s3.push(100);
    s3.push(101);
    s3.push(103);

    s4.push(15.6);
    s4.push(15.7);
    s4.push(15.8);

    mostrarStack(s);
    mostrarStack(s);
    mostrarStack(s);

    cout << "\nMostrarString\n";
   // mostrarStack(s2);
    mostrarStack(s3);
    mostrarStack(s4);


    cout << "\nMostrarString\n";
    mostrarStackString(s2);
    return 0;
}
