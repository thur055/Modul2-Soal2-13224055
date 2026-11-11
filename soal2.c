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
    //printf("Popped height: %d\n", N->height);
}

int main (){
    List L;
    char check = 'a';
    Node *N = (Node*)malloc(sizeof(Node));
    initList(&L);
    int height;
    int i = 0, a = 0;
    //char* string = (char*)malloc(sizeof(char)*MAX_LEN);
    while(scanf("%d", &height) == 1){
        Node* temp = (Node*)malloc(sizeof(Node));
        //printf("%d ", height);
        scanf("%c", &check);
        if(check == '\n'){
            break;
        }
        createNode(height, temp);
        push(&L, temp);
        i++;
    }

    /*
    
    while (string[i] != '\0'){
        Node* temp = (Node*)malloc(sizeof(Node));
        if(string[i] == ' '){
            i++;
            //printf("inispasi\n");
        }
        else{
            height = string[i] - '0';
            //printf("Height: %d\n", height);
            createNode(height, temp);
            push(&L, temp);
            i++;
        }
    }
    */
    int arr[i], out[i];
    int j = 0, x = 0;
    while (L.head != NULL){
        arr[j] = L.head->height;
        pop(&L, N);
        j++;
    }
    
    for(int k = 0; k < j;k++){
        if(k == 0){
            if (arr[k] < arr[1]){
                out[x] = k+1;
                x++;
            }
        }
        else{
            if(arr[k] < arr[k-1] && arr[k] < arr[k+1]){
                out[x] = k+1;
                x++;
            }
        }
        //printf("%d\n", arr[k]);
    }
    if (x == 0 || x == 1){
        printf("NONE");
    }
    else{
        for (int y = 0; y<x-1;y++){
            printf("%d ", out[y]);
        }
        printf("%d ", out[x-1]);
    }
}
