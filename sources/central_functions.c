/*
** EPITECH PROJECT, 2020
** main for hunter
** File description:
** main
*/

#include "hunter.h"

void read_file(char *filepath)
{
    int filedesc = open(filepath, O_RDONLY);
    char *str;

    str = malloc(sizeof(char) * 450);
    read(filedesc, str, 450);
    write(1, str, 450);
    close(filedesc);
}

void sound_destroyer(sounds_group_t *audio)
{
    sfMusic_destroy(audio->bo);
    sfSound_destroy(audio->shot.sound);
    sfSoundBuffer_destroy(audio->shot.buffer);
    sfSound_destroy(audio->hit.sound);
    sfSoundBuffer_destroy(audio->hit.buffer);
    sfSound_destroy(audio->hit2.sound);
    sfSoundBuffer_destroy(audio->hit2.buffer);
    sfSound_destroy(audio->shot_empty.sound);
    sfSoundBuffer_destroy(audio->shot_empty.buffer);
    sfSound_destroy(audio->reload.sound);
    sfSoundBuffer_destroy(audio->reload.buffer);
}

void the_destroyer(sfRenderWindow *win, sprite_group_t *assets)
{
    sound_destroyer(&assets->audio);
    sfSprite_destroy(assets->other.cursor.sprite);
    sfTexture_destroy(assets->other.cursor.sprite_texture);
    sfSprite_destroy(assets->other.wall.sprite);
    sfTexture_destroy(assets->other.wall.sprite_texture);
    sfSprite_destroy(assets->other.lives.sprite);
    sfTexture_destroy(assets->other.lives.sprite_texture);
    sfSprite_destroy(assets->other.ammo.sprite);
    sfTexture_destroy(assets->other.ammo.sprite_texture);
    sfSprite_destroy(assets->other.restart.sprite);
    sfTexture_destroy(assets->other.restart.sprite_texture);
    sfSprite_destroy(assets->other.expl.sprite);
    sfTexture_destroy(assets->other.expl.sprite_texture);
    sfRenderWindow_destroy(win);
}

int central(void)
{
    sfRenderWindow *win = create_renderwindow(1920, 1080, 32, "SUPER FENETRE");
    sfEvent mouse_clic;
    sprite_group_t assets;

    create_assets(&assets);
    sfRenderWindow_setFramerateLimit(win, 120);
    sfRenderWindow_setMouseCursorVisible(win, sfFalse);
    sfMusic_play(assets.audio.bo);
    sfMusic_setLoop(assets.audio.bo, sfTrue);
    sfMusic_setVolume(assets.audio.bo, 20);
    while (sfRenderWindow_isOpen(win)) {
        assets_time_shift(&assets);
        sfRenderWindow_display(win);
        control_window(win, mouse_clic, &assets);
    }
    the_destroyer(win, &assets);
    if (!win)
        return 84;
    return 1;
}