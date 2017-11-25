#ifndef GRAPH_H
#define GRAPH_H

// Graph

typedef struct List_Node *Adj;

//Adj vertice information
typedef struct List_Node
{
	Adj next;

	//Vertex identification
	unsigned int id;

	//Edge's weight
	double WT;

} List_Node;

//List of adjacents vertices from a ith vertex
typedef struct List
{
	// Node head
	Adj head;

	// Last node
	Adj last;

	//Vertex's key	
	double key;

	//Vertex's father
	unsigned int pi;	

} List;

typedef struct Graph
{	
	//Graph's size
	unsigned int size;	

	//Graph's Vertices(array)		
	List* Vertex;

	// Vertex's belongs to queue indicator(array)
	short* B_queue; 

} Graph;

//-------------------------------------------------------

// Min prior queue 
typedef struct Heap_node *Pointer;

typedef struct Heap_node
{
	//Vertex identification
	unsigned int id;

	//Edge's weight
	double key;

} Heap_node;

typedef struct Type_Heap
{
	// Vertices array(array)
	Heap_node* MPQ;

	// Size of queue
	unsigned int size;

	// Vertex position in queue(array)
	unsigned int* position;

} Type_Heap;

// Graph's subroutines

// arguments:()
Heap_node* Parent(Type_Heap* A, unsigned int i);
Heap_node* Left(Type_Heap* A, unsigned int i);
Heap_node* Right(Type_Heap* A, unsigned int i);

// arguments:(queue, nodes swapped)
void swap(Type_Heap* Q, Heap_node* x, Heap_node* y);

// arguments:(queue, vertices position in queue)
void Min_heapify(Type_Heap* A, unsigned int i);

// arguments:(queue)
int Extract_min(Type_Heap* A);

// arguments:(queue, vertices position in queue, new weight value)
void Decrease_key(Type_Heap *Q, int i, double new_val);

// arguments:(graph)
void Init_sng_src(Graph* G);

// arguments:(graph's size)
Graph* Init_graph(unsigned int size);

// arguments:(graph, vertices id, and edge's weight)
void Graph_updater(Graph* G, 
				   unsigned int v1,
				   unsigned int v2,
				   double w);

// arguments:(graph, source's vertices id)
Type_Heap* MPQ_creator(Graph* G, unsigned int r);

// arguments:(graph)
void Free_graph(Graph *G);

// arguments:(queue)
void Free_queue(Type_Heap *Q);

#endif
