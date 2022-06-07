/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** info_misc.c
*/

#include "dragon.h"

void speed(dragon_info_t *info, int nb)
{
    info->speed = nb;
}

void delay(dragon_info_t *info, int nb)
{
    info->delay = nb;
}
