/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** structures
*/

#ifndef STRUCTURES_H_
    #define STRUCTURES_H_

    #include <SFML/Audio/Types.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics/Vertex.h>
    #include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
    #include <SFML/Window/Event.h>
    #include <SFML/System/Clock.h>

    #define MAXWINSIZE (sfVector2u) {1920, 1080}

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

    enum e_gui_state {
        NONE = 0,
        HOVER,
        PRESSED,
    };

    typedef struct button_s {
        sfRectangleShape *rect;
        sfText *name;
        sfBool (*is_clicked) (struct button_s* button, sfRenderWindow *window);
        sfBool (*is_hover) (struct button_s* button, sfRenderWindow *window);
        enum e_gui_state state;
        sfFloatRect hitbox;
        int is_toggle;
    } button_t;

    typedef struct save_entry_s {
        char *name;
        char *value;
    } save_entry_t;

    typedef struct dialog_s {
        sfText *name;
        sfText *text;
        sfClock *clock;
        int time;
        struct dialog_s *next;
    } dialog_t;

    typedef struct dialog_dim_s {
        sfVector2f dialog_pos;
        sfVector2f name_pos;
        sfVector2f text_pos;
        sfVector2f scale;
    } dialog_dim_t;

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
        sfSprite *dialog;
        dialog_t *dialogs;
        float gamma;
        float speed;
    } rpg_t;

#endif /* !STRUCTURES_H_ */
