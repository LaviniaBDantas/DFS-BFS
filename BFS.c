#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 13 

void bfs(int adj[MAX][MAX], int v, int i) {
    int lista[MAX], inicio = 0, fim = 0;

    // marca todos os vertices como nao visitados
    bool visitado[MAX] = {false};

    visitado[i] = true;
    lista[fim++] = i;

    while (inicio < fim) {
        int atual = lista[inicio++];
        printf("%d ", atual); // Corrigido para printf

        // agora, pega todos os adjacentes ao que saiu
        // se o adjacente n tiver sido visitado, marca e desenfilera

        for (int j = 1; j <= v; j++) { 
            if (adj[atual][j] == 1 && !visitado[j]) {
                visitado[j] = true;
                lista[fim++] = j; 
            }
        }
    }
}

void addAresta(int adj[MAX][MAX], int j, int v) {
    adj[j][v] = 1;
    adj[v][j] = 1; // como  nao é direcionado
}

int main() {
    int V = 12;

    int adj[MAX][MAX] = {0};

    addAresta(adj, 1, 2);
    addAresta(adj, 1, 4);
    addAresta(adj, 1, 5);

    addAresta(adj, 2, 3);
    addAresta(adj, 2, 5);
    addAresta(adj, 2, 7);
    addAresta(adj, 2, 9);

    addAresta(adj, 3, 6);
    addAresta(adj, 3, 10);
    addAresta(adj, 3, 12);

    addAresta(adj, 4, 5);
    addAresta(adj, 4, 7);

    addAresta(adj, 5, 6);
    addAresta(adj, 5, 8);

    addAresta(adj, 6, 9);
    addAresta(adj, 6, 11);

    addAresta(adj, 7, 8);

    addAresta(adj, 8, 9);

    addAresta(adj, 9, 10);

    addAresta(adj, 10, 11);

    addAresta(adj, 11, 12);

    addAresta(adj, 12, 9); 

    printf("BFS comecando do 1:\n");
    bfs(adj, V, 1);

    return 0;
}
