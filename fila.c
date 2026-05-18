#include <stdio.h>
#include <stdlib.h>

#define SIZE 3
#define ERROFILACHEIA -1
#define ERROFILAVAZIA -2

typedef struct 
{
    int item[SIZE];
    int ini;
    int fim;
    int cont;
}FILA;

void iniciarFila(FILA *f){
    f->ini = 0;
    f->fim = 0;
    f->cont = 0;
}

int filaVazia(FILA *f){
    return f->cont == 0 ? 1 : 0;
}
int filaChaia(FILA *f){
    return f->cont == SIZE ? 1 : 0;
}

int adicionarNaFila(FILA *f, int valor){
    if (filaChaia(f)){
        return ERROFILACHEIA;
    }else{
        f->item[f->fim] = valor;
        f->cont++;
        if (f->fim == SIZE -1)
        {
            f->fim = 0;
        }else{
            f->fim++;
        }
        return f->fim;
        
    }
}

int retirarDaFila(FILA *f){
    if (filaVazia(f)){
        return ERROFILAVAZIA;
    }

    int valor = f->item[f->ini];

    if (f->ini == SIZE -1)
    {
        f->ini = 0;
    }else{
        f->ini++;
    }
    f->cont--;

    return valor;    
}

int main(){
    FILA f;
    iniciarFila(&f);
    int adicionado;

    adicionado = adicionarNaFila(&f, 10);
    adicionado = adicionarNaFila(&f, 20);
    adicionado = adicionarNaFila(&f, 30);

    printf("Retirando: %d\n ", retirarDaFila(&f));
}


