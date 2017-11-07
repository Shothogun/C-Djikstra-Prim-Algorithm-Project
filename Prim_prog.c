#include <stdio.h>
#include <limits.h>
#include "MST_Prim.h"
#include "Graph.h"
#include "MPQ.h"

void MST_Prim(Graph* G, unsigned int r){
	Init_sng_src(G);
	G->Vertex[r].key = 0;
	Type heap *Q = MPQ_creator(G);
	while (Q->size != 0)
	{
		i = Extract_min(Q)
		B_queue[i] = 0;
		List *u = G->Vertex[i]
		for(List_Node *v = u->head->next; *v != NULL; *v = v->next)
		{
			if( B_queue[v->id] == 1 &&
				v->WT < G->Vertex[v->id].key)
			{
				G->Vertex[v->id].pi = i;
				G->Vertex[v->id].key = v->WT;
			}
		}
	}
} 