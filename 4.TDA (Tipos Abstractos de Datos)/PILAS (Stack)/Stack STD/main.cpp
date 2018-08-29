using namespace std;
#include <iostream>
#include <string>
#include "Stack.h"

typedef Stack<string> Stack;

/*Prototipos*/
int contarRecursivo(Stack s);

int main()
{
    Stack<string> a;
    a.Push("123123");
    a.Push("125555");
    a.Push("David");
    a.Push("Castro");
    cout <<"cuantos: "<< a.Contar();
    while (!a.Empty()) {
        cout << a.Pop()<<endl;
    }

    cout << "" << endl;
    return 0;
}



/*****EJEMPLOS ******/
int contarRecursivo(Stack) {

}
