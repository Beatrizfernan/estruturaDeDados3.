#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int valor;
    int prioridade;
    struct elemento *prox;
} Elemento;

typedef struct fila_prioridade
{
    Elemento *inicio;
} Fila_Prioridade;

void adicionar(Fila_Prioridade *fila, int valor, int prioridade)
{
    Elemento *novo_elemento = (Elemento *)malloc(sizeof(Elemento));
    novo_elemento->valor = valor;
    novo_elemento->prioridade = prioridade;
    novo_elemento->prox = NULL;

    if (fila->inicio == NULL)
    {
        fila->inicio = novo_elemento;
    }
    else
    {
        Elemento *anterior = NULL;
        Elemento *atual = fila->inicio;
        while (atual != NULL && atual->prioridade < prioridade)
        {
            anterior = atual;
            atual = atual->prox;
        }

        if (anterior == NULL)
        {
            novo_elemento->prox = fila->inicio;
            fila->inicio = novo_elemento;
        }
        else
        {
            anterior->prox = novo_elemento;
            novo_elemento->prox = atual;
        }
    }
}
void remover(Fila_Prioridade *fila, int valor)
{
    if (fila->inicio == NULL)
    {
        
        return;
    }

    Elemento *anterior = NULL;
    Elemento *atual = fila->inicio;

    while (atual != NULL && atual->valor != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        
        return;
    }

    if (anterior == NULL)
    {
       
        fila->inicio = atual->prox;
    }
    else
    {
        anterior->prox = atual->prox;
    }

    free(atual);
}
void imprimir(Fila_Prioridade *fila)
{
    Elemento *atual = fila->inicio;

    while (atual != NULL)
    {
        printf("Valor: %d - Prioridade: %d\n", atual->valor, atual->prioridade);
        atual = atual->prox;
    }
}

int main()
{
    Fila_Prioridade fila;
    fila.inicio = NULL;

    adicionar(&fila, 3, 2);
    adicionar(&fila, 5, 1);
    adicionar(&fila, 2, 4);
    adicionar(&fila, 4, 3);

    printf("Fila de prioridade:\n");
    imprimir(&fila);

    remover(&fila, 2);

    printf("Fila de prioridade após remocao:\n");
    imprimir(&fila);

    return 0;
}