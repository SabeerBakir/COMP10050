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

	struct player players[6];
	char* class[4] = {"Elf", "Human", "Ogre", "Wizard"};
	int i;
	int choice; // choice of variable

	printf("Welcome to Crossfire!\n");

	for(i = 0; i < 6; i++)
	{
		printf("Enter the name of player %d: ", i + 1);
		fgets(players[i].name, ASIZE, stdin);
		printf("Choose class: \n[1] Elf\n[2] Human\n[3] Ogre\n[4] Wizard\n");
		scanf("%d", &choice);
		strcpy(players[i].class, class[choice - 1]);
	}

	for(i = 0; i < 6; i++)
	{
		printf("%s %10s\n", players[i].name, players[i].class);
	}




	return 0;
}

