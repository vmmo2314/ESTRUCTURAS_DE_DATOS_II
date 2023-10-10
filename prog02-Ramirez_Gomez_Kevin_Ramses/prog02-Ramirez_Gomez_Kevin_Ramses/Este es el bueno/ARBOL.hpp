#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "Nodo.hpp"

class ARBOL
{
    private:
        Nodo* raiz;

        void insertarDato(Nodo*,Persona);
        void preOrden(Nodo*);
        void inOrden(Nodo*);
        void postOrden(Nodo*);
        void eliminarDato(Nodo*);
        void cargarDatos();
        void guardaDatos(Nodo*);

        Nodo* buscarDato(Nodo*,Persona);
        Nodo* mayorDemenores(Nodo*);
        Nodo* menorDemayores(Nodo*);
        Nodo* getPadre(Nodo*, Nodo*);

        bool esHoja(Nodo*);

        int altura(Nodo*);
    public:
        ARBOL();
        void InsertarDato(Persona);
        void PreOrden();
        void Inorden();
        void PostOrden();
        void EliminarTodo();
        void EliminarDato(Nodo*);
        void Guardar();
        void Cargar();

        bool estaVacio();

        Nodo* BuscarDato(Persona);
        Nodo* MeyorDemenores();
        Nodo* MenorDemayores();

        int Altura();
};

#endif // ARBOL_HPP
