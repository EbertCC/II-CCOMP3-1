#include <iostream>
using namespace std;

void mostrar(int *p , int *q){
    for(int *a = p ; a <= q ; a++){
        cout<<*a<<" ";
    }
}


void cocktail(int *ini , int *fin){
    bool estado_swap=true;

    while(estado_swap == true && ini < fin){
        
        estado_swap = false;
        // izquierda -> derecha (mayor hacia el final)
        for(int *p = ini; p < fin; p++){
            if((*p) > *(p+1)){
                swap(*p, *(p+1));
                estado_swap = true;
            }
        }
        fin--;

        // si no hubo intercambio en la primera pasada, está ordenado
        if(estado_swap == false){
            break;
        }

        estado_swap = false;
        // derecha -> izquierda (menor hacia el inicio)
        for(int *q = fin; q > ini; q--){
            if(*q < *(q-1)){
                swap(*q, *(q-1));
                estado_swap = true;
            }
        }
        ini++;
    }

}

int main(){
    int tamanio = 9;
    int M[] = {51, 3, 28, 35, 4, 2, 7, 23, 15};

    mostrar(M, M+(tamanio-1)); 
    cout << endl;

    cocktail(M, M+(tamanio-1)); 
    cout << endl;

    mostrar(M, M+(tamanio-1)); 

    return 0;
}
