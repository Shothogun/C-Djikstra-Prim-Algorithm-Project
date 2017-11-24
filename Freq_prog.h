#ifndef FREQ_PROG_H
#define FREQ_PROG_H

#include <stdio.h>
#include <stdlib.h>
#include "Dijkstra_prog.h"
#include "Graph.h"

typedef struct Node{
	int counter;
	double dist;
	struct Node* next;
}Node;

typedef struct DFD_List {
	Node* first;
	Node* last;
}DFD_List;

void Create_DFD_List (DFD_List* l);
int If_DFD_List_Empty (DFD_List* l);
void Insert_Node (DFD_List* l, double distance);
int Remove_Node (DFD_List* l, double distance);
void Delete_DFD_List (DFD_List* l);
DFD_List* Freq (unsigned int N, Graph* G);

#endif
