/*
** EPITECH PROJECT, 2023
** Proto MyRPG
** File description:
** camera_movement
*/

#include "movement.h"
#include "my_rpg.h"
#include "raycast.h"

rpg_t *camera_mouvement(rpg_t *rpg, sfVector2f prev_mouse_pos)
{
    if (get_mouse_pos(rpg->window).y > prev_mouse_pos.y)
        if (rpg->y_offset - (get_mouse_pos(rpg->window).y
        - prev_mouse_pos.y) * 2 > -1620)
            rpg->y_offset += (prev_mouse_pos.y
            - get_mouse_pos(rpg->window).y) * 2;
    if (get_mouse_pos(rpg->window).y < prev_mouse_pos.y)
        if (rpg->y_offset + (prev_mouse_pos.y
        - get_mouse_pos(rpg->window).y) * 2 < 2700)
            rpg->y_offset -= (get_mouse_pos(rpg->window).y
            - prev_mouse_pos.y) * 2;
    if (get_mouse_pos(rpg->window).x > prev_mouse_pos.x)
        rpg->slope -= (prev_mouse_pos.x - get_mouse_pos(rpg->window).x) * 0.001;
    if (get_mouse_pos(rpg->window).x < prev_mouse_pos.x)
        rpg->slope += (get_mouse_pos(rpg->window).x - prev_mouse_pos.x) * 0.001;
    rpg->slope = reset_angle(rpg->slope);
    return (rpg);
}
