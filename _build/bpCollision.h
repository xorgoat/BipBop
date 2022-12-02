#pragma once
#ifndef BPCOLLISION_H_
#define BPCOLLISION_H_

#include "raylib.h"
#include "ball.h"
#include "paddle.h"

void bpCollision(Ball* ball, Paddle* paddle) {
    Vector2 paddlePosition = paddle->get_paddlePosition();
    Vector2 ballPosition = ball->get_ballPosition();
    Vector2 ballSpeed = ball->get_ballSpeed();
    Vector2 speed = ballSpeed;
    int ballSize = 10;

    float ballSpeedX[5] = { 5.0f, 2.0f, 0.0f, -2.0f, -5.0f };
    float ballSpeedY[5] = { -2.0f, -5.0f, -6.0f, -5.0f, -2.0f };
  
    // left most section of paddle
    if ((ballPosition.y >= (paddle->get_paddlePosition().y) - ballSize)
        && ((ballPosition.x >= (paddle->get_paddlePosition().x) - ballSize -1)
            && (ballPosition.x <= (paddle->get_paddlePosition().x) - ballSize + (120/5)))) {
        ball->set_ballSpeed(Vector2{ballSpeedX[0],ballSpeedY[0]});
    }

    //Left 2
    if ((ballPosition.y >= (paddle->get_paddlePosition().y) - ballSize)
        && ((ballPosition.x >= (paddle->get_paddlePosition().x) - ballSize + (120 / 5)))
        && (ballPosition.x <= (paddle->get_paddlePosition().x) - ballSize + 2*(120/5))) {

        ball->set_ballSpeed(Vector2{ ballSpeedX[1],ballSpeedY[1] });
    }

    //Middle
    if ((ballPosition.y >= (paddle->get_paddlePosition().y) - ballSize)
        && ((ballPosition.x >= (paddle->get_paddlePosition().x) - ballSize + 2 * (120 / 5))
            && (ballPosition.x <= (paddle->get_paddlePosition().x) - ballSize + 3 * (120 / 5)))) {

        ball->set_ballSpeed(Vector2{ ballSpeedX[2],ballSpeedY[2] });
    }

    //Right 1
    if ((ballPosition.y >= (paddle->get_paddlePosition().y) - ballSize)
        && ((ballPosition.x >= (paddle->get_paddlePosition().x) - ballSize + 3 * (120 / 5))
            && (ballPosition.x <= (paddle->get_paddlePosition().x) - ballSize + 4 * (120 / 5)))) {

        ball->set_ballSpeed(Vector2{ ballSpeedX[3],ballSpeedY[3] });
    }

    //Right most 
    if ((ballPosition.y >= (paddle->get_paddlePosition().y) - ballSize)
        && ((ballPosition.x >= (paddle->get_paddlePosition().x) - ballSize + 4 * (120 / 5))
            && (ballPosition.x <= (paddle->get_paddlePosition().x) - ballSize + 119))) {

        ball->set_ballSpeed(Vector2{ ballSpeedX[4],ballSpeedY[4] });
    }
	
}


#endif /*BPCOLLISION_H_*/