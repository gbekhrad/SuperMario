#include "World.h"

World::World(){
  numLevels = 3; // Default amount of levels is 3.
  currLevel = 1; // CurrLevel starts at 1.

  levels = new Level[3]; // create levels array of size 1
  for (int i = 0; i < numLevels; ++i){
    levels[i] = Level(); // Construct default levels.
  }
}

World::World(int numLevels, int gridDimension, int probCoins, int probNothing, int probGoombas, int probKoopas, int probMushrooms){
  this->numLevels = numLevels; 

  currLevel = 1; // The current level is index 0 of the array of levels. 
  levels = new Level[numLevels]; // reassigning the size of levels

  for (int i = 0; i < numLevels - 1; ++i) {
    levels[i] = Level(gridDimension, probCoins, probNothing, probGoombas, probKoopas, probMushrooms);
    levels[i].placePipe(); // Place a pipe on every level except the final one.
  }
  // On the final level, create a regular level object without a pipe.
  levels[numLevels - 1] = Level(gridDimension, probCoins, probNothing, probGoombas, probKoopas, probMushrooms);
}

World::~World() {
  delete[] levels; // delete the array of level objects. 
}

string World::playGame(int numLives){ // 3 is the default value of lives, but it can be overwritten.
  string log = ""; // This will keep track of the log of gameplay. 
  int numMoves; //keeping track of the amount of moves taken.
  Mario *marioObj = new Mario(numLives); // Creates a Mario object with a custom amount of lives. 

  // Print world
  for (int i = 0; i < numLevels; ++i){ // For each level in the world,
    log += "Level: " + to_string(i + 1); // Print the level number 
    log += "\n" + levels[i].printLevel() + "\n"; // And the level itself
  }

  for (int i = 0; i < numLevels; ++i){ // For each level in the world,
    
    marioObj->inLevel = true; // Reset inLevel to true when a new level begins.
    levels[i].placeMario(levels[i].getGridDimension());// Drop mario into the world

    while (marioObj->inLevel){ // While Mario is in the level,
      if (marioObj->numLives == 0){ // If he's dead
        break;
      } else {
        while (true){ // loop through this until prior if statement is reached or all levels have passed.
          log += "Current Level: " + to_string(i+1) + "\n"+levels[i].printLevel(); 
          log += levels[i].move(marioObj) + "\n"; 
          numMoves++; // a move was made, so increment the tracker.
          break;
        }
      }
    }
  }
  if (marioObj->numLives != 0){ // If Mario beats the final level and is alive,
    log += "The princess is saved in " + to_string(numMoves) + " moves!\n";
  } else {
    log += "The princess was not saved. Moves taken: " + to_string(numMoves) + "\n";
  }
  return log;
}