#include "../include/joueur.h"
#ifndef ANIM_H_INCLUDED__
#define ANIM_H_INCLUDED__

#define IDLE 0
#define COURIR 1
#define POING 2
#define PARER 3

void renderAnimation(Joueur * joueur);
void resetAnimation(Joueur * joueur);
void jouerAnimation(Joueur * joueur);
#endif
