/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** utils_event.c
*/

#include <SFML/Graphics.h>
#include "dragon.h"
#include "tower.h"

void hitboxes_visibility(dragon_t *drag)
{
    while (drag != NULL) {
        if (drag->hitboxes_visibility == 1)
            drag->hitboxes_visibility = 0;
        else
            drag->hitboxes_visibility = 1;
        drag = drag->next;
    }
}

void sprite_visibility(dragon_t *drag, tower_t *tower)
{
    while (drag != NULL) {
        if (drag->sprite_visibility == 1) {
            drag->hitboxes_visibility = 0;
            drag->sprite_visibility = 0;
        } else {
            drag->sprite_visibility = 1;
            drag->hitboxes_visibility = 1;
        }
        drag = drag->next;
    }

    while (tower != NULL) {
        if (tower->sprite_visibility == 1)
            tower->sprite_visibility = 0;
        else
            tower->sprite_visibility = 1;
        tower = tower->next;
    }
}

void check_events(sfEvent event, sfRenderWindow *win, dragon_t *dragon,
                    tower_t *tower)
{
    while (sfRenderWindow_pollEvent(win, &event) == sfTrue) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(win);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp)
            hitboxes_visibility(dragon);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown)
            sprite_visibility(dragon, tower);
    }
}
