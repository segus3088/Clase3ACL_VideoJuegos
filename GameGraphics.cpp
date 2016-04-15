#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include "GameGraphics.h"
#include "GameState.h"

SDL_Surface* PaddleGraphic1 = 0;
SDL_Surface* BallGraphic = 0;
SDL_Surface* BallPoint = 0;

int LoadGameGraphics()
{
    PaddleGraphic1 = SDL_LoadBMP("paddle_1.bmp");
    if (!PaddleGraphic1)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return 1;
    }

    PaddleSize_W = PaddleGraphic1->w;
    PaddleSize_H = PaddleGraphic1->h;

    BallPoint = SDL_LoadBMP("ball.bmp");
    if (!BallPoint)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return 1;
    }



    BallGraphic = SDL_LoadBMP("ball.bmp");
    if (!BallGraphic)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return 1;
    }

    BallSize_W = BallGraphic->w;
    BallSize_H = BallGraphic->h;

    return 0;
}

void FreeGameGraphics()
{
    SDL_FreeSurface(PaddleGraphic1);
    SDL_FreeSurface(BallGraphic);
    SDL_FreeSurface(BallPoint);
}

void DrawGameGraphics(SDL_Surface * screen)
{
    // clear screen
    SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 255, 255, 255));

    SDL_Rect dstrect;
    dstrect.x = (int)PaddlePosition.X;
    dstrect.y = (int)PaddlePosition.Y;

    // draw paddle bitmap
    SDL_BlitSurface(PaddleGraphic1, 0, screen, &dstrect);

    dstrect.x = (int)BallPosition.X;
    dstrect.y = (int)BallPosition.Y;

    // draw ball bitmap
    SDL_BlitSurface(BallGraphic, 0, screen, &dstrect);


    //dibujar puntos de vida
    //puedo hacer un for por la cantidad de vidas que tiene

    for (int i = 0; i < 3; ++i)
    {
    	/* code */
		dstrect.x = (int)i + BallSize_W * i;
		dstrect.y = (int)0;

		SDL_BlitSurface(BallPoint, 0, screen, &dstrect);
    }



    // finally, update the screen :)
    SDL_Flip(screen);
}
