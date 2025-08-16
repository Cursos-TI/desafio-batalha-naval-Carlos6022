#include <stdio.h>

void imprimirMar(int valor, int repeticoes) {
    for(int i = 0; i < repeticoes; i++) {
        printf("%d  ", valor);
    }
}

int main() {
    int tabuleiro[10][10];                                                 // Tabuleiro 10x10
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

    // Navio diagonal principal
    int navioLinhaDiagonalP = 4;
    int navioColunaDiagonalP = 4;
    int navioTamanhoDiagonalP = 3;

    // Navio diagonal secundaria
    int navioLinhaDiagonalS = 7;
    int navioColunaDiagonalS = 4;
    int navioTamanhoDiagonalS = 3;

    // Inicializa o tabuleiro com água (0)
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Validação do navio horizontal
    if(navioLinha < 1 || navioLinha > 10 ||
       navioColunaInicio < 1 || navioColunaInicio > 10 ||
       navioColunaInicio + navioTamanho - 1 > 10) {
        printf("Erro: navio horizontal fora dos limites!\n");
        return 1;
    }

    // Coloca o navio horizontal e valida sobreposição
    for(int j = navioColunaInicio - 1; j < navioColunaInicio - 1 + navioTamanho; j++) {
        if(tabuleiro[navioLinha - 1][j] == 3) {
            printf("Erro: sobreposição de navios horizontal! \n");
            return 1;
        }
        tabuleiro[navioLinha - 1][j] = 3;
    }

    // Validação do navio vertical
    if(navioColunaV < 1 || navioColunaV > 10 ||
       navioLinhaInicioV < 1 || navioLinhaInicioV > 10 ||
       navioLinhaInicioV + navioTamanhoV - 1 > 10) {
        printf("Erro: navio vertical fora dos limites!\n");
        return 1;
    }

    // Coloca o navio na vertical e valida a sobreposição
    for(int i = navioLinhaInicioV - 1; i < navioLinhaInicioV - 1 + navioTamanhoV; i++) {
        if(tabuleiro[i][navioColunaV - 1] == 3) {
            printf("Erro: sobreposição de navios vertical! \n");
            return 1;
        }
        tabuleiro[i][navioColunaV - 1] = 3;
    }

    // Validação do navio diagonal principal
    if(navioLinhaDiagonalP < 1 || navioLinhaDiagonalP > 10 ||
       navioColunaDiagonalP < 1 || navioColunaDiagonalP > 10 ||
       navioLinhaDiagonalP + navioTamanhoDiagonalP - 1 > 10 ||
       navioColunaDiagonalP + navioTamanhoDiagonalP - 1 > 10) {
        printf("Erro: navio diagonal principal fora dos limites! \n");
        return 1;
    }

    // Coloca o navio na diagonal principal e valida a sobreposição
    for(int k = 0; k < navioTamanhoDiagonalP; k++) {
        int linha = navioLinhaDiagonalP - 1 + k;
        int coluna = navioColunaDiagonalP - 1 + k;
        if(tabuleiro[linha][coluna] == 3) {
            printf("Erro: sobreposição de navios na Diagonal principal \n");
            return 1;
        }
        tabuleiro[linha][coluna] = 3;
    }

    // Validação do navio diagonal secundaria
    if(navioLinhaDiagonalS < 1 || navioLinhaDiagonalS > 10 ||
       navioColunaDiagonalS < 1 || navioColunaDiagonalS > 10 ||
       navioLinhaDiagonalS + navioTamanhoDiagonalS - 1 > 10 ||
       navioColunaDiagonalS - navioTamanhoDiagonalS + 1 < 1) {
        printf("Erro: navio diagonal secundaria fora dos limites!\n");
        return 1;
    }

    // Coloca o navio na diagonal secundaria e valida a sobreposição
    for(int k = 0; k < navioTamanhoDiagonalS; k++) {
        int linha = navioLinhaDiagonalS - 1 + k;
        int coluna = navioColunaDiagonalS - 1 - k; // vai diminuindo a coluna
        if(tabuleiro[linha][coluna] == 3) {
            printf("Erro: sobreposição de navios na Diagonal secundaria \n");
            return 1;
        }
        tabuleiro[linha][coluna] = 3;
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
        for(int j = 1; j <= 10; j++) {
            printf("%d  ", tabuleiro[i][j - 1]);
        }
        printf("\n"); // quebra a linha quando ela finaliza(linha dos 0)
    }

    return 0;
}