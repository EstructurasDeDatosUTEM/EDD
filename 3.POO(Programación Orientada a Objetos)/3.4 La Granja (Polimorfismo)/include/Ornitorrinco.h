#ifndef ORNITORRINCO_H
#define ORNITORRINCO_H

#include <Animal.h>
#include "iostream"

class Ornitorrinco : public Animal
{
    public:
        Ornitorrinco():Animal("Ornitorrinco", 4){};
        virtual ~Ornitorrinco() {};
        void emiteSonido() {
            cout << m_Nombre <<" emite el sonido: ALGO MUY RARO!"<<endl ;
        }
    protected:

    private:
};

#endif // ORNITORRINCO_H
