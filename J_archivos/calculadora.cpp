#include "calculadora.hpp"
using namespace std;

int cont=1;

void calculadoraM::menu_calculadora()
{
    int opc;
    do{

            archivos Op;
            cout<<endl;
            cout<<"\tMENU CALCULADORA"<<endl;
            cout<<"1.Sumar"<<endl;
            cout<<"2.Restar"<<endl;
            cout<<"3.Multiplicar"<<endl;
            cout<<"4.Dividir"<<endl;
            cout<<"0.Salir"<<endl;
            cout<<"Opcion a elegir:";
            cin>>opc;
            cout<<endl;
            fflush(stdin);

            switch(opc)
            {
            case 1:{
                int h,j;
               int rst;
                string suma;
                suma = "+";
                 string igual;
                 igual= "=";
                    cout<<"Ingresa tu primer numero:";
                    cin>>h;
                    cout<<"Ingresa tu segundo numero:";
                    cin>>j;
                    rst = h+j;
                    cout<<"Tu resultado es:" <<rst;
                    string sm = "+";
                    string ig = "=";
                    Op.agregar(cont,h,sm,j,ig,rst);
                    cont++;


                    }break;
            case 2:{
                int h,j;
               int rst;
                    cout<<"Ingresa tu primer numero:";
                    cin>>h;
                    cout<<"Ingresa tu segundo numero:";
                    cin>>j;
                    rst = h-j;
                    cout<<"Tu resultado es:" <<rst;

                    }break;
            case 3:{
                    int h,j;
                    int rst;
                    cout<<"Ingresa tu primer numero:";
                    cin>>h;
                    cout<<"Ingresa tu segundo numero:";
                    cin>>j;
                    rst = h*j;
                    cout<<"Tu resultado es:" <<rst;

                    }break;
            case 4:{
                    int h,j;
                    int rst;
                    cout<<"Ingresa tu primer numero:";
                    cin>>h;
                    cout<<"Ingresa tu segundo numero:";
                    cin>>j;
                    rst = h/j;
                    cout<<"Tu resultado es:" <<rst;

                    }break;
            case 0:
                break;
            default:
                cout<<"Opcion no valida";
                break;
            }

    }while(opc != 0);

}
