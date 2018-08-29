#include "Cola.h"
#define NULL 0
Cola::Cola() : mPrimero(NULL), mUltimo(NULL) {}
Cola::~Cola() { }

void Cola::agregar(int e) {
	Nodo *p = new Nodo(e, NULL);
	if(vacia()) {
		mPrimero = p;
		mUltimo = mPrimero;
		return;
	}
	mUltimo->link = p;
	mUltimo = p;
}

int Cola::extraer() {
	if(vacia())
		return int();

	Nodo *p = mPrimero;
	int e = mPrimero->dato;

	mPrimero = mPrimero->link;
	delete p;
	return e;
}

bool Cola::vacia() {
	return !(mPrimero);
}
