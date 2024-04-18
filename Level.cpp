#include "Level.h"

Level::Level() {
  gridDimension = 10; // Dimension of grid is 10x10 by default

  // Creating a new array of just default nothings ('x')
  grid = new char *[10];
  for (int i = 0; i < 10; ++i) {
    grid[i] = new char[10];
    for (int j = 0; j < 10; ++j) {
      grid[i][j] = 'x';
    }
  }

  int i = 0;
  char currentIndex; // to keep track of the index that the random lands on

  // Default probabilities of 20. Randomize the index of coins.
  while (i < 20) {
    int row = rand() % gridDimension;
    int col = rand() % gridDimension;
    currentIndex = grid[row][col];
    if (currentIndex == 'x') {
      grid[row][col] = 'c'; // Override with c.
      i++;
    }
  }

  // Override with goombas
  i = 0;
  while (i < 20) {
    int row = rand() % gridDimension;
    int col = rand() % gridDimension;
    currentIndex = grid[row][col];
    if (currentIndex == 'x') {
      grid[row][col] = 'g'; // Override with g
      i++;
    }
  }

  // Override with koopa, 20% chance
  i = 0;
  while (i < 20) {
    int row = rand() % gridDimension;
    int col = rand() % gridDimension;
    currentIndex = grid[row][col];
    if (currentIndex == 'x') {
      grid[row][col] = 'k'; // Override with k
      i++;
    }
  }

  // 20% chance of mushroom
  i = 0;
  while (i < 20) {
    int row = rand() % gridDimension;
    int col = rand() % gridDimension;
    currentIndex = grid[row][col];
    if (currentIndex == 'x') {
      grid[row][col] = 'm'; // Override with m
      i++;
    }
  }

  // Now time to place Boss and Pipe. 
  // Generate a random location to place the boss and the pipe. Note that they cannot be placed in the same location.

  // generate 2 random indices 
  int randRow;
  int randCol;

  // Run this block of code again for placing the pipe. 
  // This involves re-genenerating indices 
  while(true){
    randRow = rand() % gridDimension;
    randCol = rand() % gridDimension; 

    // Place Pipe if nothing else is conflicting. 
    if (grid[randRow][randCol] != 'H' &&
        grid[randRow][randCol] != 'w' &&
        grid[randRow][randCol] != 'b'){
            grid[randRow][randCol] = 'w';
            break;
    } else {
      continue; // if it doesnt work out, try again!
    }
  }

  // Run this block of code again for placing the boss. 
  // This involves re-genenerating indices 
  while(true){
    randRow = rand() % gridDimension;
    randCol = rand() % gridDimension; 

    // Place boss if nothing else is conflicting. 
    if (grid[randRow][randCol] != 'H' &&
        grid[randRow][randCol] != 'w' &&
        grid[randRow][randCol] != 'b'){
            grid[randRow][randCol] = 'b';
            break;
    } else {
      continue; // if it doesnt work out, try again!
    }
  }
}

Level::Level(int gridDimension, int probCoins, int probNothing, int probGoombas, int probKoopas, int probMushrooms) {
  this->gridDimension = gridDimension; // This initializes the size of the array to be stored in the object.
  // Creating the grid based on parameters provided
  grid = new char *[gridDimension];
  for (int i = 0; i < gridDimension; ++i) {
    grid[i] = new char[gridDimension];
    for (int j = 0; j < gridDimension; ++j) {
      grid[i][j] = 'x';
    }
  }

  int i = 0;
  char currentIndex; // to keep track of the index that the random lands on

  // Override each of the nothing spaces with custom probabilities, provided at runtime.

  while (i < (double(probCoins / 100.0) * (gridDimension * gridDimension))) {
    int row = rand() % gridDimension;
    int col = rand() % gridDimension;
    currentIndex = grid[row][col];
    if (currentIndex == 'x') {
      grid[row][col] = 'c'; // override
      i++;
    }
  }

  i = 0;
  while (i < (double(probGoombas / 100.0) * (gridDimension * gridDimension))) {
    int row = rand() % gridDimension;
    int col = rand() % gridDimension;
    currentIndex = grid[row][col];
    if (currentIndex == 'x') {
      grid[row][col] = 'g'; // override 
      i++;
    }
  }
  i = 0;
  while (i < (double(probKoopas / 100.0) * (gridDimension * gridDimension))) {
    int row = rand() % gridDimension;
    int col = rand() % gridDimension;
    currentIndex = grid[row][col];
    if (currentIndex == 'x') {
      grid[row][col] = 'k'; // override
      i++;
    }
  }
  i = 0;
  while (i < (double(probMushrooms / 100.0) * (gridDimension * gridDimension))) {
    int row = rand() % gridDimension;
    int col = rand() % gridDimension;
    currentIndex = grid[row][col];
    if (currentIndex == 'x') {
      grid[row][col] = 'm'; // override 
      i++;
    }
  }
  
  // Now time to place Boss. 
  // Generate a random location to place the boss.

  // generate 2 random indices 
  int randRow;
  int randCol;

  // Run this block of code again for placing the boss. 
  // This involves re-genenerating indices 
  while(true){
    randRow = rand() % gridDimension;
    randCol = rand() % gridDimension; 

    // Place Pipe if nothing else is conflicting. 
    if (grid[randRow][randCol] != 'H' &&
        grid[randRow][randCol] != 'w' &&
        grid[randRow][randCol] != 'b'){
            grid[randRow][randCol] = 'b';
            break;
    } else {
      continue; 
    }
  }
}

