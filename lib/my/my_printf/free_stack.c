/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** free_stack.c
*/

#include "../my.h"
#include "mylist.h"
#include <stdlib.h>
#include "stack.h"

void free_stack(stack_t *stack)
{
    stack_t *tmp;

    while (stack != NULL) {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}

void free_stack_printable(stack_printable_t *stack)
{
    stack_printable_t *tmp;

    while (stack != NULL) {
        tmp = stack;
        stack = stack->next;
        free(tmp->str);
        free(tmp);
    }
}
