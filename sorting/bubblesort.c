#include <stdio.h>

void bubble_sort(int array[], int size){
    int aux;
    for(int i = 1; i < size; i++){
        printf("\n%d ", i);

        for(int k = 0; k < size; k++) {
            printf("%d, ", k);

            if(array[k] > array[k+1]){
                aux = array[k];       
                array[k] = array[k+1];
                array[k+1] = aux;
            }
        }
    }
}

int main(){
    int array[7] = {1,5,19,3,4,2,10};
    bubble_sort(array, 7);
}
