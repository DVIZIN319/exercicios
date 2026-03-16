#include <stdio.h>  
#include <stdlib.h>

#define max 50
#define inv -1

typedef int Tipo_chave;

typedef struct{
    Tipo_chave chave;
}Registro;

typedef struct{
    Registro r;
    int proximo;
}Elemento;

typedef struct {
    Elemento V[max];
    int inicio;
    int disponivel;
}Lista;

void inicializar_Lista(Lista *L){
    int i;
    for(i=10;i<max-1;i++)
        L->V[i].proximo=i+1;
    L->V[max-1].proximo=inv;
    L->inicio=inv;
    L->disponivel=0;   
}

int Numero_Elementos(Lista *L){
    int i=L->inicio;
    int tamanho=0;
    while(i != inv){
        tamanho++;
        i=L->V[i].proximo;
    }
    return tamanho;
}

void Imprimir_Lista(Lista *L){
    int i=L->inicio;
    printf("\t Lista \n");
    while (i!=inv){
        printf(" %d ",L->V[i].r.chave);
        i=L->V[i].proximo;
    }
    printf("\n\n");
}

int Busca_sequencial_ordenada(Lista *L, Tipo_chave ch){
    int i=L->inicio;
    while (i!=inv && L->V[i].r.chave<ch)
        i=L->V[i].proximo;
    if (i!=inv && L->V[i].r.chave==ch)
        return i;
    else return inv;
}

bool Inserir_elemento_ordenado(Lista *L, Registro r){
    if(L->disponivel==inv)
        return false;
    int anterior=inv;
    int i=L->inicio;
    Tipo_chave ch=r.chave;
    while (i!=inv && L->V[i].r.chave<ch)
    {
        anterior=i;
        i=L->V[i].proximo;
    }
    if(i!=inv && L->V[i].r.chave==ch)
        return false;
    i=Obtencao_do_NO(L);
    L->V[i].r=r;
    if (anterior==inv){
        L->V[i].proximo=L->inicio;

    }
    else{
        L->V[i].proximo
    }
}

int Obtencao_do_NO(Lista *L){
    int resultado= L->disponivel;
    if(L->disponivel)
}

bool Excluir_elemento_lista(Lista *L, Tipo_chave ch){
    int anterior = inv;
    int i=L->inicio;
    while (i!=inv && L->V[i].r.chave<ch){
        anterior=i;
        i=L->V[i].proximo;
    }
    if (anterior == inv || L->V[i].r.chave!=ch)
        return false;
    if(anterior==inv)
        L->inicio=L->V[i].proximo;
    else
        L->V[anterior].proximo=L->V[i].proximo;
    Devolver_No_para_lista
    
}

void Devolver_No_para_lista(Lista *L, int i){
    L->V[i].proximo=L->disponivel;
    L->disponivel=i;
}
void reincializar_lista(Lista *L){
    inicializar_Lista(L);
}