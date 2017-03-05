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

void slotPlayerAssign(int playerNum, int slotNum, struct player players[], struct slot slots[]) //TO BE FIXED
{
	for(int i = 0; i < slotNum; i++) //Initialise slots as vacant
	{
		slots[i].occupied = false;
	}

	for(int i = 0; i < playerNum; i++) //Assign players to random slots	TO BE FIXED
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
		//Function to assign capabilities
		statsAssign(players, class);
	}
}

void printDash(void){

	for(unsigned int i = 0; i < 30; i++){
		printf("-");
	}

}

void statsAssign(struct player player[], char* class[]){

	//Checks what class the specific player has
	for(unsigned int i = 0; i < 4; i++){
		if(strcmp(player.class, class[i]) == 0){
			//Assigns the correct random capabilities to players based on their class
			switch(i){
			case 0: //Elf	GOTTA FIX THIS
				player->hp = 100;
				player->strength = rand()%(50)+1;
				player->magic = rand()%(29)+51;
				player->luck = rand()%(300-60-player.strength-player.magic-70)+60;
				player->smart = rand()%(300-70-player.strength-player.magic-player.luck)+70;
				player->dex = rand()%(300-player.strength-player.magic-player.luck-player->smart)+1;
				break;
			case 1: //Human	FIXED
				player->hp = 100;
				player->dex = rand()%(100)+1;
				player->luck = rand()%(100)+1;
				if((player.dex+player.luck)>102){
					player->magic = rand()%(100)+1;
				}
				else{
					player->magic = rand()%(98)+1;
				}
				player->smart = rand()%(299-player.dex-player.luck-player.magic-1)+1;
				player->strength = rand()%(299-player.dex-player.luck-player.magic-player.smart)+1;
				break;
			case 2: //Ogre	GOTTA FIX THIS
				player->hp = 100;
				player->magic = 0;
				//Max sum of luck and smartness
				player->smart = rand()%(20)+1;
				player->luck = rand()%(50-player.smart)+1;
				player->dex = rand()%(50)+80;
				player->strength = rand()%(player.dex)+80;
				break;
			case 3: //Wizards	GOTTA FIX THIS
				player->hp = 100;
				player->smart = rand()%(300-50-90-80)+90;
				player->luck = rand()%(300-50-player.smart-80)+50;
				player->magic = rand()%(300-player.luck-player.smart-80)+80;
				player->strength = rand()%(20)+1;
				player->dex = rand()%(300-player.luck-player.smart-player.magic-player.strength)+1;
				break;
			}
		}
	}

}
