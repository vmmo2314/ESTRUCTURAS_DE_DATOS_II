#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <iostream>
using namespace std;

class Persona
{
    private:
        string nombre;
        string apellido;
        string juego;
    public:
        void setNombre(string);
        void setApellido(string);
        void setJuego(string);

        string getNombre();
        string getApellido();
        string getJuego();

        bool compararmenorque(Persona,Persona);
        bool compararIgualigual(Persona,Persona);
};

#endif // PERSONA_HPP
