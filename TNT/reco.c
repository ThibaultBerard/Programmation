#include <err.h>
//#include "pixel_operations.h"
#include "display1.c"




int main()
{
    SDL_Surface* image_surface;
    SDL_Surface* screen_surface;

    init_sdl();

    image_surface = load_image("How.png"); //charge image

    screen_surface = display_image(image_surface); //affiche image

    SDL_FreeSurface(image_surface);

    SDL_FreeSurface(screen_surface);

}