//
// Created by shifa on 2/4/2024.
//

#ifndef MY_MAT_H
#define MY_MAT_H
#define SIZE 10 //define the matrix size
#define INFINITY 999999 // Assuming a large value for infinity
/*
 * Get the matrix values from the user.
*/
void init(int**, int);

/*
 * check if there is a path from i to j.
*/
int checkPath(int**, int, int, int);

/*
 * Returns the shortest path from i to j.
*/
int computeShortestPath(int**, int, int, int);

#endif