#include "Nodo.hpp"

Nodo::Nodo(Persona p)
{
    datoPTR = p;
    hijoDerecho = hijoIzquierdo  = nullptr;
}

Nodo::Nodo(Persona a,Nodo* b,Nodo* c)
{
    datoPTR = a;
    hijoDerecho = b;
    hijoIzquierdo = c;
}

Nodo::~Nodo()
{

}

void Nodo::setHijoderecho(Nodo* a)
{
    hijoDerecho = a;
}

void Nodo::setHijoizquierdo(Nodo* a)
{
    hijoIzquierdo = a;
}

void Nodo::setDatoPTR(Persona a)
{
    datoPTR = a;
}

Nodo* Nodo::getHijoderecho()
{
    return hijoDerecho;
}

Nodo* Nodo::getHijoizquierdo()
{
    return hijoIzquierdo;
}

Persona Nodo::getDatoPTR()
{
    return datoPTR;
}
