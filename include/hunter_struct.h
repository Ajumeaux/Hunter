/*
** EPITECH PROJECT, 2020
** structures for hunter
** File description:
** hunter_struct
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

typedef struct
{
    sfClock* timer;
    sfTime time;
    float seconds;
}timestruct_t;

typedef struct
{
    sfSprite *sprite;
    sfTexture* sprite_texture;
    sfIntRect rect;
    timestruct_t track;
}sprite_only_t;

typedef struct
{
    sfSprite *sprite;
    sfTexture* sprite_texture;
    sfIntRect rect;
    int stat;
    timestruct_t track;
}sprite_value_t;

typedef struct
{
    sfSound *sound;
    sfSoundBuffer *buffer;

}sounds_struct_t;

typedef struct
{
    sfSprite *sprite;
    sfTexture* sprite_texture;
    timestruct_t track;
}sprite_png_t;

typedef struct
{
    sfSprite *sprite;
    sfTexture* sprite_texture;
    sfIntRect rect;
    sfVector2f pos;
    timestruct_t move_track;
    timestruct_t track;
    int hp;
}sprite_pos_t;

typedef struct
{
    sfSprite *sprite;
    sfTexture* sprite_texture;
    sfIntRect rect;
    sfClock* timer;
    sfTime time;
    float seconds;
}sprite_timer_t;

typedef struct
{
    sprite_png_t cursor;
    sprite_only_t wall;
    sprite_timer_t expl;
    sprite_value_t lives;
    sprite_value_t ammo;
    sprite_value_t restart;
    sprite_value_t start;
}static_sprites_t;

typedef struct
{
    sounds_struct_t shot;
    sounds_struct_t hit;
    sounds_struct_t hit2;
    sounds_struct_t shot_empty;
    sounds_struct_t reload;
    sfMusic *bo;

}sounds_group_t;

typedef struct
{
    sprite_pos_t ship;
    sprite_pos_t corvette;
    sprite_pos_t hunter;
}moving_sprites_t;

typedef struct
{
    sounds_group_t audio;
    static_sprites_t other;
    moving_sprites_t ships;
}sprite_group_t;
