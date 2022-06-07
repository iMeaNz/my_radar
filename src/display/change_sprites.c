/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** change_sprites.c
*/

#include <SFML/Graphics.h>
#include "dragon.h"

void rotate_sprite(dragon_t *new_dragon);

void set_new_sprite(dragon_t *dragon, sfTexture *text)
{
    sfSprite_destroy(dragon->sprite);
    dragon->sprite = sfSprite_create();
    sfSprite_setPosition(dragon->sprite, dragon->pos);
    sfSprite_setTexture(dragon->sprite, text, sfFalse);
    rotate_sprite(dragon);
}

void modify_sprite(dragon_t *drag)
{
    sfTexture *text;
    if (drag->nb_sprite % 2 == 0)
        text = sfTexture_createFromFile("assets/dragon1.bmp", NULL);
    if (drag->nb_sprite % 2 == 1)
        text = sfTexture_createFromFile("assets/dragon2.bmp", NULL);
    set_new_sprite(drag, text);
    drag->nb_sprite++;
}

void change_sprite(dragon_t *dragon, float time_elapsed)
{
    while (dragon != NULL) {
        if (dragon->is_flying == 0) {
            dragon = dragon->next;
            continue;
        }
        if (time_elapsed >= dragon->time_since_change) {
            dragon->time_since_change++;
            modify_sprite(dragon);
        }
        dragon = dragon->next;
    }
}
