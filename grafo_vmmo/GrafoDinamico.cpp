#include <iostream>

#include "Grafo.h"
#include "alumno.hpp"
using namespace std;
int main()
{
	Grafo* grafo = new Grafo();
	int opc = 0;

	while (opc != 9){
		system("cls");
		cout << "1. Insertar vertice" << endl;
		cout << "2. Insertar arista" << endl;
		cout << "3. Mostrar lista de adyacencia" << endl;
		cout << "4. Eliminar vertice" << endl;
		cout << "5. Eliminar arista" << endl;
		cout << "6. Eliminar todo" << endl;
		cout << "7. Guardar todo" << endl;
		cout << "8. Cargar todo" << endl;
		cout << "9. Salir" << endl;
		cout << endl;
		cout << "Ingrese una opcion del menu: ";
		cin >> opc;

		system("cls");

		switch (opc){
            case 1:{
                alumno myAlumno;
                string aux;
                cout << "Ingrese el nombre del vertice: ";
                cin.ignore();
                getline(cin, aux);
                myAlumno.setNombre(aux);
                cout << "Ingrese codigo: ";
                getline(cin, aux);
                myAlumno.setCodigo(aux);
                cout << "Ingrese carrera: ";
                getline(cin, aux);
                myAlumno.setCarrera(aux);
                grafo->InsertarVertice(myAlumno);
                break;
            }
            case 2:{
                alumno ori, dest;
                int precio;
                string aux;
                cout << "Ingrese el nombre del vertice origen: ";
                cin.ignore();
                getline(cin, aux);
                ori.setNombre(aux);
                cout << "Ingrese el nombre del vertice destino: ";
                getline(cin, aux);
                dest.setNombre(aux);
                cout << "Ingrese el precio: ";
                cin >> precio;
                grafo->InsertarArista(ori, dest, precio);
                break;
            }
            case 3:{
                grafo->MostrarListaAdyacencia();
                system("pause");
                break;
            }
            case 4:{
                alumno nombre;
                string aux;
                cout << "Ingrese el nombre del vertice a eliminar: ";
                getline(cin, aux);
                nombre.setNombre(aux);
                grafo->EliminarVertice(nombre);
                break;
            }
            case 5:{
                alumno ori, dest;
                string aux;
                cout << "Ingrese el nombre del vertice origen: ";
                getline(cin, aux);
                ori.setNombre(aux);
                cout << "Ingrese el nombre del vertice destino: ";
                getline(cin, aux);
                dest.setNombre(aux);

                grafo->EliminarArista(ori, dest);
                break;
            }
            case 6:{
                grafo->EliminarTodo();
                break;
            }
            case 7:{
                cout<< "Guardando en archivo..." <<endl;
                grafo->ListaAdyacenciaGuardarEnArchivo();
                break;
            }
            case 8:{
                cout<< "Cargando de archivo..." <<endl;
                grafo->cargarArchivo();
                cout<< "Archivo cargado correctamente :)" << endl;
                break;
            }
        }
    }
}

