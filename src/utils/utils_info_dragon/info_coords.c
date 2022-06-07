/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** info_coords.c
*/

#include "dragon.h"

void x_init(dragon_info_t *info, int nb)
{
    info->pos_init.x = nb;
}

void y_init(dragon_info_t *info, int nb)
{
    info->pos_init.y = nb;
}

void x_end(dragon_info_t *info, int nb)
{
    info->pos_end.x = nb;
}

void y_end(dragon_info_t *info, int nb)
{
    info->pos_end.y = nb;
}
