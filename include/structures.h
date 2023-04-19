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
    #include <SFML/System/Types.h>
    #include <SFML/System/Vector2.h>
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
        sfVector2f hit_point;
    } ray_cast_t;

    typedef struct entity_s {
        sfCircleShape *circle;
        sfVector2f pos;
        sfSprite *sprite;
        sfVector2f size;
        float slope;
    } entity_t;

    typedef struct rpg_s {
        sfRenderWindow *window;
        sfEvent *event;
        map_t map;
        sfRectangleShape *rect;
        float y_offset;
        float slope;
        sfClock *animatinons_clock;
        sfVector2f player_pos;
        sfColor ray_color;
        float clone_slope;
        sfCircleShape *player_circle;
        sprite_t *sprite;
        entity_t *entity;
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

    #define NORTH 4.712388980384
    #define EAST 0
    #define WEST 3.14159265359;
    #define SOUTH 1.57079632679;

#endif /* !STRUCTURES_H_ */
