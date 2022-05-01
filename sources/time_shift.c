/*
** EPITECH PROJECT, 2020
** an other file for time_relatives functions
** File description:
** time_shift
*/

#include "hunter.h"

void set_track_start_texture(sprite_value_t *start)
{
    start->rect.left = (start->stat <= 0) ? 0 : start->stat * 640;
    sfSprite_setTextureRect(start->sprite, start->rect);
}

void set_track_restart_texture(sprite_value_t *restart)
{
    restart->rect.left =
    (restart->stat < 0 && restart->stat < 4) ? 0 : restart->stat * 640;
    sfSprite_setTextureRect(restart->sprite, restart->rect);
}

void start_wall_n_cursor_timer(sprite_group_t *assets)
{
    assets->other.wall.track.time =
    sfClock_getElapsedTime(assets->other.wall.track.timer);
    assets->other.wall.track.seconds =
    assets->other.wall.track.time.microseconds / 1000000.0;
    assets->other.cursor.track.time =
    sfClock_getElapsedTime(assets->other.cursor.track.timer);
    assets->other.cursor.track.seconds =
    assets->other.cursor.track.time.microseconds / 1000000.0;
    assets->other.ammo.track.time =
    sfClock_getElapsedTime(assets->other.ammo.track.timer);
    assets->other.ammo.track.seconds =
    assets->other.ammo.track.time.microseconds / 1000000.0;
}

void start_one_ship_only_timer(sprite_pos_t *ship)
{
    ship->track.time =
    sfClock_getElapsedTime(ship->track.timer);
    ship->track.seconds =
    ship->track.time.microseconds / 1000000.0;
    ship->move_track.time =
    sfClock_getElapsedTime(ship->move_track.timer);
    ship->move_track.seconds =
    ship->move_track.time.microseconds / 1000000.0;
}

void start_ships_timers(moving_sprites_t *ships)
{
    start_one_ship_only_timer(&ships->corvette);
    start_one_ship_only_timer(&ships->ship);
    start_one_ship_only_timer(&ships->hunter);
}