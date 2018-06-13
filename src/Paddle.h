#pragma once
#include "ofMain.h"

class Paddle {
public:
	Paddle(float initX, float initY, string hmnSelect, int paddleWidth, int paddleHeight, ofColor paddleColor, string whichPlayer);
	void move(int mouseX, int mouseY, float ballX, float ballY);
	void draw();

	ofRectangle playerPaddle;

private:

	ofColor color;
	string hmnSelect;
	string whichPlayer;
};
