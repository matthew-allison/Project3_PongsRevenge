#include "ofMain.h"
#include "ofApp.h"

/* Matthew Allison Project 3, Pongs Revenge
 * This game is a new take on pong. It begins with a start screen showing
 * the previous high score, and when the start button is clicked the game begins.
 * Player 1 is controlled by the mouse, and player 2 is controlled by the computer.
 * Every time the player hits the ball with their paddle, a point is scored.
 * If the ball reaches the opponents side, the player scores 100 points and gets
 * an extra ball. The player begins the game with a ball on the field and 2 back-ups.
 * When the ball reaches the players side of the field, they lose a remaining ball.
 * When the counter hits 0, if the ball reaches the players side again, the game is over.
 * If the player has acheived a new high score, their score is saved for the next time.
 * The player then has the choice whether to replay the game or not.
 */

int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);
	ofRunApp(new ofApp());

}
