/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** structures
*/

#ifndef STRUCTURES_H_
    #define STRUCTURES_H_

    #include <SFML/Audio/Types.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics/Vertex.h>
    #include <SFML/Window/Event.h>

    typedef struct map_s {
        char **array;
        int y;
    } map_t;

    typedef struct sprite_s {
        sfSprite *ray_sprite;
        sfSprite *map_sprite;
    } sprite_t;

    typedef struct ray_cast_s {
        int x_offset;
        float distance;
        sfVertex hit_point;
    } ray_cast_t;

    typedef struct rpg_s {
        sfRenderWindow *window;
        sfEvent *event;
        map_t map;
        sfRectangleShape *rect;
        float y_offset;
        float slope;
        sfVector2f player_pos;
        sfColor ray_color;
        float clone_slope;
        sfCircleShape *player_circle;
        sprite_t *sprite;
        char *sprite_str;
        sfRenderTexture *map_texture;
        sfSprite *map_sprite;
        sfSprite *metal_pipe;
        sfRectangleShape *floor;
        sfMusic *metal_pipe_sound;
        sfMusic *music;
        sfVector2f prev_mouse_pos;
        float gamma;
        float speed;
    } rpg_t;

#endif /* !STRUCTURES_H_ */
