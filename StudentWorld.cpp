#include "StudentWorld.h"
#include "Actor.h"
#include <string>
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

// ============================== CONSTRUCTOR ============================== //

StudentWorld:: StudentWorld(string assetDir) : GameWorld(assetDir) {
	for (int x = 0; x < VIEW_WIDTH; ++x) {
		for (int y = 0; y < 60; ++y) {
			m_earth[x][y];
		}
	}
}

// ============================== INITIALIZATION FUNCTION ============================== //

int StudentWorld:: init() {

	// Initialize Tunnelman
	m_player = std::make_unique<Tunnelman>(this);

	// Create Earth field
	for (int x = 0; x < VIEW_WIDTH; ++x) {
		for (int y = 0; y < 60; ++y) {
			if ((x >= 30 && x < 34) && (y >= 0 && y < 60)) {
				m_earth[x][y] = std::make_unique<Earth>(this, x, y);
				m_earth[x][y]->setVisible(false);

			} else {
				m_earth[x][y] = std::make_unique<Earth>(this, x, y);
			}
		}
	}

	return GWSTATUS_CONTINUE_GAME;
	
}

// ============================== MOVE FUNCTION ============================== //

int StudentWorld:: move() {

	// ---------- TESTING ---------- //

	//setGameStatText("Poop");

	m_player->doSomething();
	return GWSTATUS_CONTINUE_GAME;

	// ---------- GIVEN PSEUDOCODE ---------- //

	// Update the Game Status Line

	// CALL DOSOMETHING() ON EACH OBJECT
	// for each object in our data structure
		// if object is alive
			// object.doSomething
			// if Tunnelman died
				// return PLAYER_DIED

			// if Tunnelman completed level
				// return FINISHED_LEVEL

	// REMOVE NEWLY DEAD OBJECTS
	// removeDeadObjects()

	// RETURN PROPER RESULT
	// if Tunnelman died
		// return PLAYER_DIED
	// if Tunnelman completed level
		// play finished sound
		// return FINISHED_LEVEL
}

// ============================== CLEAN UP FUNCTION ============================== //

void StudentWorld:: cleanUp() {
	// Clean up Tunnelman
	m_player.reset(); 

	// Clean up Earth array
	for (int x = 0; x < VIEW_WIDTH; ++x) {
        for (int y = 0; y < 60; ++y) {
            m_earth[x][y].reset(); 
        }
    }

	m_actors.clear();
}

// ============================== ADDITIONAL FUNCTIONS ============================== //

void StudentWorld::setDisplayText() {
	int level = GameWorld::getLevel();
	int lives = GameWorld::getLives();
	int score = GameWorld::getScore();

	int health = 0; // TO DO
	int squirts = 0; // TO DO
	int gold = 0; // TO DO
	int barrelsLeft = 0; // TO DO
	int sonar = 0; // TO DO

	// CREATE A STRING OF FORM
	// Lvl: 52  Lives: 3  Hlth: 80%  Wtr: 20  Gld: 3  Oil Left: 2  Sonar: 1  Scr: 321000

	// CALL UP UPDATE TEXT FUNC
	// set

}

void StudentWorld:: removeEarth(int x, int y) {
	for (int i = x; i < x + 4; ++i) {
		for (int j = y; j < y + 4; ++j) {
			if ((i >= 0 && i < VIEW_WIDTH) && (j >= 0 && j < 60)) {
				m_earth[i][j]->setVisible(false);
	
			}
		}
	}
}
