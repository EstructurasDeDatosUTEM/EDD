 #include <iostream>

using namespace std;



#define MAX 100



class Heap {

    public:

        /** Default constructor */

        Heap();

        /** Default destructor */

        virtual ~Heap();

        void agregar(string, int);  //agrega elemento , prioridad

        string extraer();  //solo retorna el elemento

        bool vacio();

    protected:

    private:

        class DatoPrivado {

public:

   string nombre;

int prioridad;

int dato;

};

        DatoPrivado Vector[MAX];

        int Ultimo;

        void Subir();

        void Bajar();

};



/**IMPLEMENTACION**/

Heap::Heap()  {

    Ultimo = 0;

}



Heap::~Heap() {

}



bool Heap::vacio() {

return (Ultimo == 0);

}



void Heap::Subir() {

    /*En el método flotar(SUBIR) el nodo dado se compara con su nodo

    padre y se realiza el intercambio si éste es mayor que el padre,

    iterando este paso mientras sea necesario*/

int k, i;

DatoPrivado aux;

aux = Vector[Ultimo];

Vector[0] = Vector[Ultimo];

i = Ultimo; /**Última Posicion**/

k = i/2; /**posición del padre**/

/**Recorre el arreglo hasta que organiza las prioridades**/

/**Mientras el padre sea mayor que el hijo**/

while (Vector[k].prioridad > aux.prioridad) {

        //Al hijo le asigno la posición del padre

Vector[i] = Vector[k];

i = k; //Posición del Padre Anterior

k = i/2; //Posición del nuevo padre

}

//nueva Posición del padre

Vector[i] = aux;

}



void Heap::Bajar() {

int k, i;

bool fin;

DatoPrivado aux;

aux = Vector[1];

k = 1;

i = k*2;

fin = false;

while ((k <= Ultimo/2)&&(!fin)) {

if(i < Ultimo) {

if(Vector[i+1].prioridad < Vector[i].prioridad)

i++;

}

if(aux.prioridad > Vector[i].prioridad) {

Vector[k] = Vector[i];

k = i;

i = k*2;

}

else

fin = true;

}

Vector[k] = aux;

}



void Heap::agregar(string intDato, int intPrioridad) {

    /*

    Cómo añadir un nuevo elemento?

    1 Colocar el nuevo elemento como último elemento del

    montículo(Heap), justo a la derecha del último o como primero de

    un nuevo nivel.

    2 Reestablecer el orden de montıculo flotando(Subiendo) el elemento

    recién añadido

    En el método flotar(SUBIR) el nodo dado se compara con su nodo

    padre y se realiza el intercambio si éste es mayor que el padre,

    iterando este paso mientras sea necesario

    */

    DatoPrivado aux;

aux.prioridad   = intPrioridad;

aux.nombre        = intDato;



Ultimo++;

Vector[Ultimo] = aux;

Subir();

}



string Heap::extraer() {

    string x = Vector[1].nombre;

Vector[1] = Vector[Ultimo];

Ultimo--;

Bajar();

return x;

}



/**FUNCIONES EXTERNAS**/

void llenar(int A[], int n){

    int i;

    for(i=0; i<n; i++){

        cout << "Dato  " << i << " : ";

        cin >> A[i];

    }

}



void imprimir(int A[], int n){

    int i;

    cout << "arreglo..." << endl;

    for(i=0; i<n; i++){

        cout << "Arreglo[" << i << "] = " << A[i] << endl;

    }

}



//Ordena un arreglo, utilizando un Heap como TAD auxiliar

/*void HeapSort( A[], int n){

    Heap H;

    int i, k, e;

    for(i=0; i<n; i++){

        H.agregar(A[i],A[i]);

    }

    k=0;

    while( ! H.vacio()){

        e = H.extraer();

        A[k++] = e;

    }

}*/











int main() {

    cout << "Heap" << endl;

    Heap H;
    H.agregar("Hector " ,10);
    H.agregar("Maria " ,1);
    H.agregar("Pedro" ,5);
    H.agregar("Don Juan " ,3);
    H.agregar("Rogelio " ,10);
    H.agregar("Roberto " ,10);
    H.agregar("Marco " ,10);
    H.agregar("Rosa" ,1);
    H.agregar("Viviana " ,2);

    cout << "x = " << H.extraer() << endl;
    cout << "x = " << H.extraer() << endl;
    cout << "x = " << H.extraer() << endl;
    cout << "x = " << H.extraer() << endl;
    cout << "x = " << H.extraer() << endl;
    cout << "x = " << H.extraer() << endl;
    cout << "x = " << H.extraer() << endl;
    cout << "x = " << H.extraer() << endl;
    cout << "x = " << H.extraer() << endl;



    return 0;

}
