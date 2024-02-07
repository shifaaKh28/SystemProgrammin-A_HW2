#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"

int main() {
    int i, j;
    char option;

    // Allocate memory for a 2D matrix
    int **mat = (int**) malloc(SIZE * sizeof(int*));

    for (int i = 0; i < SIZE; ++i)
        mat[i] = (int*) malloc(SIZE * sizeof(int));

    // Main program loop
    do {
        // Read user's choice
        scanf("%c", &option);

        // Perform action based on user's choice
        switch (option) {
            case 'A':
                // Call function to initialize the matrix
                init(mat, SIZE);
                break;

            case 'B':
                // Read vertices and print if there is a direct path
                scanf("%d%d", &i, &j);
                printf("%s\n", checkPath(mat, i, j, SIZE) ? "True" : "False");
                break;

            case 'C':
                // Read vertices and print the shortest path length
                scanf("%d%d", &i, &j);
                printf("%d\n", computeShortestPath(mat, i, j, SIZE));
                break;

            default:
                // Do nothing for invalid choices
                break;
        }
    } while (option != 'D');

    // Free allocated memory for the matrix
    for (int i = 0; i < SIZE; ++i)
        free(mat[i]);

    free(mat);

    return 0; 
}
