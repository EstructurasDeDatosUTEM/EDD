using namespace std;

#ifndef STACK_H
#define STACK_H
#include <stack>

template <class Tipo>
class Stack : private stack<Tipo> {
public:
    void Push(Tipo _valor) {
        stack<Tipo>::push(_valor);
    }

    Tipo Pop() {
        Tipo temp = stack<Tipo>::top();
        stack<Tipo>::pop();
        return temp;
    }

    bool Empty () {
        return stack<Tipo>::empty();
    }

    /**Metodos Miembros*/
    int Contar();
};

template <class Tipo>
int Stack<Tipo>::Contar() {
    int cuantos = 0;
    while (!Empty()) {
        Pop();
        cuantos ++;
    }
    return cuantos;
}


#endif // STACK_H
