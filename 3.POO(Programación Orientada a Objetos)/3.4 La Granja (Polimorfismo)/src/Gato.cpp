#include "Gato.h"
#include "iostream"

Gato::~Gato()
{
    //dtor
}

void Gato::emiteSonido() {
    cout << m_Nombre <<" emite el sonido: MIAUUUU!"<<endl ;
}
