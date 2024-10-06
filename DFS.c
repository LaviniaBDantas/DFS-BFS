#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int v_adj;
    struct No* prox;
} No;

struct ListaAdj {
    No* inicio;
}; 

// para criar lista de adjacentes
No* criaNo(int v_adj) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->v_adj = v_adj;
    novoNo->prox = NULL;
    return novoNo;
}

void DFSRec(struct ListaAdj adj[], int visitado[], int i) {
    visitado[i] = 1; // marca como visitado
    printf("%d ", i); // printa o atual

    // agora para todos os vertices adj que nao foram visitados
    No* atual = adj[i].inicio;
    while (atual != NULL) {
        int v_adj = atual->v_adj;
        if (!visitado[v_adj]) {
            DFSRec(adj, visitado, v_adj);
        }
        atual = atual->prox;
    }
}

// funcao p iniciar o array de visitados e chamar a de recorrencia
void DFS(struct ListaAdj adj[], int v, int i) {
    int visitado[v + 1];
    for(int j = 0; j <= v; j++) {
        visitado[j] = 0;
    } 
    DFSRec(adj, visitado, i);
    }



// funcao para adicionar a aresta na lista de adjacencia
void addAresta(struct ListaAdj adj[], int i, int j) {
    // add aresta entre os vertices i e j
    No* novoNo = criaNo(j); // j sendo adj a i
    
    if(adj[i].inicio==NULL){
        adj[i].inicio=novoNo;
    }else{//percorre até o final
        No* atual=adj[i].inicio;
        while(atual->prox!=NULL){
            atual=atual->prox;
        }
        atual->prox=novoNo; //add no final
    }



    // como o grafo nao é direcionado, tem que ligar j a i tbm
    novoNo=criaNo(i);
    if(adj[j].inicio==NULL){
        adj[j].inicio=novoNo;
    }else{//percorre até o final
        No* atual=adj[j].inicio;
        while(atual->prox!=NULL){
            atual=atual->prox;
        }
        atual->prox=novoNo; //add no final
    }
}


int main() {
    int v = 12;

    struct ListaAdj adj[v+1]; 

    // inicializa cada no da lista de adj como vazio
    for (int i = 1; i <= v; i++) {
        adj[i].inicio = NULL;
    }


    int A = 22; 

int arestas[][2] = {
    {1, 2}, {1, 4}, {1, 5},
    {2, 3}, {2, 5}, {2, 7}, {2, 9},
    {3, 6}, {3, 10}, {3, 12},
    {4, 5}, {4, 7},
    {5, 6}, {5, 8},
    {6, 9}, {6, 11},
    {7, 8},
    {8, 9},
    {9, 10},
    {10, 11}, {11, 12},
    {12, 9} 
};

    // popular a lista de adjacencia com arestas
    for (int i = 0; i < A; i++) { 
        addAresta(adj, arestas[i][0], arestas[i][1]);
    }

    int partida = 1; 
    printf("DFS para busca comecando de: %d\n", partida);
    DFS(adj, v, partida);

    return 0;
}
