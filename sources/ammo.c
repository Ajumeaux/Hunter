/*
** EPITECH PROJECT, 2020
** ammo
** File description:
** functions relatives to ammo managment
*/

#include "hunter.h"

void create_ammo_sprite(sprite_value_t *ammo)
{
    sfVector2f scale = {3, 3};
    sfVector2f pos = {0, -55};

    ammo->sprite = sfSprite_create();
    ammo->sprite_texture =
    sfTexture_createFromFile("ressources/Textures/ammo.png", NULL);
    ammo->rect.left = 0;
    ammo->rect.top = 0;
    ammo->rect.height = 360;
    ammo->rect.width = 640;
    sfSprite_setTexture(ammo->sprite, ammo->sprite_texture, sfFalse);
    sfSprite_setScale(ammo->sprite, scale);
    sfSprite_setPosition(ammo->sprite, pos);
    ammo->stat = 6;
}

void set_track_ammo_texture(sprite_value_t *ammo)
{

    ammo->rect.left =
    (ammo->stat <= 0 || ammo->stat > 7) ? 0 : ammo->stat * 640;
    sfSprite_setTextureRect(ammo->sprite, ammo->rect);
}