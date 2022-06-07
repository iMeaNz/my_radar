/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** landing.c
*/

#include "dragon.h"
#include <math.h>

void check_if_landed(dragon_t *dragon)
{
    while (dragon != NULL) {
        int x = dragon->pos.x;
        int y = dragon->pos.y;
        int x_end = dragon->info.pos_end.x;
        int y_end = dragon->info.pos_end.y;
        float dist = sqrt(pow(x_end - x, 2) + pow(y_end - y, 2));
        if (dist <= 10) {
            dragon->is_flying = 0;
            dragon->collided = 1;
        }
        dragon = dragon->next;
    }
}
