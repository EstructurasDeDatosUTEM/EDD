#include "Animal.h"
#include "iostream"

Animal::~Animal()
{
    //dtor
}

Animal::Animal(string _nombre, int _patas):m_Nombre(_nombre), m_Patas(_patas) {
}

void Animal::emiteSonido(){
    cout << m_Nombre <<" emite el sonido: NO DEFINIDO"<<endl ;
}
