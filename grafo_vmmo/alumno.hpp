#ifndef ALUMNO_HPP_INCLUDED
#define ALUMNO_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;
class alumno{
private:
    string nombre;
    string codigo;
    string carrera;

public:
    void setNombre(string);
    void setCodigo(string);
    void setCarrera(string);

    string getNombre();
    string getCodigo();
    string getCarrera();

    string toString();
    string toStringSinSeparadores();

    bool comparar_nombres(alumno, alumno);
    bool compararIgualdad(alumno, alumno);

};

#endif // ALUMNO_HPP_INCLUDED
