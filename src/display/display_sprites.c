/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** display_sprites.c
*/

#include "my.h"
#include "dragon.h"
#include "tower.h"
#include "framebuffer.h"
#include <SFML/Graphics.h>

sfSprite *create_sprite(sfVector2f scale, sfVector2f pos, sfTexture *texture);
void clear_buffer(framebuffer_t *buff);
void draw_a_rectangle(sfRenderWindow *win, int c_x, int c_y, dragon_t *drag);
void draw_circle_shape(float radius, tower_t *tower, sfRenderWindow *win);
void draw_faded_circle(sfRenderWindow *win, tower_t *tower);

void draw_background(sfRenderWindow *win)
{
    sfSprite *background = sfSprite_create();
    sfTexture *text = sfTexture_createFromFile("assets/background.bmp", NULL);
    sfVector2f pos = {0, 0};
    sfSprite_setPosition(background, pos);
    sfSprite_setTexture(background, text, sfFalse);
    sfRenderWindow_drawSprite(win, background, NULL);
    sfTexture_destroy(text);
    sfSprite_destroy(background);
}

void draw_tower(sfRenderWindow *win, tower_t *tow)
{
    while (tow != NULL) {
        if (tow->sprite_visibility == 1) {
            sfRenderWindow_drawSprite(win, tow->sprite, NULL);
            draw_faded_circle(win, tow);
            draw_circle_shape(tow->radius, tow, win);
        }
        tow = tow->next;
    }
}

void draw_dragons(sfRenderWindow *win, dragon_t *dragon)
{
    while (dragon != NULL) {
        if (dragon->is_flying == 1 && dragon->sprite_visibility == 1)
            sfRenderWindow_drawSprite(win, dragon->sprite, NULL);
        if (dragon->is_flying == 1 && dragon->hitboxes_visibility == 1)
            draw_a_rectangle(win, dragon->pos.x, dragon->pos.y, dragon);
        dragon = dragon->next;
    }
}

void display_all_sprites(sfRenderWindow *win, dragon_t *dragon,
                        tower_t *tower)
{
    sfRenderWindow_clear(win, sfBlack);
    draw_background(win);
    draw_tower(win, tower);
    draw_dragons(win, dragon);
}
