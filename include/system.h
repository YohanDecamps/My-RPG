/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** system
*/

#ifndef SYSTEM_H
    #define SYSTEM_H
    #include <SFML/Graphics/Types.h>

    int save_as_jpg(sfRenderTexture *rtexture, char *name);
    int save_as_png(sfRenderTexture *rtexture, char *name);
    int save_as_bmp(sfRenderTexture *rtexture, char *name);
    int save_as_tga(sfRenderTexture *rtexture, char *name);

    char *my_getenv(char **env, char *name);

#endif /* !SYSTEM_H */
