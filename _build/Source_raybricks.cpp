#include "raylib.h"
#include "paddle.h"
#include "ball.h"
#include "bpCollision.h"
#include "collision.h"

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
#include <math.h>

/*To do:
Next: bricks, brick collision

fix life count
Implement timer
Add angles (revamped collision)
"AI"

Arrays, pointers ** , OOP ** , loops **, scope**, and error handling
*/

#define LINES_OF_BRICKS         5
#define BRICKS_PER_LINE        20

typedef struct Brick {
    Vector2 position;
    bool active;
} Brick;

static Brick brick[LINES_OF_BRICKS][BRICKS_PER_LINE] = { 0 };

int main() {

    //Initialization

    //Window
    const int windowHeight = 480;
    const int windowWidth = 640;
    InitWindow(windowWidth, windowHeight, "BipBop");

    //Paddle
    Vector2 rectangleSize = { 120,20 };
    Vector2 rectanglePosition = { (double)windowWidth / 2, (double)windowHeight - rectangleSize.y };
    Paddle* paddle = new Paddle(rectanglePosition, rectangleSize);
    Vector2 paddlePosition = paddle->get_paddlePosition();

    //Ball
    Vector2 circlePosition = { GetScreenWidth() / 2.0f - 100, GetScreenHeight() / 2.0f + 100 };
    Vector2 ballSpeed = { 4.0f, 4.0f }; //Vector2 ballSpeed = { 5.0f, 4.0f };
    int ballRadius = 10;
    Ball* ball = new Ball(circlePosition, ballSpeed, ballRadius);
    Vector2 ballPosition = ball->get_ballPosition();

    //bricks
    Vector2 brickSize = Vector2{ 640 / BRICKS_PER_LINE, 40 };
    for (int i = 0; i < LINES_OF_BRICKS; i++)
    {
        for (int j = 0; j < BRICKS_PER_LINE; j++)
        {
            brick[i][j].position = Vector2{ j * brickSize.x + brickSize.x / 2, i * brickSize.y + 50 };
            brick[i][j].active = true;
        }
    }

    int life_counter = 3;



    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    //const texture = "Fantasy-library-art.jpg";
    //Image image  = LoadImage('C:/Users/arice/OneDrive/Pictures/nao.jpg');
    //Texture2D LoadTextureFromImage(Image image);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update

        paddle->move();
        ball->move();

        ball->collision(); //Collision(ball,life_counter);
        bpCollision(ball, paddle);

        // Collision logic: ball vs bricks
        for (int i = 0; i < LINES_OF_BRICKS; i++)
        {
            for (int j = 0; j < BRICKS_PER_LINE; j++)
            {
                if (brick[i][j].active)
                {
                    // Hit below
                    if (((ballPosition.y - ballRadius) <= (brick[i][j].position.y + brickSize.y / 2)) &&
                        ((ballPosition.y - ballRadius) > (brick[i][j].position.y + brickSize.y / 2 + ballSpeed.y)) &&
                        ((fabs(ballPosition.x - brick[i][j].position.x)) < (brickSize.x / 2 + ballRadius * 2 / 3)) && (ballSpeed.y < 0))
                    {
                        brick[i][j].active = false;
                        ballSpeed.y *= -1;
                    }
                    // Hit above
                    else if (((ballPosition.y + ballRadius) >= (brick[i][j].position.y - brickSize.y / 2)) &&
                        ((ballPosition.y + ballRadius) < (brick[i][j].position.y - brickSize.y / 2 + ballSpeed.y)) &&
                        ((fabs(ballPosition.x - brick[i][j].position.x)) < (brickSize.x / 2 + ballRadius * 2 / 3)) && (ballSpeed.y > 0))
                    {
                        brick[i][j].active = false;
                        ballSpeed.y *= -1;
                    }
                    // Hit left
                    else if (((ballPosition.x + ballRadius) >= (brick[i][j].position.x - brickSize.x / 2)) &&
                        ((ballPosition.x + ballRadius) < (brick[i][j].position.x - brickSize.x / 2 + ballSpeed.x)) &&
                        ((fabs(ballPosition.y - brick[i][j].position.y)) < (brickSize.y / 2 + ballRadius * 2 / 3)) && (ballSpeed.x > 0))
                    {
                        brick[i][j].active = false;
                        ballSpeed.x *= -1;
                    }
                    // Hit right
                    else if (((ballPosition.x - ballRadius) <= (brick[i][j].position.x + brickSize.x / 2)) &&
                        ((ballPosition.x - ballRadius) > (brick[i][j].position.x + brickSize.x / 2 + ballSpeed.x)) &&
                        ((fabs(ballPosition.y - brick[i][j].position.y)) < (brickSize.y / 2 + ballRadius * 2 / 3)) && (ballSpeed.x < 0))
                    {
                        brick[i][j].active = false;
                        ballSpeed.x *= -1;
                    }
                }
            }
        }


        /*        if (life_counter == 0) {
            DrawText("Game Overrr", 10, GetScreenHeight() - 25, 20, RED);
            ballSpeed = { 0, 0 };
            ball->set_ballSpeed(ballSpeed);
        }

        if ((ballPosition.y >= (GetScreenHeight() - ballRadius - 5))) {
            life_counter--;
        }*/


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        //DrawTexture(Texture2D);
        //DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
        //DrawRectangleV(rectanglePosition, rectangleSize, MAROON);

        paddle->draw();
        ball->draw();

        // Draw bricks
        for (int i = 0; i < LINES_OF_BRICKS; i++)
        {
            for (int j = 0; j < BRICKS_PER_LINE; j++)
            {
                if (brick[i][j].active)
                {
                    if ((i + j) % 2 == 0) DrawRectangle(brick[i][j].position.x - brickSize.x / 2, brick[i][j].position.y - brickSize.y / 2, brickSize.x, brickSize.y, GRAY);
                    else DrawRectangle(brick[i][j].position.x - brickSize.x / 2, brick[i][j].position.y - brickSize.y / 2, brickSize.x, brickSize.y, DARKGRAY);
                }
            }
        }


        DrawText(TextFormat("Lives: %0i", life_counter), 10, 10, 20, GREEN);

        EndDrawing();
    }

    // De-Initialization

    CloseWindow();        // Close window and OpenGL context
    //

    return 0;
}




