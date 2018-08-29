using namespace std;
#include <iostream>
#include <string>
#include "ClaseStack.h"

typedef string Tipo;
typedef ClaseStack<string> Stack;

/*Prototipos*/
int contarRecursivo(Stack &s);

int main()
{
    cout << "Ejemplos de Stack" << endl;
    Stack myStack;
    myStack.Push("123123");
    myStack.Push("125555");
    myStack.Push("David");
    myStack.Push("Castro");

    cout <<"contarR: "<< contarRecursivo(myStack);
    cout <<"cuantos: "<< myStack.Contar();
    while (!myStack.Empty()) {
        cout << myStack.Pop()<<endl;
    }


    return 0;
}



/*****EJEMPLOS ******/
int contarRecursivo(Stack &s) {
    if(!s.Empty()) {
        Tipo e = s.Pop();
        return 1+ contarRecursivo(s);
    } else
    return 0;
}
