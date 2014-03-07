#ifndef RULES_H_
#define RULES_H_

void random_population(int **cells, int nx, int ny, double ratio);
int find_neighbor_count(int **cells, int **neighbors, int nx, int ny);
void cell_transitions(int **cells, int **neighbors, int nx, int ny);

#endif
