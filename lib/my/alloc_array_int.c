/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** alloc_array_int.c
*/

#include <stdlib.h>

int **alloc_array_int(int size, int size_col)
{
    int **output = malloc(sizeof(int *) * (size + 1));
    for (int i = 0; i < size; i++) {
        output[i] = malloc(sizeof(int) * (size_col + 1));
        for (int j = 0; j < size_col; j++)
            output[i][j] = 0;
    }
    return output;
}
