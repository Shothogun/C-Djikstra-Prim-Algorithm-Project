#ifndef IO_H 
#define IO_H 

int read(Graph *G);
void print_MST(Graph* G, unsigned int i, double* weight);
void print_distance(Graph *G, unsigned int end);
void printFreq(DFD_List* List, unsigned int Total);

#endif
