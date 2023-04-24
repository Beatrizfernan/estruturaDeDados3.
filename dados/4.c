#include <stdio.h>
#include <stdlib.h>


/************************************************/

typedef struct no{
	float item;
	struct no *prox;
}no;

typedef struct{
	no *topo;
}Tpilha;


/************************************************/

void criaPilha(Tpilha *pilha);
void empilha(Tpilha *pilha, float n);
float desempilha(Tpilha *pilha);


/************************************************/

int main()
{
	Tpilha *pilha;
	char opcao;
	float n1, n2, resultado;
	pilha = (Tpilha *) malloc(sizeof(Tpilha));
	criaPilha(pilha);

	printf("Digite o primeiro numero: ");
	scanf("%f", &n1);
	empilha(pilha, n1);

	printf("Digite o segundo numero: ");
	scanf("%f", &n2);
	empilha(pilha, n2);

	printf("Digite a operacao (+,-,*,/): ");
	scanf(" %c", &opcao);

	switch(opcao){
		case '+':
			resultado = desempilha(pilha) + desempilha(pilha);
			break;
		case '-':
			n2 = desempilha(pilha);
			n1 = desempilha(pilha);
			resultado = n1 - n2;
			break;
		case '*':
			resultado = desempilha(pilha) * desempilha(pilha);
			break;
		case '/':
			n2 = desempilha(pilha);
			n1 = desempilha(pilha);
			resultado = n1 / n2;
			break;
		default:
			printf("Operação inválida.\n");
			return 0;
	}

	printf("Resultado: %.2f\n", resultado);

	free(pilha->topo);
	free(pilha);

	return (0);
}

void criaPilha(Tpilha *pilha){
	pilha->topo=NULL;
}

void empilha(Tpilha *pilha, float n){
	no *aux;
	aux = (no *) malloc(sizeof(no));
	aux->item = n;
	aux->prox = pilha->topo;
	pilha->topo = aux;
}

float desempilha(Tpilha *pilha){
	no *aux;
	float i;
	aux = pilha->topo;
	pilha->topo = pilha->topo->prox;
	i = aux->item;
	free(aux);
	return(i);
}