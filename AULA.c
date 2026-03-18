#include <stdio.h>  
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define max 50
#define inv -1

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
   // Tipo_Aluno h;
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

    
