/*
** EPITECH PROJECT, 2023
** Proto MyRPG
** File description:
** init_other_rpg_vars
*/

#include "my_rpg.h"

void manage_event(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->window, rpg->event)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(rpg->window);
        analyse_events(rpg->window, rpg->event);
    }
}

rpg_t *init_sounds(rpg_t *rpg)
{
    rpg->music = sfMusic_createFromFile("assets/Theme.ogg");
    rpg->metal_pipe_sound =
    sfMusic_createFromFile("assets/Metal_pipe_sound.ogg");
    return (rpg);
}

rpg_t *init_map(rpg_t *rpg)
{
    rpg->map.array = my_str_to_word_array(get_buffer("map1.txt"), '\n');
    rpg->map.y = count_words(get_buffer("map1.txt"), '\n');
    rpg->map_texture = sfRenderTexture_create(1920, 1080, sfFalse);
    rpg->map_sprite = sfSprite_create();
    return (rpg);
}

rpg_t *init_mouse(rpg_t *rpg)
{
    sfWindow_setMouseCursorVisible((sfWindow *) rpg->window, sfFalse);
    sfMouse_setPosition((sfVector2i) {960, 540}, (sfWindow *) rpg->window);
    rpg->prev_mouse_pos.x = 920;
    rpg->prev_mouse_pos.y = 540;
    return (rpg);
}