#include "Mario.h"
#include "Level.h"

int Mario::marioCurrLevel = 0; // Mario's current level is defaulted to 0. To be share across all instances of a Mario object.

Mario::Mario() {
  inLevel = true; // Automatically set to true because Mario is automatically in play. 
  enemiesDefeated = 0; // Mario is yet to defeat any enemies. 
  numCoins = 0;  // start at 0
  currPowerLevel = 0; // mario's current power level is PL0
  numLives = 3; // set numLives to 3 by default
}

Mario::Mario(unsigned int numLives) {
  inLevel = true; // Automatically set to true because Mario is automatically in play. 
  enemiesDefeated = 0;
  numCoins = 0;                   // start at 0
  currPowerLevel = 0; // mario's current power level is PL0
  this->numLives = numLives;      // set numLives

}

Mario::~Mario(){}

string Mario::gainPowerLevel() {
  if (currPowerLevel == 0) { // if mario's power level is PL0
    currPowerLevel = 1; // set power level to PL1
    return "Mario's current power level is now PL1.";
  } else if (currPowerLevel == 1) { // if mario's power level is PL1
    currPowerLevel = 2; // set power level to PL2
    return "Mario's current power level is now PL2.";
  } else if (currPowerLevel == 2) { // if mario's power level is PL2
    return "Mario is already at the maximum power level, no increase.";
  } else {
    return "If this is reached, there's a problem gaining pl.";
  }
} // increase power level, check if already at max

void Mario::nextLevel(){
  marioCurrLevel++;
}

string Mario::losePowerLevel() { 
  if (currPowerLevel == 0) {
    return "Mario is already at the minimum power level, no decrease.";
  } else if (currPowerLevel == 1) {
    currPowerLevel = 0;
    return "Mario's current power level is now PL0.";
  } else if (currPowerLevel == 2) {
    currPowerLevel = 1;
    return "Mario's current power level is now PL1.";
  } else {
    return "If this is reached, there's a problem losing pl.";
  }
}

string Mario::interactCoin() {
  if (numCoins < 20) {
    numCoins += 1;
  } else if (numCoins == 20) { // If mario has 20 coins,
    numLives += 1; // Increase the number of lives
    numCoins = 0; // and reset numCoins.
    enemiesDefeated = 0; // This variable has to be reset to 0 as mario changes numLives and can no longer be eligible to gain a life from killing 7 enemies. 
  }
  return "";
}

string Mario::interactKoopa() { 
  string log; // keep track of activity log

  int random = rand() % 101; // Generate probability

  if (random <= 65) { // Mario has 65% chance of defeating a koopa
    // Mario defeats the enemy but nothing is changed, except Mario moves on.
    enemiesDefeated++; // increase the amount of enemies mario has defeated
    log += "Mario defeated the Koopa!";
  } else { // Mario loses at a 35% chance, there are 1 of 2 options:
    if (currPowerLevel == 0 && numLives > 1) { // if mario is already at the lowest power level and he has more lives to spare
      numLives -= 1; // mario loses a life
      enemiesDefeated = 0; // This variable has to be reset to 0 as mario changes numLives and can no longer be eligible to gain a life from killing 7 enemies.
      log += "Mario lost the battle. His power level was already at minimum, so Mario lost a life.";
    } else if (currPowerLevel == 0 && numLives == 1) { // Mario is at the lowest power level and he has no lives to spare
      numLives -= 1; // Mario loses his last life.
      // we can reset enemies defeated here to 0 but its not entirely necessary
      log += "Mario lost the battle, game over!";
    } else { // Mario has power levels to lose
      losePowerLevel();
      log += "Mario lost the battle, his power level is now " + to_string(currPowerLevel);
    }
  }

  if (enemiesDefeated == 7){ // before we return log, we must check if mario has defeated 7 enemies on the same life. if so,
    numLives++; // increment num lives.
    enemiesDefeated = 0; // and reset enemies defeated to 0.
    log += "Mario has defeated 7 enemies on the same life and has therefore gained a life.\n";
  } // else, carry on!

  return log;
}

