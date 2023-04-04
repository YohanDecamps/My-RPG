/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** draw_buttons
*/

#include "main_menu.h"

void draw_all_buttons(button_t **all_buttons, sfRenderWindow *window)
{
    for (int i = 0; i < 2; i++)
        draw_button(all_buttons[i], window);
}
