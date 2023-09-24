#ifndef linkedList_yan_h
#define linkedList_yan_h

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int tp_item;

typedef struct node{ //tipo auxiliar Nó
    tp_item element; //contém um elemento
    struct node* next; //contém o endereço que aponta para o próximo nó
} Node;

typedef Node* List; //tipo Lista que guarda o endereço do Nó raiz da lista

Node * start_list(){
    return NULL;
}

Node * start_node(){ //inicia um nó
    return (Node *) malloc(sizeof(Node)); //aloca memória pra criação da raiz da lista
}

int list_empty(List *list){
    if (*list == NULL)
        return true;
    return false;
}

int list_size(List *list){
    int size = 0;
    Node * current = *list;
    while (current != NULL){
        current = current->next;
        size++;
    }
    return size;
}

int add_end(List *list, tp_item value){

    Node *new_node = start_node(); //criando um nó novo

    if(new_node == NULL) //caso não consiga alocar a memória, ele retorna falso para sair da função
        return false;

    new_node->next = NULL; //marca o novo fim da lista
    new_node->element = value; //atribuindo o valor que queremos adicionar ao elemento do novo Nó

    if (list_empty(list)){//caso a lista esteja vazia:
        *list = new_node;//a raiz agora é o novo Nó criado
        return true;
    }

    //começamos a iterar a lista para achar o último Nó:
    Node * current = *list; //diz que um Nó atual é o Nó inicial da lista
    while (current->next != NULL){ //atualiza o nó atual para o próximo caso o próximo não seja o último (tenha valor NULL)
        current = current->next;
    }

    current->next = new_node;//diz que agora, o próximo do atual (último) é o novo Nó
    return true;
}

int add_start(List *list, tp_item value){ //adiciona elementos no início da lista
	
	Node *new_node = start_node(); //cria um novo nó
	
	if (new_node == NULL) //verifica se a alocação deu errado para retornar falso
		return false;
		
	new_node->element = value; //atribui o valor desejado ao elemento do novo Nó
	new_node->next = *list; //diz que o próximo Nó (do novo Nó) é a antiga raiz da lista
	
	*list = new_node; //diz que agora esse novo Nó é o Nó raiz da lista
	return true;
}

int add_at_index(List *list, int index, tp_item value){

    if (index < 0 || index > list_size(list) + 1){
        printf("\nList index out of range!\n");
        return false;
    }

    if (index == 0)
        return add_start(list, value);

    Node * new_node = start_node(); //cria um novo Nó

    if (new_node == NULL) //verifica se a alocação deu errado para retornar falso
        return false;

    Node * current = *list;
    for (int i = 0; i < index - 1; i++){
        current = current->next;
    }

    new_node->element = value; //atribui o valor desejado ao elemento do novo Nó
    new_node->next = current->next; //diz que o próximo Nó (do novo Nó) é o próximo do nó que queríamos adicionar coisas depois
    current->next = new_node;
    return true;

}

int replace_at_index(List *list, int index, tp_item value){
    if (index < 0 || index > list_size(list)){
        printf("\nList index out of range!\n");
        return false;
    }

    Node * current = *list;

    if (index != 0){
        for (int i = 0; i < index; i++){
            current = current->next;
        }
    }
    current->element = value;
    return true;
}

int remove_element(List *list, tp_item value){
    if (list_empty(list))
        return false;

    if ((*list)->element == value){
        Node *toDelete = *list;
        *list = (*list)->next;
        free(toDelete);
        return true;
    }

    Node * current = *list;
    while (current->next != NULL){
        if (current->next->element == value){
            Node *toDelete = current->next;
            current->next = current->next->next;
            free(toDelete);
            return true;
        }
        current = current->next;
    }
    printf("\nElement not found\n");
    return false;
}

int remove_at_index(List *list, int index){
    if (list_empty(list))
        return false;

    if (index < 0 || index > list_size(list)){
        printf("\nList index out of range!\n");
        return false;
    }

    if (index == 0){
        Node *toDelete = *list;
        *list = (*list)->next;
        free(toDelete);
        return true;
    }

    if (index == list_size(list)){
        Node * current = *list;
        for (int i = 0; i < index - 2; i++){
            current = current->next;
        }
        Node *toDelete = current->next;
        current->next = current->next->next;
        free(toDelete);
        return true;
    }


    Node * current = *list;
    for (int i = 0; i < index - 1; i++){
        current = current->next;
    }

    Node *toDelete = current->next;
    current->next = current->next->next;
    free(toDelete);

    return true;

}

int get_element(List *list, int index, tp_item *answer){
    if (list_empty(list)){
        printf("\nList is empty!\n");
        return false;
    }
    
    if (index < 0 || index > list_size(list)){
        printf("\nList index out of range!\n");
        return false;
    }

    Node * current = *list;

    if (index != 0){
        for (int i = 0; i < index; i++){
            current = current->next;
        }
    }

    *answer = current->element;
    return true;
}

void print_list(List *list){
    Node * current = *list;
    printf("[");
    while (current != NULL){
        printf("%d", current->element);
        if (current->next != NULL)
            printf(", ");
        current = current->next;
    }
    printf("]\n");
}

void free_list(List *list){
	//iteramos a lista novamente até chegar no último
	Node * current = *list;
    while (current != NULL){
    	Node *auxiliar = current; //um ponteiro de nó auxiliar, que guarda o endereço do Nó atual, para depois desalocar sua memória
        current = current->next; //atualiza o atual para o seu próximo
        free(auxiliar);
    }
    *list = NULL; //depois de desalocar todos os Nós, dizemos que a lista agora está vazia
}

#endif