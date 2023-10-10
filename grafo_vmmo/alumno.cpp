#include "alumno.hpp"

void alumno::setNombre(string n)
{
    nombre = n;
}

void alumno::setCodigo(string c)
{
    codigo = c;
}

void alumno::setCarrera(string c)
{
    carrera = c;
}

string alumno::getNombre()
{
    return nombre;
}

string alumno::getCodigo()
{
    return codigo;
}

string alumno::getCarrera()
{
    return carrera;
}

string alumno::toString()
{
    return nombre + "|" + codigo + "|" + carrera;
}

string alumno::toStringSinSeparadores()
{
    return nombre + ", " + codigo + ", " + carrera;
}

bool alumno::comparar_nombres(alumno a, alumno b)
{
    return a.nombre < b.nombre;
}

bool alumno::compararIgualdad(alumno a, alumno b)
{
    return a.nombre == b.nombre;
}


