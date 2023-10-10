#include "MenuPrincipal.hpp"
void MenuPrincipal::menu() {
    ARBOL Elarbol;
    Persona a;
    int opc;
    do{
    system("cls");
    cout<<"Bienvenido al arbol de preferencias de juegos"<<endl;
    cout<<"1)Insertar preferencia"<<endl;
    cout<<"2)Mostrar preferencias(preorden)"<<endl;
    cout<<"3)Mostrar preferencias(inorden)"<<endl;
    cout<<"4)Mostrar preferencias(postorden)"<<endl;
    cout<<"5)Buscar juego"<<endl;
    cout<<"6)Mostrar el MenorDemayores"<<endl;
    cout<<"7)Mostrar el MeyorDemenores"<<endl;
    cout<<"8)Eliminar preferencia"<<endl;
    cout<<"9)Cargar preferencias"<<endl;
    cout<<"10)Guardar preferencias/Salir"<<endl;
    cout<<"Seleccione una opcion:";
    cin>>opc;
    switch(opc){
    case 1: {
        string auxNombre,auxApellido,AuxJuego;
        cout<<"Ingresa tu nombre"<<endl;
        cin>>auxNombre;
        a.setNombre(auxNombre);
        cout<<"Ingresa tu apellido"<<endl;
        cin>>auxApellido;
        a.setApellido(auxApellido);
        cout<<"Ingresa tu juego"<<endl;
        cin>>AuxJuego;
        a.setJuego(AuxJuego);
        Elarbol.InsertarDato(a);
    }
    break;
    case 2: {
        cout<<"Preorden"<<endl;
        Elarbol.PreOrden();
        system("pause");
    }
    break;
    case 3:{
        cout<<"Inorden"<<endl;
        Elarbol.Inorden();
        system("pause");
    }
    break;
    case 4:{
        cout<<"Postorden"<<endl;
        Elarbol.PostOrden();
        system("pause");
    }break;
    case 5:{
        string aux;
        Nodo* c;
        Persona b;
        cout<<"Ingresa el nombre que quieras buscar"<<endl;
        cin>>aux;
        b.setNombre(aux);
        c = Elarbol.BuscarDato(b);
        if(c == nullptr){
            cout<<"Dato no encontrado"<<endl;
        }else{
            cout<<"Nombre: "<<c->getDatoPTR().getNombre()<<endl;
            cout<<"Apellido: "<<c->getDatoPTR().getApellido()<<endl;
            cout<<"Juego: "<<c->getDatoPTR().getJuego()<<endl;
            system("pause");
        }
    }break;
    case 6:{
        cout<<"El elemento menor: "<<endl;
        cout<<"Nombre: "<<Elarbol.MenorDemayores()->getDatoPTR().getNombre()<<endl;
        cout<<"Apellido: "<<Elarbol.MenorDemayores()->getDatoPTR().getApellido()<<endl;
        cout<<"Juego: "<<Elarbol.MenorDemayores()->getDatoPTR().getJuego()<<endl;
        system("pause");
    }break;
    case 7:{
        cout<<"El elemento Mayor: "<<endl;
        cout<<"Nombre: "<<Elarbol.MeyorDemenores()->getDatoPTR().getNombre()<<endl;
        cout<<"Apellido: "<<Elarbol.MeyorDemenores()->getDatoPTR().getApellido()<<endl;
        cout<<"Juego: "<<Elarbol.MeyorDemenores()->getDatoPTR().getJuego()<<endl;
        system("pause");
    }break;
    case 8:{
        string aux;
        Nodo* c;
        Persona b;
        cout<<"Ingresa el nombre que quieras eliminar"<<endl;
        cin>>aux;
        b.setNombre(aux);
        c = Elarbol.BuscarDato(b);
        if(c == nullptr){
            cout<<"Dato no encontrado"<<endl;
        }else{
            cout<<"Nombre: "<<c->getDatoPTR().getNombre()<<endl;
            cout<<"Apellido: "<<c->getDatoPTR().getApellido()<<endl;
            cout<<"Juego: "<<c->getDatoPTR().getJuego()<<endl;
            Elarbol.EliminarDato(c);
        }
    }break;
    case 9:{
        cout<<"Cargar Preferencias"<<endl;
        Elarbol.Cargar();
    }break;
    case 10:{
        remove("prueba.txt");
        cout<<"Guardar Preferencias"<<endl;
        Elarbol.Guardar();
    }break;
    }
    }while(opc!=10);
}
