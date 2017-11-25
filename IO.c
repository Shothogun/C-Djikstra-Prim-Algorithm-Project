#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
#include "Freq_prog.h"
#include "IO.h"

// Reading subroutine 		

int read(Graph *G)
{
	int flag = 0;

	// Vertex id
	unsigned int v1, v2;

	// Edge's weight
	double w;

	while(scanf("%u %u %lf%*c", &v1, &v2, &w) == 3)
	{
		if (w <= 0)
		{
			flag = 1; 
		}
		// Insert Edge in graph
		Graph_updater(G, v1, v2, w);
	}

	return flag;
}

// MST printing			

void print_MST(Graph* G, unsigned int i, double* weight)
{	
	// Seek vertex's parent 
	for(List_Node *adj = G->Vertex[i-1].head->next; adj != NULL; adj = adj->next)
	{
		if (G->Vertex[adj->id-1].pi == i)
		{
			// Vertex and edge's weight printing 
			printf("Vertices Weight\n");
			printf("%u - %u  %lf\n", i, adj->id, adj->WT);

			// Tree weight computing
			*weight += adj->WT;

			// Recursive action, access parent vertex and do same process
			print_MST(G, adj->id, weight);
		} 
	}
}

// Distance path printing		

void print_distance(Graph *G, unsigned int end)
{
	// Stop condition (reach root)
	if(G->Vertex[end-1].pi == 0)
	{
		return;
	}

	// Edges's weight calculation
	double weight = (G->Vertex[end-1].key) - (G->Vertex[(G->Vertex[end-1].pi-1)].key);

	/*Recursive action, first access parent vertex
	 ,then print edge's weight
	 (the printing follows root to end order)
	*/
	print_distance(G, G->Vertex[end-1].pi);

	// Print Vertices and its edge weight
	printf("Vertices Weight\n");
	printf("%u - %u  %lf\n",G->Vertex[end-1].pi, 
		                  	end, 
		    			   	weight);
}

// Distances and its frequences printing		

void printFreq(DFD_List* List, unsigned int Total)
{
	printf("Distance Frequence\n");
	Node* Aux = List->first->next;
	/* Access each node from dfd list, print the distance
	   between the vertices and its frequence, calculated in 
	   line 84. 
	*/
	for(Aux = List->first->next ; Aux != NULL; Aux = Aux->next)
	{
		double f = (double) Aux->counter/Total;
		printf("%lf - %lf\n", Aux->dist, f);
	}
}
