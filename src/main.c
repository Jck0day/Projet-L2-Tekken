#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../include/initSdl.h"
#include "../include/menu_principal.h"
#include "../include/jeu.h"

bool debug = false;
int main(int argc, char *argv[]) {
  // 1 si drip
  if(argc>=2){
    if(strcmp(argv[1],"drip")==0)
      menu_principal(1);
    else {
      debug = strcmp(argv[1], "debug")==0;
      menu_principal(0);
    }
  } else
    menu_principal(0);
  return 0;
}
