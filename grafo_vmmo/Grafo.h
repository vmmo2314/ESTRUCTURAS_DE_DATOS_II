#include "Vertice.h"
#include "Arista.h"
#include "alumno.hpp"

using namespace std;

class Grafo
{
    alumno dato;
	Vertice* hGrafo;
public:
	Grafo();


	Vertice* buscarVertice(alumno); // Retornar el vertice que tenga el nombre especificado

	void InsertarVertice(alumno);
	void InsertarArista(alumno, alumno, int);
	void MostrarListaAdyacencia();
	void EliminarVertice(alumno);
	void EliminarAristas(Vertice*);
	void EliminarArista(alumno, alumno);
	void EliminarTodo();

	void ListaAdyacenciaGuardarEnArchivo();
	void cargarArchivo();
};

