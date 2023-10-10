#ifndef BTREE_HPP_INCLUDED
#define BTREE_HPP_INCLUDED

#include <exception>
#include <string>
#include <iostream>
#include <fstream>

#include "alumno.hpp"

using namespace std;

template <class T>
class BTree{
    private:
        class Node{
        T* dataPtr;
        Node* left;
        Node* right;
        Node* padre;

    public:
		class Exception : public std::exception{
			private:
				std::string msg;

			public:
				explicit Exception(const char* message) : msg(message){
				}
				explicit Exception(const std::string& message) : msg(message){
				}

				virtual ~Exception() throw(){
				}
				virtual const char* what() const throw(){
					return msg.c_str();
				}
            };

        //Metodos p�blicos pertenecientes al nodo anidado al arbol
        Node();
        Node(const T&, Node*&);

        ~Node();

        T* getDataPtr() const;
        T getData()const;
        Node*& getLeft();
        Node*& getRight();
        Node*& getPadre();

        void setDataPtr(T*);
        void setData(const T&);
        void setLeft(Node*&);
        void setRight(Node*&);
        void setPadre(Node*&);
    };

    //Metodos del arbol
    public:
    typedef Node* Position;

    private:
    Position root;

    void deleteAll(Position&);

    void insertData(Position&, Position&, const T&);

    Position& findData(Position&, const T&);

    Position& getLowest(Position&);
    Position& getHighest(Position&);

    void parsePreOrder(Position&);
    void parseInOrder(Position&);
    void parsePostOrder(Position&);

    void parsePreOrderGuardar(Position&);

    void guardarArchivo(Position&);

    public:
    class Exception : public std::exception{
			private:
				std::string msg;

			public:
				explicit Exception(const char* message) : msg(message){

				}
				explicit Exception(const std::string& message) : msg(message){

				}

				virtual ~Exception() throw(){

				}
				virtual const char* what() const throw(){
					return msg.c_str();
				}

    };

    BTree();

    ~BTree();

    bool isEmpty()const;

    void insertData(const T&);

    Position& getRoot();

    Position& findData(const T&);

    void deleteAll();

    T retrieve(Position&) const;
    void verPadre(const T&);

    int getHeight(Position&);

    Position& getLowest();
    Position& getHighest();

    bool isLeaf(Position&) const;

    int getHeight();

    void parsePreOrder();
    void parseInOrder();
    void parsePostOrder();

    void eliminarDato(T&); ///pendiente


    void guardarArchivo();
    void cargarArchivo();
};

//implementacion del nodo
template<class T>
BTree<T>::Node::Node() : dataPtr(nullptr), left(nullptr), right(nullptr), padre(nullptr){} ///contructor

template<class T>
BTree<T>::Node::Node(const T& e, Node*& p) : dataPtr(new T(e)), left(nullptr), right(nullptr), padre(p){///constructor parametrizado
                                                                                    ///recibe un dato, lo asigna e inicializa sus dos posibles nodos hijos
if(dataPtr == nullptr){   //Verificaci�n en caso de que no haya memoria disponible en el equipo
    throw Exception ("Memoria insuficiente, crear primer nodo");
    }
}

template <class T>
BTree<T>::Node::~Node(){        ///Destructor del arbol
delete dataPtr;
}


template<class T>
T* BTree<T>::Node::getDataPtr() const{      ///getter que retorna un tipo puntero a arbol
    return dataPtr;
}


template<class T>
T BTree<T>::Node::getData() const{          ///getter que retorna dato tipo plantilla
if(dataPtr == nullptr){ //validaci�n en caso de que el dato a retornar no exista
    throw Exception("Dato inexistente, getData");
    }
return *dataPtr; ///desreferenciador
}


template<class T>
typename BTree<T>::Position& BTree<T>::Node::getLeft(){
    return left;
}

template<class T>
typename BTree<T>::Position& BTree<T>::Node::getRight(){
    return right;
}

