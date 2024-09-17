#include <iostream>

using namespace std;


void mostrar(int *p , int *q){
    for(int *a=p ; a < q + 1 ; a++){
        cout<<*a<<" ";
    }
}

void ordenar(int *ini, int *fin){
    for(int *x = ini+1 ; x<=fin ; x++){

        for(int *y = x ; y > ini && *y < *(y-1) ; y--){
            swap(*y,*(y-1));
        }
        
    }
}

void merge(int *p , int *q , int *fin){

    ordenar(p,q-1);//0-3
    ordenar(q,fin);//4-8
    

    while(p < q && q < fin){
        if(*p>*q){
            for(int *r=q ; r>p ; r--){
                swap(*r,*(r-1));
            }
            q++;
        }
        p++;
    }
    

}

int main(){

    int tamanio = 8;

    int M[tamanio] = {88,102,82,66,1,155,55,10001};

    mostrar(M,M+(tamanio-1));
    
    int medio = tamanio/2;
  
    merge( M, M+medio, M+(tamanio-1) );
    

    cout<<endl;
    mostrar(M,M+(tamanio-1));


    return 0;
}