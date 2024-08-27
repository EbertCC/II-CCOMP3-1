#include <iostream>
#include <cmath>

using namespace std;

void fun(double num){
    double indi[] = {200,100,50,20,10,5,2,1,0.5,0.2,0.1} ;
    
    for(int i = 0 ; i < 11 ; i++){
        int aux = num/indi[i];
        num = num - aux*indi[i];

        cout<<indi[i]<<" -> "<<aux<<endl;
    }
}

int main(){
    double  num;
    cout<<"Ingrese numero flotante"<<endl;
    cin>>num;
    fun(num);

    return 0;
}