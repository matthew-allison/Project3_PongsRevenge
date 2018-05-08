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
	gameBall = new Ball(ofGetWidth(), ofGetHeight(), white);
}

void ofApp::update(){
	player1->playerMove(ofGetMouseX(), ofGetMouseY(), gameBall->updateX(), gameBall->updateY());
	player2->playerMove(ofGetMouseX(), ofGetMouseY(), gameBall->updateX(), gameBall->updateY());
	gameBall->moveBall();
	gameBall->ballCollision(player1->ballHit(), player2->ballHit());
}

void ofApp::draw(){
	player1->drawPlayer();
	player2->drawPlayer();
	gameBall->drawBall();

}