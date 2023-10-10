#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Clases o struct

char DELIM='@';
char DELIM_REG='%';
string nombre, apellido;
string edad;



void capturar(){
    //Paso 1: solicitar datos
    cout <<"Ingresa nombre:"<<endl;
    cin>>nombre;
    cout<<"Ingresa apellido paterno:"<<endl;
    cin>>apellido;
    cout<<"Ingresa edad:"<<endl;
    cin>>edad;

    //Paso 2: Almacenar en disco
    fstream mi_arch("mis_datos.txt",ios::ate|ios::app);
    if(mi_arch.good()){
        mi_arch<<nombre<<DELIM<<apellido<<DELIM<<edad<<DELIM_REG;
        cout<<"Se guardo bien";
    }
    mi_arch.close();
}


void mostrar(){
    string aux_n,aux_a, aux, aux_e;
    fstream mi_arch2("mis_datos.txt",ios::in);
    if(mi_arch2.good()){
       while(!mi_arch2.eof()){
            getline(mi_arch2,aux_n,DELIM);
            getline(mi_arch2,aux_a,DELIM);
            getline(mi_arch2,aux_e,DELIM_REG);
            cout<<aux_n<<" "<<aux_a<<" "<<aux_e;
       }
    }
    mi_arch2.close();
}

int main()
{
    //capturar();
    mostrar();
}
