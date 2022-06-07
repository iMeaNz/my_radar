/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** show_info_dragon.c
*/

#include "my.h"
#include "dragon.h"

void show_info_dragon(dragon_info_t info)
{
    my_printf("Initial x pos : %d\n", info.pos_init.x);
    my_printf("Initial y pos : %d\n", info.pos_init.y);
    my_printf("End x pos : %d\n", info.pos_end.x);
    my_printf("End y pos : %d\n", info.pos_end.y);
    my_printf("Speed of dragon : %d\n", info.speed);
    my_printf("Delay of appararition : %d\n\n", info.delay);
}
