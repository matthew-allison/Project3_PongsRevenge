#pragma once

#include "ofMain.h"
#include "Paddle.h"
#include "Ball.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void isHitting(Paddle* p1, Paddle* p2);
		bool mouseClicked;

		Paddle* player1;
		Paddle* player2;
		Ball* gameBall;
		bool* ballHitPaddle;
		bool ballHitSides;

	private:
		
};
