#pragma once
#include "ofMain.h"

class Ball {
public:
	Ball(float initX, float initY, ofColor ballColor, float xVelocity, float yVelocity);
	void move();
	void draw();

	ofRectangle boundingBox;
	float xPos;
	float yPos;
	float xVel;
	float yVel;
	int radius;

private:
	ofColor color;

};