/*
** EPITECH PROJECT, 2023
** merge_save
** File description:
** load
*/

#include "structures.h"
#include "system.h"
#include <stdio.h>

static float get_float_from_str(char* str)
{
    int result = 0;
    float decimal = 0.0;
    float divisor = 1.0;
    while (*str != '.') {
        result = result * 10 + (*str - '0');
        ++str;
    }
    str++;
    while (*str) {
        decimal = decimal + ((*str - '0') / divisor);
        divisor *= 10;
        ++str;
    }
    return result + decimal;
}

void load (rpg_t *rpg)
{
    if (rpg->save_entry == NULL)
        return;
    char *pos_x = save_getvalue(rpg->save_entry, "pos_x");
    char *pos_y = save_getvalue(rpg->save_entry, "pos_y");
    rpg->player_pos.x = get_float_from_str(pos_x);
    rpg->player_pos.y = get_float_from_str(pos_y);
}
