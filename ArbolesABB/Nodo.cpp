#include "Nodo.hpp"


Nodo::Nodo()
{
    datoPt = nullptr;
    izq = nullptr;
    der = nullptr;
    padre = nullptr;
}

Nodo::Nodo(Persona a, Nodo* b)
{
    datoPt = new Persona(a);
    izq = nullptr;
    der = nullptr;
    padre = b;
}

Nodo::~Nodo()
{
}

Persona* Nodo::getDatoPT()
{
    return datoPt;
}

Persona Nodo::getDato()
{
    return *datoPt;
}

Nodo* Nodo::getIzq()
{
    return izq;
}

Nodo* Nodo::getDer()
{
    return der;
}

Nodo* Nodo::getPadre()
{
    return padre;
}

void Nodo::setDatoPT(Persona* a)
{
    datoPt = a;
}

void Nodo::setDato(Persona a)
{
    *datoPt = a;
}

void Nodo::setIzq(Nodo* a)
{
    izq = a;
}

void Nodo::setDer(Nodo* a)
{
    der = a;
}

void Nodo::setPadre(Nodo* a)
{
    padre = a;
}
