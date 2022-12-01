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

	if (IsKeyDown(KEY_RIGHT)) paddlePosition.x += 3.5f;
	if (IsKeyDown(KEY_LEFT)) paddlePosition.x -= 3.5f;
}

void Paddle::draw() {
	DrawRectangleV(paddlePosition, paddleSize, DARKPURPLE);
}


#endif /*PADDLE_H_*/




/*#include "raylib.h"

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

Paddle::Paddle(Vector2 paddlePosition, Vector2 paddleSize){
	this->paddlePosition = paddlePosition;
	this->paddleSize = paddleSize;
}

Vector2 Paddle::get_paddlePosition() {
	return this->paddlePosition;
}

void Paddle::move() {

	if (IsKeyDown(KEY_RIGHT)) paddlePosition.x += 3.0f;
	if (IsKeyDown(KEY_LEFT)) paddlePosition.x -= 3.0f;
}

void Paddle::draw() {
	DrawRectangleV(paddlePosition, paddleSize, DARKPURPLE);
}









#include "raylib.h"

class Paddle {
private:
	struct Rectangle rectangle;
	Vector2 paddlePosition;
	Vector2 paddleSize;
public:
	Paddle(struct Rectangle rectangle);
	Vector2 get_paddlePosition();
	void move();
	void draw();
};

Paddle::Paddle(struct Rectangle rectangle){
	this->rectangle = rectangle;
	this->paddlePosition = paddlePosition;
	//this->rectangle.x = paddlePosition;
	//rectangle.y = paddleSize;
	this->paddleSize = paddleSize;
}

Vector2 Paddle::get_paddlePosition() {
	return this->paddlePosition;
}

void Paddle::move() {

	if (IsKeyDown(KEY_RIGHT)) paddlePosition.x += 3.0f;
	if (IsKeyDown(KEY_LEFT)) paddlePosition.x -= 3.0f;
}

void Paddle::draw() {
	DrawRectangleRec(rectangle, ORANGE);
	DrawRectangleV(paddlePosition, paddleSize, DARKPURPLE);
}

*/
