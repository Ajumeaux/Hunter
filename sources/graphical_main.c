/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include "hunter.h"

void displayer(sfRenderWindow *window, sprite_group_t *assets)
{
    sfRenderWindow_drawSprite(window, assets->other.wall.sprite, NULL);
    sfRenderWindow_drawSprite(window, assets->ships.corvette.sprite, NULL);
    sfRenderWindow_drawSprite(window, assets->ships.ship.sprite, NULL);
    sfRenderWindow_drawSprite(window, assets->ships.hunter.sprite, NULL);
    sfRenderWindow_drawSprite(window, assets->other.ammo.sprite, NULL);
    sfRenderWindow_drawSprite(window, assets->other.lives.sprite, NULL);
    sfRenderWindow_drawSprite(window, assets->other.expl.sprite, NULL);
    sfRenderWindow_drawSprite(window, assets->other.restart.sprite, NULL);
    sfRenderWindow_drawSprite(window, assets->other.start.sprite, NULL);
    sfRenderWindow_drawSprite(window, assets->other.cursor.sprite, NULL);
}

void control_window(sfRenderWindow *window, sfEvent mouse_clic,
sprite_group_t *assets)
{
    sfVector2i my_mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f my_pos = {(float)my_mouse_pos.x, (float)my_mouse_pos.y};

    move_ship(assets);
    while (sfRenderWindow_pollEvent(window, &mouse_clic)) {
            simple_controls(window, mouse_clic, assets, my_pos);
            ship_aim_controls(mouse_clic, assets, my_pos);
        }
        start_options(mouse_clic, assets, my_pos);
        restart_options(window, mouse_clic, assets, my_pos);
        sfRenderWindow_clear(window, sfBlack);
        displayer(window, assets);
}

sfRenderWindow *create_renderwindow(unsigned int x,
unsigned int y, unsigned int bpp, char *title)
{
    sfVideoMode mode = {x, y, bpp};

    return (sfRenderWindow_create(mode, title, sfResize | sfClose, NULL));
}

void start_seconds(sprite_group_t *assets)
{
    start_wall_n_cursor_timer(assets);
    start_ships_timers(&assets->ships);
}

void assets_time_shift(sprite_group_t *assets)
{
    expl_control(&assets->other.expl);
    start_seconds(assets);
    set_track_cursor_texture(&assets->other.cursor);
    set_track_wall_texture(&assets->other.wall);
    set_track_lives_texture(&assets->other.lives);
    set_track_ammo_texture(&assets->other.ammo);
    set_track_restart_texture(&assets->other.restart);
    set_track_start_texture(&assets->other.start);
    set_track_ship_texture(&assets->ships.ship);
    set_track_big_ship_texture(&assets->ships.corvette);
    set_track_hunter_texture(&assets->ships.hunter);
}