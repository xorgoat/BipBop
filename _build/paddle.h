#pragma once
#ifndef PADDLE_H_
#define PADDLE_H_

#include "raylib.h"

class Paddle {
private:
	Vector2 paddlePosition;
	Vector2 paddleSize;
public:
	Paddle(Vector2 paddlePosition, Vector2 paddleSize);
	Vector2 get_paddlePosition();
	void move();
	void draw();
};

Paddle::Paddle(Vector2 paddlePosition, Vector2 paddleSize) {
	this->paddlePosition = paddlePosition;
	this->paddleSize = paddleSize;
}

Vector2 Paddle::get_paddlePosition() {
	return this->paddlePosition;
}

void Paddle::move() {
	//User can move the paddle using arrow keys
	if (IsKeyDown(KEY_RIGHT)) paddlePosition.x += 4.0f;
	if (IsKeyDown(KEY_LEFT)) paddlePosition.x -= 4.0f;

	//Stops the paddle from moving off screen
	if (paddlePosition.x <= 0) {
		paddlePosition.x = 0;
	}
	if (paddlePosition.x >= (640 - 120)) {
		paddlePosition.x = 640 - 120;
	}
}

void Paddle::draw() {
	DrawRectangleV(paddlePosition, paddleSize, DARKPURPLE);
}


#endif /*PADDLE_H_*/


