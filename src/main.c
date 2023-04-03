/*
** EPITECH PROJECT, 2023
** stumper04
** File description:
** main
*/

#include "my_rpg.h"
#include "system.h"

int main(int ac, char **av, char **env)
{
    if (my_getenv(env, "DISPLAY") == NULL)
        return ERROR;
    return myrpg();
}
