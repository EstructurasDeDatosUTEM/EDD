using namespace std;
#include <iostream>

#include <stack>
typedef int TipoStack;
class Stack : private stack<TipoStack> {
public:
    void Push(TipoStack _valor) {
        stack::push(_valor);
    }

    TipoStack Pop() {
        TipoStack temp = stack::top();
        stack::pop();
        return temp;
    }

    bool Empty () {
        return stack::empty();
    }
};

/*****ejercicios***/


int botton(Stack S){
    Stack aux;
    int e,c;
    while(!S.Empty()){
        e=S.Pop();
        aux.Push(e);
    }
    while(!aux.Empty()){
        c=aux.Pop();
        S.Push(c);
    }
    return e;
}


/*
int elementos(Cola S){
    Cola aux;
    int e,c,b=0;
    while(!S.vacia()){
        e=S.extraer();
        aux.agregar(e);
        b++;
    }
    c=e;
    while(! S.vacia()){
        S.agregar(e);
        e=aux.extraer();
    }
    return b;
}*/



/*
void Stack::reset(Stack C) {
    int b;
    while(!C.vacia()) {
            b=C.extraer();
        }
}
*/




void ordenOriginal(Stack S) {
    Stack aux;
    int valor = 0;
    while(!S.Empty()){
        aux.Push(S.Pop()); //Guarda valores en un stack auxiliar
    }

    while( !aux.Empty() ){
        valor = aux.Pop() ;
        cout<<valor<<endl;
        /* imprime valor, (cuando lo guarda en el auxiliar el orden se invierte)*/
        S.Push(valor); //de vuelve dato al stack original
    }
}








void posK(Stack S, int k){
    int m;
    Stack aux;
    while(!S.Empty()){
        m=S.Pop();
        if(k==0) {
            cout<<"Numero de la posicion k: "<<m<<endl;
        }
        aux.Push(m);
        k--;
    }
    while(!aux.Empty()){
        m=aux.Pop();
        S.Push(m);
    }
}



int main() {
    Stack myStack;
    myStack.Push(1);
    myStack.Push(2);
    myStack.Push(3);
    myStack.Push(4);
    myStack.Push(5);
    myStack.Push(6);
    myStack.Push(7);
    myStack.Push(8);

    cout <<"botton:"<< botton(myStack) << endl;

    posK(myStack, 4);

    ordenOriginal(myStack);

    while (!myStack.Empty()) {
        TipoStack temp = myStack.Pop();
        cout <<temp<<endl;
    }

    return 0;
}



