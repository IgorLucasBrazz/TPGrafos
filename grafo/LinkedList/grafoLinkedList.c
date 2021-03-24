//
// Created by vitor on 3/23/21.
//

#include "grafoLinkedList.h"


void initGrafo(GrafoLinked *grafo) {
    grafo = (GrafoLinked *) malloc(sizeof(GrafoLinked));
    grafo->numVertices = 0;
    grafo->numArestas = 0;
    grafo->list=NULL;
}

void addAresta(LinkedList *to, int from, float weight) {
    if (to->vertice == 0) {
        to->vertice = from;
        to->peso = weight;
        return;
    }

    while (to->next != NULL) {
        to = to->next;
    }
    to->next = createNode(from, weight);
}

void vizinhos(GrafoLinked *grafo int vertice) {
    int i, j;
    printf("\n\tVizinhos de %d\n", vertice);
    for (i = 0; i < grafo.numVertices; i++) {
        if (grafo->list[i] != valorInicial)
            printf("Vertice: %d\n", i + 1);
    }
    printf("\n\n");
}//Não sabemos se está certo

int grau(GrafoLinked *grafo int vertice){
    int i, j, grau = 0;
    for (i = 0; i < grafo->numVertices; i++) {
        if (grafo->list[i] != valorInicial)
            grau++;
    }
    return grau;
}

void printGrafo(GrafoLinked *grafo) {

    if (grafo == NULL || grafo->numVertices == 0) {
        fflush(stdin);
        printf("O grafo esta vazio vazia");
    }

    for (int i = 0; i < grafo->numVertices; ++i) {
        printf("%d | ", i);
        printLinked(&grafo->list[i]);
        printf("\n");
    }

}

FILE *readFiles(GrafoLinked *grafo) {
    FILE *arquivo;
    char nomeArquivo[255];

#if DEBUG
    arquivo = fopen(debugFile, "rw");
    strcpy(grafo->nomeArquivo, debugFile);
#else
    fflush(stdin);
    printf("Entre com o nome do arquivo: ");
    scanf("%s", nomeArquivo);
    arquivo = fopen(nomeArquivo, "rw");
    strcpy(grafo->nomeArquivo, nomeArquivo);
#endif
    return arquivo;

}

int textToGrafo(GrafoLinked *grafo) {
    FILE *arquivo;
    fileStruct data;


    do {
        arquivo = readFiles(grafo);

        if (arquivo == NULL) {
            printf("\n\tArquivo invalido tente novamente.\n\n");
            return 0;
        }

        fscanf(arquivo, "%d", &grafo->numVertices);


        grafo->list = createLinkedList(grafo->numVertices);


        if (grafo->list == NULL) {
            fclose(arquivo);
            printf("\n\tMemoria insuficiente.\n\n");
            return 1;
        }

        while (fscanf(arquivo, "%d %d %f", &data.linha, &data.coluna, &data.peso) != EOF) {
            addAresta(&grafo->list[data.linha - 1], data.coluna - 1, data.peso);
            addAresta(&grafo->list[data.coluna - 1], data.linha - 1, data.peso);
        }

        fclose(arquivo);

    } while (arquivo == NULL);
    printf("\n\tArquivo lido com sucesso! \\o/ \n\n");
    return 1;
}


int GRAPHbridges(GrafoLinked G){
    int v;
    conta = 0;
    numpts = 0;

    for (v = 0; v < G.numVertices; v++)
        pre[v] = -1;

    for (v = 0; v < G.numVertices; v++)
        if (pre[v] == -1) {
            parent[v] = v;
            bridgeR(G, v);
        }
    return numpts;
}

void bridgeR(GrafoLinked G, int v){
    int w;
    pre[v] = conta++;///a cada chamada ele tira um v?rtice do vetor de v?rtices marcados pre.
    low[v] = pre[v];
    for (w = 0; w < G.numVertices; w++) {
        if (G.list[v] != 0) {
            if (pre[w] == -1) {
                parent[w] = v;
                bridgeR(G, w);
                if (low[v] > low[w]) low[v] = low[w];
                //if(v==w) printf("eh ponte");
                if (low[w] == pre[w]) {
                    if ((vertice1 == v + 1 && vertice2 == w + 1) || (vertice1 == w + 1 && vertice2 == v + 1))
                        numpts++;
                }
            } else if (w != parent[v] && low[v] > pre[w])
                low[v] = pre[w];
        }
    }
}