string Mario::interactGoomba() { 
  string log; 
  
  int random = rand() % 101;

  if (random <= 80) { // Mario has 80% chance of defeating a Goomba
    // Mario defeats the enemy but nothing is changed, except Mario moves on.
    enemiesDefeated++; // increase the amount of enemies mario has defeated
    log += "Mario defeated the goomba."; 
  } else { // Mario loses at a 20% chance
    if (currPowerLevel == 0 && numLives > 1) { // if mario is already at the lowest power level and he has more lives to spare
      numLives -= 1;
      enemiesDefeated = 0; // This variable has to be reset to 0 as mario changes numLives and can no longer be eligible to gain a life from killing 7 enemies.
      log += "Mario lost the battle. His power level was already at minimum, so Mario lost a life.";
    } else if (currPowerLevel == 0 && numLives == 1) { // Mario is at the lowest power level and he has no lives to spare
      numLives -= 1; // Mario loses his last life.
      // we can reset enemies defeated here to 0 but its not entirely necessary
      log += "Mario lost the battle, game over!"; 
    } else { // Mario has power levels to lose
      losePowerLevel();
      log += "Mario lost the battle, he now is at power level " + to_string(currPowerLevel);
    }
  }

  if (enemiesDefeated == 7){ // before we return log, we must check if mario has defeated 7 enemies on the same life. if so,
    numLives++; // increment num lives.
    enemiesDefeated = 0; // and reset enemies defeated to 0.
    log += "Mario has defeated 7 enemies on the same life and has therefore gained a life.\n";
  } // else, carry on!

  return log; 
}

string Mario::interactBoss(){
  string log; // String keeping track of the log to be returned.
  
  int random = rand() % 2; // Random number, it can be either 0 or 1 with equal probability. 

  if (random == 0){ // If Mario wins,
    // Mario moves on to the next level
    log += "Mario beat the boss!\n";
    enemiesDefeated++;
    nextLevel();
    inLevel = false;
  } else if (random == 1){ // If Mario loses,
    if (currPowerLevel == 2){ // If PL2,
      losePowerLevel();
      losePowerLevel(); // Set to PL0
      log += "Mario lost to the boss! He will attempt to fight him again. Mario's power level is now " + to_string(currPowerLevel) + ".\n";
    } else if (currPowerLevel == 1){ // If at PL1
      losePowerLevel(); // Set to PL0
      numLives -= 1; // Power down
      enemiesDefeated = 0; // This variable has to be reset to 0 as mario changes numLives and can no longer be eligible to gain a life from killing 7 enemies.
      log += "Mario lost to the boss and lost a life! He will attempt to fight him again. Mario's power level is now 0 and he has " + to_string(numLives) + " lives!\n";
    } else if (currPowerLevel == 0) { // If at PL0
      numLives -= 1;
      enemiesDefeated = 0; // This variable has to be reset to 0 as mario changes numLives and can no longer be eligible to gain a life from killing 7 enemies.
      log += "Mario lost to the boss and lost a life! He will attempt to fight him again. Mario's power level is now 0 and he has " + to_string(numLives) + " lives!\n";
    } 
    if (numLives == 0){
      log += "Mario lost to the boss and has no lives left.\n";
    }
  }

  if (enemiesDefeated == 7){ // before we return log, we must check if mario has defeated 7 enemies on the same life. if so,
    numLives++; // increment num lives.
    enemiesDefeated = 0; // and reset enemies defeated to 0.
    log += "Mario has defeated 7 enemies on the same life and has therefore gained a life.\n";
  } // else, carry on!
  return log;
}

void Mario::interactPipe(){
  inLevel = false; // If mario interacts with a pipe, he is no longer in the level. This will cause him to move on. 
}