template<class T>
typename BTree<T>::Position& BTree<T>::Node::getPadre(){
    return padre;
}


template<class T>
void BTree<T>::Node::setDataPtr(T* p ){ ///setter que asigna un dato tipo puntero a arbol
dataPtr = p;
}

template<class T>
void BTree<T>::Node::setData(const T& e){ ///setter que asigna dato tipo plantilla
if(dataPtr == nullptr){ //Validacion en caso de que no exista memoria para crear un nuevo nodo
    if((dataPtr = new T(e)) == nullptr){
       throw Exception("Memoria insuficiente, setData");
       }
    }
else{
    *dataPtr = e;
    }
}

template<class T>
void BTree<T>::Node::setLeft(Position& p){
left = p;
}

template<class T>
void BTree<T>::Node::setRight(Position& p){
right = p;
}

template<class T>
void BTree<T>::Node::setPadre(Position& p){
padre = p;
}

///implementacion del arbol

template<class T>
BTree<T>::BTree() : root(nullptr){} ///constructor del arbol

template<class T>
BTree<T>::~BTree(){ ///Destructor del arbol en el lado p�blico
deleteAll();        //llama al metodo publico para eliminar todo el arbol, el cual vuelve a llamar al metodo de eliminar todo pero en su lado p�blico
}                   //y recibiendo la ra�z del arbol como par�metro

template<class T>
bool BTree<T>::isEmpty()const{  ///Booleano que retorna la comparaci�n si el arbol est� vac�o o no.
return root == nullptr;
}


template<class T>
void BTree<T>::insertData(const T& e){  ///metodo p�blico que recibe un valor tipo plantilla, llama a su mismo m�todo pero en privado
Position papa = root;
insertData(papa, root, e);                    ///y con la direcci�n del arbol a insertar como par�metro
}


template<class T>
void BTree<T>::insertData(Position& papa, Position& r, const T& e){ ///Metodo privado de inserci�n
if(r == nullptr){
    try{
    //insercion de dato
    if((r = new Node(e, papa)) == nullptr){ //Inserta y valida en caso de que no exista memoria suficiente para insertar el dato
        throw Exception("Memoria insuficiente, insertData");
            }
        }
    catch(typename Node::Exception ex){
    throw Exception (ex.what());
    }
   }

else{
    alumno aux;
    if(aux.comparar_nombres(e, r->getData())){
        papa = r;
        insertData(papa, r->getLeft(), e);
        }
    else{
        papa = r;
        insertData(papa, r->getRight(), e);
        }
    }
}

template<class T>
T BTree<T>::retrieve(Position& r)const{
return r->getData();
}


template<class T>
typename BTree<T>::Position& BTree<T>::findData(const T& e){///metodo p�blico que recibe un dato y llama a su metodo copia pero parametrizado con la ra�z
return findData(root, e);    //Llama a su misma funci�n pero privada y parametrizada con la direcci�n de la ra�z y el dato a buscar
}                            //retorna una direcci�n de memoria en caso de que el dato s� exista


template<class T>
typename BTree<T>::Position& BTree<T>::findData(Position& r, const T& e){   ///metodo privado que recibe la ra�z del arbol y un dato a buscar en esa ra�z
alumno aux;
if(r == nullptr or aux.compararIgualdad(r->getData(), e)){
    return r;      //validaci�n en caso de que el arbol est� vac�o o el dato se encuentre en la ra�z
    }
    if(aux.comparar_nombres(e, r->getData())){   //inicio de la recursividad en caso de que el dato a buscar sea menor que el dato en el campo del puntero en su direcci�n actual
        return findData(r->getLeft(), e);
    }
return findData(r->getRight(), e);  //inicio de la recursividad en caso de que el dato a buscar sea mayor que el dato en el campo del puntero en su direcci�n actual
}


template<class T>
typename BTree<T>::Position& BTree<T>::getLowest(){ ///metodo publico que llama al privado con la direcci�n de ra�z al arbol
return getLowest(root);
}


