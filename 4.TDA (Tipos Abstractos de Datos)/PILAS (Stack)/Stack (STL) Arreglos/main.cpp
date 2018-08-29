using namespace std;
#include <iostream>
#include <stack>
typedef struct Array{
    string nombre;
    int nota[10];
} TipoStack;

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

int main() {
    Stack myStack;

    TipoStack notas1;
    notas1.nombre = "Diego";
    notas1.nota[0] = 5;
    notas1.nota[1] = 6;
    notas1.nota[2] = 4;
    notas1.nota[3] = 7;
    myStack.Push(notas1);

    TipoStack a = {"Juan",{0,1,2,3,4,5,6,7,8,9}};
    myStack.Push(a);

    myStack.Push({"Pedro",{0,1,2,3,4,5,6,7,8,9}});
    myStack.Push({"Rodolfo",{5,1,5,3,4,2,6,1,8,19}});

    while (!myStack.Empty()) {
        TipoStack temp = myStack.Pop();
        cout <<temp.nombre<<endl;
        cout <<temp.nota[3]<<endl;
        int suma = 0;
        for(int i=0;i<10;i++) {
            cout << temp.nota[i]<<",";
            suma += temp.nota[i];
        }
        cout <<"La suma es: "<<suma<<endl<<endl;
    }

    return 0;
}
