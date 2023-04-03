/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #define SUCCESS 0
    #define FAILURE 1
    #define ERROR 84
    #define pi 3.1415926535

    #include <unistd.h>
    #include <stdlib.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <math.h>
    #include <time.h>

    typedef struct map_s {
        char **array;
        int y;
    }map_t;

    typedef struct sprite_s {
        sfSprite *ray_sprite;
        sfSprite *map_sprite;
    }sprite_t;

    typedef struct ray_cast_s {
        int x_offset;
        float distance;
        sfVertex hit_point;
    }ray_cast_t;

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
    }rpg_t;

    rpg_t *camera_mouvement(rpg_t *rpg, sfVector2f prev_mouse_pos);

    rpg_t *draw_all_ray_casts(rpg_t *rpg);

    void display_framerate(rpg_t *rpg);

    rpg_t *handle_direction(rpg_t *rpg, float speed,
    sfKeyCode key, float angle);

    void draw_map_sprite(rpg_t *rpg, int i, int j, char id);

    void draw_map(rpg_t *rpg);

    rpg_t *handle_player_pos(rpg_t *rpg);

    int myrpg(void);

    int my_strlen(char *str);

    int is_mouse_presed(rpg_t *rpg);

    char *get_user_input(void);

    sfVector2f get_mouse_pos(sfRenderWindow *window);

    struct sfText *create_text(char *displayed_text, int size);

    sfRenderWindow* create_window(char *name);

    sfSprite *create_sprite(char *file, sfVector2f scale);

    float update_pencil_size(rpg_t *rpg);

    sfVector2f get_mouse_pos(sfRenderWindow *window);

    rpg_t *draw_pencil(rpg_t *rpg);

    void set_cursor_pos(rpg_t *rpg);

    void analyse_events(sfRenderWindow *window, sfEvent *event);

    void set_cursor_pos(rpg_t *rpg);

    void draw_cursors(rpg_t *rpg);

    char **my_str_to_word_array(char *str, char separator);

    char *get_buffer(const char *filename);

    int count_words(char *str, char separator);

    char *int_to_string(int x);

    char *my_strcat(char *str1, char *str2);

    rpg_t *init_all_values(rpg_t *rpg);

    rpg_t *init_rpg_varibales(void);

    rpg_t *init_shapes(rpg_t *rpg);

    rpg_t *init_sprite(rpg_t *rpg, char id, char *file);

    rpg_t *init_all_sprites(rpg_t *rpg);

    void manage_event(rpg_t *rpg);

    rpg_t *init_sounds(rpg_t *rpg);

    rpg_t *init_map(rpg_t *rpg);

    rpg_t *init_mouse(rpg_t *rpg);


#endif /* !MY_H_ */
