/*
** EPITECH PROJECT, 2023
** reinitialyse rpg values
** File description:
** reinitialyse rpg values
*/
#include "my_rpg.h"
#include "lib.h"

rpg_t *reinit_rpg_values(rpg_t *rpg)
{
    rpg->slope = 2 * pi;
    rpg->player_pos.x = 75;
    rpg->player_pos.y = 275;
    rpg->gamma = 600;
    rpg->y_offset = 540;
    rpg->speed = 4;
    sfWindow_setMouseCursorVisible((sfWindow *) rpg->window, sfFalse);
    return rpg;
}
