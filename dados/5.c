#include <stdio.h>
#include <string.h>

int eConsoante(char c) {
    char vogais[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int i;
    for (i = 0; i < 10; i++) {
        if (c == vogais[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char SequenciaDeLetras[1000], Consoantes[1000], NaoEConsoante[1000];
    int i, j = 0, k = 0;
    
    printf("Digite a sequencia de caracteres: ");
    fgets(SequenciaDeLetras, sizeof(SequenciaDeLetras), stdin);

    // Remove o '\n' da sequência de caracteres
    if (SequenciaDeLetras[strlen(SequenciaDeLetras)-1] == '\n') {
        SequenciaDeLetras[strlen(SequenciaDeLetras)-1] = '\0';
    }
    
    for (i = 0; i < strlen(SequenciaDeLetras); i++) {
        if (SequenciaDeLetras[i] == '\n') {
            // Ignora o caractere '\n'
        }
        else if (eConsoante(SequenciaDeLetras[i])) {
            Consoantes[j++] = SequenciaDeLetras[i];
        }
        else {
            NaoEConsoante[k++] = SequenciaDeLetras[i];
        }
    }
    Consoantes[j] = '\0';
    NaoEConsoante[k] = '\0';
    
    printf(" %s%s", NaoEConsoante, strrev(Consoantes));
    
    return 0;
}