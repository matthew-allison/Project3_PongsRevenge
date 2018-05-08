#include "Ball.h"

Ball::Ball(int screenWidth, int screenHeight, ofColor ballColor, float xVelocity, float yVelocity) {
	this->xPos = screenWidth / 2;
	this->yPos = screenHeight / 2;
	this->xVel = xVelocity;
	this->yVel = yVelocity;
	this->yVel = 1;
	this->ballRadius = 5;
	this->ballColor = ballColor;
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->mouseClicked = mouseClicked;
	bool ballHitPaddle = false;
	bool ballScore = false;
}

void Ball::moveBall(float xVelocity, float yVelocity) {

	xPos += xVel;
	yPos += yVel;

	if (yPos <= 0) {
		yVel *= -1;
	}
	if (yPos >= screenHeight) {
		yVel *= -1;
	}
	if (xPos <= ballRadius || xPos >= screenWidth - ballRadius) {
		returnBall();
	}
}

float Ball::updateX() {
	return xPos;
}

float Ball::updateY() {
	return yPos;
}

void Ball::returnBall() {
	xPos = screenWidth / 2;
	yPos = screenWidth / 2;
	xVel = ofRandomf();
	yVel = ofRandomf();
}

void Ball::drawBall() {
	ofSetColor(ballColor);
	ofDrawCircle(xPos, yPos, ballRadius);
}

void Ball::ballCollision(bool ballPaddle1, bool ballPaddle2) {
	cout << ballPaddle1 << endl;
	cout << ballPaddle2 << endl;
	if (ballPaddle1 == true || ballPaddle2 == true) {
		xVel *= -1;
		yVel *= -1;
	}
}