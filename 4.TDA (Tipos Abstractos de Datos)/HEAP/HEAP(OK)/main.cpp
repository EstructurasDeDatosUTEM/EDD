#include <iostream>

using namespace std;
#include "HeapTemplate.h"
typedef HeapTemplate <int>Heap;

#include "ColaTemplate.h"
typedef ColaTemplate <int>Cola;

#include "StackTemplate.h"
typedef StackTemplate <int>Stack;


int main()
{
    cout << "Heap" << endl;
    Heap h;
    h.agregar(1,5);
    h.agregar(2,4);
    h.agregar(3,3);
    h.agregar(4,2);
    h.agregar(5,1);

    while (!h.vacio())
        cout <<h.extraer()<<endl;

    cout << "Colas" << endl;
    Cola c;
    c.agregar(15);
    c.agregar(3);
    c.agregar(4);
    while (!c.vacio())
        cout <<c.extraer() << endl;

    cout << "Stack" << endl;
    Stack s;
    s.push(1);
    s.push(4);
    s.push(10);
    while(!s.empty())
        cout << s.pop()<<endl;

    Stack v[10]; //vector
    v[0] = s;
    v[1] = s;

    while (!v[0].empty())
        cout <<v[0].pop()<<endl;


    cout << "Hello world!" << endl;
    return 0;
}
