#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int horas;
    int minutos;
    int segundos;
}horario;

typedef struct{
    int dia;
    int mes;
    int ano;
}data;

typedef struct{
    horario horario_comp;
    data data_comp;
    char descricao[50];
}compromisso;


void recebe(compromisso);
void imprime(compromisso);

int main(){
    compromisso comp;
    recebe(comp);
    

}

void recebe(compromisso comp){
    printf("\nDigite o dia do compromisso(D/MM/AAAA): ");
    scanf("%d %d %d", &comp.data_comp.dia, &comp.data_comp.mes, &comp.data_comp.ano);

    printf("\nInforme o horario do compromisso: ");
    scanf("%d %d %d", &comp.horario_comp.horas, &comp.horario_comp.minutos, &comp.horario_comp.segundos);

    printf("\nDecrição: ");
    fflush(stdin);
    scanf("%s", &comp.descricao);
    imprime(comp);
}

void imprime(compromisso comp){
    printf("\nData do compromisso: %d/%d/%d", comp.data_comp.dia, comp.data_comp.mes, comp.data_comp.ano);
    printf("\nhorario: %d:%d:%d", comp.horario_comp.horas, comp.horario_comp.minutos, comp.horario_comp.segundos);
    printf("\nDescricao: %s", comp.descricao);
}