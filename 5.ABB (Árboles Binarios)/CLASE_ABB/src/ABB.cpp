#include <iostream>
#include "ABB.h"
using namespace std;

    ABB::ABB() {
        B = NULL;
    }

    ABB::~ABB() {
        //dtor
    }

    ABB::ABB(const ABB& other) {
        //copy ctor
    }

    void ABB::VerABB(AB T) {
        if (T != NULL) {
          VerABB(T->izq);
          cout << "Clave: " << T->key << "    Info: " << T->info << endl;
          VerABB(T->der);
        }
    }

    void ABB::InsertarABB(AB &T, int k, int e) {
        if (T == NULL){
            T = new Nodo(k,e,NULL, NULL);
        } else {
            if (k < T->key)
                InsertarABB(T->izq, k, e);
            else
                if(k > T->key)
                    InsertarABB(T->der, k, e);
        }
    }

    int ABB::BuscarABB(AB T, int k) {
        if (T == NULL)
           return -1;
        else
            if (k < T->key)
                return BuscarABB(T->izq, k);
            else
                if (k > T->key)
                    return BuscarABB(T->der, k);
                else
                    return T->info;
    }

    void ABB::Menor(AB &S, AB &p) {
        if(S->izq != NULL)
            return Mayor(S->izq,p);
        else
            p = S;
    }

    void ABB::Mayor(AB &S, AB &p) {
        if(S->der != NULL)
             return Mayor(S->der,p);
        else {
             p = S;
             S = S->izq;
        }
    }



    void ABB::EliminarABB(AB &T, int k) {
        AB q;
        if (T != NULL)
            if (k == T->key){
               q = T;
               if(T->der == NULL)
                  T = T->izq;
               else
                  if (T->izq == NULL)
                      T = T->der;
                  else{
                     Mayor(T->izq, q);
                     T->key = q->key;
                     T->info = q->info;
                  }
                  delete q;
            } else
               if (k < T->key)
                    EliminarABB(T->izq,k);
               else
                  if (k > T->key)
                     EliminarABB(T->der,k);
    }

    //#m. public
    void ABB::Ver() {
        VerABB(B);
    }

    void ABB::Insertar(int k, int e) {
        InsertarABB(B,k,e);
    }

    int ABB::Buscar(int k) {
        return BuscarABB(B,k);
    }

    bool ABB::Existe(int k) {
        return BuscarABB(B,k) != -1;
    }

    bool ABB::Vacio() {
        return B == NULL;
    }

    int ABB::GetKey() {
        return B->key;
    }

    int ABB::GetInfo() {
        return B->info;
    }

    void ABB::Eliminar(int k) {
        EliminarABB(B,k);
    }

