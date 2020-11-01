#include <stdio.h>
#include <stdlib.h>

typedef struct dummy_node{
    int value;
    dummy_node *next;
}node;

int main(){
    node *head = malloc(sizeof(node*));
}
