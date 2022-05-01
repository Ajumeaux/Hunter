/*
** EPITECH PROJECT, 2020
** functions reatives to window control
** File description:
** window_control
*/

#include "hunter.h"

void reset(sprite_group_t *assets, sfEvent mouse_clic)
{
    assets->other.restart.stat = 3;
    if (mouse_clic.type == sfEvtMouseButtonPressed
        && mouse_clic.mouseButton.button == sfMouseLeft) {
            assets->other.restart.stat = 0;
            assets->other.lives.stat = 3;
            assets->ships.ship.pos.x = 0;
            assets->ships.corvette.pos.x = 0;
            assets->ships.hunter.pos.x = 0;
            assets->other.start.stat = 0;
            assets->other.ammo.stat = 7;
        }
}

void restart_options(sfRenderWindow *window, sfEvent mouse_clic,
sprite_group_t *assets, sfVector2f my_pos)
{
    if (assets->other.lives.stat < 0 && assets->other.start.stat == 0) {
        assets->other.restart.stat = 1;
        assets->other.ammo.stat = 6;
    }
    if (assets->other.restart.stat != 0 && (my_pos.x > 765 && my_pos.x < 944 &&
    (my_pos.y > 615 && my_pos.y < 673))) {
        reset(assets, mouse_clic);
    }
    if (assets->other.restart.stat != 0 &&
    ((my_pos.x > 975 && my_pos.x < 1155) &&
    (my_pos.y > 615 && my_pos.y < 673))) {
        assets->other.restart.stat = 2;
        if (mouse_clic.type == sfEvtMouseButtonPressed
        && mouse_clic.mouseButton.button == sfMouseLeft)
            sfRenderWindow_close(window);
    }
    if (assets->other.restart.stat != 0 && (my_pos.x < 765 || my_pos.x > 944 ||
    (my_pos.y < 615 || my_pos.y > 673)) &&
    ((my_pos.x < 975 || my_pos.x > 1155)))
        assets->other.restart.stat = 1;
}

void simple_controls(sfRenderWindow *window, sfEvent mouse_clic,
sprite_group_t *assets, sfVector2f my_pos)
{
    if (mouse_clic.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (mouse_clic.type == sfEvtMouseButtonReleased
    && mouse_clic.mouseButton.button == sfMouseLeft) {
        if (assets->other.ammo.stat >= 0) {
            sfSound_play(assets->audio.shot.sound);
            assets->other.ammo.stat -= (assets->other.start.stat == 0 &&
            assets->other.restart.stat == 0) ? 1 : 0;
        }
        if (assets->other.ammo.stat < 0)
            sfSound_play(assets->audio.shot_empty.sound);
    }
    if (mouse_clic.type == sfEvtMouseMoved)
        move_cursor(my_pos, assets->other.cursor.sprite);
    if (mouse_clic.type == sfEvtKeyReleased &&
    mouse_clic.key.code == sfKeyR && assets->other.start.stat == 0 &&
    assets->other.restart.stat == 0) {
        assets->other.ammo.stat = 6;
        sfSound_play(assets->audio.reload.sound);
    }
}

int hit(sfVector2f my_pos, sfVector2f ship_pos, int hitbox)
{
    return ((my_pos.x > (ship_pos.x + 50) - hitbox
    && my_pos.x < (ship_pos.x + 50) + hitbox)
    && (my_pos.y > (ship_pos.y + 50) - hitbox
    && my_pos.y < (ship_pos.y + 50) + hitbox));
}

void ship_aim_controls(sfEvent mouse_clic,
sprite_group_t *sprites, sfVector2f my_pos)
{
    if ((mouse_clic.type == sfEvtMouseButtonReleased &&
    mouse_clic.mouseButton.button == sfMouseLeft) &&
    hit(my_pos, sprites->ships.ship.pos, 50) == 1 &&
    sprites->other.ammo.stat >= 0)
        ship_is_hit(sprites, my_pos);
    if ((mouse_clic.type == sfEvtMouseButtonReleased &&
    mouse_clic.mouseButton.button == sfMouseLeft) &&
    hit(my_pos, sprites->ships.corvette.pos, 70) == 1 &&
    sprites->other.ammo.stat >= 0)
        corvette_is_hit(sprites, my_pos);
    if ((mouse_clic.type == sfEvtMouseButtonReleased &&
    mouse_clic.mouseButton.button == sfMouseLeft) &&
    hit(my_pos, sprites->ships.hunter.pos, 50) == 1 &&
    sprites->other.ammo.stat >= 0) {
        hunter_is_hit(sprites, my_pos);
    }
}