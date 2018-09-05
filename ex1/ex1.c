/*
Exercice 01 - Sort an array manually

Written by Dimitris Kokkonis
https://kokkonisd.github.io
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define MIN_LIMIT 0
#define MAX_LIMIT 20

/* Prints a (double) array. */
void printArray (double *array, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%.2f\n", array[i]);
    }
}


/* Checks if a (double) array is sorted. */
int isArraySorted (double *array, int size)
{
    for (int i = 0; i < size; i += 2) {
        if (array[i] > array[i + 1]) return 0;
    }

    return 1;
}


void sortArray (double *array, int size)
{
    /* === Your code starts here === */

    double *temp = malloc(sizeof(double) * size);
    double min;
    int minIndex;

    for (int i = 0; i < size; i++) {
        min = MAX_LIMIT;
        for (int j = 0; j < size; j++) {
            if (array[j] < min) {
                min = array[j];
                minIndex = j;
            }
        }

        array[minIndex] = MAX_LIMIT;

        temp[i] = min;
    }

    for (int i = 0; i < size; i++) {
        array[i] = temp[i];
    }

    free(temp);

    /* === Your code ends here === */
}


int main (int argc, char *argv[])
{
    // some random grades
    double grades[] = { 19.8, 20, 2.3, 3, 16.4, 20, 0, 0.7, 14.2, 10 };

    // print array before sort
    printArray(grades, SIZE);

    // sort the array (you have to implement this function)
    sortArray(grades, SIZE);

    // check if array is sorted
    if (!isArraySorted(grades, SIZE)) {
        printf("ERROR! Array not sorted.\n");

        return 1;
    }

    printf("\n---\n\n");

    // print array after sort, if it is indeed sorted
    printArray(grades, SIZE);

    return 0;
}
