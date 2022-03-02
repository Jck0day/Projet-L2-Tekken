#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include "../include/initSdl.h"
#include "../include/deplacements.h"
#include "../include/main.h"
#include "../include/menu_principal.h"
#include "../include/joueur.h"
#include "../include/animations.h"
#include "../include/jeu.h"

#define MODE BORDERLESS

bool quit;
SDL_DisplayMode ecran;

void initSdl() { //Créer la fenêtre et l'environnement (pour l'instant)
  quit = false;
  SDL_Texture * tex_menu_Principal = NULL;
  SDL_Rect rect1;
  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_PNG);
  SDL_GetDesktopDisplayMode(0, &ecran);

  switch(MODE){
    case FULLSCREEN: window = SDL_CreateWindow("SDL2 Tekken",
      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ecran.w, ecran.h, SDL_WINDOW_FULLSCREEN);
    break;
    case BORDERLESS: window = SDL_CreateWindow("SDL2 Tekken",
      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ecran.w, ecran.h, SDL_WINDOW_BORDERLESS);
    break;
    default: window = SDL_CreateWindow("SDL2 Tekken",
      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ecran.w / 2, ecran.h / 2, 0);
  }
  renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_Surface * perso1 = IMG_Load("res/sprites/Pingu.png");
  SDL_Surface * perso2 = IMG_Load("res/sprites/Shrek.png");

  SDL_Surface * image_stage = IMG_Load("res/backgrounds/stage2.png");
  SDL_Texture * texture_stage = SDL_CreateTextureFromSurface(renderer, image_stage);

  SDL_Texture * texture_joueur1 = SDL_CreateTextureFromSurface(renderer, perso1);
  SDL_Texture * texture_joueur2 = SDL_CreateTextureFromSurface(renderer, perso2);

  // SDL_SetRenderDrawColor(renderer, 168, 230, 255, 255);
  // SDL_RenderClear(renderer);

  TTF_Init();
  menu_principal(renderer, &ecran, &tex_menu_Principal, &rect1);
  Joueur j1, j2;
  initJoueur(&j1, 128, texture_joueur1);
  initJoueur(&j2, 680, texture_joueur2);
  resetAnimation(&j1); //Spawn du joueur
  resetAnimation(&j2);

  while (!quit) {

  Uint32 ticks = SDL_GetTicks();
  Uint32 seconds = ticks / 30; //Fréquence (toutes les 30ms)

    SDL_RenderClear(renderer);
    deplacements(&j1);
    //SDL_RenderCopy(renderer, texture_stage, NULL, NULL);
  //  SDL_RenderCopy(renderer, tex_menu_Principal, NULL, &rect1);
    jouerAnimation(&j1, seconds);
    renderAnimation(&j1);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(texture_stage);
  SDL_DestroyTexture(tex_menu_Principal);
  SDL_DestroyTexture(texture_joueur1);
  SDL_DestroyTexture(texture_joueur2);
  SDL_FreeSurface(perso1);
  SDL_FreeSurface(perso2);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}