template<class T>
typename BTree<T>::Position& BTree<T>::getLowest(Position& r){///metodo privado recibe la ra�z del arbol y realiza un recorrido por su lado m�s izquierdo
if(r == nullptr or r->getLeft() == nullptr){
    return r;
    }
return getLowest(r->getLeft());
}

template<class T>
typename BTree<T>::Position& BTree<T>::getHighest(){ ///metodo publico que llama al privado con la direcci�n de ra�z al arbol
return getHighest(root);
}

template<class T>
typename BTree<T>::Position& BTree<T>::getHighest(Position& r){ ///metodo privado recibe la ra�z del arbol y realiza un recorrido por su lado m�s derecho
if(r == nullptr or r->getRight() == nullptr){
    return r;
    }
return getHighest(r->getRight());
}

template<class T>
bool BTree<T>::isLeaf(Position& r) const{   ///Metodo booleano que verifica si un nodo es hoja
return r != nullptr and r->getLeft() == r->getRight();
}

template<class T>
int BTree<T>::getHeight(){ ///Metodo publico que llama al mismo m�todo en su area privada y manda como parametro la direcci�n de la ra�z
return getHeight(root);
}

template<class T>
int BTree<T>::getHeight(Position& r){
if(r == nullptr){
    return 0;
    }
int lH(getHeight(r->getLeft()));
int rH(getHeight(r->getRight()));

return (lH > rH ? lH : rH) +1;
}

template<class T>
void BTree<T>::parsePreOrder(){
parsePreOrder(root);
}

template<class T>
void BTree<T>::parsePreOrder(Position& r){
alumno aux;
if(r == nullptr){
    return;
    }
aux = r->getData();
cout << aux.toString() << ", ";

parsePreOrder(r->getLeft());
parsePreOrder(r->getRight());
}

///
template<class T>
void BTree<T>::parsePreOrderGuardar(Position& r){
fstream archivo, dAux;  //archivo original y archivo que sustituir� al original
string DatoAux;

archivo.open("file01.txt", ios::app);
dAux.open("temporal.txt", ios::app);

alumno Alumaux;

    if(r == nullptr){   //validaci�n en caso de que no existan datos en el nodo
        return;
    }



parsePreOrderGuardar(r->getLeft());

parsePreOrderGuardar(r->getRight());


Alumaux = r->getData();
cout << "Dato: " <<Alumaux.toString() << ", ";
DatoAux = Alumaux.toString();
dAux << DatoAux << "*"; //se guarda en archivo
cout << "insertas..." <<endl;

///fin de la recursividad

dAux.close();
archivo.close();

remove("file01.txt");
rename("temporal.txt", "file01.txt");
}
///

template<class T>
void BTree<T>::parseInOrder(){
parseInOrder(root);
}

template<class T>
void BTree<T>::parseInOrder(Position& r){
alumno aux;
if(r == nullptr){
    return;
    }

parseInOrder(r->getLeft());
aux = r->getData();
cout << aux.toString() << ", ";
parseInOrder(r->getRight());
}

template<class T>
void BTree<T>::parsePostOrder(){
parsePostOrder(root);
}

template<class T>
void BTree<T>::parsePostOrder(Position& r){
alumno aux;
if(r == nullptr){
    return;
    }

parsePostOrder(r->getLeft());
parsePostOrder(r->getRight());

aux = r->getData();
cout << aux.toString() << ", ";
}

template<class T>
void BTree<T>::deleteAll()  ///Metodo p�blico del arbol el cual solo llama al m�todo parametrizado que se encuentra en el lado privado
{                           ///del arbol.
 deleteAll(root);   //manda como par�metro la ra�z del arbol a eliminar
}

template<class T>
void BTree<T>::deleteAll(Position& r){  ///metodo privado que se encarga de eliminar todo el �rbol.
    if (r == nullptr) { //valida si el arbol no est� vac�o
        return;
    }
    ///inicia recursividad del metodo
    deleteAll(r->getLeft());    //primero elimina al m�s peque�o por el lado izquierdo
    deleteAll(r->getRight());

    delete r;

    r = nullptr;

}

