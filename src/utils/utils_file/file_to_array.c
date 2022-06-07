/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** file_to_array.c
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char **create_array(char *fn)
{
    int fd = open(fn, O_RDONLY | 0, 0);
    if (fd == -1)
        return 0;
    char *buffer = alloc_char(1000000);
    int error = read(fd, buffer, 1000000);
    if (error == -1)
        return 0;
    char **output = my_str_to_word_array(buffer);
    free(buffer);
    return output;
}
