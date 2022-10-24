#include<stdio.h>
#include<stdlib.h>

typedef struct vertice{
    int chave;
    struct vertice * dir;
    struct vertice * esq;
}VERTICE;

VERTICE * raiz = NULL; //vazia!!!!
int tam = 0;

/*procedimento busca-arvore(x, pt, f)
    se pt = vazio então f = 0
    senão se x = pt.chave então f = 1
    senão se x < pt.chave então
            se pt.esq = vazio então f = 2
            senão pt = pt.esq
            busca-arvore(x, pt, f)
    senão se pt.dir = vazio então f = 3
        senão pt = pt.dir
        busca-arvore(x, pt, f)*/

VERTICE* buscar(int x, VERTICE *aux){
    if(aux == NULL){
        return NULL; //vazia
    }else if (x == aux->chave){ 
        return aux;
    }else if(x < aux->chave){ //esq
        if(aux->esq == NULL){
            return aux;
        }else{
            return buscar(x, aux->esq);
        }
    }else{ //dir
        if(aux->dir == NULL){
            return aux;
        }else{
            return buscar(x, aux->dir);
        }
    }
}

void adicionar(int chave){
    VERTICE* aux = buscar(chave, raiz);
    if(aux != NULL && aux->chave == chave){
        //chave já existe na árvore!
        printf("insercao invalida!\n");
    }else{
        VERTICE* novo = malloc(sizeof(VERTICE));
        novo->chave = chave;
        novo->esq = NULL;
        novo->dir = NULL;
        if(aux == NULL){ //vazia
            raiz = novo;
        }else if(chave < aux->chave){//esq
            aux->esq = novo;
        }else{ //dir
            aux->dir = novo;
        }
    }
}

// Implementação do trabalho
VERTICE* remover(int chave,VERTICE *aux){
    if (aux == NULL && aux->chave == chave)
    {
        printf("\nValor nao encotrado\n");
        return NULL;
    }
    else
    {
        if (aux->chave == chave)
        {   // remover folha
            if (aux->esq == NULL && aux->dir == NULL)
            {
                free(aux);
                printf("\nValor removido: %d\n",chave);
                return NULL;
            }
            else
            {   // remover 2 filhos ou remoção da raiz
                if (aux->esq != NULL && aux->dir != NULL)
                {
                    VERTICE *lixo = aux->esq;
                    while (lixo->dir != NULL)
                    {
                        lixo = lixo->dir;
                    }
                    aux->chave = lixo->chave;
                    lixo->chave = chave;
                    printf("\nValor aser removido: %d!",chave);
                    aux->esq = remover(chave,aux->esq);
                    return aux;
                }
                else
                {   // remover 1 filho
                    VERTICE *lixo;
                    if (aux->esq != NULL)
                    {
                        lixo = aux->esq;
                    }
                    else
                    {
                        lixo = aux->dir;
                    }
                    free(aux);
                    printf("\nNo com 1 filho removido: %d\n",chave);
                    return lixo;
                }
            } 
        }
        else
        {
            if (chave < aux->chave)
            {
                aux->esq = remover(chave,aux->esq);
            }
            else
            {
                aux->dir = remover(chave,aux->dir);
            }
            return aux;
        }
    }
}

void in_ordem(VERTICE *aux){
    
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
    
    printf("%d ",aux->chave);
    
    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }
}

int main(){

    adicionar(8);
    adicionar(4);
    adicionar(16);
    adicionar(2);
    adicionar(6);
    adicionar(12);
    adicionar(18);
    adicionar(1);
    adicionar(3);
    adicionar(5);
    adicionar(7);
    adicionar(10);
    adicionar(14);
    adicionar(17);
    adicionar(19);
    adicionar(9);
    adicionar(11);
    adicionar(13);
    adicionar(15);
    adicionar(20);
    printf("\nImprimindo arvore...\n");
    in_ordem(raiz);
    remover(15,raiz);// remove folha
    in_ordem(raiz);
    remover(19,raiz);// remove NO com 1 filho
    in_ordem(raiz);
    remover(6,raiz);// remove NO com 2 filhos
    in_ordem(raiz);
    remover(8,raiz);// remove a RAIZ
    in_ordem(raiz);
    remover(1,raiz);// remove folha
    in_ordem(raiz);
    remover(9,raiz);// remove folha
    in_ordem(raiz);
    remover(14,raiz);// remove NO com 2 filhos
    in_ordem(raiz);
    remover(4,raiz);// remove NO com 2 filhos
    in_ordem(raiz);
    return 0;
}