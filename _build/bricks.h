#pragma once
#ifndef BRICKS_H_
#define BRICKS_H_

#include "raylib.h"
#include <vector>
using namespace std;
#include "block.h"

class Bricks {
private:
	Vector2 brickStartPosition;
	Vector2 brickSize;
	int integrity;
	int brickRow;
	int brickColumn;
	//vector<Block*> bricks_vector;
	//std::vector<Vector2> bVector;
public:
	Bricks(Vector2 brickStartPosition, Vector2 brickSize, int brickRow, int brickColumn, int integrity);
	Vector2 get_brickStartPosition();
	Vector2 get_brickSize();
	int get_brickRow();
	int get_brickColumn();
	int getIntegrity();
	void setIntegrity(int newIntegrity);
	//typedef struct Brick;
	void draw();
	void init_vector();

	void removeBlock(Block* block);

	vector<Block*> bricks_vector;
	
};

Bricks::Bricks(Vector2 brickStartPosition, Vector2 brickSize, int brickRow, int brickColumn, int integrity) {
	this->brickStartPosition = brickStartPosition;
	this->brickSize = brickSize;
	this->brickRow = brickRow;
	this->brickColumn = brickColumn;
	this->integrity = integrity;
	this->bricks_vector = bricks_vector;
	
}

Vector2 Bricks::get_brickStartPosition() {
	return this->brickStartPosition;
}

int Bricks::get_brickRow() {
	return this->brickRow;
}

int Bricks::get_brickColumn() {
	return this->brickColumn;
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


//vector<Block*> bricks_vector;
//fills in the vector with pointers to bricks
void Bricks::init_vector() {
	int i, j;
	for (i = 0; i < this->brickColumn; i++) {
		for (j = 0; j < this->brickRow; j++) {
			//the coordinate that the brick will be located in
			Vector2 blockPosition = { brickStartPosition.x + i * (brickSize.x + 5), 
				brickStartPosition.y + j * (brickSize.y + 5) };

			Block* block = new Block(blockPosition, getIntegrity());

			bricks_vector.push_back(block);
		}
	}
}

void Bricks::draw() {

//Iterates over the vector using the rows and columns as the amout of pointers in the vector
	for (Block* block : bricks_vector) {
		//bricks_vector[i];
		//creates a special Vector2 wich is the position of the block
		//Vector2 brickPtrPosition = bricks_vector[index]->get_blockPosition();
		Vector2 brickPtrPosition = block->get_blockPosition();
		//draws the block in the specified position
		DrawRectangleV(brickPtrPosition, brickSize, ORANGE);
		//index++;
	}
}

void Bricks::removeBlock(Block* block) {
	//for (Block* block : this->bricks_vector) {
		//if (not brick->getIsAlive()) {
		vector<Block*>::iterator new_end;
			if (this->bricks_vector.front() == block){
			// second element becomes first element
			}
		if (this->bricks_vector.back() == block) {
			this->bricks_vector.pop_back();
		}	
		//new_end = remove(this->bricks.begin(), this->bricks.end(), brick);

}
	






#endif /*BRICKS_H_*/