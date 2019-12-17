#include <iostream>
using namespace std;

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

#endif // Cola_H
/****************************************************************/



class Persona {
private:
    string m_nombre;
    int m_edad;
    int m_rut;

public:
   //constructor vacio
    Persona(){
        m_nombre = "";
        m_edad = -1;
        m_edad = -1;
    }
   //constructor parametrizado
    Persona(int rut, int edad, string nombre){
        m_rut = rut;
        m_edad = edad;
        m_nombre = nombre;
    }
    //Constructor copiaunirColas
    Persona(const Persona &other) {
        m_rut = other.m_rut;
        m_edad = other.m_edad;
        m_nombre =other.m_nombre;
    }

    //getters y setters
    void setRut(int valor) {
        m_rut = valor;
    }

    void setEdad(int valor) {
        m_edad = valor;
    }
    void setNombre(string valor) {
        m_nombre = valor;
    }

    int getRut() {
        return m_rut;
    }
    int getEdad() {
        return m_edad;
    }
    string getNombre() {
        return m_nombre;
    }

    void ver() {
        cout << "Rut: "<<m_rut;
        cout << ", Nombre: "<<m_nombre;
        cout << ", edad:"<<m_edad<<endl;
    }

    void ver2() {
        cout << m_rut<<" "<< m_edad<<" "<<m_nombre <<endl;
    }

};

///4.- Mostrar los elementos dentro de una Cola
void mostrarCola(Cola<Persona> &c) {
    Cola<Persona> aux;
    while (!c.vacio()) {
        Persona p = c.extraer();
        p.ver2();
        aux.agregar(p);
    }

    while (!aux.vacio())
        c.agregar(aux.extraer());
}

 //5.- Unir dos Colas en una sola
void unirColas(Cola<Persona> &c, Cola<Persona> &c1) {
    while (!c1.vacio())
        c.agregar(c1.extraer());
}

//6.- Contar la cantidad de elementos dentro de una Cola
int contarElementosEnCola(Cola<Persona> &c){
    Cola<Persona> aux;
    int cantidad = 0;

    while(!c.vacio()) {
        aux.agregar(c.extraer());
        cantidad++;
    }
    //retornamos los datos a la cola original
    while(!aux.vacio())
        c.agregar(aux.extraer());

    return cantidad;
}

//7.- Contar elementos de la cola en base a algún parámetro
int contarLaCantidadDePersonasRangoEdadEnCola(Cola<Persona> &c, int edadDesde, int edadHasta) {
    Cola<Persona> aux;
    int cantidad = 0;

    while (!c.vacio()){
        Persona p = c.extraer();
        if(p.getEdad() >= edadDesde && p.getEdad() <= edadHasta)
            cantidad++;
        //respaldamos el dato obtenido
        aux.agregar(p);
    }
    //retornamos los datos a la cola original
    while(!aux.vacio())
        c.agregar(aux.extraer());

    return cantidad;
}

//8.- Buscar el mayor elemento dentro de una cola
Persona buscarMayorEnCola(Cola<Persona> &c) {
    Cola<Persona> aux;
    //creamos un aux para guardar la persona Mayor
    Persona pMayor(-1, -1, "Vacio");

    while (!c.vacio()){
        Persona p = c.extraer();
        if(p.getEdad() > pMayor.getEdad())
            pMayor = Persona(p);
        aux.agregar(p);
    }
    //retornamos los datos a la cola original
    while(!aux.vacio())
        c.agregar(aux.extraer());

    return pMayor;
}


