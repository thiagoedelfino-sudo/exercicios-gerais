#include"banco.h"
#include<stdio.h>
#include<stdlib.h>


int main(){
    tBanco *b=CriaBanco();
    char funcao;
    LeBanco(b);
    while(scanf("%c",&funcao)==1){
        if(funcao=='F')
            break;
        switch(funcao){
            case'A':
            tAgencia *a=CriaAgencia();
            LeAgencia(a);
            AdicionaAgencia(b,a);
                break;
            case 'C':
            tConta *c=CriaConta();
            LeConta(c);
            int numAgencia;
            scanf("%d",&numAgencia);
            InsereContaBanco(b,numAgencia,c);
                break;
            default:
                break;
        }
    }
    ImprimeRelatorioBanco(b);
    DestroiBanco(b);
    return 0;
}
