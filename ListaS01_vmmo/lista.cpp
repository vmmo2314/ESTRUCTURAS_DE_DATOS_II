#include "Lista.hpp"

Node::Node(){
    next = nullptr;
}

Node::Node(string n, string c, string ca){
    nombre = n;
    codigo = c;
    carrera = ca;
    next = nullptr;
}


string Node::getNombre()
{
    return nombre;
}

Node* Node::getNext()
{
    return next;
}

void Node::setNombre(string d)
{
    nombre = d;
}

string Node::getCodigo()
{
    return codigo;
}

void Node::setCodigo(string code)
{
    codigo = code;
}

string Node::getCarrera()
{
    return carrera;
}

void Node::setCarrera(string career)
{
    carrera = career;
}


void Node::setNext(Node* p)
{
    next = p;
}

ListaSimple::ListaSimple(){      ///constructor de la lista
ancla = nullptr;
}

bool ListaSimple::isValidPos(Node* p)           ///Mientras la posicion sea valida, retorna verdadero
{
    Node* aux(ancla);               ///se crea un nuevo nodo tomando el valor del puntero ancla para así conocer toda la lista

    while(aux != nullptr){
        if(aux == p){
        return true;
        }
    aux = aux->getNext();
    }
return false;
}

bool ListaSimple::vacia()
{
    if(ancla == nullptr){
        return true;
    }
    else{
        return false;
    }
}

void ListaSimple::insertDataFinal(string n, string c, string ca)
{
 Node* nuevo = new Node(n, c, ca);
 nuevo->setNext(nullptr);

    if(ancla == nullptr){
     ancla = nuevo;
    }
    else{
     Node* aux = ancla;
     while (aux->getNext() != nullptr){
     aux = aux->getNext();
     }
     aux->setNext(nuevo);
    }
}


void ListaSimple::insertDataInicio(string nombre, string codigo, string carrera)      ///Recibe datos y lo inserta al inicio
{
Node *Nuevo_nodo = new Node(nombre, codigo, carrera);
    if(ancla == nullptr){
        Nuevo_nodo->setNext(nullptr);
    }else{
        Nuevo_nodo->setNext(ancla);
    }
    ancla = Nuevo_nodo;
}

void ListaSimple::printData()
{
    if(!vacia()){
        Node* aux;
        aux = ancla;

        while(aux != nullptr){
          cout << aux->getNombre() + " "<<aux->getCodigo() + " "<<aux->getCarrera()<<endl;
          aux = aux->getNext();
        }
      }
    else{
    cout<<"La lista se encuentra vacia"<<endl;
    }
}


void ListaSimple::deleteData(Node* p)
{
    if(p == ancla){
    ancla = ancla->getNext();   ///cuando el dato a eliminar es el primero en la lista
    }

    else{
    getPrevPos(p)->setNext(p->getNext());   ///al dato previo a eliminar en la lista se le asigna la direccion
                                            ///del dato siguiente a eliminar
    }
    delete p;
}

void ListaSimple::deleteAll()
{
    ancla = nullptr;
}

Node* ListaSimple::getFirstPos()
{
    return ancla;
}

Node* ListaSimple::getLastPos()
{
    if(vacia()){      ///si la lista está vacía regresa nulo
    return nullptr;
    }
    Node* aux(ancla);

    while(aux->getNext() != nullptr){  ///itera mientras no llegue al ultimo elemento en la lista
        aux = aux->getNext();          ///pues el ultimo elemento siempre apunta a nulo
    }
    return aux;
}

Node* ListaSimple::getPrevPos(Node* p)
{
    if(!isValidPos(p)){     ///verifica si la posicion recibida es valida
    return nullptr;
    }

    Node* aux(ancla);

    while(aux != nullptr and aux->getNext()!= p){
     aux = aux->getNext();
    }
    return aux;
}

Node* ListaSimple::getNextPos(Node* p)
{
    if(!isValidPos(p)){     ///verifica si la posicion recibida es valida
    return nullptr;
    }

    return p->getNext();
}

Node* ListaSimple::buscarDato(string d)
{
Node* aux(ancla);

    while(aux != nullptr){
        if(aux->getNombre() == d){
        cout<<"Dato encontrado"<<endl;
        system("pause");
        return aux;
        }
    aux = aux->getNext();
    }
    return nullptr;
}

void ListaSimple::cargarDatos()
{
fstream archivo;
string datoAux, datoAux2, datoAux3;

archivo.open("file01.txt", ios::in);

    if(!archivo.good()){                    ///Validación en caso de que el archivo no abra correctamente
    cout<<"error al abrir el archivo"<<endl;
    system("pause>>cls");
    return;
    }

    getline(archivo, datoAux, '|');
    getline(archivo, datoAux2, '|');
    getline(archivo, datoAux3, '*');
while (!archivo.eof()) {
    insertDataInicio(datoAux, datoAux2, datoAux3);
    getline(archivo, datoAux, '|');
    getline(archivo, datoAux2, '|');
    getline(archivo, datoAux3, '*');
}
archivo.close(); // cerrar archivo
}

void ListaSimple::guardarDatos()
{
Node* aux(ancla);
fstream archivo, dAux;
string DatoAux ,DatoAux1, DatoAux2;

archivo.open("file01.txt", ios::app);
dAux.open("temporal.txt", ios::app);

    if(dAux.fail() or archivo.fail()){                    ///Validación en caso de que el archivo no abra correctamente
    cout<<"error al abrir el archivo"<<endl;
    //system("pause<<cls");
    //return;
    }

    while(aux != nullptr){
        DatoAux = aux->getNombre();
        DatoAux1 = aux->getCodigo();
        DatoAux2 = aux->getCarrera();
        dAux << DatoAux << "|" << DatoAux1 << "|" << DatoAux2 << "*";
        aux = aux->getNext();
        }

dAux.close();
archivo.close();

remove("file01.txt");
rename("temporal.txt", "file01.txt");
}

void ListaSimple::modificarDatos(){
    Node* posicion;
    string auxiliar;
    cout << "Digita el nombre a modificar: " <<endl; cin>>auxiliar;
    posicion = buscarDato(auxiliar);
    if(posicion == nullptr){
        cout <<"Dato no encontrado..."<<endl;
        return;
        }
    cout<< "Escribe el nuevo nombre para: " <<posicion->getNombre()<<endl;
    cin>>auxiliar;
    posicion->setNombre(auxiliar);
    cout<< "Escribe el nuevo codigo para: " <<posicion->getNombre()<<endl;
    cin>>auxiliar;
    posicion->setCodigo(auxiliar);
    cout<< "Escribe la nueva carrera para: " <<posicion->getNombre()<<endl;
    cin>>auxiliar;
    posicion->setCarrera(auxiliar);
    cout<<"Datos modificados correctamente..."<<endl;
}


