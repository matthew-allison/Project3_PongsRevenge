#include "ofApp.h"
#include "ofMath.h"
#include <iostream>

using namespace std;

const int paddleWidth = 10;
const int paddleHeight = 100;

void ofApp::setup(){
	if (!ofFile::doesFileExist("savedHighScore.txt")) {
		string zero = "0";
		scoreBuffer.set(zero);
		ofBufferToFile("savedHighScore.txt", scoreBuffer);
		scoreBuffer.clear();
	}
	ofSetFrameRate(30);
	ofSetBackgroundColor(0, 0, 0);
	ofColor white(255, 255, 255);
	player1 = new Paddle(10, ofGetHeight() / 2, "human", paddleWidth, paddleHeight, white, "player1");
	player2 = new Paddle(ofGetWidth() - 20, ofGetHeight() / 2, "computer", paddleWidth, paddleHeight, white, "player2");
	gameBall = new Ball(ofGetWidth() / 2, ofGetHeight() / 2, white, -2, -2);
	currentState = 0;
	currentStatePtr = &currentState;
	ballAmtPtr = &ballAmt;
	scorePtr = &score;
	thisGame = new GameState();
	getHighScore();
}

void ofApp::update(){
	if (*currentStatePtr == 0) {
		selectStart();
		score = 0;
		ballAmt = 2;
	}
	if (*currentStatePtr == 1) {
		player1->move(ofGetMouseX(), ofGetMouseY(), gameBall->xPos, gameBall->yPos);
		player2->move(ofGetMouseX(), ofGetMouseY(), gameBall->xPos, gameBall->yPos);
		paddleConstraints();
		gameBall->move();
		isHitting();
		hasReachedSides();
	}
	if (*currentStatePtr == 2) {
		isNewHighScore();
	}
}

void ofApp::draw(){
	if (*currentStatePtr == 0) {
		thisGame->drawStart(highScoreStr);
	}
	else if (*currentStatePtr == 1) {
		thisGame->drawGame(*scorePtr, *ballAmtPtr);
		player1->draw();
		player2->draw();
		gameBall->draw();
	}
	else if (*currentStatePtr == 2) {
		thisGame->drawReplay(newHighScore);
	}
}

void ofApp::getHighScore() {
	scoreBuffer = ofBufferFromFile("savedHighScore.txt");
	highScoreStr = scoreBuffer.getText();
	highScore = ofToInt(highScoreStr);
}

void ofApp::mousePressed(int x, int y, int button) {
	mouseX = x;
	mouseY = y;
	mouseButton = button;
}

void ofApp::selectStart() {
	if (thisGame->startButton.inside(mouseX, mouseY) && mouseButton == 0) {
		*currentStatePtr = 1;
	}
}

void ofApp::isHitting() {
	if (gameBall->yPos <= player1->playerPaddle.getMaxY() && gameBall->yPos >= player1->playerPaddle.getMinY()) {
		if (gameBall->xPos <= player1->playerPaddle.getMaxX() && gameBall->xPos >= player1->playerPaddle.getMinX()) {
			gameBall->xVel *= -1.5;
			gameBall->yVel *= -1.5;
			score += 1;
		}
	}
	if (gameBall->yPos <= player2->playerPaddle.getMaxY() && gameBall->yPos >= player2->playerPaddle.getMinY()) {
		if (gameBall->xPos <= player2->playerPaddle.getMaxX() && gameBall->xPos >= player2->playerPaddle.getMinX()) {
			gameBall->xVel *= -1.5;
			gameBall->yVel *= -1.5;
		}
	}
}

void ofApp::hasReachedSides() {
	if (gameBall->xPos <= 0) {
		resetBall();
		*ballAmtPtr -= 1;
	}
	if (gameBall->xPos >= ofGetWidth()) {
		resetBall();
		score += 100;
		if (*ballAmtPtr < 5) {
			*ballAmtPtr += 1;
		}
	}
	if (gameBall->yPos <= 0 || gameBall->yPos >= ofGetHeight()) {
		gameBall->yVel *= -1;
	}
	if (*ballAmtPtr < 0) {
		*currentStatePtr = 2;
	}
}

void ofApp::resetBall() {
	gameBall->xPos = ofGetWidth() / 2;
	gameBall->yPos = ofGetHeight() / 2;
	gameBall->xVel = 2;
	gameBall->yVel = 2;
}

void ofApp::paddleConstraints() {
	if (player1->playerPaddle.getMinX() <= 0) {
		player1->playerPaddle.x += 0;
	}
	if (player1->playerPaddle.x >= ofGetWidth() / 2) {
		player1->playerPaddle.x = ofGetWidth() / 2;
	}
	if (player1->playerPaddle.getMinY() <= 0) {
		player1->playerPaddle.y += 0;
	}
	if (player1->playerPaddle.y >= ofGetHeight() - paddleHeight) {
		player1->playerPaddle.y = ofGetHeight() - paddleHeight;
	}
	if (player2->playerPaddle.getMinX() <= ofGetWidth() / 2) {
		player2->playerPaddle.x = ofGetWidth() / 2;
	}
	if (player2->playerPaddle.x >= ofGetHeight()) {
		player2->playerPaddle.x = ofGetHeight();
	}
	if (player2->playerPaddle.getMinY() <= 0) {
		player2->playerPaddle.y += 0;
	}
	if (player2->playerPaddle.y >= ofGetHeight() - paddleHeight) {
		player2->playerPaddle.y = ofGetHeight() - paddleHeight;
	}
}

void ofApp::isNewHighScore() {
	if (*scorePtr > highScore) {
		scoreBuffer.clear();
		string newScoreStr = ofToString(*scorePtr);
		scoreBuffer.set(newScoreStr);
		ofBufferToFile("savedHighScore.txt", scoreBuffer);
		newHighScore = true;
	}
	else {
		newHighScore = false;
	}
}

void ofApp::keyPressed(int key) {
	if (key == 'y' || key == 'Y') {
		*currentStatePtr = 0;
	}
	if (key == 'n' || key == 'N') {
		std::exit(0);
	}
}