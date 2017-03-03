/*
 * Players and Slots.c
 *
 *  Created on: 24 Feb 2017
 *      Author: Sabeer(16333886) & Kacper(16401636)
 */
#include <stdio.h>
#include <string.h>
#include "strfile.h"

int main(void)
{
	setbuf(stdout, NULL);

	int playerChoice; // choice of variable

	printf("Welcome to Crossfire!\n");

	int playerNum; // Total Number of Players
	printf("Choose the number of players (Min: 1\tMax: 6)\n");
	scanf("%d", &playerNum);

	struct player players[6];
	char* class[4] = {"Elf", "Human", "Ogre", "Wizard"};

	// Player Setup
	for(int i = 0; i < playerNum; i++)
	{
		printf("Enter the name of player %d: ", i + 1);
		scanf(" %[^\n]", players[i].name);
		printf("\nChoose class: \n[1] Elf\n[2] Human\n[3] Ogre\n[4] Wizard\n");
		scanf(" %d", &playerChoice);
		strcpy(players[i].class, class[playerChoice - 1]);
	}

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
		printf("%s%s\n", players[i].name, players[i].class);
	}




	return 0;
}
