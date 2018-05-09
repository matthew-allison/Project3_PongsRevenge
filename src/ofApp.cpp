#include "ofApp.h"
#include <iostream>

using namespace std;

const int paddleWidth = 10;
const int paddleHeight = 100;

void ofApp::setup(){
	ofSetBackgroundColor(0, 0, 50);
	ofColor white(255, 255, 255);
	player1 = new Paddle(10, ofGetHeight() / 2, "human", paddleWidth, paddleHeight, ofGetWidth(), ofGetHeight(), white, "player1");
	player2 = new Paddle(ofGetWidth() - 20, ofGetHeight() / 2, "computer", paddleWidth, paddleHeight, ofGetWidth(), ofGetHeight(), white, "player2");
	gameBall = new Ball(ofGetWidth(), ofGetHeight(), white, .5, 0.5);
}

void ofApp::update(){
	player1->playerMove(ofGetMouseX(), ofGetMouseY(), gameBall->ballPos);
	player2->playerMove(ofGetMouseX(), ofGetMouseY(), gameBall->ballPos);
	isHitting(player1, player2);
}

void ofApp::draw(){
	player1->drawPlayer();
	player2->drawPlayer();
	gameBall->drawBall();

}

void ofApp::isHitting(Paddle* p1, Paddle* p2) {
	ofPoint restartBall(ofGetWidth() / 2, ofGetHeight() / 2);
	ofRectangle p1Rect(p1->playerPaddle);
	ofRectangle p2Rect(p2->playerPaddle);
	if (p1Rect.inside(gameBall->ballPos) || p2Rect.inside(gameBall->ballPos)) {
		gameBall->xVel *= -1;
		gameBall->yVel *= -1;
	}
	if (gameBall->ballPos.x <= 0 + gameBall->ballRadius || gameBall->ballPos.x >= ofGetWidth() - gameBall->ballRadius) {
		gameBall->ballPos = restartBall;
	}
	if (gameBall->ballPos.y <= 0 + gameBall->ballRadius || gameBall->ballPos.y >= ofGetHeight() - gameBall->ballRadius) {
		gameBall->yVel *= -1;
	}
}
