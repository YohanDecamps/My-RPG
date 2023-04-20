/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** my
*/

#ifndef MYRPG_H_
    #define MYRPG_H_

    #include "structures.h"

    /**
     * @brief The main function for the project
     *
     * @return int - Exit status
     */
    int myrpg(void);

    /**
     * @brief This function initializes all the values of the rpg_t structure
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *init_all_values(rpg_t *rpg);

    /**
     * @brief This function initializes all the program's variables
     *
     * @return rpg_t* - The initialized
     */
    rpg_t *init_rpg_variables(void);

    /**
     * @brief This function initializes the sounds
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *init_sounds(rpg_t *rpg);

    /**
     * @brief This function initializes the map
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *init_map(rpg_t *rpg);

    /**
     * @brief This function initializes the mouse structure
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *init_mouse(rpg_t *rpg);

    /**
     * @brief This function initializes the entity structure
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *init_entity(rpg_t *rpg);

     * @brief This function draw all the game elements
     *
     * @param rpg - rpg_t structure
     * @return void
    */
    void draw_all(rpg_t *rpg);

    /**
     * @brief This function reinitialyses the value of rpg stuct
     *
     * @param rpg - rpg_t struture
     * @return void
    */
    rpg_t *reinit_rpg_values(rpg_t *rpg);

#endif /* !MY_H_ */
