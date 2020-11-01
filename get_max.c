#include <stdio.h>

int get_max(int array[], int size){
    int max = 0;
    for(int i = 0; i < size; i++){
        if(array[i] > max)
            max = array[i];
    }
    return max;
}

int main(){
    int array[7] = {1,5,19,3,4,2,10};
    printf("max: %d", get_max(array, 7));
}
