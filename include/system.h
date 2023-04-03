/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** system
*/

#ifndef SYSTEM_H
    #define SYSTEM_H

    #include <SFML/Graphics/Types.h>

    /**
     * @brief This function returns the value of the environment variable name,
                or NULL if the variable is not defined.
     *
     * @param env - environment variables array (Should never be NULL)
     * @param name - name of the environment variable (Should never be NULL)
     * @return char* - value of the environment variable
     */
    char *my_getenv(char **env, char *name);

#endif /* !SYSTEM_H */
