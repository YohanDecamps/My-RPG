/*
** EPITECH PROJECT, 2023
** main_menu
** File description:
** main_menu
*/
#include "menu.h"
#include "my_rpg.h"
#include "structures.h"
#include "sprites.h"

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
    draw_main_menu_buttons(all_buttons, window);
}

void analyse_button_events(sfEvent *event, sfRenderWindow *window,
button_t **all_buttons)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    update_all_buttons(all_buttons, event, window);
}

int main_menu(sfRenderWindow *window, sfEvent *event, rpg_t *rpg)
{
    sfRenderWindow_setMouseCursorVisible(window, 1);
    sfMusic_stop(rpg->music);
    button_t **all_buttons = init_all_buttons();
    sfSprite *background = create_sprite("assets/shrek_background.png",
    (sfVector2f) {1.6,1.4});
    while (sfRenderWindow_isOpen(window) && all_buttons[0]->state != PRESSED) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, background, NULL);
        while (sfRenderWindow_pollEvent(window, event))
            analyse_button_events(event, window, all_buttons);
        if (all_buttons[7]->state == PRESSED) {
            sfRenderWindow_close(window);
            return 0;
        }
        main_menu_handler(all_buttons, window);
        sfRenderWindow_display(window);
    }
    set_all_button(all_buttons, NONE);
    rpg = reinit_rpg_values(rpg);
    return 0;
}
