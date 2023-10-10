#include <iostream>
#include <string>
#include <fstream>
#include "lista.hpp"


using namespace std;

int main()
{
int opc;
string dato1;
string dato2;
string dato3;
ListaSimple myLista;
do{
cout<<endl<<endl<<"1)Insertar inicio      2)Eliminar dato"<<endl;
cout<<"3)Imprimir datos       4)Ultima posicion"<<endl;
cout<<"5)Buscar dato             6)Eliminar lista"<<endl;
cout<<"7)Primera posicion             8)Vacia?"<<endl;
cout<<"9)Insertar al final      10)Modificar"<<endl;
cout<<"11)Guardar en archivo      12)Leer de archivo"<<endl;
cout<<endl<<"0 para salir"<<endl;
cin>>opc;
switch(opc){
    case 1:{
    cout<<"Escribe el nombre a insertar"<<endl; cin>>dato1;
    cout<<"Escribe tu codigo"<<endl; cin>>dato2;
    cout<<"Escribe tu carrera"<<endl; cin>>dato3;
    myLista.insertDataInicio(dato1, dato2, dato3);
    cout<<"Datos insertados en la lista..."<<endl;
    system("pause");
    system("cls");
    }
    break;

    case 2:{
    //Eliminar dato
    Node* aux;
    cout<<"Escribe el nombre del alumno a eliminar"<<endl; cin>>dato1; ///Busca si existe el dato a eliminar
    aux = myLista.buscarDato(dato1);
    if(aux == nullptr){
        cout<<"Dato no encontrado"<<endl;
        system("pause");
        system("cls");
        break;
        }
    myLista.deleteData(aux);        ///Manda como referencia el nombre a eliminar y elimina el nodo completo
    cout<<"Dato eliminado"<<endl;
    system("pause");
    system("cls");
    }
    break;

    case 3:{
    //Imprimir datos de la lista
    system("cls");
    cout<<"Imprimiendo datos..."<<endl;
    myLista.printData();
    system("pause");
    system("cls");
    }
    break;

    case 4:{
    Node* p;
    string datos;
    cout<<"Imprimiendo ultimo dato..."<<endl<<endl;
    p = myLista.getLastPos();
    datos = p->getNombre() + p->getCodigo() + p->getCarrera();
    system("pause");
    system("cls");
    }
    break;

    case 5:{
    //Busqueda de dato por nombre

    cout<<"Digita el nombre a buscar"<<endl;cin>>dato1;
    Node* aux;
    aux = myLista.buscarDato(dato1);    //Busca por nombre
        if(aux == nullptr){
        cout<<"Dato no encontrado"<<endl;
        }
        else{
        cout<<"Dato: "<<dato1<<" si se encuentra en la lista."<<endl;
        }
    system("pause");
    system("cls");
    }
    break;

    case 6:{
    //Eliminar toda la lista
    cout<<"Eliminando lista..."<<endl;
    myLista.deleteAll();
    cout<<"Lista eliminada"<<endl;
    system("pause");
    system("cls");
    }
    break;

    case 7:{
    //Imprimir el primer dato
    Node* p;
    string datos;
    cout<<"Imprimiendo primer dato..."<<endl<<endl;
    p = myLista.getFirstPos();
    datos = p->getNombre() + p->getCodigo() + p->getCarrera();
    system("pause");
    system("cls");
    }
    break;

    case 8:{
    //Verificar si la lista está vacía
        if (myLista.vacia()== true){
            cout<<"La lista se encuentra vacia"<<endl;
            }
        else{
        cout<<"La lista no se encuentra vacia"<<endl;
        }
        system("pause");
        system("cls");
    }
    break;

    case 9:{
    //insercion al final
    cout<<"Escribe el nombre a insertar"<<endl; cin>>dato1;
    cout<<"Escribe tu codigo"<<endl; cin>>dato2;
    cout<<"Escribe tu carrera"<<endl; cin>>dato3;
    myLista.insertDataFinal(dato1 ,dato2, dato3);
    cout<<"Datos insertados en la lista"<<endl;
    system("pause");
    system("cls");
    }
    break;

    case 10:{
    myLista.modificarDatos();
    system("pause");
    system("cls");
    }
    break;

    case 11:{
    //Guardar en archivo
    if(myLista.vacia()){
        cout<<"Primero guarda datos en la lista"<<endl;
        break;
        }
    myLista.guardarDatos();
    cout<<"Datos guardados correctamente"<<endl;
    system("pause");
    system("cls");
    }
    break;

    case 12:{
    //Leer de archivo
    myLista.cargarDatos();
    cout<<"Datos cargados correctamente"<<endl;
    system("pause");
    system("cls");
    }
    break;

    case 0:{
    }
    break;
    }
}while(opc!=0);
}
