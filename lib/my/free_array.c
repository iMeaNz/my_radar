/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** free_array.c
*/

#include <stdlib.h>

void free_int_array(int **array, int size)
{
    for (int i = 0; i < size; i++)
        free(array[i]);
    free(array);
}

void free_char_array(char **array)
{
    for (int i = 0; array[i] != 0; i++)
        free(array[i]);
    free(array);
}
