/*
** EPITECH PROJECT, 2023
** Proto MyRPG
** File description:
** handle_movement
*/

#include "lib.h"
#include "my_rpg.h"
#include "structures.h"
#include <math.h>

rpg_t *handle_direction(rpg_t *rpg, float speed, sfKeyCode key, float angle)
{
    if (sfKeyboard_isKeyPressed(key)) {
        if (rpg->map.array[(int) ((rpg->player_pos.y + sin(rpg->slope + angle)
        * 20) / 50)][(int) ((rpg->player_pos.x) / 50)] == ' ')
            rpg->player_pos = (sfVector2f) {rpg->player_pos.x,
            rpg->player_pos.y + sin(rpg->slope + angle) * speed};
        if (rpg->map.array[(int) ((rpg->player_pos.y) / 50)][(int)
        ((rpg->player_pos.x + cos(rpg->slope + angle) * 20) / 50)] == ' ')
            rpg->player_pos = (sfVector2f) {rpg->player_pos.x +
            cos(rpg->slope + angle) * speed, rpg->player_pos.y};
    }
    return (rpg);
}

rpg_t *handle_player_pos(rpg_t *rpg)
{
    handle_direction(rpg, rpg->speed, sfKeyZ, 0);
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        handle_direction(rpg, rpg->speed * 0.5, sfKeyLShift, 0);
    handle_direction(rpg, rpg->speed, sfKeyS, pi);
    handle_direction(rpg, rpg->speed * 0.75, sfKeyQ, 3 * (pi / 2));
    handle_direction(rpg, rpg->speed * 0.75, sfKeyD, pi / 2);
    return (rpg);
}
