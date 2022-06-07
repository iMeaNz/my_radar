/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** framebuffer.c
*/

#include "framebuffer.h"
#include <stdlib.h>

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *buff = malloc(sizeof(framebuffer_t));
    sfColor *pixels = malloc(sizeof(sfColor) * width * height);
    buff->height = height;
    buff->width = width;
    buff->px = pixels;
    return buff;
}

void clear_buffer(framebuffer_t *buff)
{
    for (int i = 0; i < buff->height * buff->width; i++)
        buff->px[i] = sfBlack;
}
