/*
** EPITECH PROJECT, 2021
** bonus.c
** File description:
** About bonus functions for music and levels.
*/

#include "../include/header.h"

struct music *create_music(void)
{
    struct music *mus = malloc(sizeof(struct music));

    mus->loop = sfSound_create();
    return (mus);
}

char **musics(void)
{
    char **mus = malloc(sizeof(char *)*(11));

    mus[0] = "musics/Orelsan - Basique.ogg";
    mus[1] = "musics/5306_Joeboy-Baby-AFROMICRO.COM.ogg";
    mus[2] = "musics/05-Promo-_feat.-Damso_.ogg";
    //mus[1] = "musics/01-Dilemme.ogg";
    //mus[2] = "musics/nekfeu-a_la_base.ogg";
    mus[3] = "musics/nekfeu-chanson_damour.ogg";
    mus[4] = "musics/Nekfeu - 7 77 AM (Feat. 86 Joon).ogg";
    mus[5] = "musics/nekfeu-lair_du_temps_feat_framal_et_doums.ogg";
    mus[6] = "musics/Nekfeu - Point D'Interrogation (Feat. Alpha Wann).ogg";
    mus[7] = "musics/5306_Joeboy-Baby-AFROMICRO.COM.ogg";
    mus[8] = "musics/Nekfeu Esquimaux.ogg";
    mus[9] = "musics/Nekfeu - On Verra.ogg";
    mus[10] = NULL;
    return (mus);
}

void set_music(struct music *mus, char *music)
{
    mus->music = sfSoundBuffer_createFromFile(music);
    sfSound_setBuffer(mus->loop, mus->music);
    sfSound_play(mus->loop);
    sfSound_setLoop(mus->loop, sfTrue);
}

void sokoban(char **lev, char **music, struct music *mus)
{
    int j = -1;
    int lines = 0;
    int state = 0;
    char *ma = NULL;

    for (int i = 0; lev[i] != NULL; i++) {
        ma = load_file_in_mem(lev[i]);
        lines = number_of_lines(ma);
        free(ma);
        j++;
        //j = rand()%9;
        //srand(time(NULL));
        //(i%2 == 0) ? j++ : 0;
        set_music(mus, music[j]);
        state = my_sokoban(lev[i], lines);
        if (state == 1)
            break;
    }
}
