/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** alloc_array_char.c
*/

#include <stdlib.h>

char **alloc_array_char(int size, int size_col)
{
    char **output = malloc(sizeof(char *) * (size + 1));
    for (int i = 0; i < size; i++) {
        output[i] = malloc(sizeof(char) * (size + 1));
        for (int j = 0; j < size_col; j++)
            output[i][j] = 0;
    }
    return output;
}
