/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** fill_info.c
*/

#include "my.h"
#include "dragon.h"
#include "tower.h"
#include <math.h>
#include <stdlib.h>

int fill_info_dragon(dragon_info_t *info, int flag, int nb);
void add_dragon(dragon_t **dragon_list, dragon_info_t info);
void add_tower(tower_t **list_tower, int x, int y, int radius);
void show_info_dragon(dragon_info_t info);

void add_info_to_dragon_list(dragon_t **dragon_list, char *str, int *error)
{
    int i = 1;
    int len = my_strlen(str);
    dragon_info_t info;
    int flag_to_fill = 0;
    while (i < len) {
        if (is_num(str[i])) {
            int nb = my_getnbr(&str[i]);
            fill_info_dragon(&info, flag_to_fill++, nb);
            i += (nb < 10) ? 1 : (int)floor(log10(abs(nb))) + 1;
            continue;
        }
        if (str[i] != ' ') {
            *error = 1;
            my_printf("my_radar: Bad arguments, try with -h\n");
            return;
        }
        i++;
    }
    add_dragon(dragon_list, info);
}

void modify_tower_coords(int *x, int *y, int flag, int nb)
{
    if (flag == 0)
        *x = nb;
    if (flag == 1)
        *y = nb;
}

void modify_tower_radius(int *radius, int flag, int nb)
{
    if (flag == 2)
        *radius = nb;
}

void add_info_to_tower_list(tower_t **tower_list, char *str, int *error)
{
    int x = 0, y = 0, flag = 0, i = 1, radius = 0;
    while (str[i] != '\0') {
        if (is_num(str[i])) {
            int nb = my_getnbr(&str[i]);
            modify_tower_coords(&x, &y, flag, nb);
            modify_tower_radius(&radius, flag, nb);
            i += floor(log10(nb)) + 1;
            flag++;
            continue;
        }
        if (str[i] != ' ') {
            *error = 1;
            my_printf("my_radar: Bad arguments, try with -h\n");
            return;
        }
        i++;
    }
    add_tower(tower_list, x, y, radius);
}

int fill_info(dragon_t **dragon_list, tower_t **tower_list, char **array)
{
    int pos = 0;
    int error = 0;
    while (array[pos] != 0) {
        if (error)
            return 84;
        if (array[pos][0] == 'A')
            add_info_to_dragon_list(dragon_list, array[pos], &error);
        else if (array[pos][0] == 'T')
            add_info_to_tower_list(tower_list, array[pos], &error);
        else {
            my_printf("my_radar: Bad arguments, retry with -h\n");
            return 84;
        }
        pos++;
    }
    return 0;
}
