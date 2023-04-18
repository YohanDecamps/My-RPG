/*
** EPITECH PROJECT, 2023
** settings_menu
** File description:
** settings_menu
*/
#include "menu.h"
#include "structures.h"
#include "lib.h"

void draw_settings_buttons(button_t **all_buttons, rpg_t *rpg)
{
    draw_button(all_buttons[11], rpg->window);
    draw_button(all_buttons[12], rpg->window);
    draw_button(all_buttons[13], rpg->window);
    draw_button(all_buttons[14], rpg->window);
    draw_button(all_buttons[15], rpg->window);
    draw_button(all_buttons[16], rpg->window);
    draw_button(all_buttons[17], rpg->window);
    draw_button(all_buttons[18], rpg->window);
}

void set_settings_button(int state, button_t **all_buttons)
{
    all_buttons[11]->state = state;
    all_buttons[12]->state = state;
    all_buttons[13]->state = state;
    all_buttons[14]->state = state;
    all_buttons[15]->state = state;
    all_buttons[16]->state = state;
    all_buttons[17]->state = state;
    all_buttons[18]->state = state;
}

sfKeyCode assign_key(rpg_t *rpg, button_t *button)
{
    sfRenderWindow_waitEvent(rpg->window, rpg->event);
    button->state = NONE;
    return rpg->event->key.code;
}

int settings_menu(button_t **all_buttons, rpg_t *rpg)
{
    if (all_buttons[5]->state == PRESSED)
        draw_settings_buttons(all_buttons, rpg);
    if (all_buttons[5]->state == NONE)
        set_settings_button(NONE, all_buttons);
    if (all_buttons[13]->state == PRESSED)
        rpg->key_binds->forward = assign_key(rpg, all_buttons[13]);
    if (all_buttons[14]->state == PRESSED)
        rpg->key_binds->backward = assign_key(rpg, all_buttons[14]);
    if (all_buttons[15]->state == PRESSED)
        rpg->key_binds->left = assign_key(rpg, all_buttons[15]);
    if (all_buttons[16]->state == PRESSED)
        rpg->key_binds->right = assign_key(rpg, all_buttons[16]);
    return 0;
}
