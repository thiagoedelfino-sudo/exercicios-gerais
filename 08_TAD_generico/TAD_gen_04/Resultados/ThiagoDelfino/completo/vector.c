
#include"vector.h"
#include<stdlib.h>
#include<stdio.h>

struct Vector{
    int vectorSize;
    DataType *vetor;
};
/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector *v=(Vector*)calloc(1,sizeof(Vector));
    v->vetor=(DataType*)calloc(1,sizeof(DataType));
    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val){
    v->vetor[v->vectorSize]=val;
    v->vectorSize++;
    v->vetor=realloc(v->vetor,(v->vectorSize+1)*sizeof(DataType*));
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i){
    return v->vetor[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v){
    return v->vectorSize;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    if(v!=NULL){
        for(int i=0;i<v->vectorSize;i++){
            destroy(v->vetor[i]);
        }
        free(v->vetor);
        free(v);
    }
}
