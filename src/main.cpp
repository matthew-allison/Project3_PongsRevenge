#include "ofMain.h"
#include "ofApp.h"

/* Matthew Allison Project 3, Pongs Revenge Check In 2
 * So far, I have almost created the essential game parts of the game.
 * This encompasses Player 1 and Player 2 movements, and the physics of the
 * balls movement. Eventually I'm going to implement the ability to choose 
 * whether players 1 and 2 can be human controlled or computer controlled,
 * thus creating a multiplayer of sorts. I am still in the process of
 * debugging the basic mechanics of the game, but it'll hopefully be
 * completed soon.
 */

int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);
	ofRunApp(new ofApp());

}
