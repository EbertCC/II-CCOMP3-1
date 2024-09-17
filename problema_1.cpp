#include <iostream>

using namespace std;

string str_numero(int numero, int numero_aux){

    string num_str="";

    string unidades[] = {"uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve"};
    string auxiliares[] = {"diez","once","doce","trece","catorce","quince","dieciseis","diesisiete","diesiocho","diesinueve"};
    string decenas[] = {"veinte","treinta","cuarenta","cincuenta","sesenta","setenta","ochenta","noventa" };
    string centenas[] = {"ciento","doscientos","trescientos","cuatrocientos","quinientos","seiscientos","setecientos","ochocientos","novecientos"};

    if(numero == 0){
        return "cero";
    }
    if(numero == 100){
        return "cien";
    }

    if(numero>=1000){
        int aux = numero / 1000;
        if(aux == 1){
            num_str = num_str + "mil ";
        }else{
            num_str = num_str + str_numero(aux,numero)+" mil ";
        }
        numero = numero % 1000;
    }

    if(numero >= 100){
        if(numero == 100){
            num_str = num_str + "cien";
            return num_str;
        }
        int aux = numero / 100;
        num_str = num_str + centenas[aux-1]+" ";
        numero = numero % 100;
    }
    if(numero>=10 && numero<=19){
        num_str = num_str + auxiliares[numero-10];
        return num_str;
    }
    if(numero>=20){
        if(numero==21 && numero_aux>=21000){
            num_str = num_str + "veintiun";
            return num_str; 
        }
        if(numero==21){
            num_str = num_str +"veintiuno";
            return num_str; 
        }
        int aux = numero / 10;
        num_str = num_str + decenas[aux-2]+" ";
        numero = numero % 10;
    }
    if(numero>=1){
        if(numero_aux >= 101000 && numero_aux <= 101999 && numero==1){
            num_str = num_str + "un";
            return num_str;
        }
        if(numero_aux>=21000 && numero==1){
            num_str = num_str + "y un";
            return num_str;
        }
        num_str = num_str + unidades[numero-1];
    }
    return num_str;


}


int main(){

    int numero;
/*
    cout<<"Ingrese numero entero del 0 al 999999 : "<<endl;
    cin>>numero;
    
    while(numero < 0 || numero > 999999){
        cout<<"ingrese correctamente el numero del 0 al 999999 : "<<endl;
        cin>>numero;
    }
*/
    for(int i = 0; i <10;i++){
        cout<<"Ingrese numero entero del 0 al 999999 : "<<endl;
        cin>>numero;
        while(numero < 0 || numero > 999999){

            cout<<"ingrese correctamente el numero del 0 al 999999 : "<<endl;
            cin>>numero;
        }
        cout<<numero<<" < ------ > "<<str_numero(numero,0)<<endl;
    }
    //cout<<numero<<" < ------ > "<<str_numero(numero,0)<<endl;
/*
    for(int i = 0; i<50 ; i++){
        int aux = rand()%1000000;
        cout<<aux<<" <---> "<<str_numero(aux)<<endl;

    }
*/
    return 0;
}