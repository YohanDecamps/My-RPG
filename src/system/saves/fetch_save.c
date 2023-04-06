/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** fetch_save
*/

#include "lib.h"
#include "structures.h"
#include <stdlib.h>
#include <stdio.h>

static int get_save_size(char *filename)
{
    FILE *file = fopen(filename, "r");
    int size = 0;
    char *line = NULL;
    size_t len = 0;

    if (file == NULL)
        return -1;
    while (getline(&line, &len, file) != -1)
        size++;
    fclose(file);
    return size;
}

save_entry_t **fetch_save(char *filename)
{
    if (filename == NULL) return NULL;
    int size = get_save_size(filename);
    save_entry_t **save = malloc(sizeof(save_entry_t*) * (size + 1));
    if (save == NULL) return NULL;
    FILE *file = fopen(filename, "r");
    char *line = NULL;
    size_t len = 0;
    for (int i = 0; getline(&line, &len, file) != -1; i++) {
        if ((save[i] = malloc(sizeof(save_entry_t))) == NULL)
            return NULL;
        char **split = my_str_to_word_array(line, '=');
        if (split == NULL)
            return NULL;
        save[i]->name = split[0];
        save[i]->value = split[1];
        free(split);
    }
    save[size] = NULL;
    free(line);
    return save;
}
