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

    /**
     * @brief This function catches the mouse position and its movements
     *
     * @param rpg - rpg_t structure
     * @param prev_mouse_pos - previous mouse position
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *camera_mouvement(rpg_t *rpg, sfVector2f prev_mouse_pos);

    /**
     * @brief This functions casts a ray in front of the player to detect walls
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *draw_all_ray_casts(rpg_t *rpg);

    /**
     * @brief This function changes the window's title to display the framerate
     *
     * @param rpg - rpg_t structure
     */
    void display_framerate(rpg_t *rpg);

    /**
     * @brief This function handles movement keystrokes
     *
     * @param rpg - rpg_t structure
     * @param speed - The speed of the player
     * @param key - The key pressed
     * @param angle - The current angle of direction of the player
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *handle_direction(rpg_t *rpg, float speed,
    sfKeyCode key, float angle);

    /**
     * @brief This function draws a sprite on the minimap
     *
     * @param rpg - rpg_t structure
     * @param i - The current x position
     * @param j - The current y position
     * @param id - The ID of the given sprite
     */
    void draw_map_sprite(rpg_t *rpg, int i, int j, char id);

    /**
     * @brief This function draws the minimap
     *
     * @param rpg - rpg_t structure
     */
    void draw_map(rpg_t *rpg);

    /**
     * @brief This function handles the players movement and collisions
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *handle_player_pos(rpg_t *rpg);

    /**
     * @brief The main function for the project
     *
     * @return int - Exit status
     */
    int myrpg(void);

    /**
     * @brief This function returns the length of a string
     *
     * @param str - The string to be measured (not NULL)
     * @return int - The length of the string
     */
    int my_strlen(char *str);

    /**
     * @brief Get the user input object
     *
     * @return char*
     */
    char *get_user_input(void);

    /**
     * @brief Get the mouse position object
     *
     * @param window - The window to get the mouse position from
     * @return sfVector2f - The mouse position
     */
    sfVector2f get_mouse_pos(sfRenderWindow *window);

    /**
     * @brief Create a text object for buttons
     *
     * @param displayed_text - The text to be displayed (not NULL)
     * @param size - The size of the font
     * @return struct sfText* - The created CSFML sfText object
     */
    struct sfText *create_text(char *displayed_text, int size);

    /**
     * @brief Create a window object
     *
     * @param name - The name of the window
     * @return sfRenderWindow* - The created CSFML sfRenderWindow object
     */
    sfRenderWindow* create_window(char *name);

    /**
     * @brief Creates a sprite object
     *
     * @param file - The path to the image file
     * @param scale - The scale of the sprite
     * @return sfSprite* - The created CSFML sfSprite object
     */
    sfSprite *create_sprite(char *file, sfVector2f scale);

    /**
     * @brief Registers Windows events and calls the appropriate functions
     *
     * @param window - The window to get the events from
     * @param event - The event to be analysed
     */
    void analyse_events(sfRenderWindow *window, sfEvent *event);

    /**
     * @brief This function splits a string into an array of strings
     *
     * @param str - The string to be split
     * @param separator - The separator to split the string with
     * @return char** - The array of strings
     */
    char **my_str_to_word_array(char *str, char separator);

    /**
     * @brief Get a string buffer from a file
     *
     * @param filename - The name of the file
     * @return char* - The string buffer
     */
    char *get_buffer(const char *filename);

    /**
     * @brief This function counts the number of words in a string
     *
     * @param str - The string to be counted (not NULL)
     * @param separator - The separator to split the string with
     * @return int - The number of words in the string
     */
    int count_words(char *str, char separator);

    /**
     * @brief This function turns an integer into a string
     *
     * @param x - The integer to be turned into a string
     * @return char* - The string representation of the integer
     */
    char *int_to_string(int x);

    /**
     * @brief This function concatenates two strings
     *
     * @param str1 - The first string
     * @param str2 - The second string
     * @return char* - The concatenated string
     */
    char *my_strcat(char *str1, char *str2);

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
     * @brief This function initializes the shapes
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *init_shapes(rpg_t *rpg);

    /**
     * @brief This function initializes the sprites
     *
     * @param rpg - rpg_t structure
     * @param id - The ID of the sprite
     * @param file - The path to the image file
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *init_sprite(rpg_t *rpg, char id, char *file);

    /**
     * @brief This function initializes all the sprites
     *
     * @param rpg - rpg_t structure
     * @return rpg_t* - The updated rpg_t structure
     */
    rpg_t *init_all_sprites(rpg_t *rpg);

    /**
     * @brief This function manages the events
     *
     * @param rpg - rpg_t structure
     */
    void manage_event(rpg_t *rpg);

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

#endif /* !MY_H_ */
