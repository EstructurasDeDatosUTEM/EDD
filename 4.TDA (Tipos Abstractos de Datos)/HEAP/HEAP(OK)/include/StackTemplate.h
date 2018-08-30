#ifndef STACKTEMPLATE_H
#define STACKTEMPLATE_H

#include "stack"
template <class T>
class StackTemplate : private std::stack<T> {
public:
    StackTemplate(){};
    virtual ~StackTemplate(){};
    T pop();
    void push(T valor);
    bool empty();
};


template <class T>
T StackTemplate<T>::pop() {
    T valor = std::stack<T>::top();
    std::stack<T>::pop();
    return valor;
}

template <class T>
void StackTemplate<T>::push(T valor) {
    std::stack<T>::push(valor);
}

template <class T>
bool StackTemplate<T>::empty() {
    return std::stack<T>::empty();
}


#endif // STACKTEMPLATE_H
