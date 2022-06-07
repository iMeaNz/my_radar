/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** error_handling.c
*/

#include "my.h"

void display_usage(void)
{
    my_printf("Air traffic simulation panel\n\n");
    my_printf("USAGE\n    ./my_radar        [OPTIONS] path_to_script\n");
    my_printf("    path_to_script    The path to the script file.\n\n");
    my_printf("OPTIONS\n    -h    print the usage and quit.\n\n");
    my_printf("USER INTERACTIONS\n    Down arrow key      ");
    my_printf("enable/disable sprites.\n    Up arrow key");
    my_printf("        enable/disable dragon's hitboxes.\n");
}

int error_handling(int argc, char **argv)
{
    if (argc != 2) {
        my_printf("./my_radar: bad arguments: 0 given but 1 is required\n");
        my_printf("retry with -h\n");
        return 84;
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        display_usage();
        return -1;
    }
    return 0;
}
