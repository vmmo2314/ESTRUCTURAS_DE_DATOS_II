#include "Grafo.h"
#include <fstream>

bool hGrafoB = true;
Grafo::Grafo()
{
	hGrafo = NULL;
}

Vertice* Grafo::buscarVertice(alumno nombre)
{
	Vertice* i = hGrafo;

	while (i != NULL)
	{
		if (i->nombre.getNombre() == nombre.getNombre())
			return i;

		i = i->sig;
	}

	return nullptr;
}

void Grafo::InsertarVertice(alumno nombre)
{
	if (buscarVertice(nombre) == nullptr){
        Vertice* nuevo = new Vertice(nombre);
        if(hGrafo == NULL && hGrafoB){
            hGrafo = nuevo;
            hGrafoB = false;
            }
        else{
        Vertice* i = hGrafo;
        while (i->sig != nullptr && !hGrafoB)
            i = i->sig;
            i->sig = nuevo;
        }
	}
	else{
		cout << "Vertice ya existente..." << endl;
    }
}

void Grafo::InsertarArista(alumno ori, alumno dest, int precio)
{
	Vertice* vori = buscarVertice(ori);
	Vertice* vdest = buscarVertice(dest);

	if (vori == NULL)
		cout << "El vertice origen no existe" << endl;

	if (vdest == NULL)
		cout << "El vertice destino no existe" << endl;

	if (vori != NULL && vdest != NULL)
	{
		Arista* nueva = new Arista(vdest, precio);

		if (vori->ari == NULL)
			vori->ari = nueva;
		else
		{
			Arista* j = vori->ari;

			while (j->sig != NULL)
				j = j->sig;

			j->sig = nueva;
		}
	}
}

void Grafo::MostrarListaAdyacencia()
{
	Vertice* i = hGrafo;

	while (i != nullptr){
		Arista* j = i->ari;
		cout << i->nombre.getNombre() << " = ";

		while (j != nullptr){
            cout <<i->nombre.getNombre()<< "|" << i->nombre.getCarrera() << "|" << i->nombre.getCodigo() << "|" << "distancia: "<< j->precio << "-->" << j->dest->nombre.getNombre()<<"|"<< j->dest->nombre.getCodigo()<<"|"<< j->dest->nombre.getCarrera() << "*";
            j = j->sig;
		}
		cout << endl;
		i = i->sig;
	}
}

void Grafo::EliminarAristas(Vertice* vertice)
{
	if (vertice == nullptr)
		return;

	Arista* i = vertice->ari;

	while (vertice->ari != nullptr)
	{
		i = vertice->ari;
		vertice->ari = vertice->ari->sig;
		cout << "Arista " << vertice->nombre.getNombre() << "|" << vertice->nombre.getCodigo() <<"|"<<vertice->nombre.getCarrera() << i->dest->nombre.getNombre() << " eliminada" << endl;
		delete(i);
	}
}

void Grafo::EliminarVertice(alumno nombre)
{
	if (hGrafo->nombre.getNombre() == nombre.getNombre())
	{
		Vertice* i = hGrafo;
		hGrafo = hGrafo->sig;
		EliminarAristas(i);
		cout << "Vertice " << nombre.getNombre() << " fue eliminado" << endl;
		system("Pause");
		delete(i);
	}
	else
	{
		Vertice* i = hGrafo;
		Vertice* j = i->sig;
		bool existe = false;

		while (j != nullptr)
		{
			if (j->nombre.getNombre() == nombre.getNombre())
			{
				i->sig = j->sig;
				EliminarAristas(j);
				cout << "Vertice " << nombre.getNombre() << " fue eliminado" << endl;
				delete(j);
				existe = true;
				break;
			}

			i = j;
			j = j->sig;
		}

		if (!existe)
			cout << "El vertice especificado no existe" << endl;
	}
}

