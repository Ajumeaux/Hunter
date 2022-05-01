/*
** EPITECH PROJECT, 2020
** functions to create sprites, see sprite_display for part 1
** File description:
** sprite_creat
*/

#include "hunter.h"

void set_track_hunter_texture(sprite_pos_t *hunter)
{
    int ratio = hunter->track.seconds / 0.1;

    if (hunter->track.seconds > 0.1) {
        hunter->rect.left += 100 * ratio;
        hunter->rect.left =
        (hunter->rect.left >= 400) ? 0 : hunter->rect.left;
        sfClock_restart(hunter->track.timer);
    }
    sfSprite_setTextureRect(hunter->sprite, hunter->rect);
}

void create_hunter_sprite(sprite_pos_t *hunter)
{
    hunter->sprite = sfSprite_create();
    hunter->sprite_texture =
    sfTexture_createFromFile("ressources/Textures/hunter.png", NULL);
    hunter->rect.left = 0;
    hunter->rect.top = 0;
    hunter->rect.height = 100;
    hunter->rect.width = 100;
    sfSprite_setTexture(hunter->sprite, hunter->sprite_texture, sfFalse);
    hunter->hp = 2;
}

void create_lives_sprite(sprite_value_t *lives)
{
    sfVector2f scale = {3, 3};

    lives->sprite = sfSprite_create();
    lives->sprite_texture =
    sfTexture_createFromFile("ressources/Textures/lives.png", NULL);
    lives->rect.left = 0;
    lives->rect.top = 0;
    lives->rect.height = 360;
    lives->rect.width = 640;
    sfSprite_setTexture(lives->sprite, lives->sprite_texture, sfFalse);
    sfSprite_setScale(lives->sprite, scale);
    lives->stat = 3;
}

void create_restart_sprite(sprite_value_t *restart)
{
    sfVector2f scale = {3, 3};

    restart->sprite = sfSprite_create();
    restart->sprite_texture =
    sfTexture_createFromFile("ressources/Textures/restart.png", NULL);
    restart->rect.left = 0;
    restart->rect.top = 0;
    restart->rect.height = 360;
    restart->rect.width = 640;
    sfSprite_setTexture(restart->sprite, restart->sprite_texture, sfFalse);
    sfSprite_setScale(restart->sprite, scale);
    restart->stat = 0;
}

void start_options(sfEvent mouse_clic,
sprite_group_t *assets, sfVector2f my_pos)
{
    if (assets->other.start.stat != 0 && (my_pos.x > 815 && my_pos.x < 1105 &&
    (my_pos.y > 545 && my_pos.y < 650))) {
        assets->other.start.stat = 2;
        reset(assets, mouse_clic);
    }
    if (assets->other.start.stat != 0 && (my_pos.x < 815 || my_pos.x > 1105 ||
    (my_pos.y < 545 || my_pos.y > 650)))
        assets->other.start.stat = 1;
}