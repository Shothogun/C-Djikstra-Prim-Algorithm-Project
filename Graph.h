#ifndef GRAPH_H
#define GRAPH_H

typedef struct List_Node *Adj;

//Adj vertice information
typedef struct List_Node
{
	Adj next;
	//Vertex identification
	int id;
	//Edge's weight
	int WT;
} List_Node;

//List of adjacents vertices
typedef struct List
{
	Adj head;			
} List;

typedef struct Graph
{	
	//Graph's size
	int N;		
	//Graph's Vertices		
	List* Vertex;
	//Distance to source
	int* Dist;
} Graph;
#endif