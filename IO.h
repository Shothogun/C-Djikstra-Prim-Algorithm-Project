#ifndef IO_H 
#define IO_H 

int read(Graph *G);
int commmand_op(char* c);
void print_MST(Graph* G, unsigned int i, double* weight);
void print_distance(Graph *G, unsigned int end);

#endif