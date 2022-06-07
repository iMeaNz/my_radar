/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myradar-mehdy.morvan
** File description:
** main_display.c
*/

#include "my.h"
#include "dragon.h"
#include "tower.h"
#include "framebuffer.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>

void display_all_sprites(sfRenderWindow *win, dragon_t *dragon,
                        tower_t *tower);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void update_dragon_pos(dragon_t *dragon, sfClock *clock, float *time_elapsed);
void collisions(dragon_t *dragons, tower_t *tower);
void check_if_landed(dragon_t *dragon);
void change_sprite(dragon_t *dragon, float time_elapsed);
void check_events(sfEvent event, sfRenderWindow *win, dragon_t *dragon,
                    tower_t *tower);

void check_if_dragons_landed(dragon_t *dragon, sfRenderWindow *win)
{
    while (dragon != NULL) {
        if (dragon->collided != 1)
            return;
        dragon = dragon->next;
    }
    sfRenderWindow_close(win);
}

void update_dragons(dragon_t *dragon, sfClock *clock,
                    float *time_elapsed, tower_t *tower)
{
    update_dragon_pos(dragon, clock, time_elapsed);
    collisions(dragon, tower);
    check_if_landed(dragon);
    change_sprite(dragon, *time_elapsed);
}

void update_towers(tower_t *tower, float time_elapsed)
{
    while (tower != NULL) {
        if (time_elapsed >= tower->time_since_change + 1) {
            tower->time_since_change = time_elapsed;
            tower->power += (tower->up == 1) ? 1 : -1;
            if (tower->power >= 8)
                tower->up = 0;
            if (tower->power <= 4)
                tower->up = 1;
        }
        tower = tower->next;
    }
}

void main_loop(sfRenderWindow *win, dragon_t *dragons, tower_t *towers)
{
    sfEvent event;
    sfClock *clock = sfClock_create();
    float time_elapsed = 0;
    while (sfRenderWindow_isOpen(win)) {
        check_events(event, win, dragons, towers);
        display_all_sprites(win, dragons, towers);
        sfRenderWindow_display(win);
        update_dragons(dragons, clock, &time_elapsed, towers);
        check_if_dragons_landed(dragons, win);
        update_towers(towers, time_elapsed);
    }
}

void display(dragon_t *dragon_list, tower_t *tower_list)
{
    sfVideoMode mode = {1920, 1080, 0};
    sfRenderWindow *win = sfRenderWindow_create(mode, "radar", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(win, 500);
    main_loop(win, dragon_list, tower_list);
    sfRenderWindow_destroy(win);
}
