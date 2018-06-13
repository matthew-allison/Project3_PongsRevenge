#pragma once

#include "ofMain.h"
#include "Paddle.h"
#include "Ball.h"
#include "GameState.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void getHighScore();
		void mousePressed(int x, int y, int button);
		void selectStart();
		void isHitting();
		void hasReachedSides();
		void resetBall();
		void paddleConstraints();
		void isNewHighScore();
		void keyPressed(int key);

		Paddle* player1;
		Paddle* player2;
		Ball* gameBall;
		GameState* thisGame;
		int* scorePtr;
		int* ballAmtPtr;
		string highScoreStr;
		bool newHighScore;

	private:
		int currentState;
		int score;
		int ballAmt;
		int highScore;
		int* currentStatePtr;
		int mouseX;
		int mouseY;
		int mouseButton;
		ofBuffer scoreBuffer;
		
};
