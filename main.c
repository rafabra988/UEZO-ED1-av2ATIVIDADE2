#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct elemento{
    int info;
    struct elemento *prox;
};

typedef struct elemento Elemento;

Elemento * ini_ponto;
Elemento * ult_ponto;

void FilaVazia(){
    Elemento *aux;
    aux=(Elemento*)malloc(sizeof(Elemento));
    ini_ponto=aux;
    ult_ponto=aux;
}

int inserir(int add){
    Elemento *aux;
    aux=(Elemento*)malloc(sizeof(Elemento));
    aux->info = add;
    ult_ponto->prox=aux;
    ult_ponto=ult_ponto->prox;
    aux->prox=NULL;
}

void imprimir(){
    Elemento *aux;
    aux= ini_ponto->prox;
    while(aux!=NULL){
        printf("%d -> ",aux->info);
        aux=aux->prox;
    }
    printf("NULL");
}

void pesquisar(int x){
    int cont=0;
    Elemento *aux;
    aux= ini_ponto->prox;
    while(aux!=NULL){
        if(x==aux->info){
            printf("elemento encontrado");
            cont=1;
            aux=NULL;
        }else{
            aux=aux->prox;
        }
    }
    if(!cont){
        printf("elemento não foi encontrado");
    }

}

void remover(int x){
    int cont=0;
    Elemento *segundaux;
    Elemento *aux;
    aux= ini_ponto->prox;
    segundaux=ini_ponto;
    while(aux!=NULL){
        if(x==aux->info){
            printf("elemento removido");
            cont=1;
            segundaux->prox = aux->prox;
            aux=NULL;
        }else{
            aux=aux->prox;
            segundaux=segundaux->prox;
        }
    }
    if(!cont){
        printf("elemento não foi encontrado");
    }

}
//__________________________________________ex1___________________________________________
void ordenar(){
    Elemento *aux=ini_ponto;
    while(aux != NULL){
        Elemento *segundaux=aux->prox;
        while(segundaux!=NULL){
            if(aux->info > segundaux->info){
                int temp = aux->info;
                aux->info = segundaux->info;
                segundaux->info = temp;
            }
            segundaux=segundaux->prox;
        }
        aux=aux->prox;
    }
}

int remodup(){
    ordenar();
    int cont=0;
    Elemento *segundaux;
    Elemento *aux;
    Elemento *terceaux;
    aux= ini_ponto->prox;
    segundaux=ini_ponto;
    terceaux=ini_ponto;
    while(aux!=NULL){
        if(aux->info == segundaux->info){
            terceaux->prox=aux->prox;
            segundaux=NULL;
            aux=NULL;
            return 1;
        }else{
            aux=aux->prox;
            segundaux=segundaux->prox;
        }
        if(cont>0){
            terceaux=terceaux->prox;
        }
        cont++;
    }
    return 0;
}

//void removedupricado(){
//    int cont=0;
//    Elemento *segundaux;
//    Elemento *aux;
//    aux= ini_ponto->prox;
//    segundaux=ini_ponto;
//    if(aux!= NULL){
//        while(aux!=NULL){
//            aux=aux->prox;
//            cont++;
//        }
//        for(int i=0;i<cont;i++){
//            for(int j=0;j<cont;j++){
//                aux=aux->prox;
//                if(segundaux==a)
//            }
//            segundaux=segundaux->prox;
//        }
//    }
//}

int main()
{
    setlocale(LC_ALL, "Portuguese");


    int resp, valor, veri;

    FilaVazia();

    printf("quanta posições tera na lista?");
    scanf("%d",&resp);

    for(int i=0;i<resp;i++){
        printf("qual o valor do %dº elemento?",i+1);
        scanf("%d",&valor);
        inserir(valor);
    }
    veri=remodup();

    printf("%d",veri);


    for(int i=0; i<resp+1; i++){
        if(veri==1){
            remodup();
        }else{
            imprimir();
            break;
        }
    }
    //imprimir();

//
//    scanf("%d",&resp);
//    remover(resp);
//    printf("\n");
//    imprimir();

    return 0;
}
