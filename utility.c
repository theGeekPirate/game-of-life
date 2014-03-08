#include <stdio.h>
#include <stdlib.h>

int allocate_matrix(int ***M, int nx, int ny)
{
    int i;
    (*M) = (int**) malloc(sizeof(double*)*nx);
    if (*M == NULL)
        return 1;

    for (i=0; i<nx; i++) {
        (*M)[i] = (int*) malloc(sizeof(double)*ny);
        if ((*M)[i] == NULL)
            return 1;
    }
    return 0;
}

void free_matrix(int ***M, int nx)
{
    int i;
    for (i=0; i<nx; i++)
        free((*M)[i]);
    free(*M);
}

void print_matrix(char* description, int **M, int nx, int ny)
{
    int i, j;
    printf("%s:\n", description);
    for (j=0; j<ny; j++) {
        for (i=0; i<nx; i++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

void print_cell_matrix(int **M, int nx, int ny)
{
    int i, j;
    for (j=0; j<ny; j++) {
        for (i=0; i<nx; i++) {
            if (M[i][j] == 1)
                printf("X");
            else
                printf(".");
        }
        printf("\n");
    }
}
