/*
** EPITECH PROJECT, 2023
** main_menu.h
** File description:
** main_menu.h
*/

#ifndef MAIN_MENU_H_
    #define MAIN_MENU_H_

    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>

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

    sfBool is_hover(struct button_s* button, sfRenderWindow *window);
    sfBool is_clicked(struct button_s* button, sfRenderWindow *window);
    button_t *init_button(sfVector2f pos, sfVector2f size, char *text);
    void draw_button(struct button_s *button, sfRenderWindow *window);
    struct button_s *update_button(struct button_s *button, sfEvent *event,
    sfRenderWindow *window);
    struct button_s *update_button(struct button_s *button, sfEvent *event,
    sfRenderWindow *window);
    void draw_all_buttons(button_t **all_buttons, sfRenderWindow *window);
    button_t **init_all_buttons(void);
    int main_menu(sfRenderWindow *window, sfEvent *event);
    button_t **update_all_buttons(button_t **buttons, sfEvent *event,
    sfRenderWindow *window);
    void draw_main_menu_buttons(button_t **buttons, sfRenderWindow *window);
    void set_all_button(button_t **all_buttons, enum e_gui_state new_state);

#endif /* !MAIN_MENU_H_ */
