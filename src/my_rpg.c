/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** myrpg
*/

#include "my_rpg.h"
#include "movement.h"
#include "sprites.h"
#include "raycast.h"
#include "structures.h"
#include "system.h"
#include "window.h"
#include "events.h"
#include <SFML/Audio/Music.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/RenderWindow.h>

void draw_all(rpg_t *rpg)
{
    sfRectangleShape_setPosition(rpg->floor,
    (sfVector2f) {0, rpg->y_offset});
    sfRenderWindow_drawRectangleShape(rpg->window, rpg->floor, NULL);
    rpg = draw_all_ray_casts(rpg);
    sfMouse_setPosition((sfVector2i) {960, 540}, (sfWindow *) rpg->window);
    rpg->prev_mouse_pos = get_mouse_pos(rpg->window);
    if (sfKeyboard_isKeyPressed(sfKeyM) ||
    sfKeyboard_isKeyPressed(sfKeyTab))
        draw_map(rpg);
    sfRenderWindow_drawSprite(rpg->window, rpg->metal_pipe, NULL);
}

int myrpg(void)
{
    rpg_t *rpg = init_rpg_variables();
    sfMusic_play(rpg->music);
    while (sfRenderWindow_isOpen(rpg->window)) {
        sfRenderWindow_clear(rpg->window, (sfColor) {32, 16, 16, 255});
        sfRenderTexture_clear(rpg->map_texture, sfTransparent);
        manage_event(rpg);
        rpg = handle_player_pos(rpg);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfMusic_stop(rpg->metal_pipe_sound);
            sfMusic_play(rpg->metal_pipe_sound);
        }
        rpg = camera_mouvement(rpg, rpg->prev_mouse_pos);
        draw_all(rpg);
        display_framerate(rpg);
        sfRenderWindow_display(rpg->window);
    }
    return (0);
}
