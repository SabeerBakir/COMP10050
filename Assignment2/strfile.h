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
	unsigned int hp;		//Player life points
	unsigned int magic;		//Player magic skills
	unsigned int smart;		//Player smartness
	unsigned int strength;	//Player strength
	unsigned int dex;		//Player dexterity
	unsigned int luck;		//Player luck
	int position;			//Player position

};

//Slot Data Structure - id and type
struct slot{

	int id;					//Slot identification number
	char type[ASIZE];		//Slot type
	_Bool occupied;			//Slot occupied (true or false)

};

//Character removal function
void removeChar(char *str, char cremove);

//Generate slots function
void slotGenerate(int slotNum, char* slotArray[], struct slot slots[]);

//Assign players to slots
void slotPlayerAssign(int playerNum, int slotNum, struct player players[], struct slot slots[]);

//Setup Players
void setupPlayer(int playerNum, struct player players[], char* class[]);

#endif /* STRFILE_H_ */
