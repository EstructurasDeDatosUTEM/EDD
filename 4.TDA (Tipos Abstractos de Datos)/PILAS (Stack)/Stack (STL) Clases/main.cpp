using namespace std;
#include <iostream>
/**Clase Persona**/
class Personaje {
public:
    Personaje(string _nombre) : m_nombre(_nombre) {};
    ~Personaje() {};
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

    //creo un personaje
    Personaje p("MarioBros");
    myStack.Push(p);

    myStack.Push(Personaje("Luigui"));
    myStack.Push(Personaje("Pitufos"));
    myStack.Push(Personaje("Pikachu"));

    while (!myStack.Empty()) {
        TipoStack temp = myStack.Pop();
        cout <<temp.GetNombre()<<endl;
    }

    return 0;
}
