#include "ARBOL.hpp"

void ARBOL::insertarDato(Nodo* a, Persona b) {
    Nodo *vtx = new Nodo(b);
    if(raiz == nullptr) {
        raiz = vtx;
        return;
    } else {
        Persona c;
        if(c.compararIgualigual(b,a->getDatoPTR())) {
            cout<<"Duplicado";
            return;
        }
        if(c.compararmenorque(b,a->getDatoPTR())) {
            if(a->getHijoizquierdo() == nullptr) {
                a->setHijoizquierdo(vtx);
                return;
            } else {
                insertarDato(a->getHijoizquierdo(),b);
            }
        } else if(a->getHijoderecho() == nullptr) {
            a->setHijoderecho(vtx);
            return;
        } else {
            insertarDato(a->getHijoderecho(),b);
        }
    }
}

void ARBOL::preOrden(Nodo* a) {
    if(a == nullptr) {
        return;
    }

    cout<<"Nombre:"<<a->getDatoPTR().getNombre()<<endl;
    cout<<"Apellido:"<<a->getDatoPTR().getApellido()<<endl;
    cout<<"Juego:"<<a->getDatoPTR().getJuego()<<endl;
    preOrden(a->getHijoizquierdo());
    preOrden(a->getHijoderecho());
}

void ARBOL::inOrden(Nodo* a) {
    if(a == nullptr) {
        return;
    }

    inOrden(a->getHijoizquierdo());
    cout<<"Nombre:"<<a->getDatoPTR().getNombre()<<endl;
    cout<<"Apellido:"<<a->getDatoPTR().getApellido()<<endl;
    cout<<"Juego:"<<a->getDatoPTR().getJuego()<<endl;
    inOrden(a->getHijoderecho());
}

void ARBOL::postOrden(Nodo* a) {
    if(a == nullptr) {
        return;
    }

    postOrden(a->getHijoizquierdo());
    postOrden(a->getHijoderecho());
    cout<<"Nombre:"<<a->getDatoPTR().getNombre()<<endl;
    cout<<"Apellido:"<<a->getDatoPTR().getApellido()<<endl;
    cout<<"Juego:"<<a->getDatoPTR().getJuego()<<endl;
}

Nodo* ARBOL::buscarDato(Nodo* a, Persona b) {
    Persona c;
    if(a == nullptr || c.compararIgualigual(b,a->getDatoPTR())) {
        return a;
    } else {
        if(c.compararmenorque(b,a->getDatoPTR())) {
            return buscarDato(a->getHijoizquierdo(),b);
        } else {
            return buscarDato(a->getHijoderecho(),b);
        }
    }
}

Nodo* ARBOL::mayorDemenores(Nodo* a) {
    if(a == nullptr || a->getHijoderecho() == nullptr) {
        return a;
    }
    return mayorDemenores(a->getHijoderecho());
}

Nodo* ARBOL::menorDemayores(Nodo* a) {
    if(a == nullptr || a->getHijoizquierdo() == nullptr) {
        return a;
    }
    return menorDemayores(a->getHijoizquierdo());
}

int ARBOL::altura(Nodo* a) {
    if(estaVacio()) {
        return 0;
    }
    int alturizquierda = altura(a->getHijoizquierdo());
    int alturaderecha = altura(a->getHijoderecho());

    if(alturizquierda > alturaderecha) {
        return alturizquierda + 1;
    } else {
        return alturaderecha +1;
    }
}

ARBOL::ARBOL() {
    raiz = nullptr;
}

void ARBOL::InsertarDato(Persona a) {
    insertarDato(raiz,a);
}

void ARBOL::EliminarDato(Nodo* a) {
    eliminarDato(a);
}

void ARBOL::eliminarDato(Nodo* a) {
    if (esHoja(a)) {
        if (a == raiz) {
            raiz = nullptr;
        } else {
            Nodo* padre = getPadre(raiz, a);
            if (padre->getHijoizquierdo() == a) {
                padre->setHijoizquierdo(nullptr);
            } else {
                padre->setHijoderecho(nullptr);
            }
        }
        delete a;
    } else if (a->getHijoizquierdo() == nullptr || a->getHijoderecho() == nullptr) {
        Nodo* hijo;
        if (a->getHijoizquierdo() != nullptr) {
            hijo = a->getHijoizquierdo();
        } else {
            hijo = a->getHijoderecho();
        }
        if (a == raiz) {
            raiz = hijo;
        } else {
            Nodo* padre = getPadre(raiz, a);
            if (padre->getHijoizquierdo() == a) {
                padre->setHijoizquierdo(hijo);
            } else {
                padre->setHijoderecho(hijo);
            }
        }
        delete a;
    } else {
        Nodo* menor = menorDemayores(a->getHijoderecho());
        a->setDatoPTR(menor->getDatoPTR());
        eliminarDato(menor);
    }
}

void ARBOL::PreOrden() {
    preOrden(raiz);
}

void ARBOL::Inorden() {
    inOrden(raiz);
}

void ARBOL::PostOrden() {
    postOrden(raiz);
}

void ARBOL::EliminarTodo() {
    raiz = nullptr;
}

bool ARBOL::estaVacio() {
    if(!raiz) {
        return true;
    } else {
        return false;
    }
}

bool ARBOL::esHoja(Nodo* a) {
    return ((a->getHijoizquierdo()==nullptr)&&(a->getHijoderecho()==nullptr));
}


Nodo* ARBOL::MeyorDemenores() {
    return mayorDemenores(raiz);
}

Nodo* ARBOL::MenorDemayores() {
    return menorDemayores(raiz);
}

int ARBOL::Altura() {
    return altura(raiz);
}

Nodo* ARBOL::getPadre(Nodo* a, Nodo* b) {
    Persona c;
    if(a->getHijoderecho()==b || a->getHijoizquierdo()==b) {
        return a;
    } else {
        if(c.compararmenorque(b->getDatoPTR(),a->getDatoPTR())) {
            return getPadre(a->getHijoizquierdo(),b);
        } else {
            return getPadre(a->getHijoderecho(),b);
        }
    }
}

Nodo* ARBOL::BuscarDato(Persona p) {
    return buscarDato(raiz, p);
}

void ARBOL::cargarDatos() {
    char delimitador_registro = '|';
    char delimitador_campo = '#';
    ifstream archivo("file01.txt", ios::in);
    if(archivo.good()) {
        string auxstring;
        Persona a;
        while(!archivo.eof()) {
            getline(archivo,auxstring,delimitador_campo);
            if(archivo.eof()) break;
            a.setNombre(auxstring);
            getline(archivo,auxstring,delimitador_campo);
            a.setApellido(auxstring);
            getline(archivo,auxstring,delimitador_registro);
            a.setJuego(auxstring);
            InsertarDato(a);
        }
    }
    archivo.close();
}

void ARBOL::Cargar() {
    cargarDatos();
}

void ARBOL::Guardar() {
    guardaDatos(raiz);
}
void ARBOL::guardaDatos(Nodo* a) {
    if (a == nullptr) {
        return;
    } else {
        Persona p = a->getDatoPTR();
        char delimitador_registro = '|';
        char delimitador_campo = '#';
        ofstream archivo("file01.txt", ios::app);
        if (archivo.good()) {
            archivo << p.getNombre() << delimitador_campo << p.getApellido() << delimitador_campo << p.getJuego() << delimitador_registro;
            archivo.close();
            guardaDatos(a->getHijoizquierdo());
            guardaDatos(a->getHijoderecho());
        }
    }
}



