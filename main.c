#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

#define VERSION 0.1

int main(int argc, char **argv)
{
    int **cells;
    int nx = 10;
    int ny = 10;
    int c;

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
            printf("%s: Conway's Game of Life,"
                    "version %.1f\n"
                    "Written by Anders Damsgaard, "
                    "https://github.com/anders-dc/game-of-life\n", argv[0], VERSION);
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



    return 0;
}
