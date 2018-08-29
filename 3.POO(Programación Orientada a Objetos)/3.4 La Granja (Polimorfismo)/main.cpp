#include <iostream>

using namespace std;
#include "Animal.h"
#include "Gato.h"
#include "Perro.h"
#include "Ornitorrinco.h"


int main()
{
    cout << "Mi granja" << endl;

    Animal a("Demoledor", 4);
    a.emiteSonido();

    Animal *miGranja[10];

    miGranja[0] = new Gato("Antu", 4);
    miGranja[0]->emiteSonido();

    miGranja[1] = new Perro("Docko");
    miGranja[1]->emiteSonido();

    miGranja[2] = new Ornitorrinco();
    miGranja[2]->emiteSonido();
    return 0;
}
