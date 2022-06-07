/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** show_list.c
*/

#include "my.h"
#include "tower.h"
#include "dragon.h"
#include <stdlib.h>

void show_list_dragon(dragon_t *dragon_list)
{
    while (dragon_list != NULL) {
        my_printf("Initial x pos : %d\n", dragon_list->info.pos_init.x);
        my_printf("Initial y pos : %d\n", dragon_list->info.pos_init.y);
        my_printf("End x pos : %d\n", dragon_list->info.pos_end.x);
        my_printf("End y pos : %d\n", dragon_list->info.pos_end.y);
        my_printf("Speed of dragon : %d\n", dragon_list->info.speed);
        my_printf("Delay of appararition : %d\n\n", dragon_list->info.delay);
        dragon_list = dragon_list->next;
    }
}

void show_list_tower(tower_t *tower_list)
{
    while (tower_list != NULL) {
        my_printf("x pos of the tower : %d\n", tower_list->pos.x);
        my_printf("y pos of the tower : %d\n", tower_list->pos.y);
        my_printf("radius of the tower : %d\n\n", tower_list->radius);
        tower_list = tower_list->next;
    }
}
