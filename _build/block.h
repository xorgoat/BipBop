#pragma once
#pragma once
#ifndef BLOCK_H_
#define BLOCK_H_

#include "raylib.h"

class Block {
private:
	Vector2 blockPosition;
	//Vector2 brickSize;
	//int integrity;
public:
	Block(Vector2 brickPosition);
	Vector2 get_blockPosition();
	//Vector2 get_brickSize();
	//int getIntegrity();
	//void setIntegrity(int newIntegrity);
	


};

Block::Block(Vector2 blockPosition) {
	this->blockPosition = blockPosition;
	//this->brickSize = brickSize;
	//this->integrity = integrity;

}

Vector2 Block::get_blockPosition() {
	return this->blockPosition;
}
/*Vector2 Bricks::get_brickSize() {
	return this->brickSize;
}

int Bricks::getIntegrity() {
	return this->integrity;
}

void Bricks::setIntegrity(int newIntegrity) {
	this->integrity = newIntegrity;
}*/


/*void Bricks::draw() {
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
}
}*/


#endif /*BLOCK_H_*/