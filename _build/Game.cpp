#include "raylib.h"
#include "paddle.h"
#include "ball.h"
#include "bpCollision.h"
#include "collision.h"
#include "bricks.h"
#include "bbCollision.h"
#include "block.h"


/*To do:
Next: bricks, brick collision

fix life count**
Implement timer
Add angles (revamped collision) ..ehhh
"AI"

Arrays, pointers ** , OOP ** , loops **, scope**, and error handling
*/


int main() {
    Vector2 blockPosition = { 20,20 };
    Block* block = new Block(blockPosition);
    //block[1][1];
    //Initialization

    //Window
    const int windowHeight = 480;
    const int windowWidth = 640;
	InitWindow(windowWidth, windowHeight, "BipBop");
    int life_counter = 3;

    //Paddle
    Vector2 rectangleSize = { 120,20 };
    Vector2 rectanglePosition = { (double)windowWidth / 2, (double)windowHeight - rectangleSize.y };
    Paddle* paddle = new Paddle(rectanglePosition,rectangleSize);
    Vector2 paddlePosition = paddle->get_paddlePosition();

    //Ball
    Vector2 circlePosition = { GetScreenWidth() / 2.0f -100, GetScreenHeight() / 2.0f + 100 };
    Vector2 ballSpeed = { 4.0f, 3.0f }; //Vector2 ballSpeed = { 5.0f, 4.0f };
    int ballRadius = 10;
    Ball* ball = new Ball(circlePosition, ballSpeed, ballRadius, life_counter);
    Vector2 ballPosition = ball->get_ballPosition();

    //Bricks
    //Bricks(Vector2 brickPosition, Vector2 brickSize, int brickRow, int brickColumn);
    int brickRow = 2;
    int brickColumn = 8;
    int brickIntegrity = 3;
    Vector2 brickSize = { 40,40 };
    Vector2 brickPosition = { (GetScreenWidth() / 2.0f)-((brickColumn/2)*(brickSize.x) + 5),(GetScreenHeight() / 2.0f) - 200};
    Bricks* bricks = new Bricks(brickPosition, brickSize,  brickRow,  brickColumn,brickIntegrity);


    
    //life(ball, life_counter);

    
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
        //life(ball, life_counter);
        ball->collision(); //Collision(ball,life_counter);
        bpCollision(ball, paddle);
        bbCollision(ball, bricks);
        


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
        bricks->draw();
        
        

        //DrawText(TextFormat("Lives: %0i", life_counter), 10, 10, 20, GREEN);
        
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