#ifndef LEVEL_H
#define LEVEL_H

#include "Mario.h"
#include <iostream>
#include <ctime> // to seed the random number generator
#include <cstdlib> // to seed the random number generator

/**
 * Each level in the game is represented by an NxN grid, with N provided at
 * runtime. Mario may navigate the grid by moving up, down, left, and right
 * only. The grid wraps horizontally and vertically (a torus).
 */
class Level {
  public:
    /**
     * Default constructor.
     * Automatically creates a 10 by 10 level, with a 20% chance of a space being
     * a coin, 20% nothing, 20% a goomba, 20% a koopa, and 20% a mushroom.
     */
    Level();

    /**
     * Overloaded constructor.
     * @param gridDimension the width and height of the grid/level.
     * @param probCoins the probability of the space being a coin
     * @param probNothing the probability of the space being nothing
     * @param probGoombas the probability of the space being a goomba
     * @param probKoopas the probability of the space being a koopa
     * @param probMushrooms the probability of the space being a mushroom
     */
    Level(int gridDimension, int probCoins, int probNothing, int probGoombas,
          int probKoopas, int probMushrooms);

    /**
     * Default destructor.
     */
    ~Level();

    /**
     * The printLevel function loops through the grid of the level, formatted
     * correctly.
     * @return string representation of the level.
     */
    string printLevel();

    /**
     * Function that represents the movemenent of Mario. It generates a random
     * number between 0 and 3, and then uses that to determine the direction Mario
     * will move.
     * @param mario the Mario object that will move.
     * @return string logging the movement of Mario.
     */
    string move(Mario *marioObj);

    /**
     * This function places Mario after the level has been constructed.
     * Necessary to call in World constructor because Levels have to be printed at the beginning of the program without Mario.
     * @param gridDimension to make sure Mario is being correcly placed and in-bounds. 
    */
    void placeMario(int gridDimension); 

    /**
     * This function places Pipe after the level has been constructed.
     * Necessary to call in World constructor because Levels all have a pipe except the final level.
    */
    void placePipe();

    /**
     * Function that gets the gridDimension.
     * @return int represenation of the gridDimension
    */
    int getGridDimension();
  private:
    /**
     * Private member variable indicating both the width and height of the 2D
     * array (dimenstions of grid representation of the level)
     */
    int gridDimension;

    /**
     * Pointer to a 2D char array of unfixed size. Size is given during runtime.
     */
    char **grid;
};

#endif