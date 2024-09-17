#include <iostream>

using namespace std;

void mostrar(int *p,int *q){

    for(int *a = p ; a<=q ; a++){
        cout<< *a <<" ";
    }
}

void ordenar_pares_impares(int *ini,int *fin){

    while(ini < fin ){

        if(*ini % 2 == 0 ){
            ini++;
        }
        else{
            //int temp = *ini ;
            for(int *p = ini ; p < fin ; p++){
                swap(*p,*(p+1));
                //*p = *(p+1);
            } 
            //*fin = temp;
            fin--;
        }

    }

}

int main(){

    int tam=8;

    int M[tam]={1,2,3,4,5,6,7,8};

    //ordenar_pares_impares(M,M+7);
    cout<<"Array inicial "<<endl;
    mostrar(M,M+7);

    cout<<endl;
    ordenar_pares_impares(M,M+7);
    
    cout<<"Array final "<<endl;
    mostrar(M,M+7);

    




    return 0;
}