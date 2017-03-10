/*
 * strfile.h
 *
 *  Created on: 25 Feb 2017
 *      Author: Kacper Twardowski
 */

#ifndef STRFILE_H_
#define STRFILE_H_
#define ASIZE 100
#include <stdbool.h>

//Player Data Structure - stats and names
struct player{

	char name[ASIZE];		//Player name
	char class[ASIZE];		//Player class
	int hp;					//Player life points
	int magic;				//Player magic skills
	int smart;				//Player smartness
	int strength;			//Player strength
	int dex;				//Player dexterity
	int luck;				//Player luck
	int position;			//Player position

};

//Slot Data Structure - id, type and state
struct slot{

	int id;					//Slot identification number
	char type[ASIZE];		//Slot type
	_Bool occupied;			//Slot occupied (true or false)

};

//Generate slots function
void slotGenerate(int slotNum, char* slotArray[], struct slot slots[]);

//Assign players to slots
void slotPlayerAssign(int playerNum, int slotNum, struct player players[], struct slot slots[]);

//Setup Players
void setupPlayer(int playerNum, struct player players[], char* class[]);

//Prints Dashes
void printDash(void);

//Assigns Capabilities to Players
void statsAssign(struct player player[], char* class[], int playerNum);

//Move Function
void movePlayer(struct player players[], struct slot slots[], int slotNum, int *choice, int i);

//Attack Function
void attackPlayer(struct player players[], struct slot slots[], int *choice, int i, int playerNum);

//Function to determine the end of the game
int endGame(struct player players[], int playerNum);

//Function to change the player stats when they move to a new slot
void movePlayerStats(struct slot slots[], struct player players[], char* slotTypes[], int i);

//Function to check if a stat exceeds boundaries (i.e [0, 100])
void statsCheck(int *a);

//Move dead players to a graveyard
void graveyard(struct player players[], struct slot slots[], int dead);

#endif /* STRFILE_H_ */
