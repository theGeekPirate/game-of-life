#include <stdlib.h>
#include <time.h>

/* Populate a 2D array with 0's and 1's in a pseudo-random fashion.
 * The population will be ratio*100% consisting of 1's
 */
void random_population(int **cells, int nx, int ny, double ratio)
{
    int i, j;
    srand(time(NULL));

    for (i=0; i<nx; i++) {
        for (j=0; j<ny; j++) {
            if ((double)rand()/RAND_MAX < ratio)
                cells[i][j] = 1;
            else
                cells[i][j] = 0;
        }
    }
}

int find_neighbor_count(int **cells, int **neighbors, int nx, int ny)
{
    int world_is_dead = 0;
    int i, j, x, y;
    int nneighbors;

    for (i=1; i<nx-1; i++) {
        for (j=1; j<ny-1; j++) {
            nneighbors = 0;

            for (x=-1; x<2; x++) {
                for (y=-1; y<2; y++) {
                    if (x != 0 && y != 0) {
                        nneighbors += cells[i+x][j+y];
                    }
                }
            }
            neighbors[i][j] = nneighbors;
            if (nneighbors > 0)
                world_is_dead = 0;
        }
    }

    if (world_is_dead == 1)
        return 1;
    else
        return 0;
}

void cell_transitions(int **cells, int **neighbors, int nx, int ny)
{
    int i, j, nneighbors;
    for (i=1; i<nx-1; i++) {
        for (j=1; j<ny-1; j++) {
            nneighbors = neighbors[i][j];

            if (cells[i][j] == 1) { /* alive */
                if (nneighbors < 2)      /* under-population */
                    cells[i][j] = 0;
                else if (nneighbors > 3) /* over-population */
                    cells[i][j] = 0;
                else                     /* survive */
                    cells[i][j] = 1;
            } else {                /* dead */
                if (nneighbors == 3)     /* reproduction */
                    cells[i][j] = 1;
            }
        }
    }
}
