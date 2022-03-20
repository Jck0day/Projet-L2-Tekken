#include "../include/joueur.h"
#ifndef ANIM_H_INCLUDED__
#define ANIM_H_INCLUDED__

#define IDLE 0
#define COURIR 1
#define POING 2
#define PARER 3
#define PIED 4
#define SAUTER 5

void renderAnimation(Joueur * joueur);
void resetAnimation(Joueur * joueur);
void jouerAnimation(Joueur * joueur);
void jouerAnimationBackground(SDL_Rect * srcBg, SDL_Rect * dstBg,int flag_bg);

typedef struct {
  int posY;
  int nb_frames;
  char * chemin_sprite;
} Background;

#endif
