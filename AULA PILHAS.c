#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#define MAX 5

typedef struct
{
    int valor;   /* data */
}Item;

typedef struct 
{
    Item itens[MAX];
    int topo;
}Pilha;

void resetar(Pilha *p){
    p->topo = -1;

}

int isFull(Pilha *p){
    return p->topo == MAX  - 1;

}

int isEmpty(Pilha *p){
    return p->topo == -1;
}

void push(Pilha *p, Item item){
    if (isFull(p)){
        printf("Pilha Cheia\n");
        return;
    }

    p->topo++;
    p->itens[p->topo] = item;
}

Item pop(Pilha *p){
    Item vazio = {0};

    if (isEmpty(p)){
        printf("Pilha Vazia\n");
        return vazio;
    }

    Item removido = p->itens[p->topo];
    p->topo--;
    return removido;
}

void print(Pilha *p){
    if (isEmpty(p)){
        printf("Pilha vazia\n");
        return;
    }

    printf("Topo ->\n");
    for (int i = )
}


