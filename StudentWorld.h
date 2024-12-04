#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

// ============================== FORWARD DECLARATIONS ============================== //

class Actor;
class Earth;
class Tunnelman;

// ============================== CLASS DEFINITION ============================== //

class StudentWorld : public GameWorld
{
	public:
		// Constructor and Destructor
		StudentWorld(std::string assetDir);
		~StudentWorld() { cleanUp(); }

		// Required functions

		virtual int init();
		virtual int move();
		virtual void cleanUp();
		
		// Additional functions

		void setDisplayText(); // Helper for updating game stats
		void removeEarth(int x, int y);

	private:

		// Data structures for world representations
		std::unique_ptr<Tunnelman> m_player; // Holds pointer to main Tunnelman object
		std::unique_ptr<Earth> m_earth[VIEW_WIDTH][60]; // Holds Earth objects
		std::vector<std::unique_ptr<Actor>> m_actors; // Holds all other Actors in the game

};

#endif // STUDENTWORLD_H_