void Grafo::EliminarArista(alumno ori, alumno dest)
{
	Vertice* vori = buscarVertice(ori);
	Vertice* vdest = buscarVertice(dest);

	if (vori == nullptr or vdest == nullptr){
		cout << "El vertice origen no existe" << endl;
		system("pause");
		return;
    }
	else
	{
		if(vori->ari->dest->nombre.getNombre() == vdest->nombre.getNombre())
		{
			Arista* i = vori->ari;
			vori->ari = vori->ari->sig;
			cout << "Arista " << ori.getNombre() << "->" << dest.getNombre() << " eliminada" << endl;
			delete(i);
		}
		else
		{
			Arista* i = vori->ari;
			Arista* j = i->sig;

			while (j != nullptr)
			{
				if (j->dest->nombre.getNombre() == vdest->nombre.getNombre())
				{
					i->sig = j->sig;
					cout << "Arista " << ori.getNombre() << "->" << dest.getNombre() << " eliminada" << endl;
					delete(j);
					break;
				}

				i = j;
				j = j->sig;
			}
		}
	}
}

void Grafo::EliminarTodo()
{
	Vertice* i = hGrafo;

	while (hGrafo != NULL)
	{
		i = hGrafo;
		hGrafo = hGrafo->sig;
		EliminarAristas(i);
		delete(i);
	}
	cout <<"Se han eliminado los datos correctamente"<<endl;
}

void Grafo::ListaAdyacenciaGuardarEnArchivo()
{
    ofstream archivoVertices("file01Vertices.txt");
    // Guardar información de los vértices
    Vertice* i = hGrafo;
    while (i != nullptr){
        archivoVertices << i->nombre.getNombre() << "|" << i->nombre.getCarrera() << "|" << i->nombre.getCodigo() << "*";
        i = i->sig;
    }
    ofstream archivoAristas("file01Aristas.txt");
    // Guardar información de las aristas
    i = hGrafo;
    while (i != nullptr){
        Arista* j = i->ari;
        while (j != nullptr){
            archivoAristas << i->nombre.getNombre() << "|" << j->precio << "|" << j->dest->nombre.getNombre() << "*";
            j = j->sig;
        }
        i = i->sig;
    }
    archivoAristas.close();
    cout << "La lista de adyacencia se ha guardado en el archivo " << endl;
}

void Grafo::cargarArchivo()
{
    alumno myAlumno;
    fstream archivoVertices, archivoAristas;
    string datoAux, datoAux2, datoAux3, asterisco;
    archivoVertices.open("file01Vertices.txt", ios::in);
    archivoAristas.open("file01Aristas.txt", ios::in);

    if(!archivoVertices.good() or !archivoAristas.good()){                    ///Validación en caso de que el archivo no abra correctamente
    cout<<"error al abrir el archivo"<<endl;
    system("pause>>cls");
    return;
    }

    getline(archivoVertices, datoAux, '|'); //nombre
    myAlumno.setNombre(datoAux);
    getline(archivoVertices, datoAux2, '|');//carrera
    myAlumno.setCarrera(datoAux2);
    getline(archivoVertices, datoAux3, '*');//codigo
    myAlumno.setCodigo(datoAux3);
while (!archivoVertices.eof()) {
    InsertarVertice(myAlumno);
    getline(archivoVertices, datoAux, '|'); //nombre
    myAlumno.setNombre(datoAux);
    getline(archivoVertices, datoAux2, '|');//carrera
    myAlumno.setCarrera(datoAux2);
    getline(archivoVertices, datoAux3, '*');//codigo
    myAlumno.setCodigo(datoAux3);
}
archivoVertices.close(); // cerrar archivo
    alumno myAlumnoDestino;
    getline(archivoAristas, datoAux, '|'); //nombre origen
    myAlumno.setNombre(datoAux);
    getline(archivoAristas, datoAux2, '|');//peso
    int pesoAux = stoi(datoAux2); //conversion de string int para el peso
    getline(archivoAristas, datoAux3, '*');//nombre destino
    myAlumnoDestino.setNombre(datoAux3);
while (!archivoAristas.eof()) {
    InsertarArista(myAlumno, myAlumnoDestino, pesoAux);
    getline(archivoAristas, datoAux, '|'); //nombre origen
    myAlumno.setNombre(datoAux);
    getline(archivoAristas, datoAux2, '|');//peso
    int pesoAux = stoi(datoAux2); //conversion de string int para el peso
    getline(archivoAristas, datoAux3, '*');//nombre destino
    myAlumnoDestino.setNombre(datoAux3);
}
archivoAristas.close(); // cerrar archivo
}

