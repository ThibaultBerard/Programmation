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

    Uint32 pixel = get_pixel(image_surface, i, j);
    Uint8 r, g, b;
    SDL_GetRGB(pixel, image_surface->format, &r, &g, &b);

    int num1 = atoi((const char*) r);
    int num2 = atoi((const char*) g);
    int num3 = atoi((const char*) b);

    printf("%i\n", num1);
    printf("%i\n", num2);
    printf("%i\n", num3);

}
