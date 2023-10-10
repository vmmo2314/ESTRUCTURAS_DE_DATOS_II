#include <string>
#include "archivos.hpp"
#include "calculadora.hpp"

using namespace std;
void archivos::menuArchivos(){
{
int opc;
    archivos objeto2;
    do{
        cout<<endl;
        cout<<"\tMENU ARCHIVOS"<<endl;
        cout<<"1.Agregar"<<endl;
        cout<<"2.Mostrar"<<endl;
        cout<<"3.Buscar"<<endl;
        cout<<"4.Modificar"<<endl;
        cout<<"5.Eliminar"<<endl;
        cout<<"0.Salir"<<endl;
        cout<<"Opcion a elegir:";
        cin>>opc;
        cout<<endl;
        system("cls");
        fflush(stdin);

            switch(opc)
            {

            case 1:{}


                    break;

            case 2:{
                    objeto2.mostrar();
                    }
                    break;

            case 3:
                    {}

                    break;

            case 4:{
                    string auxSt;
                    cout<<"digita la etiqueta de la operacion a modificar...";cin>>auxSt;
                    objeto2.modificar(auxSt);
                    }
                    break;

            case 5:{}


                    break;

            case 0:{}
                break;

            default:{

                cout<<"Opcion no valida";
                }
                break;

            }

    }while(opc != 0);

}
}

void archivos::agregar(int e,int a,string op,int b,string ig,int res)
{
     ofstream archivo("mi_archivo.txt",ios::app);
     if(archivo.good()){
     int s,r,m;
     s=a;
     r=b;
     m=res;
     archivo<<e<<'#'<<s<<'#'<<op<<'#'<<b<<'#'<<ig<<'#'<<res<<'~';
     }
     archivo.close();
}

void archivos::mostrar()
{
    string d1,d2,r;
    string sign1,sign2, et;
    ifstream archivo("mi_archivo.txt",ios::in);
    if(archivo.good()){
       while(!archivo.eof()){//Guarda variables
         getline(archivo, et, '#');
         getline(archivo, d1, '#');
         getline(archivo, sign1, '#');
         getline(archivo, d2, '#');
         getline(archivo, sign2, '#');
         getline(archivo,r,'~');
         if(archivo.eof()) break;
         cout<<"Resultado de la operacion " <<et<<".- "<<d1<<" "<<sign1<<" "<<d2<<" "<<sign2<<" "<<r;//Imprime variables guardadas
       }
    }else{
           return;
       }
    archivo.close();

}


void archivos::buscar()
{

}

void archivos::modificar(string et)
{
calculadoraM opt; //operacion a realizar
string etiqueta,d1,d2,rslt;
int i1, i2, i3;
string aux;
string signo, opr;
    ifstream archivo("file01.txt",ios::in);
    ofstream temp("temp.txt",ios::app);
        if(archivo.good()){
            while(!archivo.eof()){
                getline(archivo, etiqueta,'#');
                getline(archivo, d1,'#');
                getline(archivo, opr,'#');
                getline(archivo, d2,'#');
                getline(archivo, signo,'#');
                getline(archivo, rslt,'~');
                if(archivo.eof()) break;
                if(etiqueta == et){ ///en caso de que exista coicidencia en el archivo, se salta la línea del archivo original y se suple con la nueva información
                        cout<<"Ingresa el nuevo dato"<<endl;
                        cin>>d1;
                        i1 = stoi(d1);
                        cout<<"Ingresa el segundo nuevo dato"<<endl;
                        cin>>d2;
                        i2 = stoi(d2);
                        cout<<"Que operacion deseas realizar...\nDigita el signo"<<endl; cin>>aux;
                        if(signo == "+"){
                            i3 = i1 + i2;
                            temp << rslt;
                        }else if(signo == "-"){
                            i3 = i1 - i2;
                            temp << rslt;
                        }else if(signo == "*"){
                            i3 = i1 * i2;
                            temp << rslt;
                        }else if(signo == "/"){
                            i3 = i1 / i2;
                            temp << rslt;
                        }
                        temp <<etiqueta << "#" << d1 << "#" <<aux << "#" << d2 <<"#"<< signo<<"#"<<rslt<< "*"; ///en caso de que no exista coincidencia en el archivo se
                                                                                                                ///escriben los datos en un nuevo txt
                    }

                else{
                    temp <<etiqueta << "#" << d1 << "#" <<opr << "#" << d2 <<signo<<"#"<<rslt<< "*";
                }
            }
        }else{
            return;
        }
        archivo.close();
}

void archivos::eliminar()
{

}
