#ifndef GRAPH_H
#define GRAPH_H
#include "MPQ.h"

typedef struct List_Node *Adj;

//Adj vertice information
typedef struct List_Node
{
	Adj next;
	//Vertex identification
	unsigned int id;
	//Edge's weight
	unsigned int WT;
} List_Node;

//List of adjacents vertices from a ith vertex
typedef struct List
{
	// Node head
	Adj head;
	//Vertex's key	
	unsigned int key;
	//Vertex's father
	int pi;	
} List;

typedef struct Graph
{	
	//Graph's size
	unsigned int size;		
	//Graph's Vertices		
	List* Vertex;
	// Queue's 
	short* B_queue; 
} Graph;

void Init_sng_src(Graph* G);

#endif
