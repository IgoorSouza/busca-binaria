#include <cstdio>
#include <cstring>
#include <cctype>

int buscaBinaria(char nomes[][100], int n, char* busca) {
    int s = 0, e = n - 1;
    int inicio = -1;

    while (s <= e) {
        int m = (s + e) / 2;
        int i = 0;
        bool possuiBusca = true;

        while (busca[i] != '\0') {
            if (tolower(nomes[m][i]) != tolower(busca[i])) {
                possuiBusca = false;
                break;
            }

            i++;
        }

        if (possuiBusca) {
            inicio = m;
            break;
        } else if (strcasecmp(nomes[m], busca) > 0) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }

    return inicio;
}

int main() {
    char nomes[1000][100];
    int numNomes = 0;
    char busca[100];
    FILE* arquivo = fopen("nomes.txt", "r");

    scanf("%s", busca);

    while (fgets(nomes[numNomes], 100, arquivo)) {
        nomes[numNomes][strcspn(nomes[numNomes], "\n")] = '\0';
        numNomes++;
    }

    fclose(arquivo);
    int inicio = buscaBinaria(nomes, numNomes, busca);

    for (int i = inicio; i < numNomes; i++) {
        int j = 0;
        bool possuiBusca = true;

        while (busca[j] != '\0') {
            if (tolower(nomes[i][j]) != tolower(busca[j])) {
                possuiBusca = false;
                break;
            }

            j++;
        }

        if (possuiBusca) {
            printf("%s\n", nomes[i]);
        }
    }

    return 0;
}
