/*
** EPITECH PROJECT, 2023
** main_menu
** File description:
** main_menu
*/
#include "main_menu.h"

void show_saves(button_t **all_buttons, sfRenderWindow *window)
{
    draw_button(all_buttons[2], window);
    draw_button(all_buttons[3], window);
    draw_button(all_buttons[4], window);
}

void main_menu_handler(button_t **all_buttons, sfRenderWindow *window)
{
    if (all_buttons[1]->state == PRESSED)
        show_saves(all_buttons, window);
}

static void analyse_events(sfEvent *event, sfRenderWindow *window,
button_t **all_buttons)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    update_all_buttons(all_buttons, event, window);
}

int main_menu(sfRenderWindow *window, sfEvent *event)
{
    sfRenderWindow_setMouseCursorVisible(window, 1);
    button_t **all_buttons = init_all_buttons();
    while (sfRenderWindow_isOpen(window) && all_buttons[0]->state != PRESSED) {
        sfRenderWindow_clear(window, (sfColor) {130, 130, 130, 255});
        while (sfRenderWindow_pollEvent(window, event)) {
            analyse_events(event, window, all_buttons);
        }
        if (all_buttons[7]->state == PRESSED)
            return 1;
        main_menu_handler(all_buttons, window);
        draw_main_menu_buttons(all_buttons, window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_setMouseCursorVisible(window, 0);
    set_all_button(all_buttons, NONE);
    return 0;
}
