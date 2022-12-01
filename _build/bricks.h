#pragma once
#ifndef BRICKS_H_
#define BRICKS_H_

#include "raylib.h"

class Bricks {
private:
	Vector2 brickPosition;
	Vector2 brickSize;
	int integrity;
	int brickRow;
	int brickColumn;
public:
	Bricks(Vector2 brickPosition, Vector2 brickSize, int brickRow, int brickColumn, int integrity);
	Vector2 get_brickPosition();
	Vector2 get_brickSize();
	int getIntegrity();
	void setIntegrity(int newIntegrity);
	//typedef struct Brick;
	void draw();
	
	
};

Bricks::Bricks(Vector2 brickPosition, Vector2 brickSize, int brickRow, int brickColumn, int integrity) {
	this->brickPosition = brickPosition;
	this->brickSize = brickSize;
	this->brickRow = brickRow;
	this->brickColumn = brickColumn;
	this->integrity = integrity;
	
}

Vector2 Bricks::get_brickPosition() {
	return this->brickPosition;
}

Vector2 Bricks::get_brickSize() {
	return this->brickSize;
}

int Bricks::getIntegrity() {
	return this->integrity;
}

void Bricks::setIntegrity(int newIntegrity) {
	this->integrity = newIntegrity;
}

/*
typedef struct Bricks::Brick {
	Vector2 position;
} Brick;
*/


void Bricks::draw() {
	//brickRow = 2;
	//brickColumn = 5;
	//static Brick* brick[2][5] = { 0 };


	int i, j;

	for (i = 0; i < this->brickColumn; i++) {
		for (j = 0; j < this->brickRow; j++) {
			//DrawRectangleV(rectanglePosition, rectangleSize, MAROON);
			DrawRectangleV(Vector2{ brickPosition.x + (45 * i), brickPosition.y + 45 * j }, brickSize, ORANGE);


			//Bricks* bodySeg = new Bricks(this->brickPosition.x + (45 * i), this->brickPosition.y + (45 * j));
			//DrawRectangle(bodyseg.position.x - brickSize.x / 2,brick[i][j].position.y - brickSize.y / 2, brickSize.x,brickSize.y, GRAY);

		}

	}



	/*

	for (int i = 0; i < brickRow; i++)
	{
		for (int j = 0; j < brickColumn; j++)
		{
			
			if ((i + j) % 2 == 0) {
				DrawRectangle(brick[i][j].position.x - brickSize.x / 2, 
					brick[i][j].position.y - brickSize.y / 2, brickSize.x, 
					brickSize.y, GRAY);
			}
			else {
				DrawRectangle(brick[i][j].position.x - brickSize.x / 2, 
					brick[i][j].position.y - brickSize.y / 2, 
					brickSize.x, brickSize.y, DARKGRAY);
			}
		}
	}*/
}

#endif /*BRICKS_H_*/