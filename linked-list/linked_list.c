#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Linked_list Linked_list;

struct Node{
    int val;
    Node* next;
};

int push(Linked_list* list, int val);

void print_list_forwards(Linked_list* list);

struct Linked_list {
    Node* head;
    Node* tail;
    int (*push)(Linked_list*, int);
    void(*print_list_forwards)(Linked_list*);
};

void print_list_forwards(Linked_list* list){
   
    Node* node = list->head;
    printf("%d", node->val);
    node = node->next;
   
    while(node != NULL){
        printf(", %d", node->val);
        node = node->next;
    }
}

Linked_list Linked_list_init(){
   
    Linked_list list;
       
    list.push = &push;
    list.print_list_forwards = &print_list_forwards;
   
    return list;
}

int push(Linked_list* list, int val){
   
    Node* new_node = (Node*) malloc(sizeof (Node));
   
    new_node->val = val;
    new_node->next = NULL;
   
    if(list->head == NULL){
        list->head = new_node;
        return 1;
    }
    if(list->tail == NULL){
        list->tail = new_node;
        list->head->next = new_node;
        return 1;
    }
    else{
        list->tail->next = new_node;
        list->tail = new_node;
        return 1;
    }
    return -1;
}


int main(){

    Linked_list lista = Linked_list_init();

    lista.push(&lista, 5);
    lista.push(&lista, 25);
   
    lista.print_list_forwards(&lista);

    return 0;
}