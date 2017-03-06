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
		printf("Player %d\nName: %s\nClass: %s\n", i+1, players[i].name, players[i].class);
		printf("=== STATS ===\nMagic: %d\nSmartness: %d\nStrength: %d\nDexterity: %d\nLuck: %d\n", players[i].magic, players[i].smart, players[i].strength, players[i].dex, players[i].luck);
		printf("=== SLOTS ===\nStart: %d\n", players[i].position + 1);
	}
	printDash();

	printf("\n=== BEGIN! ===\n");

	int choice;
	while(endGame(players, playerNum) == 0)
	{
		for(int i = 0; i < playerNum; i++)
		{
			printf("%s: Would you like to: \n[1]Move\n[2]Attack?\n", players[i].name);
			scanf("%d", &choice);

			if(choice == 1)
			{
				movePlayer(players, slots, slotNum, choice, i);
				movePlayerStats(slots, players, slotTypes, i);
				printf("You are now in slot: %d\n", players[i].position + 1);
			}
			else if(choice == 2)
			{

			}
			printDash();
			printf("\n");
		}
	}
	return 0;
}
