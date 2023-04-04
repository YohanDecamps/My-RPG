/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** update_button
*/

#include "main_menu.h"

struct button_s *update_button(struct button_s *button, sfEvent *event,
sfRenderWindow *window)
{
    if (event->type == sfEvtMouseMoved)
        if (button->is_hover(button, window))
            button->state = HOVER;
    if (event->type == sfEvtMouseButtonReleased)
        if (button->is_clicked(button, window))
            button->state = PRESSED;
    if (event->type == sfEvtMouseMoved)
        if (button->is_hover(button, window) == sfFalse)
            button->state = NONE;
    if (sfMouse_isButtonPressed(sfMouseLeft))
        if (button->is_clicked(button, window))
            button->state = NONE;
    return (button);
}
