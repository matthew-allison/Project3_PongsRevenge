#pragma once
#include "ofMain.h"

class Ball {
public:
	Ball(int screenWidth, int screenHeight, ofColor ballColor, float xVelocity, float yVelocity);
	ofPoint moveBall();
	void drawBall();

	ofPoint ballPos;
	bool ballHitPaddle;
	bool ballScorePlayer1;
	bool ballScorePlayer2;
	float xVel;
	float yVel;

private:
	int screenWidth;
	int screenHeight;
	int ballRadius;
	ofColor ballColor;
	bool mouseClicked;

};