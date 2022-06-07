/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** add_to_stack.c
*/

#include "my.h"
#include "tower.h"
#include "dragon.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <math.h>

void update_quadrants(dragon_t *dragon);

sfVector2f create_vector_direction(dragon_info_t info)
{
    sfVector2f direction;
    direction.x = info.pos_end.x - info.pos_init.x;
    direction.y = info.pos_end.y - info.pos_init.y;
    float norm = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    direction.x /= norm;
    direction.y /= norm;
    return direction;
}

void rotate_sprite(dragon_t *new_dragon)
{
    static const double PI = 3.1415926535;
    float x = new_dragon->direction.x;
    float y = new_dragon->direction.y;
    float angle = acos(x);
    if (x >= 0 && y >= 0)
        angle = acos(x) + PI / 2;
    if (x < 0 && y >= 0)
        angle = acos(y) + PI;
    if (x < 0 && y < 0)
        angle = acos(-x) - PI / 2;
    if (x >= 0 && y < 0)
        angle = acos(-y);
    angle = (angle * 180) / PI;
    new_dragon->sprite_angle = angle;
    sfSprite_rotate(new_dragon->sprite, angle);
}

void create_sprite_dragon(dragon_t *new_dragon)
{
    new_dragon->sprite = sfSprite_create();
    sfTexture *text = sfTexture_createFromFile("assets/dragon1.bmp", NULL);
    sfSprite_setPosition(new_dragon->sprite, new_dragon->info.pos_init);
    sfSprite_setTexture(new_dragon->sprite, text, sfFalse);
}

void add_dragon(dragon_t **dragon_list, dragon_info_t info)
{
    dragon_t *new_dragon = malloc(sizeof(dragon_t));
    new_dragon->info = info;
    if (!new_dragon->info.delay)
        new_dragon->is_flying = 1;
    else
        new_dragon->is_flying = 0;
    new_dragon->direction = create_vector_direction(new_dragon->info);
    create_sprite_dragon(new_dragon);
    new_dragon->pos = new_dragon->info.pos_init;
    rotate_sprite(new_dragon);
    new_dragon->collided = 0;
    new_dragon->nb_sprite = 0;
    new_dragon->hitboxes_visibility = 1;
    new_dragon->sprite_visibility = 1;
    new_dragon->time_since_change = 1;
    new_dragon->next = (*dragon_list);
    (*dragon_list) = new_dragon;
}

void add_tower(tower_t **list_tower, int x, int y, int radius)
{
    tower_t *new_tower = malloc(sizeof(tower_t));
    new_tower->pos.x = x;
    new_tower->pos.y = y;
    new_tower->circle_drawn = 0;
    new_tower->radius = 1920 * (float)radius / 100;
    new_tower->sprite = sfSprite_create();
    new_tower->sprite_visibility = 1;
    new_tower->power = 6;
    new_tower->time_since_change = 0;
    new_tower->up = 1;
    sfTexture *text = sfTexture_createFromFile("assets/tower.bmp", NULL);
    sfSprite_setPosition(new_tower->sprite, new_tower->pos);
    sfSprite_setTexture(new_tower->sprite, text, sfFalse);
    new_tower->next = (*list_tower);
    (*list_tower) = new_tower;
}
