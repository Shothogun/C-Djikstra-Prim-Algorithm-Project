#ifndef IO_H 
#define IO_H 

//arguments:(graph)
int read(Graph *G);

//arguments:(graph, source id and M.S.T.'s weight parameter)
void print_MST(Graph* G, unsigned int i, double* weight);

//arguments:( graph, end id)
void print_distance(Graph *G, unsigned int end);

//arguments:(dfd list, total of pair of vertices parameter)
void printFreq(DFD_List* List, unsigned int Total);

#endif
