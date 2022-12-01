#pragma once
#ifndef COLLISION_H_
#define COLLISION_H_

#include "raylib.h"
#include "ball.h"
#include "paddle.h"

void Collision(Ball* ball, int lives) {
    Vector2 ballPosition = ball->get_ballPosition();
    Vector2 ballSpeed = ball->get_ballSpeed();
    Vector2 speed = ballSpeed;
    int ballSize = 10;

    if (lives == 0) {
        DrawText("Game Overrr", 10, GetScreenHeight() - 25, 20, RED);
        speed = { 0, 0 };
        ball->set_ballSpeed(ballSpeed);
    }

    // Check walls collision for bouncing
    if ((ballPosition.x >= (GetScreenWidth() - ballSize)) || (ballPosition.x <= ballSize)) {
        speed.x *= -1.0f;
        ball->set_ballSpeed(speed);
    }
    if ((ballPosition.y <= ballSize)) {
        speed.y *= -1.0f;
        ball->set_ballSpeed(speed);
    }
    if ((ballPosition.y >= (GetScreenHeight() - ballSize))) {
        lives--;
        //resets the ball
        ball->set_ballPosition({ 320, 400 });
        speed = { 5.0f, 4.0f };
        ball->set_ballSpeed(speed);
    }


}


#endif /*COLLISION_H_*/