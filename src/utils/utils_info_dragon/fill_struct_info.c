/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** fill_struct_info.c
*/

#include "my.h"
#include "dragon.h"

void x_init(dragon_info_t *info, int nb);
void y_init(dragon_info_t *info, int nb);
void x_end(dragon_info_t *info, int nb);
void y_end(dragon_info_t *info, int nb);
void delay(dragon_info_t *info, int nb);
void speed(dragon_info_t *info, int nb);

int fill_info_dragon(dragon_info_t *info, int flag, int nb)
{
    void (*ptr_func[])(dragon_info_t *info, int nb) =
    {
        &x_init, &y_init, &x_end, &y_end, &speed, &delay
    };
    for (int i = 0; i < 6; i++) {
        if (i == flag) {
            ptr_func[i](info, nb);
            return 1;
        }
    }
    return 0;
}
