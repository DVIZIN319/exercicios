#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 5

typedef struct Fila{
    
    int item[MAXSIZE];
    int fim;
    int ini;
    int cont;

}Fila;

void iniciar(Fila *f){
    f->ini = 0;
    f->fim = 0;
    f->cont = 0;
}

void inserir(Fila *f){
    if(f->cont == MAXSIZE){
        printf("\nFILA CHEIA");
        return;

    }
    int valor;
    printf("\ninsira um numero: ");
    scanf("%d", &valor);

    f->item[f->fim] = valor;
    f->fim = (f->fim + 1 ) % MAXSIZE;
    f->cont++;
    printf("\n!!!inserido!!!\n");
}

void remover(Fila *f){
    if (f->cont == 0){
        printf("\nFILA JÀ ESTA VAZIA");
        return;
    }
    int itemExcluido = f->item[f->ini];

    f->ini = (f->ini + 1 ) % MAXSIZE;
    f->cont--;

    printf("ITEM REMOVIDO");
}

void listar(Fila *f){
    if(f->cont == 0){
        printf("\nA FILA ESTA VAZIA");
        return;
    }
    printf("\nFILA: ");
    int ind = f->ini;

    for(int i = 0; i < f->cont; i++){
        printf("\n -%d- ", f->item[ind]);
        ind = (ind + 1) % MAXSIZE;
    }
}

int main(){
    Fila minhaFila;
    iniciar(&minhaFila);
    int op;
    
    do{
        printf("\nESCOLHA\n");
        printf("\n 1-INSERIR\n 2-REMOVER\n 3-LISTAR\n 4-SAIR\n");
        scanf("%d",&op);

        switch (op)
        {
        case 1:
            inserir(&minhaFila);
            break;
        case 2:
            remover(&minhaFila);
            break;
        case 3:
            listar(&minhaFila);
            break;
        case 4:
            printf("saindo.....");
            break;
        
        default:
            printf("INVALIDO");
            break;
        }

    }while (op != 4);
    
    return 0;
    
}