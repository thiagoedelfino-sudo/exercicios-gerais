#include"receita.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NOME 100
#define MAX_INSTRUCAO 200

struct _Receita{
    char nomeMed[MAX_NOME],medicamento[MAX_NOME],nomePaci[MAX_NOME],instrucao[MAX_INSTRUCAO];
};

/*
    Função que cria uma receita e retorna o seu endereço de memória
    @param nomeMedicamento: nome do medicamento prescrito na receita
    @param nomePaciente: nome do paciente para quem a receita foi prescrita
    @param nomeMedico: nome do médico que prescreveu a receita
    @param instrucoes: instruções para o uso do medicamento
    @return: endereço de memória da receita criada
*/
Receita *criaReceita(char *nomeMedicamento, char *nomePaciente, char *nomeMedico, char *instrucoes){
    Receita *r=(Receita*)calloc(1,sizeof(Receita));
    strcpy(r->medicamento,nomeMedicamento);
    strcpy(r->nomePaci,nomePaciente);
    strcpy(r->nomeMed,nomeMedico);
    strcpy(r->instrucao,instrucoes);
    return r;
}

/*
    Função que lê os dados de uma receita a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da receita lida
*/
Receita *leReceita(){
     char nomeMed[MAX_NOME],medicamento[MAX_NOME],nomePaci[MAX_NOME],instrucao[MAX_INSTRUCAO];
     scanf("%[^\n]\n",nomeMed);
     scanf("%[^\n]\n",nomePaci);
     scanf("%[^\n]\n",medicamento);
     scanf("%[^\n]\n",instrucao);
     Receita *r=criaReceita(medicamento,nomePaci,nomeMed,instrucao);
     return r;

}

/*
    Função que calcula o preço de impressão de uma receita de acordo com a especificação
    @param dado: ponteiro genérico para a receita a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da receita
*/
float calculaPrecoImpressaoReceita(void *dado, float precoCaractere){
    float preco=0;
    Receita *r=(Receita*)dado;
    preco+=strlen(r->instrucao)+strlen(r->medicamento)+strlen(r->nomeMed)+strlen(r->nomePaci);
    return preco*=precoCaractere;
}

/*
    Função que imprime uma receita de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a receita a ser impressa
*/
void imprimeReceita(void *dado){
    Receita *r=(Receita*)dado;
    printf("--RECEITA   --\n");
    printf("MEDICAMENTO: %s\n",r->medicamento);
    printf("PACIENTE: %s\n",r->nomePaci);
    printf("INSTRUCOES: %s\n",r->instrucao);
    printf("MEDICO: %s\n",r->nomeMed);
    printf("--------\n");

}

/*
    Função que desaloca uma receita
    @param dado: ponteiro genérico para a receita a ser desalocada
*/
void desalocaReceita(void *dado){
    Receita *r=(Receita*)dado;
    if(r!=NULL){
        free(r);
    }
}