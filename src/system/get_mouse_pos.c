/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** get_mouse_pos
*/

#include "my_rpg.h"

sfVector2f get_mouse_pos(sfRenderWindow *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f mouse_pos = (sfVector2f) {
    sfMouse_getPositionRenderWindow(window).x * 1920 / window_size.x,
    sfMouse_getPositionRenderWindow(window).y * 1011 / window_size.y};
    return (mouse_pos);
}
