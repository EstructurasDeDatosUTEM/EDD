using namespace std;
#ifndef STACK_H
#define STACK_H

template <class T>
class Stack {
	public:
		class Nodo {
			public:
				Nodo(const T& e, Nodo *p) : dato(e), link(p) {}
				~Nodo() { }

				T dato;
				Nodo *link;
		};

		Stack();
		~Stack();

		void push(T e);
		T pop();

		bool empty();

	private:
		Nodo *mL;
};


template <class T>
Stack<T>::Stack() {
    mL = 0;
}

template <class T>
Stack<T>::~Stack() {
    T e;
	while(!empty())
		e = pop();
}

template <class T>
void Stack<T>::push(T e) {
	Nodo *p = new Nodo(e, 0);

	if(mL == 0) {
		mL = p;
	} else{
		p->link = mL;
		mL = p;
	}
}

template <class T>
T Stack<T>::pop() {
	Nodo *p = mL;
	T e;

	if(p == 0){
//		nada
	} else {
		e = mL->dato;
		mL = mL->link;
		delete p;
		return e;
	}
}

template <class T>
bool Stack<T>::empty() {
	return (mL == 0);
}

template <class T>
T sumar(Stack<T>& S) {
	T aux;
	T e;
	if(S.empty())
		return 0;
	else {
		e = S.pop();
		aux = e + sumar(S);
		S.push(e);
		return aux;
	}
}
/**/


#endif // STACK_H
