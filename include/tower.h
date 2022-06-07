/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** tower.h
*/

#include <SFML/Graphics.h>

#ifndef TOWER_H
    #define TOWER_H

typedef struct tower {
    sfVector2f pos;
    int circle_drawn;
    float radius;
    sfSprite *sprite;
    int sprite_visibility;
    float time_since_change;
    int power;
    int up;
    struct tower *next;
} tower_t;
#endif
