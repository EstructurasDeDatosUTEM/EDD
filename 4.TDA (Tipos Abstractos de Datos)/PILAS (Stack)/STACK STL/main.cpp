using namespace std;
#include <iostream>
/**Clase Persona**/
class Personaje {
public:
    Personaje(string _nombre) : m_nombre(_nombre) {};
    ~Personaje();
    string GetNombre(){
        return m_nombre;
    }
private:
    string m_nombre;
};

#include <stack>
typedef Personaje TipoStack;
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



    while (!myStack.Empty()) {
        cout <<myStack.Pop()<<endl;
    }

    //cout << "Hello world!" << endl;
    return 0;
}
