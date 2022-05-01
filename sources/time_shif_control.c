/*
** EPITECH PROJECT, 2020
** time relatives functions
** File description:
** time_shif_control
*/

#include "hunter.h"

void expl_control(sprite_timer_t *expl)
{
    int ratio = expl->seconds / 0.005;

    if (expl->rect.left != 0 || expl->rect.top != 0) {
        expl->time = sfClock_getElapsedTime(expl->timer);
        expl->seconds = expl->time.microseconds / 1000000.0;
        if (expl->seconds > 0.005) {
            expl->rect.left += 140 * ratio;
            expl->rect.top += (expl->rect.left >= 840) ? 140 : 0;
            expl->rect.left = (expl->rect.left >= 840) ? 0 : expl->rect.left;
            expl->rect.top = (expl->rect.top >= 840) ? 0 : expl->rect.top;
            sfClock_restart(expl->timer);
        }
    }
    sfSprite_setTextureRect(expl->sprite, expl->rect);
}

void set_track_ship_texture(sprite_pos_t *ship)
{
    int ratio = ship->track.seconds / 0.1;

    if (ship->track.seconds > 0.1) {
        ship->rect.left += 100 * ratio;
        ship->rect.left = (ship->rect.left >= 500) ? 100 : ship->rect.left;
        sfClock_restart(ship->track.timer);
    }
    sfSprite_setTextureRect(ship->sprite, ship->rect);
}

void set_track_big_ship_texture(sprite_pos_t *corvette)
{
    int ratio = corvette->track.seconds / 0.1;

    if (corvette->track.seconds > 0.1) {
        corvette->rect.left += 100 * ratio;
        corvette->rect.left =
        (corvette->rect.left >= 400) ? 0 : corvette->rect.left;
        sfClock_restart(corvette->track.timer);
    }
    sfSprite_setTextureRect(corvette->sprite, corvette->rect);
}

void set_track_cursor_texture(sprite_png_t *cursor)
{
    int ratio = cursor->track.seconds / 0.05;

    if (cursor->track.seconds > 0.05) {
        sfSprite_rotate(cursor->sprite, 2 * ratio);
        sfClock_restart(cursor->track.timer);
    }
}

void set_track_wall_texture(sprite_only_t *wall)
{
    if (wall->track.seconds > 0.1) {
        wall->rect.top += 0;
        wall->rect.top = (wall->rect.top >= 1280) ? 0 : wall->rect.top;
        sfClock_restart(wall->track.timer);
    }
    sfSprite_setTextureRect(wall->sprite, wall->rect);
}