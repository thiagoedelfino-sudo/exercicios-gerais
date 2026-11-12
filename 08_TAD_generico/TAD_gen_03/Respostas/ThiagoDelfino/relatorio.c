#include"relatorio.h"
#include<stdio.h>
#include"aluno.h"


/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos){
    float media,nota,porceAlunosAprov,porceMas,porceFem,porceOutros;
    media=nota=porceAlunosAprov=porceFem=porceMas=0;
    int vSize=VectorSize(alunos);
    for(int i=0;i<vSize;i++){
        tAluno *a=(tAluno*)VectorGet(alunos,i);
        nota+=GetNotaAluno(a);
        if(GetGeneroAluno(a)=='F')
            porceFem++;
        else if(GetGeneroAluno(a)=='M')
            porceMas++;
        else
            porceOutros++;
        if(nota>=6)
            porceAlunosAprov++;
        
        
    }
    media=nota/vSize;
    porceFem=porceFem*100/vSize;
    porceMas=porceMas*100/vSize;
    porceOutros=porceOutros*100/vSize;
    porceAlunosAprov=porceAlunosAprov*100/vSize;
    printf("Media das notas: %.2f%\n",media);
    printf("porcentagem de alunos aprovados: %.2f%",porceAlunosAprov);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%\n",porceMas);
    printf("Feminino: %.2f%\n",porceFem);
    printf("Outro: %.2f%\n",porceOutros);
    
}
