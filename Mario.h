#ifndef MARIO_H
#define MARIO_H

#include <string>
#include <ctime> // to seed the random number generator
#include <cstdlib> // to seed the random number generator
using namespace std;


/**
 * Mario starts with a number of lives provided at runtime. 
 * Mario also has the ability to collect coins. He starts with 0 coins. 
 * For every 20 coins collected, he earns an extra life (and the number of coins resets to 0).
 * At any moment, Mario is in one of 3 power levels, PL0, PL1, and PL2. PL0 is the weakest and PL2 is the strongest. 
 * Mario's change in power levels occurs through different interactions briefed below.
 * 
 * Gameplay:
 * Mario will begin at a random location in the first level, with power PL0, and starts interacting with the environment immediately. 
 * Once he has interacted with the current location, he moves on to the next location by moving up, down, left, or right. 
 * The direction is chosen randomly with uniform probability (25% each). Interactions with each position occur as briefed.
*/
class Mario {
  public:
    /**
     * Default constructor. 
     * Mario starts with 0 coins, PL0, and defaults to 3 lives.
    */
    Mario();

    /**
     * Overloaded constructor. 
     * Mario starts with 0 coins, PL0, and has a custom amount of lives. 
     * @param numLives representing the amount of lives Mario has. 
    */
    Mario(unsigned int numLives); 

    /** Default destructor. */
    ~Mario();

    /**
     * Function that allows Mario to increase his power level. 
     * It checks if Mario is already at maximum, so it will not exceed PL2.
     * @return string indicating his new power level and that he has increased.
    */
    string gainPowerLevel(); 

    /**
     * Function that allows Mario to decrease his power level. 
     * It checks if Mario is already at minimum, so it will not go below PL0.
     * @return string indicating his new power level and that he has decreased.
    */
    string losePowerLevel(); // decrease power level, check if already at min

    /**
     * Function that allows Mario to interact with a coin, increasing his coin count. 
     * Checks to see if coins = 20, if so, increase power level. 
     * @return string indicating new coin count.
    */
    string interactCoin(); 

    /**
     * Function that interacts with a Goomba.
     * Mario defeats the enemy with a 80% probability, the position becomes empty, and Mario moves on. 
     * If Mario loses (20% probability), his power level is decreased by 1, 
     * the Goomba stays in the position, and Mario moves on. The exception is if Mario loses while at PL0, 
     * in which case a life is lost. If Mario has another life, he continues at the same location, with 
     * PL0. Otherwise, the simulation ends, and the game is lost.
     * @return string indicating the result of the battle.
    */
    string interactGoomba(); 

    /**
     * Function that interacts with a Koopa.
     * Mario defeats the enemy with a 65% probability, the position becomes empty, and Mario moves on. 
     * If Mario loses (35% probability), his power level is decreased by 1, 
     * the Koopa stays in the position, and Mario moves on. 
     * The exception is if Mario loses while at PL0, in which case a life
     * is lost. If Mario has another life, he continues at the same location, with
     * PL0. Otherwise, the simulation ends, and the game is lost.
     * @return string indicating the result of the battle.
    */
    string interactKoopa(); // interact koopa

    /**
     * When mario encounters a boss, he will defeat the enemy with a 50% probability. 
     * If he wins, the position becomes empty, and Mario moves on to the next level. 
     * If Mario is in the last level, the princess is saved, the game is won, and the simulation is over. 
     * If Mario loses (50% probability), his power level is decreased by 2, 
     * and Mario attempts to defeat the boss again. 
     * 
     * The exception is if Mario loses while at PL0 or PL1, in which case a life is lost. 
     * If Mario has another life, he continues at the same location, with PL0. 
     * Otherwise, the simulation ends, and the game is lost.
     * @return string indicating the result of the battle.
    */
    string interactBoss();

    /**
     * If Mario encounters the warp pipe, he will immediately jump to a random position in the 
     * next level without having to beat the current level boss.
    */
    void interactPipe();

    /**
     * Void function that moves mario to the next level. 
    */
    void nextLevel();

    /**
     * Member variable of Mario keeping track of his current power level. 
     * Public access so accessible to move function in Level class.
    */
    int currPowerLevel;

    /**
     * Member variable of Mario keeping track of his amount of lives. 
     * Public access so accessible to move function in Level class.
    */
    int numLives;

    /**
     * Member variable of Mario keeping track of his amount of coins. 
     * Public access so accessible to move function in Level class.
    */
    unsigned int numCoins;

    /**
     * public boolean of the Mario class to keep track of whether or not Mario is on a pipe/alive. 
     * To be updated to true when Mario is on a pipe or dead. It is set to true automatically.
    */
    bool inLevel;

    /**
     * static integer keeping track of the level mario is on.
    */
    static int marioCurrLevel;

  private:
    /**
     * integer keeping track of the amount of enemies mario has defeated
    */
    int enemiesDefeated;  
};

#endif