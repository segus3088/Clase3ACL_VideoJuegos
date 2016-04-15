#include "GameState.h"

Vector2D PaddlePosition;
Vector2D BallPosition;
Vector2D VectorDirection;

int ScreenSize_W = 0; // Initalized from screen surface size
int ScreenSize_H = 0;

int PaddleSize_W = 0; // Initialized from bitmap size
int PaddleSize_H = 0;

int BallSize_W = 0; // Initialized from bitmap size
int BallSize_H = 0;

static int PressingLeft = 0;
static int PressingRight = 0;

void InitializeGame()
{
    PaddlePosition.X = (ScreenSize_W - PaddleSize_W) / 2;
    PaddlePosition.Y = ScreenSize_H - PaddleSize_H - 40;

    BallPosition.X = (ScreenSize_W - BallSize_W) / 2;
    BallPosition.Y = ScreenSize_H / 2;

    VectorDirection.X = 1;
    VectorDirection.Y = 1;
}

void UpdatePlayerInput(const SDL_Event * event)
{
    if (!event)
        return;

    if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_LEFT)
        PressingLeft = 1;

    if (event->type == SDL_KEYUP && event->key.keysym.sym == SDLK_LEFT)
        PressingLeft = 0;

    if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_RIGHT)
        PressingRight = 1;

    if (event->type == SDL_KEYUP && event->key.keysym.sym == SDLK_RIGHT)
        PressingRight = 0;
}

bool DetetionColition(int rect1_x, int rect1_y, int rect1_width, int rect1_height, int rect2_x, int rect2_y, int rect2_width, int rect2_height)
{
	if (rect1_x < rect2_x + rect2_width &&
	rect1_x + rect1_width > rect2_x &&
	rect1_y < rect2_y + rect2_height &&
	rect1_height + rect1_y > rect2_y)
	{
	// collision detected!
		return true;
	}
	return false;

}

void UpdateGame(float deltaTime)
{
    const float PaddleSpeed = 200.0f;
    const float BallSpeed = 150.0f;

    BallPosition.Y += (BallSpeed * deltaTime) * VectorDirection.Y;
    BallPosition.X += (BallSpeed * deltaTime) * VectorDirection.X;

    //Para cuando se sale del campo
    if (BallPosition.Y >= (ScreenSize_H - BallSize_H) )
    {
    	/* code */
    	VectorDirection.Y = -1;
    }

    if (BallPosition.Y <= 0)
    {
    	/* code */
    	VectorDirection.Y = 1;
    }

    if (BallPosition.X >= (ScreenSize_W - BallSize_W) )
    {
    	/* code */
    	VectorDirection.X = -1;
    }

    if (BallPosition.X <= 0)
    {
    	/* code */
    	VectorDirection.X = 1;
    }

    //detectar colition

    if (DetetionColition(BallPosition.X, BallPosition.Y, BallSize_W, BallSize_H, PaddlePosition.X, PaddlePosition.Y, PaddleSize_W, PaddleSize_H))
    {
    	/* code */
    	VectorDirection.X *= 1;
    	VectorDirection.Y *= -1; 
    }
    




    if (PressingLeft)
        PaddlePosition.X -= PaddleSpeed * deltaTime;

    if (PressingRight)
        PaddlePosition.X += PaddleSpeed * deltaTime;
}