Level::~Level() {
  ; // Level to be destructed through world class destructor. 
}

void Level::placeMario(int gridDimension){
  // Create random numbers (for indices based on the grid dimension)
  // Run this block of code for placing Mario. 
  while(true){
    int randRow = rand() % gridDimension;
    int randCol = rand() % gridDimension; // Generating a random from 0 to the grid size.

      // Place mario if nothing else is conflicting. 
    if (grid[randRow][randCol] != 'H' &&
        grid[randRow][randCol] != 'w' &&
        grid[randRow][randCol] != 'b'){ // if its not already populated with the 1-of-a-kind items,
          grid[randRow][randCol] = 'H'; // Place mario and break
          break;
    } else { // If the rand indices do have the object,
      continue; // try again.
    }
  }
}

int Level::getGridDimension(){
  return gridDimension;
}

void Level::placePipe(){
  // Create random numbers
  // Run this block of code again for placing the pipe. 
  while(true){
    int randRow = rand() % gridDimension;
    int randCol = rand() % gridDimension; // Generating a random from 0 to the grid size.

    // Place Pipe if nothing else is conflicting. 
    if (grid[randRow][randCol] != 'H' &&
        grid[randRow][randCol] != 'w' &&
        grid[randRow][randCol] != 'b'){ // if its not already populated with the 1-of-a-kind items,
            grid[randRow][randCol] = 'w'; // Place pipe and break
            break;
    } else { // If the rand indices do have the object,
      continue; // try again.
    }
  }
}

string Level::printLevel() {
  string printedGrid; // a string to keep track of the grid to print and return.

  for (int i = 0; i < gridDimension; ++i) {
    for (int j = 0; j < gridDimension; ++j) { // for every element in the grid,
      printedGrid += grid[i][j];              // Print the element.
      printedGrid += " "; // This is just for formatting purposes.
    }
    printedGrid += "\n";
  }
  return printedGrid; // return the full grid.
}

