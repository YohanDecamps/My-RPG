/*
** EPITECH PROJECT, 2023
** Proto MyRPG
** File description:
** draw_map
*/

#include "lib.h"
#include "my_rpg.h"
#include "structures.h"

void draw_map_sprite(rpg_t *rpg, int i, int j, char id)
{
    if (rpg->maps[rpg->level]->array[i][j] == id) {
        sfSprite_setPosition(rpg->sprite[(int) id].map_sprite, (sfVector2f)
        {j * 50 - rpg->player_pos.x + 150, i * 50 - rpg->player_pos.y + 150});
        sfRenderTexture_drawSprite(rpg->map_texture,
        rpg->sprite[(int) id].map_sprite, NULL);
    }
}

void draw_map_x(rpg_t *rpg, int i)
{
    for (int j = 0; j < my_strlen(rpg->maps[rpg->level]->array[i]); j++) {
        if (rpg->maps[rpg->level]->array[i][j] == ' ') {
            sfRectangleShape_setPosition(rpg->rect, (sfVector2f) {j * 50
            - rpg->player_pos.x + 150, i * 50 - rpg->player_pos.y + 150});
            sfRectangleShape_setFillColor(rpg->rect, sfBlack);
            sfRenderTexture_drawRectangleShape(rpg->map_texture,
            rpg->rect, NULL);
        }
        for (int nb = 0; nb < my_strlen(rpg->sprite_str); nb++)
            draw_map_sprite(rpg, i, j, rpg->sprite_str[nb]);
    }
}

void draw_map(rpg_t *rpg)
{
    for (int i = 0; i < rpg->maps[rpg->level]->y; i++)
        draw_map_x(rpg, i);
    sfRenderTexture_drawCircleShape(rpg->map_texture, rpg->player_circle, NULL);
    sfSprite_setTexture(rpg->map_sprite,
    sfRenderTexture_getTexture(rpg->map_texture), sfTrue);
    sfSprite_setTextureRect(rpg->map_sprite, (sfIntRect) {0, 1080, 300, -300});
    sfSprite_setRotation(rpg->map_sprite, -rpg->slope * (180 / pi) - 90);
    sfSprite_setOrigin(rpg->map_sprite, (sfVector2f) {150, 150});
    sfSprite_setPosition(rpg->map_sprite, (sfVector2f) {150, 150});
    sfRenderWindow_drawSprite(rpg->window, rpg->map_sprite, NULL);
}
