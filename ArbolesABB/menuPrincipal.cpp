#include "menuPrincipal.hpp"

void menuPrincipal::menu(Persona p,ElArbol b)
{
    int opc;
    Nodo *auxraiz;
    Nodo *padre;
    do{
    auxraiz = b.getRaiz();
    padre = auxraiz;
    //system("cls");
    cout<<"Arbol De Preferencia de Juegos"<<endl;
    cout<<"1)Insertar al arbol"<<endl;
    cout<<"2)Inorden"<< endl;
    cout<<"3)Preorden"<< endl;
    cout<<"4)Posorden"<< endl;
    cout<<"5)Elemento mayor"<< endl;
    cout<<"6)Elemento menor"<< endl;
    cout<<"7)Altura izquierda"<< endl;
    cout<<"8)Altura derecho"<< endl;
    cout<<"9)eliminar todo" << endl;
    cout<<"10)guardar en archivo"<< endl;
    cout<<"11)cargar desde archivo" <<endl;
    cout<<"12)eliminar dato"<< endl;
    cout<<"13)Ver padre" <<endl;
    cout<<"14)Salir" <<endl;
    cin>>opc;
    switch(opc){
        case 1:{
            cout<<"Insertar datos"<<endl;
            string auxNombre,auxApellido,auxJuego;
            cout<<"Dame tu nombre"<<endl;cin>>auxNombre;
            p.setNombre(auxNombre);
            cout<<"Dame tu apellido"<<endl;cin>>auxApellido;
            p.setApellido(auxApellido);
            cout<<"Dame tu juego"<<endl;cin>>auxJuego;
            p.setJuego(auxJuego);
            b.insetarDato(padre,auxraiz,p);
        }
        break;
        case 2:{
            cout<<"Inorden"<<endl;
            if(b.vacio()){
                cout<<"Esta vacio"<<endl;
            }else{
                b.inOrder(auxraiz);
            system("pause");
            }
        }
        break;
        case 3:{
            cout<<"Preorden"<<endl;
            if(b.vacio()){
                cout<<"Esta vacio"<<endl;
            }else{
                b.preOrder(auxraiz);
                system("pause");
            }
        }
        break;
        case 4:{
            cout<<"Postorden"<<endl;
            if(b.vacio()){
                cout<<"Esta vacio"<<endl;
            }else{
                b.postOrder(auxraiz);
                system("pause");
            }
        }
        break;
        case 5:{
            cout<<"El mas derecho"<<endl;
            Persona auxiliar;
            auxiliar = b.Dato(b.elmasDer(auxraiz));
            cout<<"El mas derecho es:"<<auxiliar.getNombre();
            cout<<auxiliar.getApellido();
            cout<<auxiliar.getJuego();
            system("pause");
        }
        break;
        case 6:{
            cout<<"El mas izquierdo"<<endl;
            Persona auxiliar;
            auxiliar = b.Dato(b.elmasDer(auxraiz));
            cout<<"El mas izquierdo es:"<<auxiliar.getNombre();
            cout<<auxiliar.getApellido();
            cout<<auxiliar.getJuego();
            system("pause");
        }
        break;
        case 7:{
            cout<<"Altura derecha"<<b.Altura(b.getRaiz()->getDer());
            system("pause");
        }
        break;
        case 8:{
            cout<<"Altura izquierda"<<b.Altura(b.getRaiz()->getIzq());
            system("pause");
        }
        break;
        case 9:{
            cout<<"Eliminar todo"<<endl;
            b.eliminarTodo(auxraiz);
        }
        break;
        case 10:{
            cout<<"Guardar"<<endl;

        }
        break;
        case 11:{
            cout<<"Cargar"<<endl;

        }
        break;
        case 12:{
            cout<<"Eliminar un dato"<<endl;
            Persona a;
            string auxNombre;
            cout<<"Dame el nombre a eliminar"<<endl;
            cin>>auxNombre;
            a.setNombre(auxNombre);
            b.eliminarDato(a);
        }
        break;
        case 13:{
            cout<<"Ver padre"<<endl;

        }
        break;
    }
    }while(opc!=14);
}
