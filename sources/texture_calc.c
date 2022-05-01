/*
** EPITECH PROJECT, 2020
** texture_calc
** File description:
** wow
*/

#include "hunter.h"

void set_track_lives_texture(sprite_value_t *lives)
{
    if (lives->stat >= 3)
        lives->rect.left = 640;
    if (lives->stat == 2)
        lives->rect.left = 1280;
    if (lives->stat == 1)
        lives->rect.left = 1920;
    if (lives->stat == 0)
        lives->rect.left = 2560;
    sfSprite_setTextureRect(lives->sprite, lives->rect);
}

void move_cursor(sfVector2f my_pos, sfSprite *cursor)
{
    sfVector2f pos = my_pos;

    sfSprite_setPosition(cursor, pos);
}

void move_expl(sfVector2f my_pos, sfSprite *expl)
{
    sfVector2f pos = my_pos;

    pos.x -= 70;
    pos.y -= 70;
    sfSprite_setPosition(expl, pos);
}

void move_single_ship(sprite_pos_t *ship, int speed)
{
    float ratio = ship->move_track.seconds / 0.016666;

    if (ship->move_track.seconds > 0.016666) {
        ship->pos.x += speed * ratio;
        ship->pos.y = (ship->pos.x > 1900) ?
        rand() % 925 : ship->pos.y;
        sfClock_restart(ship->move_track.timer);
        sfSprite_setPosition(ship->sprite, ship->pos);
    }
}

void move_ship(sprite_group_t *assets)
{
    move_single_ship(&assets->ships.ship, 8);
    assets->other.lives.stat -= (assets->ships.ship.pos.x > 1900) ? 1 : 0;
    assets->ships.ship.pos.x =
    (assets->ships.ship.pos.x > 1900) ? 0 : assets->ships.ship.pos.x;
    move_single_ship(&assets->ships.corvette, 5);
    assets->other.lives.stat -= (assets->ships.corvette.pos.x > 1900) ? 1 : 0;
    assets->ships.corvette.pos.x =
    (assets->ships.corvette.pos.x > 1900) ? 0 : assets->ships.corvette.pos.x;
    move_single_ship(&assets->ships.hunter, 6.5);
    assets->other.lives.stat -= (assets->ships.hunter.pos.x > 1900) ? 1 : 0;
    assets->ships.hunter.pos.x =
    (assets->ships.hunter.pos.x > 1900) ? 0 : assets->ships.hunter.pos.x;
}