#include "GameState.h"

GameState::GameState() {
	buttonFont.load("Animal Silence.otf", 100);
	highScoreFont.load("a_d_mono.ttf", 75);
	scoreFont.load("a_d_mono.ttf", 40);
	smallFont.load("Animal Silence.otf", 30);
	startButton.setFromCenter(ofGetWidth() * 0.5, ofGetHeight() * 0.33, 500, 200);
	replayButton.setFromCenter(ofGetWidth() * 0.51, ofGetHeight() * 0.53, 700, 150);
}

void GameState::drawStart(string highScoreStr) {
	ofSetColor(0, 179, 0);
	ofDrawRectangle(startButton);
	ofSetColor(0, 0, 0);
	buttonFont.drawString("START", ofGetWidth() * 0.29, ofGetHeight() * 0.40);
	ofSetColor(255, 255, 255);
	highScoreFont.drawString("HIGH SCORE:", ofGetWidth() * 0.26, ofGetHeight() * 0.65);
	highScoreFont.drawString(highScoreStr, ofGetWidth() * 0.26, ofGetHeight() * 0.80);	
}

void GameState::drawGame(int score, int remBalls) {
	string scoreStr = "SCORE: " + ofToString(score);
	string ballStr = "Remaning: " + ofToString(remBalls);
	ofSetColor(255, 255, 255);
	scoreFont.drawString(scoreStr, ofGetWidth() * 0.42, ofGetHeight() * 0.08);
	scoreFont.drawString(ballStr, ofGetWidth() * 0.02, ofGetHeight() * 0.08);
}

void GameState::drawReplay(bool isNewHighScore) {
	ofSetColor(0, 179, 0);
	ofDrawRectangle(replayButton);
	ofSetColor(255, 255, 255);
	buttonFont.drawString("REPLAY?", ofGetWidth() * 0.20, ofGetHeight() * 0.60);
	smallFont.drawString("Press y for Yes, n for No", ofGetWidth() * 0.25, ofGetHeight() * 0.70);
	if (isNewHighScore) {
		ofSetColor(255, 255, 0);
		highScoreFont.drawString("NEW HIGH SCORE!", ofGetWidth() * 0.18, ofGetHeight() * 0.35);
	}
}
