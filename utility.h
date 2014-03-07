#ifndef UTILITY_H_
#define UTILITY_H_

int allocate_matrix(int ***M, int nx, int ny);
void free_matrix(int ***M, int nx);
void print_matrix(char* description, int **M, int nx, int ny);

#endif
