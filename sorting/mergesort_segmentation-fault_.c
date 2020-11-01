/*
 * Time complexity:
 *  +/- the same every case: 0(n*log(n)) 
 */

#include <stdio.h>
#include <stdlib.h>

void msort(int* array, int* aux_array, int left_delimiter, int right_delimiter);
void merge(int* array, int* aux_array, int left_delimiter, int mid_point, int right_delimiter);

/*
 * Function: mergesort
 * --------------------
 *  (wrapper for msort)
 *  
 *  input: int array
 *  no output 
 *  effect: sorts the given int array
 */

void mergesort(int* array){
    // Gets array size
    int array_size = sizeof(array)/sizeof(array[0]);
    
    // Allocates the aux_array and delimiter variables
    int *aux_array = malloc(sizeof(int)*array_size);
    int left_delimiter = 0;
    int right_delimiter = array_size-1;

    msort(array, aux_array, left_delimiter, right_delimiter);

    free(aux_array);
}

/*
 * Function: msort
 * ---------------
 *  input:  int array,
 *          aux int array,
 *          int left_delimiter,
 *          int right_delimiter
 *  no output 
 *  effect: sorts the given int array
 */ 

void msort(int* array, int* aux_array, int left_delimiter, int right_delimiter){
    // Gets array size
    int array_size = sizeof(array)/sizeof(array[0]);
    
    // Recursion base case
    if(left_delimiter==right_delimiter)
        return;

    // Recursion steps
    int mid_point = (left_delimiter+right_delimiter)/2;
    msort(array, aux_array, left_delimiter, mid_point);
    msort(array, aux_array, mid_point+1, right_delimiter);
    merge(array, aux_array, left_delimiter, mid_point, right_delimiter);
}

/*
 * Function: merge
 * ---------------
 *  input:  int array,
 *          aux int array,
 *          int left_delimiter,
 *          int mid_point
 *          int right_delimiter
 *  effect: merge two orderly arrays in order
 */
void merge(int* array, int* aux_array, int left_delimiter, int mid_point, int right_delimiter){
    // Merge delimiters
    int i = left_delimiter; 
    int j = mid_point+1;

    // For each item in the array,
    for(int k = left_delimiter; k < right_delimiter; k++){
        // if first half "is empty" 
        if(i == mid_point+1){
            aux_array[k] = array[j];
            j++;
        }
        // if second half "is empty"
        else if(j == right_delimiter+1){
            aux_array[k] = array[i];
            i++;
        }
        // if both halfs are not "empty" i item < j item
        else if(array[i] < array[j]){
            aux_array[k] = array[i];
            i++;
        }
        // if both halfs are not "empty" j item < i item
        else{
            aux_array[k] = array[j];
            j++;
        }
    }

    // Copy each element from aux_array to array
    for(int k = left_delimiter; k < right_delimiter; k++){
        array[k] = aux_array[k];
    }
}


// Testing
int main(void){
    int array[5] = {4, 5, 1, 2, 3};

    // Prints input array
    printf("input array: { ");
    for(int i=0; i<5; i++){
        printf("%d, ",array[i]);
    }
    printf("}\n");


    mergesort(array);

    // Prints output array
    printf("output array: { ");
    for(int i=0; i<5; i++){
        printf("%d, ",array[i]);
    }
    printf("}\n");

    return 1;
}
