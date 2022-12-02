#include "raylib.h"
#include <vector>
using namespace std;

#include "paddle.h"
#include "ball.h"
#include "bpCollision.h"
#include "collision.h"
#include "bricks.h"
#include "bbCollision.h"
#include "block.h"

#include "timer.h"

int main() {
    Vector2 blockPosition = { 20,20 };
    //Initialization

    //Window
    const int windowHeight = 480;
    const int windowWidth = 640;
	InitWindow(windowWidth, windowHeight, "BipBop");
    int life_counter = 3;

    //Paddle
    Vector2 rectangleSize = { 120,20 };
    Vector2 rectanglePosition = { (double)windowWidth / 2 - rectangleSize.x, (double)windowHeight - rectangleSize.y };
    Paddle* paddle = new Paddle(rectanglePosition,rectangleSize);
    Vector2 paddlePosition = paddle->get_paddlePosition();

    //Ball
    Vector2 circlePosition = { GetScreenWidth() / 2.0f - 50, GetScreenHeight()- 50 };
    Vector2 ballSpeed = { -4.0f, 4.0f }; //Vector2 ballSpeed = { 5.0f, 4.0f };
    int ballRadius = 10;
    Ball* ball = new Ball(circlePosition, ballSpeed, ballRadius, life_counter);
    Vector2 ballPosition = ball->get_ballPosition();

    //Bricks
    //Bricks(Vector2 brickPosition, Vector2 brickSize, int brickRow, int brickColumn);
    int brickRow = 3;
    int brickColumn = 10;
    int brickIntegrity = 3;
    Vector2 brickSize = { 40,40 };
    //Vector2 brickPosition = { 20,20 };
    Vector2 brickPosition = { (GetScreenWidth() / 2.0f) - ((brickColumn / 2) * (brickSize.x) + 5),(GetScreenHeight() / 2.0f) - 210 };
    Bricks* bricks = new Bricks(brickPosition, brickSize,  brickRow,  brickColumn,brickIntegrity);
    bricks->init_vector();

    //timer
    double start = GetTime();
    double lifeTime = 0;
    Timer* timer = new Timer(start, lifeTime);
    Timer time  =  Timer(start, lifeTime);
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()){  // Detect window close button or ESC key
        // Update

        timer->startTimer(timer,lifeTime);
        double endTime = timer->getElapsed(time);
        DrawText(TextFormat("Time: %0i", endTime/6000), 250, 5, 20, GRAY);
        Vector2 speed = ball->get_ballSpeed();
        if (speed.x == 0 && speed.y == 0) {
            timer->timerDone(time);
            double endTime = timer->getElapsed(time);
            DrawRectangleV(Vector2{250,5},Vector2{200,20},RAYWHITE);
            DrawText(TextFormat("Time: %0i", time), 250, 400, 20, GRAY);
        }

        paddle->move();
        ball->move();
        ball->collision();
        bpCollision(ball, paddle);
        bbCollision(ball, bricks);
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        paddle->draw();
        ball->draw();
        bricks->draw();

        
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