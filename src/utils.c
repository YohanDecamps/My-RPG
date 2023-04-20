/*
** EPITECH PROJECT, 2023
** merge_save
** File description:
** utils
*/

void free_map(int y, int **maze)
{
    for (int i = 0; i < y - 1; i++)
        free(maze[i]);
    free(maze);
}

char **copy_char_array(char** original, int length)
{
    char **copied = malloc(length * sizeof(char *));
    for (int i = 0; i < length; i++) {
        int str_length = strlen(original[i]);
        copied[i] = my_strdup(original[i]);
    }
    return copied;
}