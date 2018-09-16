#include <iostream>
#include "ABB.h"
using namespace std;

int ABB::hojas(AB T) {
    if(T==NULL)
        return 0;
    else {
        int siSumar = 0;
        if(T->der == NULL && T->izq == NULL)
            return 1;
        else
            hojas(T->izq) + hojas(T->der);
    }
}


/*void ABB::VerABB(AB T) {
    if (T != NULL) {
      VerABB(T->izq);
      cout << "Clave: " << T->key << "    Info: " << T->info << endl;
      VerABB(T->der);
    }
}*/

int main() {
    cout << "ABB" << endl;
    ABB T;
    T.Insertar(12,12);
    T.Insertar(21,11);
    T.Insertar(3,13);
    T.Eliminar(3);
    T.Insertar(3,17);
    T.Ver();

    return 0;
}

