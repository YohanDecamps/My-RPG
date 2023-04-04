/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** events
*/

#ifndef EVENTS_H_
    #define EVENTS_H_

    #include "structures.h"

    /**
     * @brief This function manages the events
     *
     * @param rpg - rpg_t structure
     */
    void manage_event(rpg_t *rpg);

    /**
     * @brief Registers Windows events and calls the appropriate functions
     *
     * @param window - The window to get the events from
     * @param event - The event to be analysed
     */
    void analyse_events(sfRenderWindow *window, sfEvent *event);

#endif /* !EVENTS_H_ */
