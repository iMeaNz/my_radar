/*
** EPITECH PROJECT, 2021
** FRAMEBUFFER
** File description:
** Frame_buffer
*/

#include <SFML/Graphics.h>

#ifndef FRAMEBUFFER_H
    #define FRAMEBUFFER_H

typedef struct framebuffer {
    int width;
    int height;
    sfColor *px;
} framebuffer_t;
#endif
