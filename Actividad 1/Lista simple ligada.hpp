#ifndef LISTA_SIMPLE_LIGADA_HPP_INCLUDED
#define LISTA_SIMPLE_LIGADA_HPP_INCLUDED

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Node{
    private:
            string nombre;
            string apellido;
            string juego;
            Node* sig;
    public:
            Node(string,string,string);

            string getNombre();
            string getApellido();
            string getJuego();
            Node* getSig();

            void setNombre(string);
            void setApellido(string);
            void setJuego(string);
            void setSig(Node*);
};

class lista{
    private:
            Node* HEAD;
        public:

            lista();

            bool vacia();

            void insertDatoInicio(string,string,string);
            void insertDatoAlfinal(string,string,string);
            void imprimirDato();
            void modificarDato(Node*);

            void eliminardatoporposicion(Node*);
            void deleteAll();

            Node* getFirstPos();
            Node* getLastPos();
            Node* getPrevPos(Node*);
            Node* getNextPos(Node*);

            Node* buscarDato(string);

            void cargarDatos();
            void guardarDatos();
};

#endif // LISTA_SIMPLE_LIGADA_HPP_INCLUDED
