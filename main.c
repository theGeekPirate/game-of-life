#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include "utility.h"
#include "rules.h"

#define GOLVERSION 0.1

/*#define SHOW_NEIGHBORS*/

int main(int argc, char **argv)
{
    int **cells;
    int **neighbors;
    int nx = 80;
    int ny = 40;
    int c;
    unsigned int it = 0;
    int world_is_dead = 0;

    while ((c = getopt(argc, argv, "hv")) != -1)
        switch (c)
    {
        case 'h':
            printf("usage: %s [OPTIONS] nx ny\n"
                    "where nx and ny are the grid dimensions.\n"
                    "-h\tDisplay help\n"
                    "-v\tDisplay version information\n", argv[0]);
            return 0;
            break;
        case 'v':
            printf("%s: Conway's Game of Life, version %.1f\n"
                    "Written by Anders Damsgaard, "
                    "https://github.com/anders-dc/game-of-life\n", argv[0], GOLVERSION);
            return 0;
            break;
        case '?':
            if (isprint(optopt))
                fprintf(stderr, "Unknown option `-%c`.\n", optopt);
            else
                fprintf(stderr, "Unknown option character `\\x%x`.\n", optopt);
            return 1;

        default:
            abort();
    }

    if (optind == argc - 2) {
        nx = atoi(argv[optind]);
        ny = atoi(argv[optind + 1]);
    } 

    printf("Grid dimensions: %dx%d\n", nx, ny);

    allocate_matrix(&cells, nx, ny);
    allocate_matrix(&neighbors, nx, ny);

    random_population(cells, nx, ny, 0.5);

    print_cell_matrix(cells, nx, ny);

    while (world_is_dead == 0) {

        world_is_dead = find_neighbor_count(cells, neighbors, nx, ny);
        cell_transitions(cells, neighbors, nx, ny);

        printf("\n%d. generation (end with Ctrl-C)\n", it);
#ifdef SHOW_NEIGHBORS
        print_matrix("neighbors", neighbors, nx, ny);
#endif
        print_cell_matrix(cells, nx, ny);

        usleep(5e5);

        it++;
    }

    free_matrix(&cells, nx);
    free_matrix(&neighbors, nx);

    return 0;
}
