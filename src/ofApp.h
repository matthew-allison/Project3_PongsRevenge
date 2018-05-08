#pragma once

#include "ofMain.h"
#include "Paddle.h"
#include "Ball.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		bool mouseClicked;

		Paddle* player1;
		Paddle* player2;
		Ball* gameBall;
		float p1InitX;
		float* player1X;
		float p1InitY;
		float* player1Y;
		float p2InitX;
		float* player2X;
		float p2InitY;
		float* player2Y;

	private:
		
};
