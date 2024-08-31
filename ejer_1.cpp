#include <iostream>
#include <cstdlib>

using namespace std;

string fun(int numero){

    string num_str="";

    string unidades[] = {"uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve"};
    string especiales[] = {"diez","once","doce","trece","catorce","quince","dieciseis","diesisiete","diesiocho","diesinueve"};
    string decenas[] = {"veinte","treinta","cuarenta","cincuenta","sesenta","setenta","ochenta","noventa" };
    string centenas[] = {"ciento","doscientos","trescientos","cuatrocientos","quinientos","seiscientos","setecientos","ochocientos","novecientos"};
    
    if(numero == 0){
        return "cero";
    }
    if(numero == 100){
        return "cien";
    }
    
    if(numero>=1000){
        int aux = numero/1000;
        if(aux == 1){
            num_str = num_str + "mil ";
        }else{
            num_str = num_str + fun(aux) + " mil ";
        }
        numero = numero % 1000;
    }

    if(numero >= 100){
        int aux = numero/100;
        num_str = num_str + centenas[aux-1]+" ";
        numero = numero % 100;
    }
    if(numero >= 10 && numero <= 19){
        num_str = num_str + especiales[numero-10];
        return num_str;
    }

    if(numero >= 20){
        int aux = numero/10;
        num_str = num_str + decenas[aux-2]+" ";
        numero = numero % 10;
    }
    if(numero >= 1){
        num_str = num_str + unidades[numero-1];
    }
    
    return num_str;
}


int main(){
    int num;
    
    cout<<"ingrese numero entero entre 0 y 999999 : "<<endl;
    cin>>num;

    while (num>999999 || num <0 ){
        cout<<"Ingrese correctamente el numero : "<<endl;
        cin>>num;
    }
    cout<<num<<" <---> "<<fun(num)<<endl;
    
   /*
    for(int i = 0; i<50 ; i++){
        int aux = rand()%1000000;
        cout<<aux<<" <---> "<<fun(aux)<<endl;

    }
*/

    return 0;
    

}