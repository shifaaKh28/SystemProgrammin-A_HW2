#include <stdbool.h>
#include "stdio.h"
#include "my_mat.h"

/**
 * Dijkstra's algorithm to find the shortest path in a graph.
 *
 * @param mat: The adjacency matrix representing the graph.
 * @param start: The starting vertex.
 * @param distination: The destination vertex to find the shortest path to.
 * @param len: The number of vertices in the graph.
 * @return The shortest path distance from the starting vertex to the destination vertex.
 */
int dijkstra_algorithm(int** mat, int start, int distination, const int len) {
    // Array to store the shortest distance from the starting vertex to each vertex
    int distanceFromVert[len];

    // Array to keep track of which vertices have been visited
    bool visited[len];

    // Counter for the number of vertices visited
    int counter = 0;

    // Variables to store the minimum distance and the current vertex
    int min;
    int current;

    // Initialization: Set all distances to infinity, except the starting vertex
    // which is set to 0. Mark all vertices as not visited.
    for (int i = 0; i < len; i++) {
        distanceFromVert[i] = INFINITY;
        visited[i] = false;
    }
    distanceFromVert[start] = 0;

    // Main loop: Continue until all vertices have been visited
    while (++counter < len) {

        min = INFINITY;
        // Find the vertex with the minimum distance that has not been scanned
        for (int vertex = 0; vertex < len; ++vertex) {
            if (visited[vertex] || distanceFromVert[vertex] > min)
                continue;

            min = distanceFromVert[vertex];
            current = vertex;
        }

        // Mark the current vertex as visited
        visited[current] = true;

        // Update distances to neighbors based on the newly visited vertex
        for (int vertex2 = 0; vertex2 < len; vertex2++) {
            if (visited[vertex2] || !mat[current][vertex2] || distanceFromVert[current] == INFINITY || (distanceFromVert[current] + mat[current][vertex2] >= distanceFromVert[vertex2]))
                continue;

            distanceFromVert[vertex2] = distanceFromVert[current] + mat[current][vertex2];
        }
    }

    // Return the shortest path distance to the specified destination vertex
    return distanceFromVert[distination];
}

void init(int** mat, int size) {
    for (int i = 0; i <size ; ++i) {
        for (int j = 0; j <size; ++j) {
            scanf("%d", &mat[i][j]);
        }
      }
}

int checkPath(int** mat, int i, int j, int len) {
    // Check if there is a direct edge between i and j
    if (mat[i][j] > 0) {
        return 1;  // Return 1 to indicate there is a direct path
    }

    // Use Dijkstra's algorithm to find the shortest path
    int ans = dijkstra_algorithm(mat, i, j, len);

    // Check if there is a valid path (distance less than infinity and not equal to zero)
    return (ans < INFINITY && ans != 0) ? 1 : 0;  // Return 1 if true, 0 otherwise
}

int computeShortestPath(int** mat, int i, int j, int len) {
    // Use Dijkstra's algorithm to find the shortest path
    int ans = dijkstra_algorithm(mat, i, j, len);

// Check if a valid path exists
// If true, return the shortest path length; otherwise, return -1
    return (ans != 0) && (ans != INFINITY) ? ans : -1;
}