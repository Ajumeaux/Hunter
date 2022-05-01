/*
** EPITECH PROJECT, 2020
** librairie print_f
** File description:
** Central functions
*/

#include "hunter_struct.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define _README_ "ressources/read_me.txt"

//Sprites Display
void move_cursor(sfVector2f my_pos, sfSprite *cursor);
void move_expl(sfVector2f my_pos, sfSprite *expl);
void move_ship(sprite_group_t *assets);
void create_cursor_sprite(sprite_png_t *cursor);
void create_expl_sprite(sprite_timer_t *expl);
void create_wall_sprite(sprite_only_t *wall);
void create_ship_sprite(sprite_pos_t *ship);
void create_big_ship_sprite(sprite_pos_t *big_ship);
void create_hunter_sprite(sprite_pos_t *hunter);
void create_lives_sprite(sprite_value_t *lives);
void create_restart_sprite(sprite_value_t *restart);
void create_start_sprite(sprite_value_t *start);
void create_ammo_sprite(sprite_value_t *ammo);

//textures assigments
void set_track_cursor_texture(sprite_png_t *cursor);
void set_track_wall_texture(sprite_only_t *wall);
void set_track_ship_texture(sprite_pos_t *ship);
void set_track_big_ship_texture(sprite_pos_t *big_ship);
void set_track_hunter_texture(sprite_pos_t *hunter);
void set_track_lives_texture(sprite_value_t *lives);
void set_track_restart_texture(sprite_value_t *restart);
void set_track_start_texture(sprite_value_t *start);
void expl_control(sprite_timer_t *expl);
void set_track_ammo_texture(sprite_value_t *ammo);

//Time_functions
void start_wall_n_cursor_timer(sprite_group_t *assets);
void start_ships_timers(moving_sprites_t *assets);

//main functions
void control_window(sfRenderWindow *window, sfEvent mouse_clic,
sprite_group_t *sprites);
sfRenderWindow *create_renderwindow(unsigned int x,
unsigned int y, unsigned int bpp, char *title);
void create_assets(sprite_group_t *assets);
void assets_time_shift(sprite_group_t *assets);
void start_seconds(sprite_group_t *assets);

//custom controls options
void simple_controls(sfRenderWindow *window, sfEvent mouse_clic,
sprite_group_t *sprites, sfVector2f my_pos);
void ship_aim_controls(sfEvent mouse_clic,
sprite_group_t *sprites, sfVector2f my_pos);
void corvette_is_hit(sprite_group_t *assets, sfVector2f my_pos);
void ship_is_hit(sprite_group_t *assets, sfVector2f my_pos);
void hunter_is_hit(sprite_group_t *assets, sfVector2f my_pos);
void restart_options(sfRenderWindow *window, sfEvent mouse_clic,
sprite_group_t *assets, sfVector2f my_pos);
void reset(sprite_group_t *assets, sfEvent mouse_clic);
void start_options(sfEvent mouse_clic,
sprite_group_t *assets, sfVector2f my_pos);
void reload(sprite_group_t *assets, sfEvent mouse_clic);

//Music and sounds

//Central functions
int central(void);
void the_destroyer(sfRenderWindow *win, sprite_group_t *assets);
void read_file(char *filepath);