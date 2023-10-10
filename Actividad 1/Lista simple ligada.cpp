#include "Lista simple ligada.hpp"
Node::Node(string a, string b, string c){
    nombre = a;
    apellido = b;
    juego = c;
    sig = nullptr;
}


string Node::getNombre()
{
    return nombre;
}

string Node::getApellido()
{
    return apellido;
}

string Node::getJuego()
{
    return juego;
}

Node* Node::getSig()
{
    return sig;
}

void Node::setNombre(string a)
{
    nombre = a;
}
void Node::setApellido(string a)
{
    apellido = a;
}
void Node::setJuego(string a)
{
    juego = a;
}

void Node::setSig(Node* a)
{
    sig = a;
}

lista::lista(){
    HEAD = nullptr;
}

bool lista::vacia()
{
    if( HEAD == nullptr){
        return true;
    }
    else{
        return false;
    }
}

void lista::insertDatoInicio(string nombreaux,string apellidoaux,string juegoaux)
{
Node *Nuevo_nodo = new Node(nombreaux,apellidoaux,juegoaux);
    if(HEAD == nullptr){
        Nuevo_nodo->setSig(nullptr);
    }else{
        Nuevo_nodo->setSig(HEAD);
    }
    HEAD = Nuevo_nodo;
}
void lista::insertDatoAlfinal(string nombreaux,string apellidoaux,string juegoaux)
{
Node *Nuevo_nodo = new Node(nombreaux,apellidoaux,juegoaux);
Node *Tail;
Tail = getLastPos();

    if(HEAD == nullptr){
        HEAD = Nuevo_nodo;
    }else{
        Tail->setSig(Nuevo_nodo);
    }
}

void lista::imprimirDato()
{

    if(!vacia()){
        Node* aux;
        aux = HEAD;
        while(aux != nullptr){
            cout<<"------------------------------------------"<<endl;
          cout << aux->getNombre()<<" "<<aux->getApellido()<<" "<<aux->getJuego()<<endl;
        cout<<"------------------------------------------"<<endl;
          aux = aux->getSig();
        }
      }
    else{
    cout<<"Lista vacia"<<endl;
    }
    system("pause");
}


void lista::eliminardatoporposicion(Node* p)
{
    if(p == HEAD){
    HEAD = HEAD->getSig();
    }
    else{
    getPrevPos(p)->setSig(p->getSig());
    }
    delete p;
}

void lista::deleteAll()
{
    HEAD = nullptr;
}

Node* lista::getFirstPos()
{
    return HEAD;
}

Node* lista::getLastPos()
{
    if(vacia()){
    return nullptr;
    }
    Node* aux = HEAD;

    while(aux->getSig() != nullptr){
        aux = aux->getSig();
    }
    return aux;
}

Node* lista::getPrevPos(Node* p)
{
    Node* aux = HEAD;

    while(aux != nullptr and aux->getSig()!= p){
     aux = aux->getSig();
    }
    return aux;
}

Node* lista::getNextPos(Node* p)
{
    return p->getSig();
}

Node* lista::buscarDato(string d)
{
Node* aux = HEAD;

    while(aux != nullptr){
        if(aux->getNombre() == d){
                cout<<"------------------------------------------"<<endl;
          cout << aux->getNombre()<<" "<<aux->getApellido()<<" "<<aux->getJuego()<<endl;
        cout<<"------------------------------------------"<<endl;
        return aux;
        }
    aux = aux->getSig();
    }
    return nullptr;
}

void lista::modificarDato(Node* p)
{
    string dato, dato2, dato3;
    cout<<"Escribe el Nombre a insertar"<<endl; cin>>dato;
    cout<<"Escribe el Apellido a insertar"<<endl; cin>>dato2;
    cout<<"Escribe el Juego a insertar"<<endl; cin>>dato3;
    p->setNombre(dato);p->setApellido(dato2);p->setJuego(dato3);
}

void lista::cargarDatos()
{
    string data;
    string aux_Nombre,aux_Apellido,aux_Juego;
    ifstream archivo("file01.txt",ios::in);
    if(archivo.good()){
            getline(archivo, aux_Nombre,'|');
            getline(archivo, aux_Apellido,'|');
            getline(archivo, aux_Juego,'*');
            while(!archivo.eof()){
            insertDatoAlfinal(aux_Nombre,aux_Apellido,aux_Juego);
            getline(archivo, aux_Nombre,'|');
            getline(archivo, aux_Apellido,'|');
            getline(archivo, aux_Juego,'*');
        }
    }else{
        return;
    }
    archivo.close();
}

void lista::guardarDatos()
{
        Node* aux = HEAD;
            fstream archivo("file01.txt",ios::out);
            if(archivo.good()){
            while(aux != nullptr){
                string aux_Nombre,aux_Apellido,aux_Juego;
                aux_Nombre = aux->getNombre()+'|';
                aux_Apellido = aux->getApellido()+'|';
                aux_Juego = aux->getJuego()+'*';
                archivo << aux_Nombre << aux_Apellido << aux_Juego;
                aux = aux->getSig();
                }
            }
        archivo.close();
}
