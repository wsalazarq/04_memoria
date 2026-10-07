#include <iostream>
using namespace std;

void nextFit(int blockSize[], int m, const int processSize[], int n) {
    int* allocation = new int[n];

    for (int i = 0; i < n; ++i)
        allocation[i] = -1;

    int j = 0; // Inicia la búsqueda en el primer bloque

    // Algoritmo Next-Fit
    for (int i = 0; i < n; ++i) {
        int count = 0; // Para evitar bucle infinito recorriendo m bloques

        while (count < m) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i]; // Particionamiento dinámico
                break;
            }
            j = (j + 1) % m; // Avanza circularmente
            count++;
        }
    }

    // Salida
    cout << "\n--- NEXT-FIT ---\n";
    cout << "No. Proceso\tTamano Proceso\tNo. Bloque\n";
    for (int i = 0; i < n; ++i) {
        cout << " " << (i + 1) << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << (allocation[i] + 1);
        else
            cout << "No Asignado";
        cout << "\n";
    }

    delete[] allocation;
}

int main() {
    int blockSize[]   = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 301};

    int m = sizeof(blockSize)   / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    nextFit(blockSize, m, processSize, n);
    return 0;
}