#include "linkedlist/linkedlist.h"
#include "../../utils/utils.h"

#ifndef TP_C_GRAFOLINKEDLIST_H
#define TP_C_GRAFOLINKEDLIST_H

typedef struct {
    int numVertices;
    int numArestas;
    char *nomeArquivo;
    //Lista de linked lists
    LinkedList *list;
} GrafoLinked;


void initGrafo(GrafoLinked *grafo);

int textToGrafo();

void addAresta(LinkedList *to, int from, float weight);

FILE *readFiles(GrafoLinked *grafo);

void printGrafo(GrafoLinked *grafo);

void vizinhos(GrafoLinked *grafo int vertice);

int grau(GrafoLinked *grafo int vertice);

int GRAPHbridges(GrafoLinked G);

void bridgeR(GrafoLinked G, int v);

#endif //TP_C_GRAFOLINKEDLIST_H
