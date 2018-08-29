#ifndef CLASECOLA_H
#define CLASECOLA_H
#include <queue>

typedef int Tipo2;
template <class Tipo>
class ClaseCola : private std::queue<Tipo>{
    public:
        ClaseCola();
        virtual ~ClaseCola();
        void Agregar(Tipo _valor);
        Tipo Extraer();
        bool Vacio();
        /*Funciones Miembro*/
        void Reset();
    protected:

    private:
};

template <class Tipo>
ClaseCola<Tipo>::ClaseCola(){};

template <class Tipo>
ClaseCola<Tipo>::~ClaseCola() {};

template <class Tipo>
void ClaseCola<Tipo>::Agregar(Tipo _valor){
   std::queue<Tipo>::push(_valor);
}

template <class Tipo>
Tipo ClaseCola<Tipo>::Extraer(){
    Tipo aux;
    aux = std::queue<Tipo>::front();
    std::queue<Tipo>::pop();
    return aux;
}

template <class Tipo>
bool ClaseCola<Tipo>::Vacio(){
    return std::queue<Tipo>::empty();
}

template <class Tipo>
void ClaseCola<Tipo>::Reset() {
    while(!Vacio())
        Extraer();
};


#endif // CLASECOLA_H
