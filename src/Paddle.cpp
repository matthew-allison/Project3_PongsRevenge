#include "ofMain.h"
#include "Paddle.h"


Paddle::Paddle(float initX, float initY, string hmnSelect, int paddleWidth, int paddleHeight, int screenWidth, int screenHeight, ofColor paddleColor, string whichPlayer) {
	this->playerPaddle = ofRectangle(initX, initY, paddleWidth, paddleHeight);
	this->paddleColor = paddleColor;
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->paddleCenter = ofPoint(playerPaddle.getCenter());
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

void Paddle::playerMove(int mouseX, int mouseY, float gameBallX, float gameBallY) {
	ballX = gameBallX;
	ballY = gameBallY;

	if (hmnSelect == "human") {
		playerPaddle.setX(mouseX);
		playerPaddle.setY(mouseY);
	}
	if (hmnSelect == "computer") {
		if (playerPaddle.getX() < ballX) {
			playerPaddle.setX(playerPaddle.getX() + 1);
		}
		if (playerPaddle.getX() > ballX) {
			playerPaddle.setX(playerPaddle.getX() - 1);
		}
		if (playerPaddle.getY() < ballY) {
			playerPaddle.setY(playerPaddle.getY() + 1);
		}
		if (playerPaddle.getY() > ballY) {
			playerPaddle.setY(playerPaddle.getY() - 1);
		}
	}
	moveConstraints();
}

void Paddle::drawPlayer() {
	ofSetColor(paddleColor);
	ofDrawRectangle(playerPaddle);
}

void Paddle::moveConstraints() {
	if (playerPaddle.getMinX() <= 0) {
		playerPaddle.setX(0);
	}
	if (whichPlayer == "player1") {
		if (playerPaddle.getMaxX() >= screenWidth / 2) {
			playerPaddle.setX(screenWidth / 2);
		}
	}
	else if (whichPlayer == "player2") {
		if (playerPaddle.getMaxX() <= screenWidth / 2) {
			playerPaddle.setX(screenWidth / 2);
		}
	}
	if (playerPaddle.getMinY() <= 0) {
		playerPaddle.setY(0);
	}
	if (playerPaddle.getMaxY() >= screenHeight) {
		playerPaddle.setY(screenHeight - paddleHeight * 2);
	}
	
}