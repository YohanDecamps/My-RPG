/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** update_buttons
*/

#include "structures.h"
#include "menu.h"

void set_all_button(button_t **all_buttons, enum e_gui_state new_state)
{
    for (int i = 0; i < 11; i++)
        all_buttons[i]->state = new_state;
}

button_t **update_all_buttons(button_t **buttons,
sfEvent *event, sfRenderWindow *window)
{
    for (int i = 0; i < 11; i++)
        buttons[i] = update_button(buttons[i], event, window);
    return (buttons);
}