template<class T>
typename BTree<T>::Position& BTree<T>::getRoot(){   ///metodo privado que solo usa el arbol, retorna la direcci�n de la ra�z
return root;
}

template<class T>
void BTree<T>::guardarArchivo(){        ///metodo publico que llama al privado con la ra�z
    guardarArchivo(root);
}

template<class T>
void BTree<T>::guardarArchivo(Position& r){
    parsePreOrderGuardar(r);        ///metodo que es llamado por el metodo privado de guardar archivo pero
                                    ///parametrizado con la ra�z

}


template<class T>
void BTree<T>::cargarArchivo(){
///este metodo no necesita de una ra�z, pues esta la genera el m�todo de inserci�n en caso de ser necesaria
ifstream archivo;
string datoAux, datoAux2, datoAux3;
alumno alumaux;
archivo.open("file01.txt", ios::in);

    if(!archivo.good()){                    ///Validaci�n en caso de que el archivo no abra correctamente
    cout<<"error al abrir el archivo"<<endl;
    system("pause"); system("cls");
    return;
    }
    ///inicio de los atributos de la clase alumno
    getline(archivo, datoAux, '|'); //almacena el nombre
    getline(archivo, datoAux2, '|'); //almacena el codigo
    getline(archivo, datoAux3, '*'); //almacena la carrera
    ///fin de los atributos de la clase alumno
    //inserci�n de la informaci�n obtenida en sus correspondientes atributos de la clase alumno
    alumaux.setNombre(datoAux);
    alumaux.setCodigo(datoAux2);
    alumaux.setCarrera(datoAux3);

    while (!archivo.eof()) {
        insertData(alumaux); ///se inserta el alumno en un campo del arbol
        getline(archivo, datoAux, '|');
        getline(archivo, datoAux2, '|');
        getline(archivo, datoAux3, '*');
        //inserci�n de la informaci�n obtenida en sus correspondientes atributos de la clase alumno
        alumaux.setNombre(datoAux);
        alumaux.setCodigo(datoAux2);
        alumaux.setCarrera(datoAux3);
    }
archivo.close(); // cerrar archivo
}

