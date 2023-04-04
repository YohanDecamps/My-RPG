/*
** EPITECH PROJECT, 2023
** init_all_buttons
** File description:
** init_all_buttons
*/
#include "main_menu.h"

button_t **init_all_buttons(void)
{
    button_t **all_buttons = malloc(sizeof(button_t *) * 10);
    if (all_buttons == NULL)
        return NULL;
    for (int i = 0; i < 10; i++) {
        all_buttons[i] = malloc(sizeof(button_t));
        if (all_buttons[i] == NULL)
            return NULL;
    }
    all_buttons[0] = init_button((sfVector2f) {840, 450}, (sfVector2f)
    {250, 75}, "New Game");
    all_buttons[1] = init_button((sfVector2f) {840, 575}, (sfVector2f)
    {250, 75}, "Load Game");
    return all_buttons;
}
