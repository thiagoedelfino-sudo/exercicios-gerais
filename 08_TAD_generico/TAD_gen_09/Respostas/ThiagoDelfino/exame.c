#include"exame.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NOME 100

struct _Exame{
    char nomeMedico[MAX_NOME],solicitao[MAX_NOME],nomepaciente[MAX_NOME];
};

/*
    Função que cria um exame e retorna o seu endereço de memória
    @param nomePaciente: nome do paciente para quem o exame foi prescrita
    @param nomeMedico: nome do médico que prescreveu o exame
    @param solicitacao: solicitao de qual exame 
    @return: endereço de memória da examecriada
*/
Exame *criaExame(char *nomeMedico, char *nomePaciente, char *solicitacao){
    Exame *e=(Exame*)calloc(1,sizeof(Exame));
    strcpy(e->nomeMedico,nomeMedico);
    strcpy(e->nomepaciente,nomePaciente);
    strcpy(e->solicitao,solicitacao);
    return e;
}

/*
    Função que lê os dados de um exame a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da exame lida
*/
Exame *leExame(){
    
}

/*
    Função que calcula o preço de impressão de um exame de acordo com a especificação
    @param dado: ponteiro genérico para o exame a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão do exame
*/
float calculaPrecoImpressaoExame(void *dado, float precoCaractere);

/*
    Função que imprime um exame de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para o exame a ser impressa
*/
void imprimeExame(void *dado);

/*
    Função que desaloca um exame
    @param dado: ponteiro genérico para o exame a ser desalocada
*/
void desalocaExame(void *dado);