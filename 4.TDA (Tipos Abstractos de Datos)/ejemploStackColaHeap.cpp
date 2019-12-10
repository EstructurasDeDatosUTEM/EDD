#include <iostream>
using namespace std;

/***********************************************STACK***********************************************/
#ifndef Stack_H
#define Stack_H

#include <stack>
template <class T>
class Stack : private std::stack<T> {
public:
    Stack(){};
    virtual ~Stack(){};
    T pop();
    void push(T valor);
    bool empty();
};


template <class T>
T Stack<T>::pop() {
    T valor = std::stack<T>::top();
    std::stack<T>::pop();
    return valor;
}

template <class T>
void Stack<T>::push(T valor) {
    std::stack<T>::push(valor);
}

template <class T>
bool Stack<T>::empty() {
    return std::stack<T>::empty();
}
#endif // Stack_H

/***********************************************QUEUE(COLA)***********************************************/

#ifndef Cola_H
#define Cola_H
#include <queue>
template <class Tipo>
class Cola : private std::queue<Tipo>{
    public:
        Cola() {};
        virtual ~Cola() {};
        void agregar(Tipo _valor);
        Tipo extraer();
        bool vacio();
        /*Funciones Miembro*/
        void reset();
    protected:

    private:
};

template <class Tipo>
void Cola<Tipo>::agregar(Tipo _valor){
   std::queue<Tipo>::push(_valor);
}

template <class Tipo>
Tipo Cola<Tipo>::extraer(){
    Tipo aux;
    aux = std::queue<Tipo>::front();
    std::queue<Tipo>::pop();
    return aux;
}

template <class Tipo>
bool Cola<Tipo>::vacio(){
    return std::queue<Tipo>::empty();
}

template <class Tipo>
void Cola<Tipo>::reset() {
    while(!vacio())
        extraer();
};

#endif // Cola_H

/***********************************************COLA DE PRIORIDAD(HEAP)***********************************************/
#ifndef Heap_H
#define Heap_H

template <class T>
class Heap {
public:
    Heap() {};
    virtual ~Heap() {};

    void agregar(T dato, int prioridad) {
        ParPrioridadDato par;
        par.first = prioridad;
        par.second= dato;
        h2.push(par);
    };

    T extraer(){
        ParPrioridadDato par = h2.top();
        h2.pop();
        return par.second;
    }

    bool vacio() {
        return h2.empty();
    }

private:
    typedef std::pair<int, T> ParPrioridadDato; // Prioridad, orden

    class ComparePrioridad {
        public:
            bool operator() (ParPrioridadDato a, ParPrioridadDato b) {
                return a.first > b.first;
            }
    };
    std::priority_queue<ParPrioridadDato, std::vector<ParPrioridadDato>, ComparePrioridad> h2;
};

#endif // Heap_H
/***********************************************COLA DE PRIORIDAD(HEAP)***********************************************/





int ejemploStack() {
    cout << "[Ejemplo Stack]" << endl;

    Stack<int> s;
    s.push(1);
    s.push(4);
    s.push(10);
    while(!s.empty())
        cout << s.pop()<<endl;

    //ejemplo de stack utilizando vectores
    Stack<int> v[10]; //vector
    v[0] = s;
    v[1] = s;

    while (!v[0].empty())
        cout <<v[0].pop()<<endl;

    return 0;
}

void ejemploCola() {
    cout << "[Colas]" << endl;
    Cola<int> c;
    c.agregar(15);
    c.agregar(3);
    c.agregar(4);
    while (!c.vacio())
        cout <<c.extraer() << endl;

}

void ejemploHeap() {
    cout << "[Heap]" << endl;
    Heap<int> h;
    h.agregar(1,5);
    h.agregar(2,4);
    h.agregar(3,3);
    h.agregar(4,2);
    h.agregar(5,1);

    while (!h.vacio())
        cout <<h.extraer()<<endl;
}


