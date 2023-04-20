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
#include "dialogs.h"

rpg_t *init_all_values(rpg_t *rpg)
{
    rpg->slope = 2 * pi;
    rpg->player_pos.x = 75;
    rpg->player_pos.y = 275;
    rpg->gamma = 600;
    rpg->y_offset = 540;
    rpg->speed = 4;
    rpg->how_to_play_back = sfRenderTexture_create(500, 800, 0);
    sfRenderTexture_clear(rpg->how_to_play_back, sfWhite);
    rpg->how_to_play_text = create_text("You are Amonichi Gustavo,\n a SUS \
Inc. employee.\nYour role is to retrieve the\nObunga last name meaning you\n\
will have to adventure in his \nmanor.\nThe SUS inc. gave you a weapon\nto \
defend yourself, but because\nof the inflation they could only\nafford a \
Cardboard pipe\nthat you can use by pressing\nleft click.\nObunga's manor is \
divided in\ndifferent floor, each one\nhaving its own menace.\n\n\
Current objective :\nSurvive", 25);
    return (rpg);
}

rpg_t *init_rpg_variables(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    rpg->size_x = 1920;
    rpg->size_y = 1080;
    rpg = init_all_values(rpg);
    rpg->window = create_window("RPG", 1920, 1080);
    rpg = init_mouse(rpg);
    rpg->event = malloc(sizeof(sfEvent));
    rpg = init_map(rpg);
    rpg = init_all_sprites(rpg);
    rpg = init_shapes(rpg);
    rpg = init_sounds(rpg);
    rpg->key_binds = malloc(sizeof(movement_keys_t));
    rpg = init_key_binds(rpg);
    rpg->dialog = init_dialog_sprite();
    rpg->dialogs = NULL;
    return (rpg);
}
