    #ifndef ABB_H
    #define ABB_H

    class ABB {
        public:
            class Nodo {
                public:
                    Nodo(int k, int e, Nodo *p, Nodo *q)
                        : key(k), info(e), izq(p), der(q) {}
                    ~Nodo() { }

                    int key;
                    int info;
                    Nodo *izq;
                    Nodo *der;
            };
            typedef Nodo *AB;
            //---------------------------
            ABB();
            virtual ~ABB();
            ABB(const ABB& other);
            void Ver();
            void Insertar(int, int);
            bool Existe(int);
            int Buscar(int);
            bool Vacio();
            int GetKey();
            int GetInfo();
            void Eliminar(int);

            /***/
            int hojas(AB T);

        private:
            AB B;
            void VerABB(AB);
            void InsertarABB(AB &, int, int);
            int BuscarABB(AB , int);
            void EliminarABB(AB &, int);
            void Mayor(AB &, AB &);
            void Menor(AB &, AB &);
    };

    #endif // ABB_H
