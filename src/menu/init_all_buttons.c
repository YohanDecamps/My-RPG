/*
** EPITECH PROJECT, 2023
** init_all_buttons
** File description:
** init_all_buttons
*/
#include "menu.h"
#include "structures.h"

static void init_settings_buttons(button_t **all_buttons)
{
    all_buttons[11] = init_button((sfVector2f) {570, 200}, (sfVector2f)
    {250, 75}, "Resolution");
    all_buttons[12] = init_button((sfVector2f) {570, 300}, (sfVector2f)
    {250, 75}, "Sensitivity");
    all_buttons[13] = init_button((sfVector2f) {570, 400}, (sfVector2f)
    {250, 75}, "Move Forward");
    all_buttons[14] = init_button((sfVector2f) {570, 500}, (sfVector2f)
    {250, 75}, "Move Backwards");
    all_buttons[15] = init_button((sfVector2f) {570, 600}, (sfVector2f)
    {250, 75}, "Move Left");
    all_buttons[16] = init_button((sfVector2f) {570, 700}, (sfVector2f)
    {250, 75}, "Move Right");
    all_buttons[17] = init_button((sfVector2f) {570, 800}, (sfVector2f)
    {250, 75}, "Use");
    all_buttons[18] = init_button((sfVector2f) {570, 900}, (sfVector2f)
    {250, 75}, "Interact");
}

static void init_pause_menu_button(button_t **all_buttons)
{
    all_buttons[8] = init_button((sfVector2f) {840, 300}, (sfVector2f)
    {250, 75}, "Resume Game");
    all_buttons[9] = init_button((sfVector2f) {840, 400}, (sfVector2f)
    {250, 75}, "Save");
    all_buttons[10] = init_button((sfVector2f) {840, 600}, (sfVector2f)
    {250, 75}, "Exit to Main Menu");
}

static void init_main_menu_buttons(button_t **all_buttons)
{
    all_buttons[0] = init_button((sfVector2f) {840, 300}, (sfVector2f)
    {250, 75}, "New Game");
    all_buttons[1] = init_button((sfVector2f) {840, 400}, (sfVector2f)
    {250, 75}, "Load Game");
    all_buttons[2] = init_button((sfVector2f) {1110, 260}, (sfVector2f)
    {200, 75}, "Save 1");
    all_buttons[3] = init_button((sfVector2f) {1110, 350}, (sfVector2f)
    {200, 75}, "Save 2");
    all_buttons[4] = init_button((sfVector2f) {1110, 440}, (sfVector2f)
    {200, 75}, "Save 3");
    all_buttons[5] = init_button((sfVector2f) {840, 500}, (sfVector2f)
    {250, 75}, "Settings");
    all_buttons[6] = init_button((sfVector2f) {840, 600}, (sfVector2f)
    {250, 75}, "Rate us");
    all_buttons[7] = init_button((sfVector2f) {840, 700}, (sfVector2f)
    {250, 75}, "Exit");
}

button_t **init_all_buttons(void)
{
    button_t **all_buttons = malloc(sizeof(button_t *) * 19);
    if (all_buttons == NULL)
        return NULL;
    for (int i = 0; i < 19; i++) {
        all_buttons[i] = malloc(sizeof(button_t));
        if (all_buttons[i] == NULL)
            return NULL;
    }
    init_main_menu_buttons(all_buttons);
    init_pause_menu_button(all_buttons);
    init_settings_buttons(all_buttons);
    return all_buttons;
}
