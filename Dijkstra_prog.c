#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Dijkstra_prog.h"
#include "Graph.h"

void Relax(Graph *G, List_Node *v, unsigned int i)
{
	if(G->Vertex[v->id-1].key > G->Vertex[i-1].key + v->WT)
	{
		G->Vertex[v->id-1].pi = i;
		G->Vertex[v->id-1].key = G->Vertex[i-1].key + v->WT;
	}
}

void Dijkstra(Graph *G, unsigned int r)
{
	Init_sng_src(G);
	G->Vertex[r-1].key = 0;
	Type_Heap *Q = MPQ_creator(G, r);
	while (Q->size != 0)
	{
		int i = Extract_min(Q);
		G->B_queue[i-1] = 0;
		List *u = &G->Vertex[i-1];
		for(List_Node *v = u->head->next; v != NULL; v = v->next)
		{
			if (G->B_queue[v->id-1] == 1)
			{
				Relax(G,v,i);
				Decrease_key(Q, 
							 Q->position[v->id-1], 
							 G->Vertex[i-1].key + v->WT);
			}
		}
	}
	Free_queue(Q);
}