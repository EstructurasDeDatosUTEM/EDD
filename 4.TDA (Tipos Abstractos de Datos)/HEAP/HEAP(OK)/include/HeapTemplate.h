#ifndef HEAPTEMPLATE_H
#define HEAPTEMPLATE_H

#include <queue>
template <class T>
class HeapTemplate {
public:
    HeapTemplate() {};
    virtual ~HeapTemplate() {};

    void agregar(T dato, int prioridad) {
        ParPrioridadDato par;
        par.first = prioridad;
        par.second= dato;
        h2.push(par);
    };

    T extraer(){
        if(!h2.empty()) {
            ParPrioridadDato par = h2.top();
            h2.pop();
            return par.second;
        }
        return 0;
    }

    bool vacio() {
        return h2.empty();
    }

private:
    typedef std::pair<int, T> ParPrioridadDato; // Prioridad, orden

    class ComparePrioridad {
        public:
            bool operator() (ParPrioridadDato a, ParPrioridadDato b) {
                return a.first > b.first;
            }
    };
    std::priority_queue<ParPrioridadDato, std::vector<ParPrioridadDato>, ComparePrioridad> h2;
};


#endif // HEAPTEMPLATE_H
