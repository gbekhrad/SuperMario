#include "Level.h"
#include "World.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
  srand(time(0)); // seed the random generator

  // Set the default values:
  int numLevels = 3; 
  int gridDimension = 5;
  int numLives = 3;
  int probCoins = 20;
  int probNothing = 20;
  int probGoombas = 20;
  int probKoopas = 20;
  int probMushrooms = 20;
 
  if (argc == 3) {
    ifstream file(argv[1]); // Open file provided in cl arg
    if (!file.is_open()) { // Check if file is open
      throw runtime_error("File DNE.");
    } else {
      string line; // Store in line 
      for(int i = 0; i < 8; i++){ // for each line in the file 
        getline(file, line); // get the line from the file 
        if (i == 0){
          numLevels = stoi(line); 
        } else if (i == 1){
          gridDimension = stoi(line);
        } else if(i == 2){
          numLives = stoi(line);
        } else if (i == 3){
          probCoins = stoi(line);
        } else if (i == 4){
          probNothing = stoi(line);
        } else if (i == 5){
          probGoombas = stoi(line);
        } else if (i == 6){
          probKoopas = stoi(line);
        } else if (i == 7){
          probMushrooms = stoi(line);
        }
      }
    } 
  }
  
  // Create the world using the parameters given.
  World myWorld = World(numLevels, gridDimension, probCoins, probNothing, probGoombas, probKoopas, probMushrooms);  
  string myOutput = myWorld.playGame(numLives);
  // Output to the file.
  ofstream outputF((argv[2]));
  if (outputF.is_open()){
    outputF << myOutput; // append the playGame string returns to the output file
    outputF.close(); // close the output file 
  } else { // Handle invalid args.
    throw runtime_error("Unable to open output file.");
  }

  return 0;
}


