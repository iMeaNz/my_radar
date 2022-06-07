/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** update_dragons.c
*/

#include "dragon.h"
#include <SFML/System.h>
#include <math.h>
#include <SFML/Graphics.h>

void update_dragon_pos(dragon_t *dragon, sfClock *clock, float *time_elapsed)
{
    sfInt64 time = sfClock_getElapsedTime(clock).microseconds;
    float time_in_s = (float)time * pow(10, -6);
    while (dragon != NULL) {
        if (*time_elapsed >= (float)dragon->info.delay && !dragon->collided)
            dragon->is_flying = 1;
        if (dragon->is_flying == 1 && time >= 50000) {
            float spd = (float)dragon->info.speed;
            dragon->pos.x = dragon->pos.x + dragon->direction.x * (spd / 20);
            dragon->pos.y = dragon->pos.y + dragon->direction.y * (spd / 20);
            sfSprite_setPosition(dragon->sprite, dragon->pos);
        }
        dragon = dragon->next;
    }
    if (time > 50000)
        sfClock_restart(clock);
    *time_elapsed = *time_elapsed + time_in_s;
}