string Level::move(Mario* marioObj) {
  // String keeping track of Mario's position and his interactions with the
  // environment. To be returned once the function completes.
    string motionLog = "";

    int currY;
    int currX;
    int nextY;
    int nextX;

    for (int j = 0; j < gridDimension; ++j) {
        for (int i = 0; i < gridDimension; ++i) {
            if (grid[j][i] == 'H') {
                currY = j;
                currX = i;
                break; // stop searching after the position is found
            }
        }
    }

    motionLog += "Mario's current position is row " + to_string(currY + 1) + ", column " + to_string(currX + 1) + ".\n" 
                  + "His current power level is PL" + to_string(marioObj->currPowerLevel) + ".\n";

    int random = rand() % 4; // Generate 25% chances for a direction to move in. 

    if (random == 0) {  // Move up
        if (currY != 0) {
          nextX = currX;
          nextY = currY - 1;
        } else if (currY == 0){
          nextX = currX;
          nextY = gridDimension-1; // this makes the array "circular"
        }
        if (grid[nextY][nextX] == 'c') {
            motionLog += "Mario will move up. He found a coin." + marioObj->interactCoin() + "\n";
        } else if (grid[nextY][nextX] == 'g') {
            motionLog += "Mario will move up. He found a goomba.\n" + marioObj->interactGoomba() + "\n";
        } else if (grid[nextY][nextX] == 'k') {
            motionLog += "Mario will move up. He found a koopa.\n" + marioObj->interactKoopa() + "\n";
        } else if (grid[nextY][nextX] == 'm') {
            motionLog += "Mario will move up. He found a mushroom.\n" + marioObj->gainPowerLevel() + "\n";
        } else if (grid[nextY][nextX] == 'x') {
            motionLog += "Mario will move up. He found nothing :(\n";
        } else if (grid[nextY][nextX] == 'w') {
            motionLog += "Mario will move up, reach a pipe, and warp to the next level.\n";
            marioObj->interactPipe();
        } else if (grid[nextY][nextX] == 'b'){
            motionLog += "Mario will move up. He found a boss.\n" + marioObj->interactBoss();
        }
        grid[nextY][nextX] = 'H';
        grid[currY][currX] = 'x';
        currX = nextX;
        currY = nextY; // Mario moves on.
    } else if (random == 1) {  // Move down
        if (currY != gridDimension - 1) {
          nextX = currX;
          nextY = currY + 1;
        } else if (currY == gridDimension - 1){
          nextX = currX;
          nextY = 0; // this makes the array "circular"
        }
        if (grid[nextY][nextX] == 'c') {
            motionLog += "Mario will move down. He found a coin." + marioObj->interactCoin() + "\n";
        } else if (grid[nextY][nextX] == 'g') {
            motionLog += "Mario will move down. He found a goomba.\n" + marioObj->interactGoomba() + "\n";
        } else if (grid[nextY][nextX] == 'k') {
            motionLog += "Mario will move down. He found a koopa.\n" + marioObj->interactKoopa() + "\n";
        } else if (grid[nextY][nextX] == 'm') {
            motionLog += "Mario will move down. He found a mushroom.\n"+marioObj->gainPowerLevel() + "\n";
        } else if (grid[nextY][nextX] == 'x') {
            motionLog += "Mario will move down. He found nothing :(\n";
        } else if (grid[nextY][nextX] == 'w') {
            motionLog += "Mario will move down, reach a pipe, and warp to the next level.\n";
            marioObj->interactPipe();
        } else if (grid[nextY][nextX] == 'b'){
            motionLog += "Mario will move up. He found a boss.\n" + marioObj->interactBoss();
        }
        grid[nextY][nextX] = 'H';
        grid[currY][currX] = 'x';
        currX = nextX;
        currY = nextY; // Mario moves on.
    } else if (random == 2) {  // Move right
        if (currX != gridDimension - 1) {
            nextX = currX + 1;
            nextY = currY;
        } else if (currX == gridDimension-1){
          nextX = 0;
          nextY = currY; // this makes the array "circular"
        }
        if (grid[nextY][nextX] == 'c') {
            motionLog += "Mario will move right. He found a coin." + marioObj->interactCoin() + "\n";
        } else if (grid[nextY][nextX] == 'g') {
            motionLog += "Mario will move right. He found a goomba.\n" + marioObj->interactGoomba() + "\n";
        } else if (grid[nextY][nextX] == 'k') {
            motionLog += "Mario will move right. He found a koopa.\n" + marioObj->interactKoopa() + "\n";
        } else if (grid[nextY][nextX] == 'm') {
            motionLog += "Mario will move right. He found a mushroom.\n" + marioObj->gainPowerLevel() + "\n";
        } else if (grid[nextY][nextX] == 'x') {
            motionLog += "Mario will move right. He found nothing :(\n";
        } else if (grid[nextY][nextX] == 'w') {
            motionLog += "Mario will move right, reached a pipe, and warp to the next level.\n";
            marioObj->interactPipe();
        } else if (grid[nextY][nextX] == 'b'){
            motionLog += "Mario will move up. He found a boss.\n" + marioObj->interactBoss();
        }
        grid[nextY][nextX] = 'H';
        grid[currY][currX] = 'x';
        currX = nextX;
        currY = nextY; // Mario moves on.
    } else if (random == 3) {  // Move left
        if (currX != 0) {
          nextX = currX - 1;
          nextY = currY;
        } else if (currX == 0){
          nextX = gridDimension - 1;
          nextY = currY; // this makes the array "circular"
        }
        if (grid[nextY][nextX] == 'c') {
            motionLog += "Mario will move left. He found a coin." + marioObj->interactCoin() + "\n";
        } else if (grid[nextY][nextX] == 'g') {
            motionLog += "Mario will move left. He found a goomba.\n" + marioObj->interactGoomba() + "\n";
        } else if (grid[nextY][nextX] == 'k') {
            motionLog += "Mario will move left. He found a koopa.\n" + marioObj->interactKoopa() + "\n";
        } else if (grid[nextY][nextX] == 'm') {
            motionLog += "Mario will move left. He found a mushroom.\n" + marioObj->gainPowerLevel() + "\n";
        } else if (grid[nextY][nextX] == 'x') {
            motionLog += "Mario will move left. He found nothing :(\n";
        } else if (grid[nextY][nextX] == 'w') {
            motionLog += "Mario will move left, reach a pipe, and warp to the next level.\n";
            marioObj->interactPipe();
        } else if (grid[nextY][nextX] == 'b'){
            motionLog += "Mario will move up. He found a boss.\n" + marioObj->interactBoss();
        } 
        grid[nextY][nextX] = 'H';
        grid[currY][currX] = 'x';
        currX = nextX;
        currY = nextY; // Mario moves on.
    } 
    motionLog += "Mario has " + to_string(marioObj->numLives) + " lives and " + to_string(marioObj->numCoins) + " coin(s).\n";
    return motionLog; // Return everything Mario did that move!
}