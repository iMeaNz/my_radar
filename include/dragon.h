/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** dragon.h
*/

#include <SFML/Graphics.h>

#ifndef DRAGON_H
    #define DRAGON_H

typedef struct dragon_info {
    sfVector2f pos_init;
    sfVector2f pos_end;
    int speed;
    int delay;
} dragon_info_t;

typedef struct dragon {
    dragon_info_t info;
    int is_flying;
    int collided;
    float time_since_change;
    sfVector2f direction;
    sfVector2f pos;
    int nb_sprite;
    int hitboxes_visibility;
    float sprite_angle;
    sfSprite *sprite;
    int sprite_visibility;
    struct dragon *next;
} dragon_t;
#endif
