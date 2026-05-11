#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>


typedef struct{
    char nome[40];
    struct Musica *proximo;
    struct Musica *anterior;

}Musica;

Musica *atual = NULL;
Musica *inicio = NULL;

void inserir(char *nome){
    Musica *nova = (Musica*) malloc(sizeof(Musica));
    strcpy(nova->nome, nome);
    nova->proximo = NULL;

    if(inicio == NULL){
        nova->anterior = NULL;
        inicio = nova;
        atual = inicio;
    }else{
        Musica *temp = inicio;
        while (temp->anterior != NULL)temp = temp->proximo;
        temp->proximo = nova;
        nova->anterior = temp;
        
    }
    printf("Musica '%s' adicionada \n", nome);

}

void lista(){
    Musica *temp = inicio;
    if (!temp){
        printf("PlayList vazia \n");
        return;
    }
    printf("Minha Play\n");
    while(temp){
        printf("%s %s\n", temp == atual) ? "-> " : "  ", temp->nome;
        temp = temp->proximo;
    }
}


void remover(char *nome){
    Musica *temp = inicio;
    while (temp && strcmp(temp->nome, nome)!= 0)temp = temp->proximo;
    if (temp == atual) atual = (temp->proximo) ? temp->proximo : temp->anterior;
    if (temp->anterior) temp->anterior = temp->proximo;
    else inicio = temp->proximo;
    if(temp->proximo) temp->proximo = temp->anterior;

    free(temp);
    printf("Musica removida");    
}

void navegar(int mov){
    if (!atual) return;
    if(mov == 1 && atual->proximo) atual = atual->proximo;
    else if (mov == -1 && atual->anterior) atual = atual->anterior;
    printf("Musica atual: %s\n", atual->nome);
}

int main(){
    int op;
    char nome[40];

    do{
        printf("\n 1-Inserir |2-remover |3-Lista |4-proxima |5-anterior | 0-sair");
        scanf("%d", &op);
        switch (op){
        case 1:
            printf("NOME DA MUSICA: ");
            scanf("%[^\n}s", nome);
            inserir(nome);
            break;
        case 2:
            printf("NOME DA MUSICA: ");
            scanf("%[^\n]s", nome);
            remover(nome);
            break;
        case 3:
            lista();
        case 4:
            navegar(1);
        case 5:
            navegar(-1);
        
        }
    }while (op != 0);
    return 0;

}