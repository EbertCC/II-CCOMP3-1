
#include <iostream>

using namespace std;

void mostrar(int *p , int *q){
    for(int *a = p ; a <= q ; a++){
        cout<<*a<<" ";
    }
}


void cocktail(int *ini , int *fin){
    bool estado=true;

    while(estado && ini<fin){
        estado=false;

        for(int *p=ini ; p < fin ; p++){
            if( (*p) > *(p+1)  ){
                swap(*p,*(p+1));
                estado = true;
            }
        }

        fin--;
        
        if(estado == false){
            break;
        }

        estado = false;

        for(int *q = fin ; q>ini ;q--){
            if( *q < *(q-1) ){
                swap(*q,*(q-1));
                estado = true;
            }
        }

        ini++;

    }


}


int main(){
    int tamanio=9;
    int M[tamanio] = {51,3,28,35,4,2,7,23,15};
    
    mostrar(M,M+(tamanio-1));

    cocktail(M,M+(tamanio-1));
    cout<<endl;

    mostrar(M,M+(tamanio-1));
    
    return 0 ; 
}