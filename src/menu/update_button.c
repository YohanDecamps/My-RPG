/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** update_button
*/
#include "structures.h"
#include "menu.h"

static void update_button_mousbuttonreleased(struct button_s *button,
sfRenderWindow *window)
{
    if (button->is_hover(button, window) && button->state == PRESSED)
        button->state = HOVER;
    else if (button->is_hover(button, window) && button->state != PRESSED)
        button->state = PRESSED;
}

struct button_s *update_button(struct button_s *button, sfEvent *event,
sfRenderWindow *window)
{
    if (event->type == sfEvtMouseMoved)
        if (button->is_hover(button, window) && button->state != PRESSED)
            button->state = HOVER;
    if (event->type == sfEvtMouseButtonReleased) {
        update_button_mousbuttonreleased(button, window);
    }
    if (event->type == sfEvtMouseMoved)
        if (button->is_hover(button, window) == sfFalse &&
        button->state != PRESSED)
            button->state = NONE;
    return (button);
}
