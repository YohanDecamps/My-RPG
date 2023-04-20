/*
** EPITECH PROJECT, 2023
** Proto MyRPG
** File description:
** init_rpg_values
*/

#include "lib.h"
#include "raycast.h"
#include "structures.h"
#include "sprites.h"
#include "my_rpg.h"
#include <SFML/System/Vector2.h>
#include "dialogs.h"

rpg_t *init_all_values(rpg_t *rpg)
{
    rpg->slope = SOUTH;
    rpg->player_pos.x = 225;
    rpg->player_pos.y = 275;
    rpg->gamma = 600;
    rpg->y_offset = 540;
    rpg->speed = 4;
    return (rpg);
}

rpg_t *init_rpg_variables(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    rpg = init_all_values(rpg);
    rpg->window = create_window("RPG");
    rpg = init_mouse(rpg);
    rpg->event = malloc(sizeof(sfEvent));
    rpg = init_map(rpg);
    rpg = init_all_sprites(rpg);
    rpg = init_shapes(rpg);
    rpg = init_sounds(rpg);
    rpg = init_entity(rpg);
    rpg->dialog = init_dialog_sprite();
    rpg->dialogs = NULL;
    return (rpg);
}
