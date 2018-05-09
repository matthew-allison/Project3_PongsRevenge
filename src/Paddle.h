#pragma once
#include "ofMain.h"

class Paddle {
public:
	Paddle(float initX, float initY, string hmnSelect, int paddleWidth, int paddleHeight, int screenWidth, int screenHeight, ofColor paddleColor, string whichPlayer);
	void playerMove(int mouseX, int mouseY, ofPoint ballPos);
	void drawPlayer();
	
	int screenWidth;
	int screenHeight;
	ofRectangle playerPaddle;

private:
	void moveConstraints();

	ofColor paddleColor;
	string hmnSelect;
	string whichPlayer;
};
