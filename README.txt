Gabriella Bekhrad
gabimbek@gmail.com
Commit: 4/17/2024

Source Files:
  - main.cpp
  - Level.h
  - Level.cpp
  - World.h
  - World.cpp
  - Mario.h
  - Mario.cpp

Instructions to run:
  g++ *.cpp
  ./a.out [inputFileName].txt [outputFileName.txt]

Sources:
  https://cplusplus.com/reference/string/stoi/  

High Level Overview: 
Main class inherits world and level classes. 
In the main class, we take in the input file, take out the parameters provided in it and pass those to create our world. 
World inherets level and has an array which stores level objects called levels.
 The paramters which include gridDimension, probCoins, etc. are used to Populate each level (nxn array) 
 with the different types of objects based on the probability of a given index being said object. 
 The level class which inherets Mario also provides each level with a boss. 
 We also have 2 methods in Level.cpp 'placePipe' and 'placeMario' which insert a single mario object onto an already existing level, 
 and single warp pipe into levels before they are outputed except for the final level. 
 The Mario class has methods for interacting with all the different objects and also keeps track of his lives, coins, etc. 
 and enacts the different functions associated with those items such as adding a life every 20 coins.

The programs input file follows the following specifications 
(a command line argument text file of the following format):
Line # 1 is the number of levels, L (a positive integer)
Line # 2 is the dimension of the grid, N (a positive integer)
Line # 3 is the number of initial lives, V (a positive integer)
Line # 4 is the approximate percentage of the positions in each level with coins (a positive integer)
Line # 5 is the approximate percentage of the positions in each level with nothing (a positive integer)
Line # 6 is the approximate percentage of the positions in each level with Goombas (a positive integer)
Line # 7 is the approximate percentage of the positions in each level with Koopas (a positive integer)
Line # 8 is the approximate percentage of the positions in each level with mushrooms (a positive integer)
