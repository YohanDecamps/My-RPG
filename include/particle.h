/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-ethan.thierry
** File description:
** particle
*/

#ifndef PARTICLE_H_
    #define PARTICLE_H_

    #include "structures.h"
    #include "stdlib.h"
    #include <SFML/Graphics.h>

    void update_particles (verlet_t **particle, sfVector2f move, sfRenderWindow *w);

    verlet_t **create_particles (particles_args_t *args);

#endif /* !PARTICLE_H_ */
