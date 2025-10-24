#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// comb sort
void combSort(int v[], int n, int *comp, int *trocas) {
    int gap = n;
    int trocou = 1;
    float shrink = 1.3;

    while (gap > 1 || trocou) {
        gap = (int)(gap / shrink);
        if (gap < 1) gap = 1;

        trocou = 0;
        for (int i = 0; i + gap < n; i++) {
            (*comp)++;
            if (v[i] > v[i + gap]) {
                int aux = v[i];
                v[i] = v[i + gap];
                v[i + gap] = aux;
                (*trocas)++;
                trocou = 1;
            }
        }
    }
}

     // gnome sort
void gnomeSort(int v[], int n, int *comp, int *trocas) {
    int i = 0;
    while (i < n) {
        if (i == 0 || v[i - 1] <= v[i]) {
            i++;
        } else {
            int aux = v[i];
            v[i] = v[i - 1];
            v[i - 1] = aux;
            (*trocas)++;
            i--;
        }
        (*comp)++;
    }
}

// bucket sort
void bucketSort(int v[], int n, int *comp, int *trocas) {
    int bucket[MAX];
    for (int i = 0; i < MAX; i++) bucket[i] = 0;

    for (int i = 0; i < n; i++) {
        bucket[v[i]]++;
        (*comp)++;
    }

    int pos = 0;
    for (int i = 0; i < MAX; i++) {
        while (bucket[i] > 0) {
            v[pos++] = i;
            bucket[i]--;
            (*trocas)++;
        }
    }
}

                   // bubble sort com flag
void bubbleFlag(int v[], int n, int *comp, int *trocas) {
    int trocou = 1;
    for (int i = 0; i < n - 1 && trocou; i++) {
        trocou = 0;
        for (int j = 0; j < n - i - 1; j++) {
            (*comp)++;
            if (v[j] > v[j + 1]) {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                (*trocas)++;
                trocou = 1;
            }
        }
    }
}

// selection sort
void selectionSort(int v[], int n, int *comp, int *trocas) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            (*comp)++;
            if (v[j] < v[menor]) menor = j;
        }
        if (menor != i) {
            int aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
            (*trocas)++;
        }
    }
}

// cocktail sort
void cocktailSort(int v[], int n, int *comp, int *trocas) {
    int trocou = 1;
    int ini = 0, fim = n - 1;

    while (trocou) {
        trocou = 0;
        for (int i = ini; i < fim; i++) {
            (*comp)++;
            if (v[i] > v[i + 1]) {
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                (*trocas)++;
                trocou = 1;
            }
        }

        if (!trocou) break;
        trocou = 0;
        fim--;

        for (int i = fim - 1; i >= ini; i--) {
            (*comp)++;
            if (v[i] > v[i + 1]) {
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                (*trocas)++;
                trocou = 1;
            }
        }
        ini++;
    }
}

//   função pra copiar vetor 
void copiar(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) destino[i] = origem[i];
}

int main() {
    int v1[] = {12, 18, 9, 25, 17, 31, 22, 27, 16, 13, 19, 23, 20, 30, 14, 11, 15, 24, 26, 28};
    int v2[] = {5, 7, 9, 10, 12, 14, 15, 17, 19, 21, 22, 23, 24, 25, 27, 28, 29, 30, 31, 32};
    int v3[] = {99, 85, 73, 60, 50, 40, 35, 30, 25, 20, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6};
    int aux[20];
    int n = 20;

    char *nomes[] = {"Bubble", "Selection", "Cocktail", "Comb", "Gnome", "Bucket"};
    void (*funcoes[])(int*, int, int*, int*) = {bubbleFlag, selectionSort, cocktailSort, combSort, gnomeSort, bucketSort};

    int *vetores[] = {v1, v2, v3};
    char *tipo[] = {"Vetor bagunçado", "Vetor ordenado", "Vetor invertido"};

    for (int v = 0; v < 3; v++) {
        printf("\n==== %s ====\n", tipo[v]);
        for (int a = 0; a < 6; a++) {
            copiar(vetores[v], aux, n);
            int comp = 0, trocas = 0;
            funcoes[a](aux, n, &comp, &trocas);
            printf("%-10s -> Comparações: %-4d | Trocas: %-4d\n", nomes[a], comp, trocas);
        }
    }

    return 0;
}
