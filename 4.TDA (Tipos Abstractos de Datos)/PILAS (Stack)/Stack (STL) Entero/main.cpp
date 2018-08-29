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

    while (!myStack.Empty()) {
        TipoStack temp = myStack.Pop();
        cout <<temp<<endl;
    }

    return 0;
}
