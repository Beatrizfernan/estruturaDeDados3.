#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *prox;
} No;

No *topo = NULL;

void empilhar(int c) {
    No *novo = (No *) malloc(sizeof(No));
    novo->chave = c;
    novo->prox = topo;
    topo = novo;
}

int desempilhar() {
    if (topo == NULL) {
        printf("A pilha está vazia!\n");
        return -1;
    }
    int c = topo->chave;
    No *aux = topo;
    topo = topo->prox;
    free(aux);
    return c;
}

void remover(int c) {
    No *atual = topo, *anterior = NULL;
    while (atual != NULL) {
        if (atual->chave == c) {
            if (anterior == NULL) {
                topo = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Item removido com sucesso!\n");
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("O item não foi encontrado na pilha!\n");
}

void exibir() {
    printf("Pilha: ");
    No *atual = topo;
    while (atual != NULL) {
        printf("%d ", atual->chave);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    empilhar(3);
    empilhar(5);
    empilhar(2);
    empilhar(4);
    exibir();
    int c;
    printf("Digite a chave do item a ser removido: ");
    scanf("%d", &c);
    remover(c);
    exibir();
    return 0;
}