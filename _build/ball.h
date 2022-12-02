#pragma once
#ifndef BALL_H_
#define BALL_H_

#include "raylib.h"
#include "paddle.h"
#include "timer.h"

class Ball {
private:
	Vector2 ballPosition;
	Vector2 ballSpeed;
	int ballSize;
	int life;
public:
	Ball(Vector2 ballPosition, Vector2 ballSpeed, int ballSize, int life);
	Vector2 get_ballPosition();
	Vector2 get_ballSpeed();
	void set_ballSpeed(Vector2 newSpeed);
	void set_ballPosition(Vector2 Position);
	void move();
	void draw();
	void collision();
};

Ball::Ball(Vector2 ballPosition, Vector2 ballSpeed, int ballSize, int life) {
	this->ballPosition = ballPosition;
	this->ballSpeed = ballSpeed;
	this->ballSize = ballSize;
	this->life = life;
}

Vector2 Ball::get_ballPosition() {
	return this->ballPosition;
}

Vector2 Ball::get_ballSpeed() {
	return this->ballSpeed;
}

void Ball::set_ballSpeed(Vector2 newSpeed) {
	this->ballSpeed = newSpeed;
}

void Ball::set_ballPosition(Vector2 newPosition) {
	this->ballPosition = newPosition;
}

void Ball::move() {
	ballPosition.x += ballSpeed.x;
	ballPosition.y += ballSpeed.y;
	
}

void Ball::draw() {
	DrawCircleV(ballPosition, ballSize, MAROON);
}

// Checks walls collision for bouncing
void Ball::collision() {
	if (life == 0) {
		DrawText("Game Overrr", 10, 480 - 40, 20, RED);
		ballSpeed = { 0, 0 }; //Stops the ball to end the game
	}
	if ((ballPosition.x >= (GetScreenWidth() - ballSize)) || (ballPosition.x <= ballSize)) {
        ballSpeed.x *= -1.0f;
    }
    if ((ballPosition.y <= ballSize)) {
        ballSpeed.y *= -1.0f;
    } 
	//Ball goes below the screen
    if ((ballPosition.y >= (GetScreenHeight() - ballSize))) {
        life--;
        //resets the ball
        ballPosition = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
        ballSpeed = { 2.0f, -3.0f };
    }
	//Displays the umber of lives on the screen
	DrawText(TextFormat("Lives: %0i", life), 10, 5, 20, GREEN);  
}


#endif /*BALL_H_*/