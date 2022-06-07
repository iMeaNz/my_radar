/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** free_stack.c
*/

#include "tower.h"
#include "dragon.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

void free_dragons(dragon_t *dragon_list)
{
    dragon_t *tmp;

    while (dragon_list != NULL) {
        tmp = dragon_list;
        dragon_list = dragon_list->next;
        sfSprite_destroy(tmp->sprite);
        free(tmp);
    }
}

void free_towers(tower_t *tower_list)
{
    tower_t *tmp;

    while (tower_list != NULL) {
        tmp = tower_list;
        tower_list = tower_list->next;
        sfSprite_destroy(tmp->sprite);
        free(tmp);
    }
}
