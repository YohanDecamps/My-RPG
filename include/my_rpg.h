/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** my
*/

#ifndef MYRPG_H_
    #define MYRPG_H_

    #include "structures.h"

    #define MAPS_COUNT 4

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
    rpg_t *init_maps(rpg_t *rpg);

    /**
     * @brief This function initializes the mouse structure
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *init_mouse(rpg_t *rpg);

    /**
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
     * @return rpg_t srtucture
    */
    rpg_t *reinit_rpg_values(rpg_t *rpg);

    /**
     * @brief Switches the level
     *
     * @param rpg - rpg_t structure
     * @return int - return status
     */
    int switch_level(rpg_t *rpg, int level);

    /**
     * @brief This function frees the memory allocated for the rpg_t structure
     *
     * @param rpg - rpg_t structure
     */
    void freemem(rpg_t *rpg);
    
    /**
     * @brief This function init default key binds
     *
     * @param rpg - rpg_t structure
     * @return rpg_t structure
     */
    rpg_t *init_key_binds(rpg_t *rpg);

#endif /* !MY_H_ */
