#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivoEntrada, *arquivoSaida;
    char nomeArquivoEntrada[100], nomeArquivoSaida[100];
    char caractere;
    int dentroDaTag = 0;

    printf("Digite o nome do arquivo HTML de entrada: ");
    scanf("%s", nomeArquivoEntrada);

    printf("Digite o nome do arquivo de saída (onde o texto sem as tags HTML será salvo): ");
    scanf("%s", nomeArquivoSaida);

    arquivoEntrada = fopen(nomeArquivoEntrada, "r");
    arquivoSaida = fopen(nomeArquivoSaida, "w");

    if (arquivoEntrada == NULL || arquivoSaida == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    while ((caractere = fgetc(arquivoEntrada)) != EOF) {
        if (caractere == '<') {
            dentroDaTag = 1;
        } else if (caractere == '>') {
            dentroDaTag = 0;
        } else if (!dentroDaTag) {
            fputc(caractere, arquivoSaida);
        }
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    printf("As tags HTML foram removidas e o texto foi salvo em '%s'.\n", nomeArquivoSaida);

    return 0;
}
