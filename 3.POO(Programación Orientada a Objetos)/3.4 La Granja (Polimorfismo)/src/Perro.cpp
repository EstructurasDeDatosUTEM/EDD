#include "Perro.h"
#include "iostream"

Perro::Perro(string _nombre):Animal(_nombre, 4)
{
    //ctor
}

Perro::~Perro()
{
    //dtor
}

void Perro::emiteSonido() {
    cout << m_Nombre <<" emite el sonido: GUAUUU!"<<endl ;
}
