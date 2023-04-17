/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** dialogs
*/

#ifndef DIALOGS_H_
    #define DIALOGS_H_

    #include "structures.h"

    #define TEXT_SIZE 50
    #define NAME_SIZE 70
    #define NAME_POSITION (sfVector2u) {310, 460}
    #define TEXT_POSITION (sfVector2u) {100, 350}

    dialog_t *create_dialog(dialog_t *dialogs, char *name, char *text, int time);

    sfSprite *init_dialog_sprite(void);

    void display_dialogs(rpg_t *rpg);

#endif /* !DIALOGS_H_ */
