#include <iostream>

using namespace std;

struct Nodo{
    int info;
    struct Nodo *izq;
    struct Nodo *der;
};
typedef Nodo * AB;

void preOrden(AB T) {
    if(T != NULL) {
        cout << T->info << " ";
        preOrden(T->izq);
        preOrden(T->der);
    }
}
void enOrden(AB T) {
    if(T != NULL) {
        enOrden(T->izq);
        cout << T->info << " ";
        enOrden(T->der);
    }
}
void postOrden(AB T) {
    if(T != NULL) {
        postOrden(T->izq);
        postOrden(T->der);
        cout << T->info << " ";
    }
}

int nodos(AB T) {
    if(T == NULL)
        return 0;
    else
        return (nodos(T->izq) + 1 + nodos(T->der));
}

int nulos(AB T) {
    if(T == NULL)
        return 1;
    else
        return (nulos(T->izq) + nulos(T->der));
}


int cantidadDeNodos(AB T) {
    if(T == NULL)
        return 0;
    else
        return 1+ cantidadDeNodos(T->izq) + cantidadDeNodos(T->der);
}

int hojas(AB T) {
    if(T == NULL)
        return 0;

    if(T->izq==NULL and T->der==NULL)
        return 1;
    else
        return (hojas(T->izq) + hojas(T->der));
}

int internos(AB T) {
    if(T == NULL)
        return 0;

    if(T->izq==NULL and T->der==NULL)
        return 0;
    else
        return (internos(T->izq) + 1 + internos(T->der));
}

int altura(AB T) {
    if(T==NULL)
        return -1;
    else {
        int hi = altura(T->izq);
        int hd = altura(T->der);
        if(hi > hd)
            return 1 + hi;
        else
            return 1 + hd;
    }
}

void insertarABB(AB &T, int valor) {
    if (T == NULL){
        T = new Nodo;
        T->info = valor;
        T->izq  = NULL;
        T->der  = NULL;

    } else {
        if (valor < T->info)
            insertarABB(T->izq, valor);
        else
            if(valor > T->info)
                insertarABB(T->der, valor);
    }
}

bool comprobarAVL(AB T) {
    if(T == NULL)
        return true;

    int fb = altura(T->der) - altura(T->izq);

    if((fb > 1)||(fb < -1))
        return false *  comprobarAVL(T->der) *  comprobarAVL(T->izq);
    else
        return true *  comprobarAVL(T->der) *  comprobarAVL(T->izq);
}

void factorBalanceAVL(AB T) {
    if(T == NULL)
        return;

    factorBalanceAVL(T->izq);
    factorBalanceAVL(T->der);
    cout <<endl << T->info <<" Altura["<<altura(T)<<"], FB="<<altura(T->der) - altura(T->izq);
}




/******************VARIOS*******************************/
int menor(AB T) {
    if(T ==  NULL)
        return -1;

    if(T->izq == NULL)
        return T->info;
    else
        menor(T->izq);
}


int mayor(AB T) {
    if(T ==  NULL)
        return -1;

    if(T->der == NULL)
        return T->info;
    else
        mayor(T->der);
}

/**eliminar todas las hojas**/
AB podarArbol(AB T) {
    if (T == NULL)
        return NULL;

    if(T->der == NULL && T->izq == NULL) {
        AB aux =T;
        cout <<"\nborrando ["<<aux->info<<"]\n";
        delete aux;
        T = NULL;
        return NULL;
    } else {
        T->izq = podarArbol(T->izq);
        T->der = podarArbol(T->der);
    }

/*
    AB auxDerecho = T->der;
    if(auxDerecho!= NULL &&(auxDerecho->izq == NULL) && (auxDerecho->der == NULL)){
        T->der = NULL;
        delete auxDerecho;
    }

    AB auxIzquierdo = T->izq;
    if(auxIzquierdo != NULL &&(auxIzquierdo->izq == NULL) && (auxIzquierdo->der == NULL)){
        T->izq = NULL;
        delete auxIzquierdo;
    }*/
}



int main() {
    cout << "Arboles ABB (Version)" << endl;
    AB T = NULL;
    insertarABB(T, 10);
    insertarABB(T, 15);
    insertarABB(T, 5);
    insertarABB(T, 20);
    insertarABB(T, 12);
    insertarABB(T, 7);
    insertarABB(T, 2);
    /*caso 2 Desbalance*/
    insertarABB(T, 8);
    insertarABB(T, 9);


    cout << "Pre-Orden" << endl;
    preOrden(T);
    cout << endl;

    cout << "En-Orden" << endl;
    enOrden(T);
    cout << endl;

    cout << "Post-Orden" << endl;
    postOrden(T);
    cout << endl;

    cout << "Cumple condicion AVL:" <<comprobarAVL(T);
    factorBalanceAVL(T);

    cout << "Cantidad de NULL     : " << nulos(T) << endl;
    cout << "Cantidad de Nodos    : " << nodos(T) << endl;
    cout << "Cantidad de Hojas    : " << hojas(T) << endl;
    cout << "Cantidad de Internos : " << internos(T) << endl;
    cout << "Altura arbol         : " << altura(T) << endl;
    cout << "Cantidad de Nodos    : " << cantidadDeNodos(T) << endl;
    cout << "El menor elemento    : " << menor(T) << endl;
    cout << "El mayor elemento    : " << mayor(T) << endl;

     cout <<endl<<"Podando"<<endl;
        podarArbol(T);
        preOrden(T);

        podarArbol(T);
        preOrden(T);


/*    while (T != NULL) {
        cout <<endl<<"Podando"<<endl;
        podarArbol(T);
        preOrden(T);
    }*/


    return 0;
}
