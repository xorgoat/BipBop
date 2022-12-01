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

    if ((ballPosition.y >= (paddle->get_paddlePosition().y) - ballSize)
        && ((ballPosition.x >= (paddle->get_paddlePosition().x) - ballSize+ 120/2)
            && (ballPosition.x <= (paddle->get_paddlePosition().x) - ballSize + 120))) {
        speed.x *= +1.0f;
        speed.y *= -1.0f;
        ball->set_ballSpeed(speed);
        //ball->get_ballSpeed();
    }

    if ((ballPosition.y >= (paddle->get_paddlePosition().y) - ballSize)
        && ((ballPosition.x >= (paddle->get_paddlePosition().x) - ballSize)
            && (ballPosition.x <= (paddle->get_paddlePosition().x) - ballSize + 120/2))) {
        speed.x *= -1.0f;
        speed.y *= -1.0f;
        ball->set_ballSpeed(speed);
        //ball->get_ballSpeed();
    }
	
}


#endif /*BPCOLLISION_H_*/