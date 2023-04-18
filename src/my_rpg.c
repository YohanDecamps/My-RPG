/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** myrpg
*/

#include "my_rpg.h"
#include "menu.h"
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
#include <stdio.h>

void draw_all(rpg_t *rpg)
{
    sfRectangleShape_setPosition(rpg->floor,
    (sfVector2f) {0, rpg->y_offset});
    sfRenderWindow_drawRectangleShape(rpg->window, rpg->floor, NULL);
    rpg = draw_all_ray_casts(rpg);
    rpg->prev_mouse_pos = get_mouse_pos(rpg->window);
    if (sfKeyboard_isKeyPressed(sfKeyM) ||
    sfKeyboard_isKeyPressed(sfKeyTab))
        draw_map(rpg);
}

void render_metal_pipe(rpg_t *rpg, int *is_metal_pipe_throw, sfVector2f *scale)
{
    sfSprite *metal_pipe_sprite = sfSprite_copy(rpg->metal_pipe);
    sfSprite_setOrigin(metal_pipe_sprite, (sfVector2f) {275 / 2, 184 / 2});
    sfSprite_move(metal_pipe_sprite, (sfVector2f) {-275 * 2.5, -184 / 2});
    sfSprite_scale(metal_pipe_sprite, *scale);
    sfRenderWindow_drawSprite(rpg->window, metal_pipe_sprite, NULL);
    if ((*scale).x <= 0)
        *is_metal_pipe_throw = 0;
    (*scale).x -= 0.075;
    (*scale).y -= 0.075;
}

void metal_pipe_handler(rpg_t *rpg)
{
    static int is_metal_pipe_throw = 0;
    static sfVector2f distance_multiplier = {1, 1};
    sfTime time = sfClock_getElapsedTime(rpg->pipe_clock);
    if (sfTime_asSeconds(time) > rpg->throw_speed &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_play(rpg->metal_pipe_sound);
        sfClock_restart(rpg->pipe_clock);
        is_metal_pipe_throw = 1;
        distance_multiplier = (sfVector2f) {1, 1};
    }
    if (is_metal_pipe_throw == 1) {
        render_metal_pipe(rpg, &is_metal_pipe_throw, &distance_multiplier);
    } else {
        sfRenderWindow_drawSprite(rpg->window, rpg->metal_pipe, NULL);
    }
}

int myrpg(void)
{
    rpg_t *rpg = init_rpg_variables();
    main_menu(rpg->window, rpg->event, rpg);
    sfMusic_play(rpg->music);
    while (sfRenderWindow_isOpen(rpg->window)) {
        sfRenderWindow_clear(rpg->window, (sfColor) {32, 16, 16, 255});
        sfRenderTexture_clear(rpg->map_texture, sfTransparent);
        if (manage_event(rpg) == 1)
            return 0;
        rpg = handle_player_pos(rpg);
        rpg = camera_mouvement(rpg, rpg->prev_mouse_pos);
        sfMouse_setPosition((sfVector2i) {960, 540}, (sfWindow *) rpg->window);
        draw_all(rpg);
        metal_pipe_handler(rpg);
        display_framerate(rpg);
        sfRenderWindow_display(rpg->window);
    }
    return (0);
}
