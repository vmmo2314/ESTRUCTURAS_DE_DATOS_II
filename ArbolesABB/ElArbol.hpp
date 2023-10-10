#ifndef ELARBOL_HPP
#define ELARBOL_HPP

#include "Nodo.hpp"
#include "Persona.hpp"

class ElArbol
{
private:
    Nodo* raiz;
public:

    void insetarDato(Nodo*, Nodo*, Persona);

    Nodo* encontrarDato(Nodo*,Persona);
    Nodo* elmasIzq(Nodo*);
    Nodo* elmasDer(Nodo*);

    void inOrder(Nodo*);
    void preOrder(Nodo*);
    void postOrder(Nodo*);
    void eliminarTodo(Nodo*);
    void eliminarDato(Persona);

    ElArbol();
    ~ElArbol();

    int Altura(Nodo*);
    bool hoja(Nodo*);
    bool vacio();

    Nodo* getRaiz();
    void setRaiz(Nodo*);
    Persona Dato(Nodo*);
};

#endif // ELARBOL_HPP
