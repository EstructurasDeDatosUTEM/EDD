#ifndef COLA_H
#define COLA_H

class Cola {
    public:
        class Nodo {
			public:
				Nodo(const int& e, Nodo *p) : dato(e), link(p) {}
				~Nodo() { }
				int dato;
				Nodo *link;
		};
        Cola();
        virtual ~Cola();
        void agregar(int e);
		int extraer();
		bool vacia();

    private:
        Nodo *mPrimero;
		Nodo *mUltimo;
};

#endif // COLA_H
