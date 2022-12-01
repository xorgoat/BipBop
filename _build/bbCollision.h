#pragma once
#pragma once
#ifndef BBCOLLISION_H_
#define BBCOLLISION_H_

#include "raylib.h"
#include "ball.h"
#include "bricks.h"

void bbCollision(Ball* ball, Bricks* bricks) {
    Vector2 brickPosition = bricks->get_brickPosition();
    Vector2 brickSize = bricks->get_brickSize();
    int brickIntegrity = bricks->getIntegrity();
    Vector2 ballPosition = ball->get_ballPosition();
    Vector2 ballSpeed = ball->get_ballSpeed();
    Vector2 speed = ballSpeed;
    int ballSize = 10;
    int integrity = brickIntegrity;

    if (integrity==0) {
        DrawText(TextFormat("one of the bricks should be dead but idk"), 310, 240, 20, PINK);
    }

    if ((ballPosition.y >= (bricks->get_brickPosition().y) - ballSize)
        && ((ballPosition.y <= (bricks->get_brickPosition().y) - ballSize+brickSize.y))
            && ((ballPosition.x >= (bricks->get_brickPosition().x) - ballSize)
                && (ballPosition.x <= (bricks->get_brickPosition().x) - ballSize + brickSize.x))) {
        speed.x *= +1.0f;
        speed.y *= -1.0f;
        ball->set_ballSpeed(speed);
        integrity--;
        bricks->setIntegrity(integrity);
        //ball->get_ballSpeed();
    }


}


#endif /*BBCOLLISION_H_*/