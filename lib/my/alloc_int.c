/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** alloc.c
*/

#include <stdlib.h>

int *alloc_int(int size)
{
    int *output = malloc(sizeof(int) * (size + 1));
    for (int i = 0; i <= size; i++)
        output[i] = 0;
    return output;
}
