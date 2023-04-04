/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_buttons
*/

#include "main_menu.h"

button_t **update_all_buttons(button_t **buttons,
sfEvent *event, sfRenderWindow *window)
{
    for (int i = 0; i < 2; i++)
        buttons[i] = update_button(buttons[i], event, window);
    return (buttons);
}
