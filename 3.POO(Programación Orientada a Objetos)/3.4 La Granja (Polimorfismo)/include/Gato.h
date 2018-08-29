#ifndef GATO_H
#define GATO_H

#include <Animal.h>


class Gato : public Animal
{
    public:
        Gato(string _nombre, int _patas): Animal(_nombre, _patas) {};
        virtual ~Gato();
        void emiteSonido();

    protected:

    private:
};

#endif // GATO_H
