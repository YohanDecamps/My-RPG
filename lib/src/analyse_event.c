/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** analyse_event
*/

#include "../include/my.h"

void analyse_events(sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
}
