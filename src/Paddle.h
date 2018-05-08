#pragma once
#include "ofMain.h"

class Paddle {
public:
	Paddle(float initX, float initY, string hmnSelect, int paddleWidth, int paddleHeight, int screenWidth, int screenHeight, ofColor paddleColor, string whichPlayer);
	void playerMove(int mouseX, int mouseY, float gameBallX, float gameBallY);
	void drawPlayer();
	bool ballHit();
	
	int screenWidth;
	int screenHeight;

private:
	void moveConstraints();

	ofRectangle playerPaddle;
	ofPoint paddleCenter;
	float paddleWidth;
	float paddleHeight;
	ofColor paddleColor;
	string hmnSelect;
	string whichPlayer;
	float ballX;
	float ballY;
};
