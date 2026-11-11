#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100
typedef struct Node{
    int height;
    struct Node *Next; 
} Node;

typedef struct List{
    struct Node* head;
} List;

void createNode(int height, Node* N){
    N->height = height;
    N->Next = NULL;
}
void initList(List *L){
    L->head = NULL;
}

void push(List *L, Node* N){
    if (L->head == NULL){
        L->head = N;
        return;
    }
    Node *temp;
    temp = L->head;
    L->head = N;
    N->Next = temp;
}

void pop(List *L, Node* N){
    if (L->head == NULL){
        return;
    }
    N = L->head;
    L->head = N->Next;
    //printf("%d\n", N->height);
}

int main (){
    List L;
    Node *N = (Node*)malloc(sizeof(Node));
    initList(&L);
    int height;
    char check;
    int i = 0;
    while (check != '\n'){
        Node* temp = (Node*)malloc(sizeof(Node));
        scanf("%d%c", &height, &check);
        createNode(height, temp);
        push(&L, temp);
        i++;
    }
    int arr[i], out[i];
    int j = 0, x = 0;
    while (L.head != NULL){
        arr[j] = L.head->height;
        pop(&L, N);
        j++;
    }
    for(int k = 0; k < i;k++){
        if(k == 0){
            if (arr[k] < arr[1]){
                out[x] = arr[k];
                x++;
            }
        }
        else{
            if(arr[k] < arr[k-1] && arr[k] < arr[k+1]){
                out[x] = arr[k];
                x++;
            }
        }
    }
    for (int y = x-1; y>0;y--){
        printf("%d ", out[y]);
    }
    printf("%d\n", out[0]);
    
}
