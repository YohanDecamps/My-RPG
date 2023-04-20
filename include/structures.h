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
    #include <SFML/System/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Window/Event.h>
    #include <SFML/System/Clock.h>

    #define MAXWINSIZE (sfVector2u) {1920, 1080}

    #define NORTH 4.712388980384
    #define EAST 0
    #define WEST 3.14159265359;
    #define SOUTH 1.57079632679;

    // gravity suggested value = {0, 6000}
    // medium_speed suggested value = 40000
    typedef struct particles_args {
        sfVector2f position;
        sfTexture *texture;
        int medium_speed_x;
        int medium_speed_y;
        int nbr;
        int radius;
    } particles_args_t;

    typedef struct verletobject {
        sfCircleShape *circle;
        sfVector2f curr_pos;
        sfVector2f old_pos;
        sfVector2f acceleration;
        int need_to_be_killed;
    } verlet_t;

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

    enum e_gui_state {
        NONE = 0,
        HOVER,
        PRESSED,
    };

    typedef struct save_entry_s {
        char *name;
        char *value;
    } save_entry_t;

    typedef struct movement_keys_s {
        sfKeyCode forward;
        sfKeyCode backward;
        sfKeyCode left;
        sfKeyCode right;
        sfKeyCode run;
    } movement_keys_t;

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
        sfSprite *dialog;
        dialog_t *dialogs;
        float gamma;
        float speed;
        int size_x;
        int size_y;
        movement_keys_t *key_binds;
    } rpg_t;

    typedef struct button_s {
        sfRectangleShape *rect;
        sfText *name;
        sfBool (*is_clicked) (struct button_s* button,
        sfRenderWindow *window, rpg_t *rpg);
        sfBool (*is_hover) (struct button_s* button,
        sfRenderWindow *window, rpg_t *rpg);
        enum e_gui_state state;
        sfFloatRect hitbox;
        int is_toggle;
    } button_t;

#endif /* !STRUCTURES_H_ */
