#include "Ball.h"

Ball::Ball(int screenWidth, int screenHeight, ofColor ballColor, float xVelocity, float yVelocity) {
	this->ballPos = ofPoint(screenWidth, screenHeight);
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

ofPoint Ball::moveBall() {
	ballPos.x += xVel;
	ballPos.y += yVel;
	return ballPos;
}

void Ball::drawBall() {
	ofSetColor(ballColor);
	ofDrawCircle(ballPos.x, ballPos.y, ballRadius);
}
