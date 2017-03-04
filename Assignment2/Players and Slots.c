/*
 * Players and Slots.c
 *
 *  Created on: 24 Feb 2017
 *      Author: Sabeer(16333886) & Kacper(16401636)
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "strfile.h"

int main(void)
{
	setbuf(stdout, NULL);
	srand(time(NULL)); // Initialise the random number generator

	printf("Welcome to Crossfire!\n");

	int playerNum; // Total Number of Players
	printf("Choose the number of players (Min: 1\tMax: 6)\n");
	scanf("%d", &playerNum);

	int slotNum; // Total Number of Slots
	printf("Choose the number of slots (Min: 1\tMax: 20)\n");
	scanf("%d", &slotNum);

	struct player players[playerNum];
	char* class[4] = {"Elf", "Human", "Ogre", "Wizard"};
	char* slotTypes[3] = {"Level Ground", "Hill", "City"};

	struct slot slots[slotNum]; //Array of slots

	slotGenerate(slotNum, slotTypes, slots); //Assign random types to slots

	slotPlayerAssign(playerNum, slotNum, players, slots); //Assign players to random slots

	setupPlayer(playerNum, players, class);// Player Setup


//	for(int i = 0; i < playerNum; i++){
//		removeChar(players[i].name, '\n');
//		removeChar(players[i].class, '\n');
//	}
//	for(int i = 0; i < playerNum; i++){
//		for(int k = 0; players[i].class[k] != '\0'; k++){
//			if(players[i].class[k] == '\n'){
//				printf("found");
//			}
//			printf("%c ", players[i].class[k]);
//		}
//	}

	for(int i = 0; i < playerNum; i++)
	{
		printf("%s %s\n", players[i].name, players[i].class);
	}




	return 0;
}
