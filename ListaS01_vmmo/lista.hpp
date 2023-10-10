#ifndef LISTA_HPP_INCLUDED
#define LISTA_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node{
    private:
            string nombre;
            string codigo;
            string carrera;
            Node* next;
    public:
            Node();
            Node(string, string, string);

            string getNombre();
            string getCodigo();
            string getCarrera();
            Node* getNext();

            void setNombre(string);
            void setCodigo(string);
            void setCarrera(string);
            void setNext(Node*);
};

class ListaSimple{
    private:
        bool isValidPos(Node*);
        Node* ancla;
    public:
        ListaSimple();

        bool vacia();

        void insertDataInicio(string, string, string);
        void insertDataFinal(string, string, string);

        void printData();
        string returnData();

        void deleteData(Node*);
        void deleteAll();

        Node* getFirstPos();
        Node* getLastPos();
        Node* getPrevPos(Node*);
        Node* getNextPos(Node*);

        Node* buscarDato(string);

        void cargarDatos();
        void guardarDatos();
        void modificarDatos();
};


#endif // LISTA_HPP_INCLUDED
