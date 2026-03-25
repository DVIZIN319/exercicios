#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include <locale.h>
#include <stdbool.h>

typedef int Tipo_chave;

typedef struct{
    char nome_disc[40];
}Disciplina;
 

typedef struct{
    char nome[30];
    Disciplina D;
}Aluno;

typedef struct{
    Tipo_chave chave;
    Aluno a;
}Registro;

typedef struct AUX_ELEMENTO{
    Registro r;
    struct AUX_ELEMENTO *proximo;
}Elemento;

typedef Elemento *POINT;

typedef struct{
    Elemento *link;
    int info;
    POINT inicio;
}Lista;


void inicializar_Lista(Lista *L){
    L->inicio = NULL;
    
}

int Numero_Elementos(Lista *L){
    POINT aux=L->inicio;
    int tamanho = 0;
    while(aux != NULL){
        tamanho++;
        aux = aux->proximo;
    }
    return tamanho;

}

void Imprimir_Lista(Lista *L){
    POINT aux=L->inicio;
    printf("\t Lista \n");
    while (aux != NULL){
        printf("%s %d " , aux->r.a.nome,aux->r.chave);
        aux = aux->proximo;
    }
    printf("\n\n");
}

int Busca_sequencial_ordenada(Lista *L, Tipo_chave ch){
    POINT pos = L->inicio;
    while (pos != NULL)
    if (pos->r.chave==ch)
        return pos;
    pos = pos->proximo;
}

POINT Busca_Sequencial_Aux(Lista *L, Tipo_chave ch, POINT *anterior){
    *anterior=NULL;
    POINT atual=L->inicio;
    while((atual!=NULL)&&(atual->r.chave == ch)){
        *anterior=atual;
        atual=atual->proximo;
    }
    if((atual!=NULL)&&(atual->r.chave==ch))
        return atual;
    return NULL;
}

bool Inserir_elemento_ordenado(Lista *L, Registro r){
    Tipo_chave ch=r.chave;
    POINT anterior , i;
    i = Busca_Sequencial_Aux(L,ch,&anterior);
    if(i!=NULL)
        return false;
    i=(POINT)malloc(sizeof(Elemento));
    i->r=r;
    if (anterior==NULL){
        i->proximo=L->inicio;
        L->inicio=i;
    }
    else{
        i->proximo=anterior->proximo;
        anterior->proximo=i;
    }
    
}

/*int Obtencao_do_NO(Lista *L){
    POINT resultado;
    if(L->disponivel!=inv)
        L->disponivel=L->V[L->disponivel].proximo;
    return resultado;
}*/

bool Excluir_elemento_lista(Lista *L, Tipo_chave ch){
    POINT anterior, i;
    i = Busca_Sequencial_Aux(L,ch,&anterior);
    if(i == NULL)
        return false;
    if(anterior == NULL)
        L->inicio=i->proximo;
    else
        anterior->proximo=i->proximo;
    free(i);
    return false;
}

/*void Devolver_No_para_lista(Lista *L, int i){
    L->V[i].proximo=L->disponivel;
    L->disponivel=i;
}*/
void reincializar_lista(Lista *L){
    POINT aux=L->inicio;
    while(aux!=NULL){
        POINT limpar=aux;
        aux=aux->proximo;
        free(limpar);
    }
    L->inicio=NULL;
}

int main(){
    setlocale(LC_ALL,"");
    Lista L;
    char sair;
    int opcao = 0;
    Registro reg;

    inicializar_Lista(&L);
    do{
        printf("1-Criar lista de alunos: \n");
        printf("2- Inserir Aluno na lista: \n");
        printf("3- Imprimir a lista: \n");
        
        printf("Digite a opcao: \n");
        scanf("%d",&opcao);
        printf("\n==================================\n");
        
        switch(opcao){
            case 1:
                printf("Lista iniciada !!");
                inicializar_Lista(&L);
                break;
            case 2:
                    do{printf("Digite o nome do aluno: ");
                    scanf(" %[^\n]s", reg.a.nome);    
                    printf("Digite a matricula: ");
                    scanf("%d", &reg.chave);
    
                    if (Inserir_elemento_ordenado(&L, reg)) {
                        printf("Aluno inserido com sucesso!\n");
                    } else {
                        printf("Erro: Matrícula ja existe ou falha na insercao.\n");
                         }
                         break;
                    printf("deseja continuar cadastrando? (S/N)");
                    scanf("%d", &opcao);
                    }while (opcao != "n");
                    break;
                    
            case 3:
                    Imprimir_Lista(&L);
                    break;
        
        }
        printf("\n\n==================================\n\n");
        fflush(stdin);
        printf("Deseja sair do programa (s/n): \n");
        scanf("%c",&sair);
        printf("\n\n==================================\n\n");
    }while(sair!='s');
    return 0;
}