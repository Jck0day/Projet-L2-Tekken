#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../include/animations.h"
#include "../include/joueur.h"
#include "../include/jeu.h"
#include "../include/personnages.h"

void renderAnimation(Joueur * joueur){
  SDL_RenderCopyEx(renderer, (joueur->texture), &(joueur->perso.srcrect), &(joueur->perso.dstrect), 0, 0, joueur->direction);
}

void resetAnimation(Joueur * joueur){
  SDL_Rect srcrect = {
    0, //Pas
    0,
    joueur->perso.taille_perso.w,
    joueur->perso.taille_perso.h
  };
  SDL_Rect dstrect = {
    joueur->position.x,
    joueur->position.y,
    joueur->perso.taille_perso.w,
    joueur->perso.taille_perso.h
  };
  joueur->perso.srcrect=srcrect;
  joueur->perso.dstrect=dstrect;
}

void jouerAnimation(Joueur * joueur){ //Pour freezer l'anim il faut anuller le getTick
  int posYSprite;
  int anim=joueur->action;

  switch (anim) {
    case COURIR:
                 posYSprite=0;
    break;
    case PARER:
                posYSprite=640;
    break;
    case POING:
                posYSprite=1280;
    break;
    case IDLE:
    		       posYSprite=0;
  }
    Uint32 seconds = SDL_GetTicks() / 30; //Fréquence (toutes les 30ms)
    Uint32 sprite = seconds % joueur->perso.nb_frame[anim];

    SDL_Rect srcrect = {
    sprite * 540, //Pas
    posYSprite,
    joueur->perso.taille_perso.w,
    joueur->perso.taille_perso.h
  };

  SDL_Rect dstrect = {
    joueur->position.x,
    joueur->position.y,
    joueur->perso.taille_perso.w,
    joueur->perso.taille_perso.h
  };

   joueur->perso.srcrect=srcrect;
   joueur->perso.dstrect=dstrect;

}
