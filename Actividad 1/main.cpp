#include <iostream>
#include "Lista simple ligada.hpp"
#include <string>
#include <fstream>

int menu();

using namespace std;

int main()
{
    int opc;
    string dato;
    string dato2;
    string dato3;
    lista l;
    do{
    opc = menu();
    switch(opc){
    case 1:{
    cout<<"Escribe el Nombre a insertar"<<endl; cin>>dato;
    cout<<"Escribe el Apellido a insertar"<<endl; cin>>dato2;
    cout<<"Escribe el Juego a insertar"<<endl; cin>>dato3;
    l.insertDatoInicio(dato,dato2,dato3);
    }
    break;

    case 2:{
    cout<<"Escribe el Nombre a insertar"<<endl; cin>>dato;
    cout<<"Escribe el Apellido a insertar"<<endl; cin>>dato2;
    cout<<"Escribe el Juego a insertar"<<endl; cin>>dato3;
    l.insertDatoAlfinal(dato,dato2,dato3);
    }
    break;

    case 3:{
    Node* aux;
    cout<<"Escribe el dato a eliminar"<<endl; cin>>dato;
    aux = l.buscarDato(dato);
    if(aux == nullptr){
        cout<<"Dato no encontrado"<<endl;
        break;
        }
    l.eliminardatoporposicion(aux);
    cout<<"Dato eliminado"<<endl;
    }
    break;

    case 4:{
    l.imprimirDato();
    }
    break;

    case 5:{
        cout<<"Escribe el dato a buscar"<<endl; cin>>dato;
        Node* aux;
        aux = l.buscarDato(dato);
        if(aux == nullptr){
        cout<<"Dato no encontrado"<<endl;
        }
    system("pause");
    }
    break;

    case 6:{
    l.deleteAll();
    system("cls");
    }
    break;
    case 7:{
            Node* aux;
            cout<<"Escribe el dato a buscar"<<endl; cin>>dato;
            aux = l.buscarDato(dato);
            if(aux == nullptr){
            cout<<"Dato no encontrado"<<endl;
            }else{
            l.modificarDato(aux);
            }
        }
    break;
    case 8:{
        l.cargarDatos();
        cout<<"Datos cargados Correctamente"<<endl;
        }
    break;
    case 9:{
        l.guardarDatos();
        cout<<"Datos Guardados Correctamente"<<endl;
        }
    break;
    case 0:{
    }
    break;
    }
    system("cls");
    }while(opc != 0);
}

int menu(){
int opc;
cout<<"1)Insertar al inicio"<<endl;
cout<<"2)Insertar al final"<<endl;
cout<<"3)Eliminar por posicion"<<endl;
cout<<"4)Imprimir datos"<<endl;
cout<<"5)Buscar dato"<<endl;
cout<<"6)Eliminar lista"<<endl;
cout<<"7)Modificar dato"<<endl;
cout<<"8)Cargar"<<endl;
cout<<"9)Guardar"<<endl;
cout<<"0)Salir"<<endl;
cin>>opc;
return opc;
}
