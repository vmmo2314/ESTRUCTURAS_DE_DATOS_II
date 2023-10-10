#include "alumno.hpp"
#include <iostream>

class Arista;

class Vertice
{
	alumno nombre;
	Vertice* sig;
	Arista* ari;

	friend class Grafo;
public:
	Vertice(alumno nombre);
};

