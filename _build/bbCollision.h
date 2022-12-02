#pragma once
#pragma once
#ifndef BBCOLLISION_H_
#define BBCOLLISION_H_

#include "raylib.h"
#include "ball.h"
#include "bricks.h"
#include "block.h"
#include <vector>
using namespace std;

void bbCollision(Ball* ball, Bricks* bricks) {

    //bricks
    Vector2 brickPosition = bricks->get_brickStartPosition();
    Vector2 brickSize = bricks->get_brickSize();
    //int brickIntegrity = bricks->getIntegrity();
    int brickRow = bricks->get_brickRow();
    int brickColumn = bricks->get_brickColumn();
    //int integrity = brickIntegrity;
    //vector<Block*> bricksPtrVector = bricks->bricks_vector;

    //block
    //Vector2 blockPosition = block->
    
    //ball
    Vector2 ballPosition = ball->get_ballPosition();
    Vector2 ballSpeed = ball->get_ballSpeed();
    Vector2 speed = ballSpeed;
    int ballSize = 10;

    int index = 0;

    //for (i = 0; i < bricks->brickRow; i++)
    //for (int i = 0; i < brickRow * brickColumn; i++) {
    for (Block* block : bricks->bricks_vector) {

        //bricks->bricks_vector[i];
        //int blockIntegrity = bricks->bricks_vector[i]->getIntegrity();
        int blockIntegrity = block->getIntegrity();
        int integrity = blockIntegrity;
        //Vector2 blockPtrPosition = bricks->bricks_vector[i]->get_blockPosition();
        Vector2 blockPtrPosition = block->get_blockPosition();

        //delete block from vector
        if (integrity == 0) {
            bricks->removeBlock(block);
            block->set_blockPosition(Vector2{ 700,500 });
        }
        

        //collision 
        //top (of the block)
        if ((ballPosition.x >= blockPtrPosition.x) 
            && (ballPosition.y == blockPtrPosition.y - ballSize) 
            && (ballPosition.x <= blockPtrPosition.x+brickSize.x)) {
            
            integrity--;
            //bricks->bricks_vector[i]->setIntegrity(integrity);
            block->setIntegrity(integrity);
            speed.x *= 1.0f;
            speed.y *= -1.0f;
            ball->set_ballSpeed(speed);
        }
        //left side
        if ((ballPosition.y >= blockPtrPosition.y - ballSize) 
            && (ballPosition.x == blockPtrPosition.x - ballSize) 
            && (ballPosition.y <= blockPtrPosition.y + brickSize.y - ballSize)) {
            integrity--;
            //bricks->bricks_vector[i]->setIntegrity(integrity);
            block->setIntegrity(integrity);
            speed.x *= -1.0f;
            speed.y *= 1.0f;
            ball->set_ballSpeed(speed);
        }
        //right side
        if ((ballPosition.x >= blockPtrPosition.x - ballSize) 
            && (ballPosition.y == blockPtrPosition.y - ballSize)
            && (ballPosition.x == blockPtrPosition.y + brickSize.y - ballSize)
            && (ballPosition.y <= blockPtrPosition.y + brickSize.y - ballSize)) {
            integrity--;
            //bricks->bricks_vector[i]->setIntegrity(integrity);
            block->setIntegrity(integrity);
            speed.x *= -1.0f;
            speed.y *= 1.0f;
            ball->set_ballSpeed(speed);
        }
        //bottom
        if ((ballPosition.y >= blockPtrPosition.y - ballSize) 
            && (ballPosition.x == blockPtrPosition.x - ballSize)
            && (ballPosition.y == blockPtrPosition.x + brickSize.x - ballSize)
            && (ballPosition.x <= blockPtrPosition.x + brickSize.x - ballSize)) {
            integrity--;
            //bricks->bricks_vector[i]->setIntegrity(integrity);
            block->setIntegrity(integrity);
            speed.x *= 1.0f;
            speed.y *= -1.0f;
            ball->set_ballSpeed(speed);
        }
          

        index++;

    }
   

}



#endif /*BBCOLLISION_H_*/