//9.- Extraer el mayor elemento dentro de una cola
Persona buscarMayorYExtraerEnCola(Cola<Persona> &c) {
    /*construya una función que utilizando el TDA COLA entregue el objeto
     Persona con la mayor edad dentro de la cola.
    Considere que la clase persona tiene los atributos nombre, edad y
    rut (es único, por lo que no se repite en la cola)*/
    Cola<Persona> aux;
    //creamos un aux para guardar la persona Mayor
    Persona pMayor(-1, -1, "Vacio");
    int posicionMayor = 0;
    int posicion = 0;
    while (!c.vacio()){
        Persona p = c.extraer();
        posicion++;
        if(p.getEdad() > pMayor.getEdad()){
            pMayor = Persona(p);
            posicionMayor = posicion;
        }
        aux.agregar(p);
    }
    //retornamos los datos a la cola original
    /**omitimos el mayor encontrado según su posición**/
     posicion = 0;
     while(!aux.vacio()) {
        posicion++;
        if(posicion == posicionMayor)
            aux.extraer();
        else
            c.agregar(aux.extraer());
    }
    return pMayor;
}


//10.- Ordenar elementos por algún parámetro
void ordenarPorEdad(Cola<Persona> &c) {
    Cola<Persona> aux;
    while (!c.vacio())
        aux.agregar(buscarMayorYExtraerEnCola(c));

    while (!aux.vacio())
        c.agregar(aux.extraer());
}

int main()
{
    /**
    1.- Traemos la Clase Cola
    2.- Creamos la clase Persona
    3.- Agregamos datos a una Cola
    4.- Mostrar los elementos dentro de una Cola
    5.- Unir dos Colas en una sola
    6.- Contar la cantidad de elementos dentro de una Cola
    7.- Contar elementos de la cola en base a algún parámetro
    8.- Buscar el mayor elemento dentro de una cola
    9.- Extraer el mayor elemento dentro de una cola
    10.- Ordenar elementos por algún parámetro**/
    cout << "Ejercicios de Colas" << endl;

    Cola<Persona> cola;
    cola.agregar(Persona( 1,23,"ANGEL"));
    cola.agregar(Persona( 2, 4,"DANIEL"));
    cola.agregar(Persona( 3,27,"MAXIMILIANO"));
    cola.agregar(Persona( 4,13,"DANTE"));
    cola.agregar(Persona( 5,25,"ROBERTO"));
    cola.agregar(Persona( 6,56,"RICARDO"));
    cola.agregar(Persona( 7,63,"LUZ"));
    cola.agregar(Persona( 8, 2,"PILAR"));
    cola.agregar(Persona( 9,25,"NAHUEL"));
    cola.agregar(Persona(10,31,"SEBASTIAN"));

    Cola<Persona> cola2;
    cola2.agregar(Persona(11, 3,"MONICA"));
    cola2.agregar(Persona(12,35,"ROCIO"));
    cola2.agregar(Persona(13,24,"MARCELO"));
    cola2.agregar(Persona(14,12,"CRISTIAN"));
    cola2.agregar(Persona(15,23,"DIEGO"));
    cola2.agregar(Persona(16,55,"MAURO"));
    cola2.agregar(Persona(17,34,"JOAQUIN"));
    cola2.agregar(Persona(18,27,"VANIA"));
    cola2.agregar(Persona(19,21,"IAN"));

    cout <<endl <<"MostrarCola"<<endl;
    mostrarCola(cola);

    cout <<endl <<"Union Cola1 y Cola2"<<endl;
    unirColas(cola, cola2);

    cout <<endl <<"MostrarCola Unida"<<endl;
    mostrarCola(cola);

    cout <<endl <<"Contar la cantidad de elementos en la cola"<<endl;
    cout <<"cantidad:"<<contarElementosEnCola(cola)<<endl;


    cout <<"Personas entre 18 y 100 anhos:";
    cout << contarLaCantidadDePersonasRangoEdadEnCola(cola, 18, 100)<<endl;

    Persona pMayor =buscarMayorEnCola(cola);
    cout <<"el mayor es:"<< pMayor.getEdad()<<" "<<pMayor.getNombre()<<endl;


    cout <<endl <<"**MostrarCola"<<endl;
    mostrarCola(cola);
    cout <<endl <<"**MostrarCola Ordenada"<<endl;
    ordenarPorEdad(cola);
    mostrarCola(cola);

    return 0;
}
