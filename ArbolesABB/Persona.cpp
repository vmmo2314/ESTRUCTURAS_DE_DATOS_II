#include "Persona.hpp"

void Persona::setNombre(string a)
{
    nombre = a;
}

void Persona::setApellido(string a)
{
    apellido = a;
}

void Persona::setJuego(string a)
{
    juego = a;
}

string Persona::getNombre()
{
    return nombre;
}

string Persona::getApellido()
{
    return apellido;
}

string Persona::getJuego()
{
    return juego;
}

bool Persona::compararmenorque(Persona a, Persona b)
{
    return a.nombre < b.nombre;
}

bool Persona::compararIgualigual(Persona a, Persona b)
{
    return a.nombre == b.nombre;
}
