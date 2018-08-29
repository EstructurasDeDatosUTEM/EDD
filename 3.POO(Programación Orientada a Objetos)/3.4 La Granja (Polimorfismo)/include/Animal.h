using namespace std;
#ifndef ANIMAL_H
#define ANIMAL_H
#include "string"

class Animal
{
    public:
        Animal(string _nombre, int _patas);
        virtual ~Animal();
        virtual void emiteSonido();

    protected:
        string m_Nombre;
    private:

        int m_Patas;
};

#endif // ANIMAL_H
