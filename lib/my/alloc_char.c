/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** alloc_char.c
*/

#include <stdlib.h>

char *alloc_char(int size)
{
    char *output = malloc(sizeof(char) * size + 1);
    for (int i = 0; i <= size; i++)
        output[i] = 0;
    return output;
}
