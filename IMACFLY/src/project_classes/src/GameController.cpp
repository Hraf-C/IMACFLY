#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include "project_classes/GameController.hpp"
#include "project_classes/Arrival.hpp"
#include "project_classes/Ground.hpp"
#include "project_classes/Coin.hpp"
#include "project_classes/Gap.hpp"
#include "project_classes/Block.hpp"
#include "project_classes/Skblock.hpp"
#include "project_classes/Player.hpp"
#include "project_classes/Exception.hpp"

GameController::GameController(Level* level){
	_level = level;
}

int GameController::loadLevel(){

	FILE *level_file;

	/*open file*/
	level_file = fopen(_level->getSourceFile().c_str(), "r");
	
	

	try {
	    if (level_file == NULL){
	      Exception err1(1,2,"Erreur de chargement du fichier");
	      throw err1;
	    }
	} 
	catch(const Exception &err){
		std::cerr << "Exception lancée : " << std::endl << "Niveau : " << err.getLevel() << std::endl << "Code : " << err.getCode() << std::endl << err.what() << std::endl;
	}

	/* ppm file management */
	
	char line[64];
	int r, g, b;
	int width, height, color_max;


	try {
	    if (fgets(line, sizeof line, level_file) == NULL){
	      Exception err1(1,2,"Exit - fgets");
	      throw err1;
	    }
	} 
	catch(const Exception &err){
		std::cerr << "Exception lancée : " << std::endl << "Niveau : " << err.getLevel() << std::endl << "Code : " << err.getCode() << std::endl << err.what() << std::endl;
	}

	

	try {
	    if (strcmp(line, "P3\n") != 0){
	      Exception err1(1,2,"Format du fichier non pris en charge");
	      throw err1;
	    }
	} 
	catch(const Exception &err){
		std::cerr << "Exception lancée : " << std::endl << "Niveau : " << err.getLevel() << std::endl << "Code : " << err.getCode() << std::endl << err.what() << std::endl;
	}

	

	try {
	    if (fgets(line, sizeof line, level_file) == NULL){
	      Exception err1(1,2,"Exit - fgets");
	      throw err1;
	    }
	} 
	catch(const Exception &err){
		std::cerr << "Exception lancée : " << std::endl << "Niveau : " << err.getLevel() << std::endl << "Code : " << err.getCode() << std::endl << err.what() << std::endl;
	}

	

	try {
	    if (line[0] == '#') {
		 	if (fgets(line, sizeof line, level_file) == NULL) {
		      Exception err1(1,2,"Exit - fgets");
		      throw err1;
		    }
		}
	} 
	catch(const Exception &err){
		std::cerr << "Exception lancée : " << std::endl << "Niveau : " << err.getLevel() << std::endl << "Code : " << err.getCode() << std::endl << err.what() << std::endl;
	}

	sscanf(line, "%d %d", &width, &height);

	_level->setSizeX(width);
	_level->setSizeX(height);

	

	try {
	    if (fgets(line, sizeof line, level_file) == NULL){
	      Exception err1(1,2,"Exit - fgets");
	      throw err1;
	    }
	} 
	catch(const Exception &err){
		std::cerr << "Exception lancée : " << std::endl << "Niveau : " << err.getLevel() << std::endl << "Code : " << err.getCode() << std::endl << err.what() << std::endl;
	}
	
	sscanf(line, "%d", &color_max);

	std::vector<Cell*> cells; // Vector of all blocks, skyblock, arrivals (any cube to display)
	std::vector<Block*> blocks; // Vector of blocks
	std::vector<Skblock*> skyblock; // Vector of skyblock
	std::vector<Arrival*> arrivals; // Vector of arrivals
	std::vector<Coin*> coins; // Vector of coins
	std::vector<Cell*> leftTurns; // Vector of leftTurns
	std::vector<Cell*> rightTurns; // Vector of rightTurns

	Cell * cell; // Temporary cell

	for (unsigned int i = 0; i < height; ++i) {
		for (unsigned int j = 0; j < width; ++j) {
		  	if (fgets(line, sizeof line, level_file) == NULL)
		    	return 0;
		  	sscanf(line, "%d", &r);
		  	if (fgets(line, sizeof line, level_file) == NULL)
		    	return 0;
		  	sscanf(line, "%d", &g);
		  	if (fgets(line, sizeof line, level_file) == NULL)
		  		return 0;
		  	sscanf(line, "%d", &b);
		  
		  	if (r != 255 || g != 255 || b != 255) {
		  	// ------ DEPARTURE & ARRIVAL -----
		    	if (r == 255 && g == 50 && b == 255) {
		    	   	/* Arrival - Magenta */
		      		arrivals.push_back(new Arrival('f',1.f, 1.f, (float)i, (float)j, 0.f));
		    	}
		    	if (r == 100 && g == 50 && b == 200) {
		      		/* Departure - Purple*/
		      		Player player('p', 1, 1, (float)i, (float)j, 1, 0.2, "Toto", 0, 1, 1, float(i));
		      		_level->setPlayer(player);
		      		cells.push_back(new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f));
		    	}

		  	// ------ GROUND -----
	    		if (r == 100 && g == 0 && b == 0) {
	      			/* Ground - Dark brown */
		      		cells.push_back(new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f));
		    	}
		    	if (r == 255 && g == 150 && b == 0) {
		      		/* Ground + coin 1 - Light Yellow */
		      		cells.push_back(new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f));
		      		coins.push_back(new Coin('c',1.f, 1.f, (float)i, (float)j, 1.f, 10));
		    	}

		    	if (r == 255 && g == 255 && b == 0) {
		      		/* Ground + coin 2 - Yellow */
		      		cells.push_back(new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f));
		      		coins.push_back(new Coin('c',1.f, 1.f, (float)i, (float)j, 2.f, 10));
		    	}

		    	if (r == 150 && g == 150 && b == 0) {
		      		/* TurnLeft - Brown */
		      		cell = new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f);
		      		leftTurns.push_back(cell);
		      		cells.push_back(cell);	
		    	}

		    	if (r == 150 && g == 50 && b == 0) {
		      		/* TurnRight - Light Brown */
		      		cell = new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f);
		      		rightTurns.push_back(cell);
		      		cells.push_back(cell);
		    	}

		  	// ------ HOLE -----
		    	if (r == 0 && g == 0 && b == 0) {
		      		/* Gap - Grey */
		    	}
		    	if (r == 100 && g == 100 && b == 100) {
		      		/* Gap + coin 2 - Black */
		      		coins.push_back(new Coin('c',1.f, 1.f, (float)i, (float)j, 2.f, 10));
		   		}

		  	// ------ BLOCK -----
		    	if (r == 50 && g == 200 && b == 255) {
		      		/* Block + coin 2 - Light blue */
		      		cells.push_back(new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f));
		    		blocks.push_back(new Block('b',1.f, 1.f, (float)i, (float)j, 1.f));
		      		coins.push_back(new Coin('c',1.f, 1.f, (float)i, (float)j, 2.f, 10));
		    	}

		    	if (r == 0 && g == 0 && b == 255) {
		      		/* Block - Blue */
		    		cells.push_back(new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f));
		    		blocks.push_back(new Block('b',1.f, 1.f, (float)i, (float)j, 1.f));
		    	}

		  	// ------ skyblock -----
		    	if (r == 0 && g == 255 && b == 0) {
		      		/* skyblock - Green */
		    		cells.push_back(new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f));
		    		skyblock.push_back(new Skblock('b',1.f, 1.f, (float)i, (float)j, 2.f));
		    	}

		    	if (r == 50 && g == 150 && b == 0) {
		      		/* skyblock + coin 1- Dark green */
		    		cells.push_back(new Ground('g',1.f, 1.f, (float)i, (float)j, 0.f));
		    		skyblock.push_back(new Skblock('b',1.f, 1.f, (float)i, (float)j, 2.f));
		    		coins.push_back(new Coin('c',1.f, 1.f, (float)i, (float)j, 1.f, 10));
		    	}
		  	}
		}
	}
	fclose (level_file);
	_level->setCells(cells);
	_level->setCoins(coins);
	_level->setBlocks(blocks);
	_level->setSkyblock(skyblock);
	_level->setArrivals(arrivals);
	_level->setLeftTurns(leftTurns);
	_level->setRightTurns(rightTurns);
}

bool GameController::checkAABBCollision(const Player &a, const Object &b){
   //check the X axis
   if(abs(a.getPosX() - b.getPosX()) < 1) {
      //check the Y axis
      if(abs(a.getPosY() - b.getPosY()) < 1) {
          //check the Z axis
          if(abs(a.getPosZ() - b.getPosZ()) < 1) {
             return true;
          }
      }
   }
   return false;
}

bool GameController::check2DAABBCollision(const Player &a, const Object &b){
   //check the X axis
   if(abs(a.getPosX() - b.getPosX()) < 1) {
      //check the Y axis
      if(abs(a.getPosY() - b.getPosY()) < 1) {
      	return true;
      }
   }
   return false;
}