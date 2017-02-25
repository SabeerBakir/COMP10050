/*
 * strfile.h
 *
 *  Created on: 25 Feb 2017
 *      Author: Kacper Twardowski
 */

#ifndef STRFILE_H_
#define STRFILE_H_
#define ASIZE 100

//Player Data Structure - stats and names
struct players{

	char name[ASIZE];		//Player name
	char class[ASIZE];		//Player class
	unsigned int hp;		//Player life points
	unsigned int magic;		//Player magic skills
	unsigned int smart;		//Player smartness
	unsigned int strenght;	//Player strength
	unsigned int dex;		//Player dexterity
	unsigned int luck;		//Player luck

};

#endif /* STRFILE_H_ */
