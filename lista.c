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
       L->inicio=NULL;
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
    int p=L->info;
    printf("\t Lista \n");
    while (p != NULL){
        printf(" %d " , L->link.r.chave);
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
        L->V[i].proximo=L->V[anterior].proximo;
        L->V[anterior].proximo=i;
    }
}

int Obtencao_do_NO(Lista *L){
    int resultado= L->disponivel;
    if(L->disponivel!=inv)
        L->disponivel=L->V[L->disponivel].proximo;
    return resultado;
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
    Devolver_No_para_lista(L,i);
    return true;
    
}

void Devolver_No_para_lista(Lista *L, int i){
    L->V[i].proximo=L->disponivel;
    L->disponivel=i;
}
void reincializar_lista(Lista *L){
    inicializar_Lista(L);
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
                   inicializar_Lista(&L);
                   break;
            case 2:
                    printf("Digite a matricula do aluno: ");
                    scanf("%d",&reg.chave);
                    Inserir_elemento_ordenado(&L,reg);
                    break;


            case 3:
                    Imprimir_Lista(&L);
                    break;
            
            case 5:
                    printf("Digite o nome do aluno: ");
                    scanf("%s",reg.a.nome);
                    printf("Digite a matricula do aluno: ");
                    scanf("%d",&reg.chave);
                    Inserir_elemento_ordenado(&L,reg);
                    break;
            case 6:
                    printf("Digite a matricula do aluno que deseja excluir: ");
                    scanf("%d",&reg.chave);
                    Excluir_elemento_lista(&L,reg.chave);
        
        }
        printf("\n\n==================================\n\n");
        fflush(stdin);
        printf("Deseja sair do programa (s/n): \n");
        scanf("%c",&sair);
        printf("\n\n==================================\n\n");
    }while(sair!='s');
    return 0;
}