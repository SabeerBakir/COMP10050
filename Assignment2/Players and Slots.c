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
	printf("Choose the number of players\t(Min: 1\tMax: 6)\n");
	scanf("%d", &playerNum);

	int slotNum; // Total Number of Slots
	printf("Choose the number of slots\t(Min: %d\tMax: 20)\n", playerNum);
	scanf("%d", &slotNum);
	if(slotNum < playerNum){
		slotNum = playerNum;
		printf("The number of slots has been set to the minimum\n");
	}
	if(slotNum > 20){
		slotNum = 20;
		printf("The number of slots has been set to the maximum\n");
	}
	puts("");

	struct player players[playerNum];
	char* class[4] = {"Elf", "Human", "Ogre", "Wizard"};
	char* slotTypes[3] = {"Level Ground", "Hill", "City"};

	struct slot slots[slotNum]; //Array of slots

	slotGenerate(slotNum, slotTypes, slots); //Assign random types to slots

	slotPlayerAssign(playerNum, slotNum, players, slots); //Assign players to random slots

	setupPlayer(playerNum, players, class); //Player Setup



	//Displays Player Info
	puts("All Players:");
	for(int i = 0; i < playerNum; i++)
	{
		//statsAssign(players[i], class); //Function to assign capabilities
		printDash();
		printf("\n");
		printf("Player %d\nName: %sClass: %s\n", i+1, players[i].name, players[i].class);
		printf("=== STATS ===\nMagic: %u\nSmartness: %u\nStrength: %u\nDexterity: %u\nLuck: %u\n", players[i].magic, players[i].smart, players[i].strength, players[i].dex, players[i].luck);
	}
	printDash();

	return 0;
}
