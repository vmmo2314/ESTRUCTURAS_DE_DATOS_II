#include "ElArbol.hpp"
                            //papa  raiz    alumno
void ElArbol::insetarDato(Nodo* a, Nodo* b, Persona c)
{
    if(b == nullptr){
        b = new Nodo(c, a);
        setRaiz(b);
        cout<<"Entro aqui 1"<<endl;
        cout<<b->getDato().getNombre()<<endl;
        system("pause");
    }else{
        cout<<"Entro aqui 2"<<endl;
        system("pause");
        Persona aux;
        if(aux.compararmenorque(c,b->getDato())){
        cout<<"Entro aqui 3"<<endl;
        system("pause");
        a = b;
        insetarDato(a,b->getDer(),c);
        }else{
        cout<<"Entro aqui 4"<<endl;
        system("pause");
        a = b;
        insetarDato(a,b->getIzq(),c);
        }
    }
}

Nodo* ElArbol::encontrarDato(Nodo* a, Persona b)
{
    Persona aux;
    if(a == nullptr || aux.compararIgualigual(a->getDato(),b)){
        return a;
    }else if(aux.compararmenorque(b,a->getDato())){
        return encontrarDato(a->getIzq(),b);
    }else{
        return encontrarDato(a->getDer(),b);
    }
}

Nodo* ElArbol::elmasIzq(Nodo* a)
{
    if(a == nullptr || a->getIzq()==nullptr){
        return a;
    }else{
        return elmasIzq(a->getIzq());
    }
}

Nodo* ElArbol::elmasDer(Nodo* a)
{
    if(a == nullptr || a->getDer()==nullptr){
        return a;
    }else{
        return elmasIzq(a->getDer());
    }
}

bool ElArbol::vacio()
{
    return raiz == nullptr;
}


void ElArbol::inOrder(Nodo* a)
{
    if(!a){
    return;
    }
    Persona aux;
    inOrder(a->getIzq());
    aux = a->getDato();
    cout<<aux.getNombre();
    cout<<aux.getApellido();
    cout<<aux.getJuego();
    inOrder(a->getDer());
}

void ElArbol::preOrder(Nodo*a)
{
        if(!a){
        return;
        }
        Persona aux;
        aux = a->getDato();
        cout<<aux.getNombre();
        cout<<aux.getApellido();
        cout<<aux.getJuego();
        preOrder(a->getIzq());
        preOrder(a->getDer());
}

void ElArbol::postOrder(Nodo* a)
{
        if(!a){
        return;
        }
        Persona aux;
        preOrder(a->getIzq());
        preOrder(a->getDer());
        aux = a->getDato();
        cout<<aux.getNombre();
        cout<<aux.getApellido();
        cout<<aux.getJuego();
}

void ElArbol::eliminarTodo(Nodo* a)
{
        if(!a){
        return;
        }
        eliminarTodo(a->getIzq());
        eliminarTodo(a->getDer());
        delete a;
}

ElArbol::ElArbol()
{
   raiz = nullptr;
}

ElArbol::~ElArbol()
{
    eliminarTodo(raiz);
}

int ElArbol::Altura(Nodo* a)
{
    if(a == nullptr){
    return 0;
    }
    int iH = Altura(a->getIzq());
    int dH = Altura(a->getDer());

    if(iH>dH){
        return iH+1;
    }else{
        return dH+1;
    }
}

bool ElArbol::hoja(Nodo* a)
{
    return a != nullptr and a->getIzq() == a->getDer();
}

void ElArbol::setRaiz(Nodo* r){
    raiz = r;
}

Nodo* ElArbol::getRaiz()
{
    return raiz;
}

Persona ElArbol::Dato(Nodo* a)
{
    return a->getDato();
}

void ElArbol::eliminarDato(Persona nombre)
{
    Persona papa;
    Nodo* nAux;
    Nodo* padreAux;
    Nodo* tempPtr;
    Nodo* tempL;
    Nodo* tempR;
    nAux = encontrarDato(raiz,nombre);

    if(nAux == nullptr){
    cout << "Dato no encontrado..." <<endl;
    return;
    }else{
        padreAux = nAux->getPadre();

        if(hoja(nAux)){
        if(padreAux->getIzq() == nAux){
            padreAux->setIzq(nullptr);
        }
        else{
            padreAux->setDer(nullptr);
        }
        nAux = nullptr;
        delete nAux;
        return;
        }
        if(nAux->getIzq() != nullptr and nAux->getIzq() == nullptr){
        padreAux->setIzq(nAux->getIzq());
        delete nAux;
        padreAux->getIzq()->setPadre(padreAux);
        return;
        }else if(nAux->getIzq() == nullptr and nAux->getIzq() != nullptr){
         padreAux->setDer(nAux->getDer());
        delete nAux;
        padreAux->getIzq()->setPadre(padreAux);
        return;
        }
        else{
        tempL = nAux->getIzq();
        tempR = nAux->getIzq();
        tempPtr = elmasIzq(nAux->getIzq());
        nAux->setDato(tempPtr->getDato());
        tempPtr = nullptr;
        delete tempPtr;
        nAux->setIzq(tempL);
        nAux->setDer(tempPtr);
        }
    }
}
