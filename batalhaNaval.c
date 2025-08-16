#include <stdio.h>

void imprimirMar(int valor, int repeticoes) {
    for(int i = 0; i < repeticoes; i++) {
        printf("%d  ", valor);
    }
}

int main() {

    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Colunas
    int linhas[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};                      // Linhas

    // Navio horizontal
    int navioLinha = 3;        // Linha do navio horizontal
    int navioColunaInicio = 4; // Coluna inicial
    int navioTamanho = 3;      // Comprimento

    // Navio vertical
    int navioColunaV = 8;      // Coluna H (posição 8)
    int navioLinhaInicioV = 6; // Linha Inicial
    int navioTamanhoV = 3;     // Comprimneto vartical

    // Validação do navio horizontal
    if(navioLinha < 1 || navioLinha > 10 ||
       navioColunaInicio < 1 || navioColunaInicio > 10 ||
       navioColunaInicio + navioTamanho - 1 > 10) {
        printf("Erro: navio horizontal fora dos limites!\n");
        return 1;
    }

    // Validação do navio vertical
    if(navioColunaV < 1 || navioColunaV > 10 ||
       navioLinhaInicioV < 1 || navioLinhaInicioV > 10 ||
       navioLinhaInicioV + navioTamanhoV - 1 > 10) {
        printf("Erro: navio vertical fora dos limites!\n");
        return 1;
    }

    // Cabeçalho do tabuleiro (colunas)
    for(int i = 0; i < 10; i++) { // Imprime os caracteres das colunas e posiciona o 'A' em cima da primerira coluna
        if(i == 0) {
            printf("   %c  ", colunas[i]); // caso seja o 'A' ele imprime com 3 espaços
        } else {
            printf("%c  ", colunas[i]); // imprime os restantes dos caracteres restante sem espço
        }
    }

    printf("\n"); // Quebra a linha quando ela finaliza(linha das colunas)

    // Construindo as linhas
    for(int i = 0; i < 10; i++) { // repete 10 vezes formando um tabuleiro 10X10

        if(linhas[i] == 10) { // imprime o numero referente a linha, se não for o 10 ele adiciona um espaço, para que um numero fique um em baixo do outro
            printf("%d ", linhas[i]);
        } else {
            printf(" %d ", linhas[i]); // adiciona o espaço se não for o 10
        }

        // Percorre as 10 colunas
        for(int j = 1; j <= 10; j++) {
            int valor = 0; // Valor padrão para se referir a água

            // Navio horizontal
            if(linhas[i] == navioLinha &&
               j >= navioColunaInicio &&
               j < navioColunaInicio + navioTamanho) {
                valor = 3;
            }

            // Navio vertical
            if(j == navioColunaV &&
               linhas[i] >= navioLinhaInicioV &&
               linhas[i] < navioLinhaInicioV + navioTamanhoV) {
                valor = 3;
            }

            printf("%d  ", valor);
        }

        printf("\n"); // quebra a linha quando ela finaliza(linha dos 0)
    }
}