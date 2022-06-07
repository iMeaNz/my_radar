/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** utils_draw.c
*/

#include "framebuffer.h"
#include <SFML/Graphics.h>
#include <math.h>
#include "tower.h"
#include "dragon.h"

void put_pixel(framebuffer_t *framebuffer, unsigned int x,
                unsigned int y, sfColor color);
void clear_buffer(framebuffer_t *buff);

void draw_circle_shape(float rad, tower_t *tower, sfRenderWindow *win)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f pos = {tower->pos.x - rad + 25 , tower->pos.y - rad + 56};
    sfColor white = sfWhite;
    white.a = 50;
    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setRadius(circle, rad);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, white);
    sfCircleShape_setOutlineThickness(circle, 2);
    sfRenderWindow_drawCircleShape(win, circle, NULL);
    sfCircleShape_destroy(circle);
}

void set_outline_faded_circle(sfColor white, sfCircleShape *circle,
                                int i, tower_t *tower)
{
    sfColor white_bright;
    sfColor white_brighter;
    if (i <= tower->radius / 4) {
        white_brighter = white;
        white_brighter.a += 6;
        sfCircleShape_setOutlineColor(circle, white_brighter);
    } else if (i <= tower->radius / 2) {
        white_bright = white;
        white_bright.a += 3;
        sfCircleShape_setOutlineColor(circle, white_bright);
    } else
        sfCircleShape_setOutlineColor(circle, white);
}

void draw_faded_circle(sfRenderWindow *win, tower_t *tower)
{
    int c_x = tower->pos.x + 25;
    int c_y = tower->pos.y + 56;
    sfColor white = sfWhite;
    white.a = tower->power;
    for (int i = tower->radius - 1; i > 0; i--) {
        sfCircleShape *circle = sfCircleShape_create();
        sfVector2f pos = {c_x - i, c_y - i};
        sfCircleShape_setPosition(circle, pos);
        sfCircleShape_setRadius(circle, (float)i);
        sfCircleShape_setFillColor(circle, sfTransparent);
        set_outline_faded_circle(white, circle, i, tower);
        sfCircleShape_setOutlineThickness(circle, 4);
        sfRenderWindow_drawCircleShape(win, circle, NULL);
        sfCircleShape_destroy(circle);
        white.a += (i % 10 == 0) ? 1 : 0;
    }
}

void draw_a_rectangle(sfRenderWindow *win, int c_x, int c_y, dragon_t *drag)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f pos = {c_x, c_y};
    sfVector2f size = {20, 20};
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfRed);
    sfRectangleShape_setOutlineThickness(rect, 2);
    float angle = drag->sprite_angle;
    sfRectangleShape_setRotation(rect, angle);
    sfRenderWindow_drawRectangleShape(win, rect, NULL);
    sfRectangleShape_destroy(rect);
}
