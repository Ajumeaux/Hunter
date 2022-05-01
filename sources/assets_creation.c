/*
** EPITECH PROJECT, 2020
** creation of assets
** File description:
** functions used to create all the assets
*/

#include "hunter.h"

void create_start_sprite(sprite_value_t *start)
{
    sfVector2f scale = {3, 3};

    start->sprite = sfSprite_create();
    start->sprite_texture =
    sfTexture_createFromFile("ressources/Textures/start.png", NULL);
    start->rect.left = 0;
    start->rect.top = 0;
    start->rect.height = 360;
    start->rect.width = 640;
    sfSprite_setTexture(start->sprite, start->sprite_texture, sfFalse);
    sfSprite_setScale(start->sprite, scale);
    start->stat = 1;
}

void create_ships_assets(moving_sprites_t *ships)
{
    create_ship_sprite(&ships->ship);
    create_big_ship_sprite(&ships->corvette);
    create_hunter_sprite(&ships->hunter);
    ships->ship.track.timer = sfClock_create();
    ships->ship.move_track.timer = sfClock_create();
    ships->corvette.track.timer = sfClock_create();
    ships->corvette.move_track.timer = sfClock_create();
    ships->hunter.track.timer = sfClock_create();
    ships->hunter.move_track.timer = sfClock_create();
    ships->ship.pos.x = 0;
    ships->ship.pos.y = rand() % 925;
    ships->corvette.pos.x = 0;
    ships->corvette.pos.y = rand() % 900;
    ships->hunter.pos.x = 0;
    ships->hunter.pos.y = rand() % 925;
}

void create_other_assets(static_sprites_t *other)
{
    create_cursor_sprite(&other->cursor);
    create_expl_sprite(&other->expl);
    create_wall_sprite(&other->wall);
    create_lives_sprite(&other->lives);
    create_restart_sprite(&other->restart);
    create_start_sprite(&other->start);
    create_ammo_sprite(&other->ammo);
    other->expl.timer = sfClock_create();
    other->cursor.track.timer = sfClock_create();
    other->wall.track.timer = sfClock_create();
    other->ammo.track.timer = sfClock_create();
}

void create_sound_assets(sounds_struct_t *audio, char *path)
{
    audio->buffer =
    sfSoundBuffer_createFromFile(path);
    audio->sound = sfSound_create();
    sfSound_setBuffer(audio->sound, audio->buffer);
}

void create_assets(sprite_group_t *assets)
{
    create_sound_assets(&assets->audio.shot,
    "ressources/Sounds/8bit_spaceshot.ogg");
    create_sound_assets(&assets->audio.shot_empty,
    "ressources/Sounds/shot_empty.ogg");
    create_sound_assets(&assets->audio.hit,
    "ressources/Sounds/metal_hit.ogg");
    create_sound_assets(&assets->audio.hit2,
    "ressources/Sounds/metal_hit2.ogg");
    create_sound_assets(&assets->audio.reload,
    "ressources/Sounds/reload.ogg");
    assets->audio.bo = sfMusic_createFromFile("ressources/Sounds/bo_halo.ogg");
    create_other_assets(&assets->other);
    create_ships_assets(&assets->ships);
}