class Persona {
private:
    string m_nombre;
    int m_edad;
public:
    //constructor vacio
    Persona(){
        m_nombre = "";
        m_edad = -1;
    }
    //constructor parametrizado
    Persona(int edad, string nombre){
        m_edad = edad;
        m_nombre = nombre;
    }
    //Constructor copia
    Persona(const Persona &other) {
        m_edad = other.m_edad;
        m_nombre =other.m_nombre;
    }
    //getters y setters
    void setEdad(int valor) {
        m_edad = valor;
    }
    void setNombre(string valor) {
        m_nombre = valor;
    }
    int getEdad() {
        return m_edad;
    }
    string getNombre() {
        return m_nombre;
    }

    void ver() {
        cout << "Nombre: "<<m_nombre << ", edad:"<<m_edad<<endl;
    }

    void ver2() {
        cout << m_edad<<" "<<m_nombre <<endl;
    }

};

void OrdenarCola(Cola<Persona> &colap){
    //ordenaremos la cola por edad
    Heap<Persona> h;
    while (!colap.vacio()) {
        //extraemos el dato y lo dejamos en la variable p
        Persona p = colap.extraer();
        //el primero parámetro es el objeto y el segundo es la edad
        h.agregar(p, p.getEdad());
        /**NOTA:
        Heap es un TDA de ordenamiento que utiliza colas de prioridad
        para ordenar datos, el primer parámetro de entrada en el método
        agregar es el DATO a ordenar y el segundo parámetro es el valor
        por el cuál ordenaremos el DATO. */
    }

    //ahora volvemos a dejar los datos que estan ordenados en el HEAP en la cola original
    while(!h.vacio()) {
        Persona p = h.extraer();
        colap.agregar(p);
    }
}

void mostrarCola(Cola<Persona> &cola) {
    Cola<Persona> colaAux;
    while(!cola.vacio()) {
        Persona p = cola.extraer();
        p.ver2();
        //guardamos el dato en una cola auxiliar
        colaAux.agregar(p);
    }

    //retornamos los datos de la cola auxiliar a la cola original
    while(!colaAux.vacio()) {
        cola.agregar(colaAux.extraer());
    }
}

//invertir una cola de datos
void invertirCola(Cola<Persona> &cola) {
    Stack<Persona> stackAux;

    while(!cola.vacio()) {
        Persona p = cola.extraer();
        //guardamos el dato en un STACK auxiliar
        /**Recordemos que el STACK funciona LIFO
        El último que entra es el primero en salir*/
        stackAux.push(p);
    }

    //retornamos los datos de la cola auxiliar a la cola original
    while(!stackAux.empty()) {
        cola.agregar(stackAux.pop());
    }
}


void ejemploColaClases() {
    cout <<endl;
    cout <<"[Ejemplo Cola Utilizado Clases]"<<endl;
    Cola<Persona> colaPersonas;

    //creamos una persona en p1
    Persona p1(39, "David");
    //agregamos p1 a la Cola
    colaPersonas.agregar(p1);

    //ahora agregamos directamente
    colaPersonas.agregar(Persona(37, "Mary"));
    colaPersonas.agregar(Persona(22, "Dayana"));
    colaPersonas.agregar(Persona( 7, "Seba"));
    colaPersonas.agregar(Persona(11, "Ignacio"));
    colaPersonas.agregar(Persona(14, "Antonia"));

    /*//recorremos la cola de personas hasta mientras no este vacia
    while (!colaPersonas.vacio()) {
        //extraemos el dato desde la cola y lo dejamos en un temporal
        Persona p = colaPersonas.extraer();
        cout <<"edad: "<< p.getEdad()<<endl;
        cout <<"nombre: "<< p.getNombre()<<endl;
    }*/
    cout<<"[Mostrar Cola Original]"<<endl;
    mostrarCola(colaPersonas);

    //llamamos a la función de ordenamiento utilizando HEAPs
    OrdenarCola(colaPersonas);
    cout<<endl;
    cout<<"[Mostrar Cola Ordenada]"<<endl;
    mostrarCola(colaPersonas);

    //invertimos los datos utilizando un STACK
    invertirCola(colaPersonas);
    cout<<endl;
    cout<<"[Mostrar Cola Invertida por un Stack]"<<endl;
    mostrarCola(colaPersonas);

}


int main() {
    ejemploStack();
    ejemploCola();
    ejemploHeap();
    ejemploColaClases();
    return 0;
}

