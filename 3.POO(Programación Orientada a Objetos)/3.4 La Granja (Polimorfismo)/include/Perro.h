#ifndef PERRO_H
#define PERRO_H

#include <Animal.h>


class Perro : public Animal
{
    public:
        Perro(string _nombre);
        virtual ~Perro();
        void emiteSonido();
    protected:

    private:
};

#endif // PERRO_H
