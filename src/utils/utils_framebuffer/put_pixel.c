/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** put_pixel.c
*/

#include <SFML/Graphics.h>
#include "framebuffer.h"

void put_pixel(framebuffer_t *framebuffer, unsigned int x,
                unsigned int y, sfColor color)
{
    framebuffer->px[framebuffer->width * y + x] = color;
}
