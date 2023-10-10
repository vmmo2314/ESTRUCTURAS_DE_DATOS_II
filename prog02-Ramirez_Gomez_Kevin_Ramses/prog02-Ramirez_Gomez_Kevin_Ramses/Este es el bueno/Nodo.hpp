#ifndef NODO_HPP
#define NODO_HPP

#include "Persona.hpp"
#include <iostream>
#include <cstring>
#include <fstream>

class Nodo
{
    private:
        Persona datoPTR;
        Nodo* hijoDerecho;
        Nodo* hijoIzquierdo;
    public:
    Nodo(Persona);
    Nodo(Persona,Nodo*,Nodo*);
    ~Nodo();

    void setHijoderecho(Nodo*);
    void setHijoizquierdo(Nodo*);
    void setDatoPTR(Persona);

    Nodo* getHijoderecho();
    Nodo* getHijoizquierdo();
    Persona getDatoPTR();
};

#endif // NODO_HPP
