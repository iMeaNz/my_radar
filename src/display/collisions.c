/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** collisions.c
*/

#include "dragon.h"
#include "tower.h"
#include <SFML/System.h>
#include <math.h>
#include <SFML/Graphics.h>

int range_tower(dragon_t *dragon, tower_t *tower)
{
    int x = dragon->pos.x;
    int y = dragon->pos.y;
    while (tower != NULL) {
        int x_tower = tower->pos.x;
        int y_tower = tower->pos.y;
        float dist = sqrt(pow(x_tower - x, 2) + pow(y_tower - y, 2));
        if (dist <= tower->radius) {
            return 1;
        }
        tower = tower->next;
    }
    return 0;
}

void check_collisions(dragon_t *dragon1, dragon_t *dragon2, tower_t *tower)
{
    if (dragon1->is_flying == 0 || dragon2->is_flying == 0)
        return;
    if (range_tower(dragon1, tower) || range_tower(dragon2, tower))
        return;
    int x1 = dragon1->pos.x;
    int x2 = dragon2->pos.x;
    int y1 = dragon1->pos.y;
    int y2 = dragon2->pos.y;
    float dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    if (dist <= 10) {
        dragon1->is_flying = 0;
        dragon2->is_flying = 0;
        dragon1->collided = 1;
        dragon2->collided = 1;
    }
}

void collisions(dragon_t *dragons, tower_t *tower)
{
    while (dragons != NULL) {
        dragon_t *next = dragons->next;
        while (next != NULL) {
            check_collisions(dragons, next, tower);
            next = next->next;
        }
        dragons = dragons->next;
    }
}
