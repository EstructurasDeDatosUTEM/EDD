#ifndef COLATEMPLATE_H
#define COLATEMPLATE_H

#include <queue>
template <class Tipo>
class ColaTemplate : private std::queue<Tipo>{
    public:
        ColaTemplate() {};
        virtual ~ColaTemplate() {};
        void agregar(Tipo _valor);
        Tipo extraer();
        bool vacio();
        /*Funciones Miembro*/
        void reset();
    protected:

    private:
};

template <class Tipo>
void ColaTemplate<Tipo>::agregar(Tipo _valor){
   std::queue<Tipo>::push(_valor);
}

template <class Tipo>
Tipo ColaTemplate<Tipo>::extraer(){
    Tipo aux;
    aux = std::queue<Tipo>::front();
    std::queue<Tipo>::pop();
    return aux;
}

template <class Tipo>
bool ColaTemplate<Tipo>::vacio(){
    return std::queue<Tipo>::empty();
}

template <class Tipo>
void ColaTemplate<Tipo>::reset() {
    while(!vacio())
        extraer();
};

#endif // COLATEMPLATE_H
