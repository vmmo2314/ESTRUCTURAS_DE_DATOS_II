#include "menu.hpp"

using namespace std;

void menu::mainmenu()
{
    calculadoraM objeto1;
    archivos objeto2;
    int opc;
    do{
    cout<<endl;
    cout<<"MENU PRINCIPAL"<<endl;
    cout<<"1.Calculadora"<<endl;
    cout<<"2.Archivos"<<endl;
    cout<<"0.Salir"<<endl;
    cout<<"Opcion a elegir:";
    cin>>opc;
    cout<<endl;
    switch(opc){
        case 1:
         objeto1.menu_calculadora();
         break;

        case 2:
        objeto2.menuArchivos();
        break;

        case 3:
        break;

        default:
        opc = 0;
        cout<<"Opcion no valida";
        }

    }while(opc != 0);
}
