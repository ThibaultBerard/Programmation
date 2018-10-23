#include <err.h>
//#include "pixel_operations.h"
#include "display1.c"

Uint8* pixel_ref(SDL_Surface *surf, unsigned x, unsigned y)
{
    int bpp = surf->format->BytesPerPixel;
    return (Uint8*)surf->pixels + y * surf->pitch + x * bpp;
}

Uint32 get_pixel(SDL_Surface *surface, unsigned x, unsigned y)
{
    Uint8 *p = pixel_ref(surface, x, y);

    switch (surface->format->BytesPerPixel)
    {
        case 1:
            return *p;

        case 2:
            return *(Uint16 *)p;

        case 3:
            if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
                return p[0] << 16 | p[1] << 8 | p[2];
            else
                return p[0] | p[1] << 8 | p[2] << 16;

        case 4:
            return *(Uint32 *)p;
    }

    return 0;
}

int main()
{
    SDL_Surface* image_surface;
    SDL_Surface* screen_surface;

    // TODO: Initialize the SDL
    init_sdl();


    image_surface = load_image("How.png");


    // TODO: Display the image.
    screen_surface = display_image(image_surface);

    // TODO: Wait for a key to be pressed.
    wait_for_keypressed();

    int width = image_surface->w;

    int height = image_surface->h;

    int average = 1;

    while (average != 0){
    for (int i = 1; i <width ; ++i)
    {
        for (int j = 1; j < height; ++j)
        {
            Uint32 pixel = get_pixel(image_surface, i, j);

            Uint8 r, g, b;
            SDL_GetRGB(pixel, image_surface->format, &r, &g, &b);

	    int R = r;
	    int G = g;
	    int B = b;

	    average = (R+G+B)/3;

	     printf("%i\n", R);
	     printf("%i\n", G);
	     printf("%i\n", B);

	    /*printf("%hhn\n", &r);
	     printf("%hhn\n", &g);
	     printf("%hhn\n", &b);
	    */
	     //wait_for_keypressed();

           

        }}

    }
    
   SDL_FreeSurface(image_surface);


   SDL_FreeSurface(screen_surface);

    wait_for_keypressed();

    // TODO: Free the image surface.
    SDL_FreeSurface(image_surface);

    // TODO: Free the screen surface.
    SDL_FreeSurface(screen_surface);

    return 0;
}

/*int main()
{
    SDL_Surface* image_surface;
    SDL_Surface* screen_surface;

    init_sdl();

    image_surface = load_image("How.png"); //charge image

    screen_surface = display_image(image_surface); //affiche image

        
    Uint32 pixel = get_pixel(image_surface, 100, 100);
    Uint8 r, g, b;
    SDL_GetRGB(pixel, image_surface->format, &r, &g, &b);

    //int num1 = atoi((const char*) r);
    //int num2 = atoi((const char*) g);
    //int num3 = atoi((const char*) b);

    printf("%hhn\n", &r);
    printf("%hhn\n", &g);
    printf("%hhn\n", &b);

    SDL_FreeSurface(image_surface);

    SDL_FreeSurface(screen_surface);


    }*/

