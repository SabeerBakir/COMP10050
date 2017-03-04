/*
 * PSfunctions.c
 *
 *  Created on: 2 Mar 2017
 *      Author: Kacper Twardowski
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "strfile.h"
#define ASIZE 100

void removeChar(char *str, char cremove){

	printf("Removal function entered\n");

	/*for(size_t i = 0; i < ASIZE; i++){
		if(str[i] == cremove){
			printf("found");
			str[i] = ' ';
		}
		printf("%c", str[i]);
	}*/

	return;
}

void slotGenerate(int slotNum, char* slotArray[], struct slot slots[])
{
	for(int i = 0; i < slotNum; i++) //Assign random types to the slots
	{
		int j = rand()%3;
		slots[i].id = i;
		strcpy(slots[i].type, slotArray[j]);
	}
}

void slotPlayerAssign(int playerNum, int slotNum, struct player players[], struct slot slots[])
{
	for(int i = 0; i < slotNum; i++) //Initialise slots as vacant
	{
		slots[i].occupied = false;
	}

	for(int i = 0; i < playerNum; i++) //Assign players to random slots
	{
		int j = rand()%slotNum;
		players[i].position = j;
		slots[j].occupied = true;
	}
}

void setupPlayer(int playerNum, struct player players[], char* class[])
{
	int playerChoice; //Variable for player choice

	for(int i = 0; i < playerNum; i++)
	{
		printf("Enter the name of player %d: ", i + 1);
		scanf(" %[^\n]", players[i].name);
		printf("\nChoose class: \n[1] Elf\n[2] Human\n[3] Ogre\n[4] Wizard\n");
		scanf(" %d", &playerChoice);
		strcpy(players[i].class, class[playerChoice - 1]);
	}
}
