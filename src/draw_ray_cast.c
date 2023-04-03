/*
** EPITECH PROJECT, 2023
** Proto MyRPG
** File description:
** draw_ray_cast
*/

#include "my_rpg.h"

int is_vertical(float xprd, float yprd)
{
    if ((xprd < 0.5 && yprd < 0.5 && xprd < yprd)
    || (xprd > 0.5 && yprd > 0.5 && xprd > yprd)
    || (xprd < 0.5 && yprd > 0.5 && 1 - xprd > yprd)
    || (xprd > 0.5 && yprd < 0.5 && xprd > 1 - yprd))
        return (1);
    return (0);
}

void set_texture(float xprd, float yprd, sfSprite *sprite)
{
    if (is_vertical(xprd, yprd))
        sfSprite_setTextureRect(sprite, (sfIntRect)
        {yprd * 256, 0, 1, 256});
    else
        sfSprite_setTextureRect(sprite, (sfIntRect)
        {xprd * 256, 0, 1, 256});
}

void draw_ray_sprite(rpg_t *rpg, ray_cast_t *rc, int i)
{
    sfSprite *sprite = rpg->sprite[(int) rpg->sprite_str[i]].ray_sprite;
    char id = rpg->sprite_str[i];
    if (rpg->map.array[(int) rc->hit_point.position.y / 50]
    [(int) rc->hit_point.position.x / 50] == id) {
        float xprd = rc->hit_point.position.x / 50 -
        (int) (rc->hit_point.position.x / 50);
        float yprd = rc->hit_point.position.y / 50 -
        (int) (rc->hit_point.position.y / 50);
        float shades = rc->distance * 255 / rpg->gamma;
        if (shades > 255)
            shades = 255;
        sfSprite_setScale(sprite, (sfVector2f)
        {1, (float) ((96 * 1080) / rc->distance) / 256});
        sfSprite_setColor(sprite, (sfColor)
        {255 - shades, 255 - shades, 255 - shades, 255});
        set_texture(xprd, yprd, sprite);
        sfSprite_setPosition(sprite, (sfVector2f) {960 + rc->x_offset,
        rpg->y_offset - (((96 * 1080) / rc->distance) / 2)});
        sfRenderWindow_drawSprite(rpg->window, sprite, NULL);
    }
}

void draw_ray_cast(rpg_t *rpg, int nb)
{
    float distance = 0.20;
    sfVertex point;
    point.position = (sfVector2f) {rpg->player_pos.x + cos(rpg->slope) * 1,
    rpg->player_pos.y + sin(rpg->slope) * 1};
    for (; rpg->map.array[(int) point.position.y / 50]
    [(int) point.position.x / 50] == ' '; distance = distance + 1)
        point.position = (sfVector2f) {rpg->player_pos.x + cos(rpg->slope)
        * distance, rpg->player_pos.y + sin(rpg->slope) * distance};
    distance = distance * cos(rpg->slope - rpg->clone_slope);
    if (distance <= 0)
        distance = 1;
    ray_cast_t *rc = malloc(sizeof(ray_cast_t));
    rc->x_offset = nb;
    rc->distance = distance;
    rc->hit_point = point;
    for (int i = 0; i < my_strlen(rpg->sprite_str); i++)
        draw_ray_sprite(rpg, rc, i);
}

rpg_t *draw_all_ray_casts(rpg_t *rpg)
{
    rpg->clone_slope = rpg->slope;
    for (int i = 0; i <= 960; i++) {
        draw_ray_cast(rpg, i);
        rpg->slope = rpg->clone_slope + 0.0005 * (i + 1);
    }
    rpg->slope = rpg->clone_slope;
    for (int i = -0; i >= -960; i--) {
        draw_ray_cast(rpg, i);
        rpg->slope = rpg->clone_slope + 0.0005 * (i - 1);
    }
    rpg->slope = rpg->clone_slope;
    draw_ray_cast(rpg, 0);
    return (rpg);
}
