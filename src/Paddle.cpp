#include "ofMain.h"
#include "Paddle.h"


Paddle::Paddle(float initX, float initY, string hmnSelect, int paddleWidth, int paddleHeight, ofColor paddleColor, string whichPlayer) {
	this->playerPaddle = ofRectangle();
	playerPaddle.setFromCenter(initX, initY, paddleWidth, paddleHeight);
	this->color = paddleColor;
	if (hmnSelect == "human") {
		this->hmnSelect = "human";
	}
	else if (hmnSelect == "computer") {
		this->hmnSelect = "computer";
	}
	if (whichPlayer == "player1") {
		this->whichPlayer = "player1";
	}
	else if (whichPlayer == "player2") {
		this->whichPlayer = "player2";
	}
	
};

void Paddle::move(int mouseX, int mouseY, float ballX, float ballY) {
	if (hmnSelect == "human") {
		playerPaddle.x = mouseX;
		playerPaddle.y = mouseY;
	}
	if (hmnSelect == "computer") {
		if (playerPaddle.getMinX() < ballX &&
			playerPaddle.getMaxX() > ballX &&
			playerPaddle.getMinY() < ballY &&
			playerPaddle.getMaxY() > ballY) {
			playerPaddle.x += 0;
			playerPaddle.y += 0;
		}
		else {
			if (playerPaddle.getMinX() < ballX) {
				playerPaddle.x += 5;
			}
			if (playerPaddle.getMinX() > ballX) {
				playerPaddle.x -= 5;
			}
			if (playerPaddle.getMinY() < ballY || playerPaddle.getMaxY() < ballY) {
				playerPaddle.y += 5;
				if (playerPaddle.getMaxY() + 10 > ballY) {
					playerPaddle.y += 10;
				}
			}
			if (playerPaddle.getMinY() > ballY || playerPaddle.getMaxY() > ballY) {
				playerPaddle.y -= 5;
			}
		}
	}
}

void Paddle::draw() {
	ofSetColor(color);
	ofDrawRectangle(playerPaddle);
}