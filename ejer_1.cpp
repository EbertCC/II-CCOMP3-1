#include <iostream>

using namespace std;

string numero_string(int numero){

    string num_strin ="";
    string aux_num[] = {"diez","once","doce","trece","catorce","quince","dieciseis","diesisiete","diesiocho","diesinueve"};  //10
    string unidades[] = {"uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve" };     //10
    string decenas[] = {"diez","veinte","treinta","cuarenta","cincuenta","sesenta","setenta","ochenta","noventa" };  //10
    string centenas[] = {"ciento","doscientos","trescientos","cuatrocientos","quinientos","seiscientos","setecientos","ochocientos","novecientos"}; //10
    
    if(numero == 0){
        return "cero";
    }
    
    //casos mas de mil
    if(numero >= 10000){
        int mil = numero/1000;
        //caso que hay exactamente entre 1000 a 1999 solo agregamos mil
        if(numero == 1 ){
            num_strin = num_strin + "mil ";
        } else {
            //recursividad a partir del mil se repite agregando mil al final
            num_strin = num_strin + numero_string(mil)+ " mil ";
        }
        //actualizamos el numero
        numero = numero%1000;
    }
    //caso de centenas
    if(numero>=100){
        int aux = numero/100;
        num_strin = num_strin + centenas[aux-1]+" ";
        numero = numero % 100;
    }
    //caso decenas
    if(numero >= 20){
        int aux = numero/10;
        num_strin = num_strin + decenas[aux-1]+" ";
        numero = numero % 10;
    }
    //caso del 10 al 19
    if(numero >= 10 && numero<=19){
        num_strin = num_strin + aux_num[numero-10];
        return num_strin;
    }
    //caso de unidades
    if(numero > 0){
        num_strin = num_strin + unidades[numero-1];
    }

    return num_strin;

}


int main(){

    int numero;

    cout<<"ingrese numero entre 0 y 999999"<<endl;
    cin>>numero;

    while (numero<0 || numero > 999999){
        cout<<"ingrese de nuevo el numero"<<endl;
        cin>>numero;
    }

    cout<<numero<<" <--> "<<numero_string(numero);
    
 


    return 0;
}