/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** create_window
*/

#include "../include/my.h"

sfRenderWindow* create_window(char *name)
{
    sfRenderWindow* window;
    window = sfRenderWindow_create((sfVideoMode) {1920, 1080, 32},
    name, sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(window, 1);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}