/*
*
* if (life_counter == 0) {
            DrawText("Game Overrr", 10, GetScreenHeight() - 25, 20, RED);
            ballSpeed = { 0, 0 };
            ball->set_ballSpeed(ballSpeed);
            ball->get_ballSpeed();
        }
*
* DrawText(" 123" + life_counter, 10, 10, 20, GREEN);
*
        // Check walls collision for bouncing
        if ((ballPosition.x >= (GetScreenWidth() - ballRadius)) || (ballPosition.x <= ballRadius)) {
            ballSpeed.x *= -1.0f;
            ball->set_ballSpeed(ballSpeed);
            ball->get_ballSpeed();
        }
        if ((ballPosition.y <= ballRadius)) {
            ballSpeed.y *= -1.0f;
            ball->set_ballSpeed(ballSpeed);
            ball->get_ballSpeed();
        }
        if ((ballPosition.y >= (GetScreenHeight() - ballRadius))) {
            life_counter--;
            //resets the ball
            ballPosition = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
            ballSpeed = { 5.0f, 4.0f };
            ball->set_ballSpeed(ballSpeed);
            ball->get_ballSpeed();
        }
        //if ((ballPosition.y >= (GetScreenHeight() - ballRadius)) || (ballPosition.y <= ballRadius)) ballSpeed.y *= -1.0f;

        //CheckCollisionCircleRec(ballPosition, ballRadius, (Rectangle) { paddlePosition.x, paddlePosition.y, rectangleSize.x, rectangleSize.y }));
        //paddle->get_paddlePosition().y
        if ((ballPosition.y >= (paddlePosition.y) - ballRadius)
            && ((ballPosition.x >= (paddlePosition.x) - ballRadius)
                && (ballPosition.x <= (paddlePosition.x) - ballRadius + 120))) {
            ballSpeed.x *= +1.0f;
            ballSpeed.y *= -1.0f;
            ball->set_ballSpeed(ballSpeed);
            ball->get_ballSpeed();
        }*/
        //&& (ballPosition.y >= GetScreenWidth() - ballRadius - 20)) ballSpeed.x *= -1.0f;