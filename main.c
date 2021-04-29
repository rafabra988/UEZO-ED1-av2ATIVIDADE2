#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoesed1t2.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
/*__________________________________________exe1__________________________________*/
//    int resp, valor;
//
//    FilaVazia();
//
//    printf("quanta posições tera na lista?");
//    scanf("%d",&resp);
//
//    for(int i=0;i<resp;i++){
//        printf("qual o valor do %dº elemento?",i+1);
//        scanf("%d",&valor);
//        inserir(valor);
//    }
//
//    printf("\n");
//    removdup();
//    imprimir();
/*________________________________________exe2____________________________________*/

    int valor1,valor2, resp, valor;

    FilaVazia();

    printf("quanta posições tera na lista?");
    scanf("%d",&resp);

    for(int i=0;i<resp;i++){
        printf("qual o valor do %dº elemento?",i+1);
        scanf("%d",&valor);
        inserir(valor);
    }
    while(valor1>resp){
        printf("gostária de pular quantos valores?\n");
        scanf("%d",&valor1);
        if(valor1>resp){
            printf("o valor deve ser menor q %d\n", resp+1);
        }

    }
    while(valor2>resp){
        printf("gostária de pular quantos valores?");
        scanf("%d",&valor1);
        if(valor2>resp){
            printf("o valor deve ser menor q %d\n", resp+1);
        }
    }



    pulareapagar(valor1,valor2);

    imprimir();

    return 0;
}
