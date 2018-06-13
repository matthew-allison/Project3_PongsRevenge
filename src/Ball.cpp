#include "Ball.h"

Ball::Ball(float initX, float initY, ofColor ballColor, float xVelocity, float yVelocity) {
	this->xPos = initX;
	this->yPos = initY;
	this->boundingBox = ofRectangle();
	boundingBox.setFromCenter(xPos, yPos, radius, radius);
	this->boundingBox.x = xPos;
	this->boundingBox.y = yPos;
	this->xVel = xVelocity;
	this->yVel = yVelocity;
	this->radius = 5;
	this->color = ballColor;
}

void Ball::move() {

	xPos += xVel;
	yPos += yVel;
}

void Ball::draw() {
	ofSetColor(color);
	ofDrawCircle(xPos, yPos, radius);
}
