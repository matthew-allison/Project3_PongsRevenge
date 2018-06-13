#pragma once
#include "ofMain.h"

class GameState {
public:
	GameState();
	void drawStart(string highScoreStr);
	void drawGame(int score, int remBalls);
	void drawReplay(bool isNewHighScore);

	ofRectangle startButton;
	ofRectangle replayButton;

private:
	int highScore;
	int finalScore;
	int thisState;
	ofFile savedHighScore;
	ofBuffer scoreBuffer;
	ofTrueTypeFont buttonFont;
	ofTrueTypeFont highScoreFont;
	ofTrueTypeFont scoreFont;
	ofTrueTypeFont smallFont;
};
