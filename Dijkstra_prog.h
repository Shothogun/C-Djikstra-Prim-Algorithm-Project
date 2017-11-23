#ifndef Dijkstra_PROG_Hh
#define Dijkstra_PROG_H
#include "Graph.h"

void Relax(Graph *G, List_Node *v, unsigned int i);

void Dijkstra(Graph *G, unsigned int r);



#endif