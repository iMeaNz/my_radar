/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** main.c
*/

#include "my.h"
#include "dragon.h"
#include "tower.h"
#include <stdlib.h>

int error_handling(int argc, char **argv);
char **create_array(char *fn);
int fill_info(dragon_t **dragon_list, tower_t **tower_list, char **array);
void show_list_dragon(dragon_t *dragon_list);
void show_list_tower(tower_t *tower_list);
void free_dragons(dragon_t *dragon_list);
void free_towers(tower_t *tower_list);
void display(dragon_t *dragon_list, tower_t *tower_list);

int main(int argc, char **argv)
{
    int error = error_handling(argc, argv);
    dragon_t *dragon_list = NULL;
    tower_t *tower_list = NULL;
    if (error == 84)
        return 84;
    else if (error == -1)
        return 0;
    char **info_array = create_array(argv[1]);
    if (info_array == 0)
        return 84;
    if (fill_info(&dragon_list, &tower_list, info_array) == 84)
        return 84;
    free_char_array(info_array);
    display(dragon_list, tower_list);
    free_dragons(dragon_list);
    free_towers(tower_list);
    return 0;
}
