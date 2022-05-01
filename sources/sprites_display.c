/*
** EPITECH PROJECT, 2020
** sprite_display
** File description:
** fnctions to display the different sprites
*/

#include "hunter.h"

void create_expl_sprite(sprite_timer_t *expl)
{
    expl->sprite = sfSprite_create();
    expl->sprite_texture =
    sfTexture_createFromFile("ressources/Textures/explosion.png", NULL);
    expl->rect.left = 0;
    expl->rect.top = 0;
    expl->rect.height = 140;
    expl->rect.width = 140;
    sfSprite_setTexture(expl->sprite, expl->sprite_texture, sfFalse);
}

void create_cursor_sprite(sprite_png_t *cursor)
{
    sfVector2f origin;
    sfVector2f scale = {2.5, 2.5};

    cursor->sprite = sfSprite_create();
    cursor->sprite_texture =
    sfTexture_createFromFile("ressources/Textures/final_target.png", NULL);
    sfSprite_setTexture(cursor->sprite, cursor->sprite_texture, sfFalse);
    origin = sfSprite_getOrigin(cursor->sprite);
    origin.x += 50;
    origin.y += 50;
    sfSprite_setOrigin(cursor->sprite, origin);
    sfSprite_setScale(cursor->sprite, scale);
}

void create_wall_sprite(sprite_only_t *wall)
{
    sfVector2f scale = {3, 3};

    wall->sprite = sfSprite_create();
    wall->sprite_texture =
    sfTexture_createFromFile("ressources/Textures/fontdraw.png", NULL);
    wall->rect.left = 0;
    wall->rect.top = 0;
    wall->rect.height = 360;
    wall->rect.width = 640;
    sfSprite_setTexture(wall->sprite, wall->sprite_texture, sfFalse);
    sfSprite_setScale(wall->sprite, scale);
}

void create_ship_sprite(sprite_pos_t *ship)
{
    ship->sprite = sfSprite_create();
    ship->sprite_texture =
    sfTexture_createFromFile("ressources/Textures/spaceship.png", NULL);
    ship->rect.left = 100;
    ship->rect.top = 0;
    ship->rect.height = 100;
    ship->rect.width = 100;
    sfSprite_setTexture(ship->sprite, ship->sprite_texture, sfFalse);
    ship->hp = 1;
}

void create_big_ship_sprite(sprite_pos_t *big_ship)
{
    big_ship->sprite = sfSprite_create();
    big_ship->sprite_texture =
    sfTexture_createFromFile("ressources/Textures/corvette.png", NULL);
    big_ship->rect.left = 0;
    big_ship->rect.top = 0;
    big_ship->rect.height = 100;
    big_ship->rect.width = 100;
    sfSprite_setTexture(big_ship->sprite, big_ship->sprite_texture, sfFalse);
    big_ship->hp = 3;
}