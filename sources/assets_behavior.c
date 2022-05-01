/*
** EPITECH PROJECT, 2020
** functions related to assets behavior
** File description:
** wow
*/

#include "hunter.h"

void which_hit_sound(sfSound *hit1, sfSound *hit2)
{
    int random = rand() % 2;
    if (random == 1)
        sfSound_play(hit1);
    else
        sfSound_play(hit2);
}

void corvette_is_hit(sprite_group_t *assets, sfVector2f my_pos)
{
    which_hit_sound(assets->audio.hit.sound, assets->audio.hit2.sound);
    assets->ships.corvette.hp--;
    if (assets->ships.corvette.hp <= 0) {
        move_expl(my_pos, assets->other.expl.sprite);
        assets->other.expl.rect.left += 140;
        assets->ships.corvette.pos.x = 0;
        assets->ships.corvette.pos.y = rand() % 900;
        assets->ships.corvette.hp = 3;
    }
}

void ship_is_hit(sprite_group_t *assets, sfVector2f my_pos)
{
    which_hit_sound(assets->audio.hit.sound, assets->audio.hit2.sound);
    assets->ships.ship.hp--;
    if (assets->ships.ship.hp <= 0) {
        move_expl(my_pos, assets->other.expl.sprite);
        assets->other.expl.rect.left += 140;
        assets->ships.ship.pos.x = 0;
        assets->ships.ship.pos.y = rand() % 925;
        assets->ships.ship.hp = 1;
    }
}

void hunter_is_hit(sprite_group_t *assets, sfVector2f my_pos)
{
    which_hit_sound(assets->audio.hit.sound, assets->audio.hit2.sound);
    assets->ships.hunter.hp--;
    if (assets->ships.hunter.hp <= 0) {
        move_expl(my_pos, assets->other.expl.sprite);
        assets->other.expl.rect.left += 140;
        assets->ships.hunter.pos.x = 0;
        assets->ships.hunter.pos.y = rand() % 925;
        assets->ships.hunter.hp = 2;
    }
}