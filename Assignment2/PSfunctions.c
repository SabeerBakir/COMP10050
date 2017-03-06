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

	for(int j, i = 0; i < playerNum; i++) //Assign players to random slots
	{
		j = rand()%slotNum;
		while(slots[j].occupied){
			j = rand()%slotNum;
		}
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

	statsAssign(players, class, playerNum); //Assigns random capabilities to players

	return;
}

void printDash(void){

	for(unsigned int i = 0; i < 30; i++){
		printf("-");
	}

}

void statsAssign(struct player player[], char* class[], int playerNum){

	for(unsigned int j = 0; j < playerNum; j++){
		//Checks what class the specific player has
		for(unsigned int i = 0; i < 4; i++){
			if(strcmp(player[j].class, class[i]) == 0){
				//Assigns the correct random capabilities to players based on their class	Max: [1, 100]
				switch(i){
				case 0: //Elf
					player[j].hp = 100;
					player[j].luck = rand()%(41)+60;
					player[j].smart = rand()%(31)+70;
					player[j].strength = rand()%(50)+1;
					player[j].magic = rand()%(29)+51;
					player[j].dex = rand()%(100)+1;
					break;
				case 1: //Human
					player[j].hp = 100;
					player[j].dex = rand()%(100)+1;
					player[j].luck = rand()%(100)+1;
					if((player[j].dex+player[j].luck)>102){
						player[j].magic = rand()%(100)+1;
					}
					else{
						player[j].magic = rand()%(98)+1;
					}
					player[j].smart = rand()%(299-player[j].dex-player[j].luck-player[j].magic-1)+1;
					if(player[j].smart > 100){ // [1,100]
						player[j].smart = 100;
					}
					player[j].strength = rand()%(299-player[j].dex-player[j].luck-player[j].magic-player[j].smart)+1;
					if(player[j].strength > 100){ // [1,100]
						player[j].strength = 100;
					}
					break;
				case 2: //Ogre
					player[j].hp = 100;
					player[j].magic = 0;
					//Max sum of luck and smartness
					player[j].smart = rand()%(20)+1;
					player[j].luck = rand()%(50-player[j].smart)+1;
					player[j].dex = rand()%(21)+80;
					player[j].strength = rand()%(21)+80;
					break;
				case 3: //Wizards
					player[j].hp = 100;
					player[j].smart = rand()%(11)+90;
					player[j].luck = rand()%(51)+50;
					player[j].magic = rand()%(21)+80;
					player[j].strength = rand()%(20)+1;
					player[j].dex = rand()%(100)+1;
					break;
				}
			}
		}
	}
	return;
}

void movePlayer(struct player players[], struct slot slots[],int slotNum,int choice, int i)
{
	int direction;

	if((slots[players[i].position - 1].occupied == true) && (slots[players[i].position + 1].occupied == true))
	{
		printf("You can't move anywhere.\n");
		choice = 2;
	}
	else if((slots[players[i].position - 1].occupied == true) && (players[i].position == slotNum - 1))
	{
		printf("You can't move anywhere.\n");
		choice = 2;
	}
	else if((slots[players[i].position + 1].occupied == true) && (players[i].position == 0))
	{
		printf("You can't move anywhere.\n");
		choice = 2;
	}
	else if((slots[players[i].position - 1].occupied == true) || (players[i].position == 0))
	{
		slots[players[i].position].occupied = false;
		players[i].position++;
		slots[players[i].position].occupied = true;
		printf("Cannot move left. You have moved to the right.\n");
	}
	else if((slots[players[i].position + 1].occupied == true) || (players[i].position == slotNum - 1))
	{
		slots[players[i].position].occupied = false;
		players[i].position--;
		slots[players[i].position].occupied = true;
		printf("Cannot move right. You have moved to the left.\n");
	}
	else
	{
		printf("[1] Left\n[2] Right\n");
		scanf("%d", &direction);
		if(direction == 1)
		{
			slots[players[i].position].occupied = false;
			players[i].position--;
			slots[players[i].position].occupied = true;
			printf("You have moved to the left.\n");
		}
		else if(direction == 2)
		{
			slots[players[i].position].occupied = false;
			players[i].position++;
			slots[players[i].position].occupied = true;
			printf("You have moved to the right.\n");
		}
	}

}

int endGame(struct player players[], int playerNum)
{
	int endgame = 0;
	int deadPlayers = 0;

	for(int i = 0; i < playerNum; i++)
	{
		if(players[i].hp == 0)
		{
			deadPlayers++;
		}
	}

	if(deadPlayers == playerNum - 1)
	{
		endgame = 1;
	}

	return endgame;
}









