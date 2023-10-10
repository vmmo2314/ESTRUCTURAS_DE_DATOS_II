#ifndef ARCHIVOS_HPP_INCLUDED
#define ARCHIVOS_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class archivos{
public:
    void menuArchivos();
    void agregar(int, int,string ,int ,string, int);
    void mostrar();
    void buscar();
    void modificar(string);
    void eliminar();
};

#endif // ARCHIVOS_HPP_INCLUDED
