#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Freq_prog.h"
#include "Dijkstra_prog.h"

// DFD_list creator algorithm
void Create_DFD_List (DFD_List* l) 
{
	// Graphs allocation and initialization of head node
	l->first = (Node*) malloc (sizeof (Node));
	// Set head node next to NULL
	l->first->next = NULL; 
	l->last = l->first;
}

//DFDL_list empty verifier 
int If_DFD_List_Empty (DFD_List* l) 
{					
	if (l->first->next==NULL) 
		return 1;
	else
		return 0;
}

// Insertion DFD_list algorithm
void Insert_Node (DFD_List* l, double distance) 
{
	// New Node memory allocation and insertion in the last of list
	l->last->next = (Node*) malloc (sizeof(Node)); 
	l->last = l->last->next; 
	l->last->counter = 1;
	l->last->dist = distance;
	l->last->next = NULL; 
}

// Removal DFD_list algorithm
int Remove_Node (DFD_List* l, double distance) 
{
	Node *ant;
	Node *rmv = l->first->next;
	if (If_DFD_List_Empty(l))
		return 1; 
	// Seeks node with the distance given
	while (rmv->dist != distance) 
	{
		ant = rmv;
		if (rmv->next != NULL)
			rmv=rmv->next; 
		else
			return 1;
	}

	// Node removal
	ant->next = rmv->next; 
	free (rmv);
	return 0;
}

// DFD_list desalocation
void Delete_DFD_List (DFD_List* l) 
{
	Node *aux;
	// Access each node and free it
	while (!If_DFD_List_Empty(l))
	{
		aux = l->first->next;
		l->first->next = aux->next;
		free(aux);
	}
	// Head_node desalocation
	free (l->first); 
}

DFD_List* Freq (unsigned int N, Graph* G)
{
	// Parameters initialization
	unsigned int i, j;
	Node* aux;
	DFD_List* dfd_list = (DFD_List*) malloc(sizeof(DFD_List));

	//DFD_list creation
	Create_DFD_List (dfd_list);

	// Access each vertex from graph 
	for (i=1; i<=N; i++)
	{
		// Do Dijkstra algorithm for current vertex from loop as source
		Dijkstra(G, i);

		/* Access each vertex pair of vertex whose distance between  
		 vertex i haven't been analysed*/

		for(j = i; j<=N; j++)
		{	
			/* Access each node from dfd_list
			 and verifies if its value is already 
			 registered */

			aux = dfd_list->first; 
			while(aux->next != NULL)
			{
				aux=aux->next;

				// Updates distance occurrence, with counter
				if (aux->dist == G->Vertex[j-1].key)
				{
					aux->counter += 1;
					break;
				}
			}

			// If this distance hasn't been occurred, it's inserted in list
			if (aux->next == NULL)
			{
				Insert_Node (dfd_list, G->Vertex[j-1].key);
			}
		}
	}
	return dfd_list;	
}

// DFD free
void freeDFD(DFD_List* dfd_list)
{
	Node* Aux= dfd_list->first;
	Node* next;
	while(Aux != NULL)
	{
		next = Aux->next;
		free(Aux);
		Aux = next;
	}
	free(Aux);
	free(dfd_list);	
}
