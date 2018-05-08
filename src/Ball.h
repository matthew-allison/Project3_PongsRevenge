#pragma once
#include "ofMain.h"

class Ball {
public:
	Ball(int screenWidth, int screenHeight, ofColor ballColor, float xVelocity, float yVelocity);
	void moveBall(float xVelocity, float yVelocity);
	float updateX();
	float updateY();
	void drawBall();
	void ballCollision(bool ballPaddle1, bool ballPaddle2);

	bool ballHitPaddle;
	bool ballScorePlayer1;
	bool ballScorePlayer2;
	float xPos;
	float yPos;

private:
	void returnBall();
	int screenWidth;
	int screenHeight;
	float xVel;
	float yVel;
	int ballRadius;
	ofColor ballColor;
	bool mouseClicked;

};