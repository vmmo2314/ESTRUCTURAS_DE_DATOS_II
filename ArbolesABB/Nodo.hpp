#ifndef NODO_HPP
#define NODO_HPP

#include "Persona.hpp"
#include <iostream>

class Nodo
{
    private:
        Persona* datoPt;
        Nodo* izq;
        Nodo* der;
        Nodo* padre;
    public:
        Nodo();
        Nodo(Persona,Nodo*);
        ~Nodo();

        Persona* getDatoPT();
        Persona getDato();
        Nodo* getIzq();
        Nodo* getDer();
        Nodo* getPadre();

        void setDatoPT(Persona*);
        void setDato(Persona);
        void setIzq(Nodo*);
        void setDer(Nodo*);
        void setPadre(Nodo*);
};

#endif // NODO_HPP
