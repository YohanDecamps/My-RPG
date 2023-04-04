/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** raycast
*/

#ifndef RAYCAST_H_
    #define RAYCAST_H_

    #include "structures.h"

    /**
     * @brief This functions casts a ray in front of the player to detect walls
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *draw_all_ray_casts(rpg_t *rpg);

    /**
     * @brief This function initializes the shapes
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *init_shapes(rpg_t *rpg);

#endif /* !RAYCAST_H_ */
