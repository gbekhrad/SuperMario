#ifndef WORLD_H
#define WORLD_H

#include "Level.h"

/**
 * The world consists of a number of levels, numLevels, which will be provided at runtime. 
 * To finish the game, Mario must navigate from level 1 to level L by defeating intermediate bosses and defeat 
 * the final boss in level L. If Mario runs out of lives before this task is accomplished, the game is lost.
*/
class World {
    public: 
        /**
         * Default world constructor. 
         * numLevels is automatically 3, and levels are created by default as well.
        */
        World(); 

        /**
         * Overloaded world constructor.
         * @param numLevels number of levels in the world
         * @param gridDimension the dimension of each level
         * @param probCoins the probability of the space being a coin
         * @param probNothing the probability of the space being nothing
         * @param probGoombas the probability of the space being a goomba
         * @param probKoopas the probability of the space being a koopa
         * @param probMushrooms the probability of the space being a mushroom
         */
        World(int numLevels, int gridDimension, int probCoins, int probNothing, int probGoombas, int probKoopas, int probMushrooms);
        
        /** Default destructor. */
        ~World(); 

        /**
         * Function that runs all the rules of the gameplay in its entirety.
         * @param numLives to represent the amount of lives mario has in the game.
         * @return string representation of the entire gameplay.
        */
        string playGame(int numLives); // Print the level at int currlevel index

    private:
        /**
         * int represenatation of the number of levels in a world.
        */
        unsigned int numLevels;

        /**
         * int represenation of the current level mario is on.
        */
        unsigned int currLevel; 

        /**
         * Pointer to a mario object that is used in the world.
        */
        Mario* marioObj;

        /**
         * Array to hold all of the Level objects in the world.
        */
        Level* levels;
};

#endif