template<class T>
void BTree<T>::eliminarDato(T& nombre){
alumno papa;
Position nAux, padreAux, tempPtr, tempL, tempR;
nAux = findData(nombre);

    if(nAux == nullptr){
    cout << "Dato no encontrado..." <<endl;
    return;
    }

    ///validaciones en caso de que el nodo a eliminar sea la ra�z
    else if(nAux == root){
        cout << "El nodo es la raiz del arbol" <<endl;
        //variaciones de eliminar la ra�z
            if(isLeaf(nAux)){ //si el nodo ra�z no tiene hijos
                delete nAux;
                root = nullptr; //reseteas la ra�z
                cout << "El dato ha sido eliminado..." <<endl;
                system("pause"); system("cls");
                return;
            }
            else if(nAux->getLeft()!= nullptr and nAux->getRight() == nullptr){ //si la ra�z tiene un hijo por la izquierda
                cout << "Tiene solo un nodo por la izquierda" <<endl;
                root = nAux->getLeft();
                delete nAux;
                root->setPadre(root); //reseteas la ra�z
                cout << "El dato ha sido eliminado y religado..." <<endl;
                system("pause"); system("cls");
                return;
            }
            else if(nAux->getLeft()== nullptr and nAux->getRight() != nullptr){ //si la ra�z tiene un hijo por la derecha
                cout << "Tiene solo un nodo por la derecha" <<endl;
                root = nAux->getRight();
                delete nAux;
                root->setPadre(root);
                cout << "El dato ha sido eliminado y religado..." <<endl;
                system("pause"); system("cls");
                return;
            }

    }

    else{   //aqui tambien entra una variaci�n de eliminar la ra�z (cuando esta tiene hijos por la derecha y por la izquierda) pero el religado
            //no afecta el algoritmo como para preocuparse por ello.
        cout << "Dato encontrado: " << nombre.getNombre() <<endl;
        //es necesario el metodo de buscar padre para religado de nodos
        padreAux = nAux->getPadre();

        if(nAux == root){   //si el nodo a eliminar es igual a la ra�z, este es la ra�z de todo el arbol, por ello no se imprimen los datos del padre
            cout << "Nodo raiz" <<endl;
        }

        else{
        cout << "Nodo padre: " <<padreAux->getData().toString()<<endl;  //Si el nodo no a eliminar no es igual a la ra�z, s� tiene padre y es posible mostrar sus datos
        }

        if(isLeaf(nAux)){ ///validaci�n en caso de que el nodo sea hoja.
        ///RECURSOS HAY!
        cout << "El dato es hoja." <<endl;

        if(padreAux->getLeft() == nullptr){
            root == nullptr;
            }
    //se busca por cu�l lado del pap� se encuentra el dato a eliminar y se apunta a nulo
    //esto para no afectar  el religado de datos
        else if(padreAux->getLeft() == nAux){ //si el padre por su lado izquierdo coincide con el dato a eliminar, se sabe que el dato a eliminar est�
                                              //por el lado izquierdo del padre
            padreAux->getLeft() = nullptr;
        }

        else{
            padreAux->getRight() = nullptr;  //sino, el dato a eliminar se encuentra por el lado derecho del padre
        }
        nAux = nullptr;
        delete nAux;
        ///BENDITA SEA LA EFICIENCIA

        cout << "Dato eliminado :)" <<endl;
        return;
        }

        ///Eliminaci�n de un nodo con un hijo
        if(nAux->getLeft() != nullptr and nAux->getRight() == nullptr){ //cuando el nodo a eliminar tiene solo un hijo por la izquierda
        padreAux->getLeft() = nAux->getLeft(); //nodo religado
        delete nAux;
        padreAux->getLeft()->setPadre(padreAux); //se actualiza la direcci�n del padre al nuevo nodo
        return;
        }

        ///Eliminaci�n de un nodo con un hijo
        else if(nAux->getLeft() == nullptr and nAux->getRight() != nullptr){ //cuando el nodo a eliminar tiene solo un hijo por la derecha
        padreAux->getRight() = nAux->getRight(); //nodo religado
        delete nAux;
        padreAux->getRight()->setPadre(padreAux); //se actualiza la direcci�n del padre al nuevo nodo
        return;
        }
        else{
        ///Eliminaci�n de un nodo con dos hijos
        //Se resguardan las direcciones izquierda y derecha del nodo a eliminar *ojo, antes de eliminarlo*
        tempL = nAux->getLeft();
        tempR = nAux->getRight();
        //Se busca menor de los derechos para sustituir el lugar del nodo a eliminar
        tempPtr = getLowest(nAux->getRight());
        //sustituye los datos del nodo a eliminar por el nodo m�s derecho de los izquierdos
        nAux->setData(tempPtr->getData());
        tempPtr = nullptr;
        delete tempPtr;
        cout <<"Nodo eliminado... \nReligando"<<endl;
        //Religa las direcciones inicialmente guardadas
        nAux->setLeft(tempL);
        nAux->setRight(tempPtr);
        }
    }
cout << "El dato ha sido eliminado y religado..." <<endl;
system("pause"); system("cls");
}

template<class T>
void BTree<T>::verPadre(const T& Nombre)
{
Position nAux;
nAux = findData(Nombre);

    if(nAux == nullptr){
        cout << "Dato no encontrado..." <<endl;
    return;
    }
    if(nAux == root){
        cout << "Nodo raiz, el padre es el mismo elemento...\n" <<nAux->getData().toString()<<endl;
    }
    else{
        cout << "Nodo padre: " <<nAux->getPadre()->getData().toString()<<endl;
    }
}


#endif // BTREE_HPP_INCLUDED
