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
				case 2: //Shrek
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

void movePlayer(struct player players[], struct slot slots[], int slotNum, int *choice, int i)
{
	int direction;

	if((slots[players[i].position - 1].occupied == true) && (slots[players[i].position + 1].occupied == true))
	{
		printf("You can't move anywhere. You must attack!\n");
		*choice = 2;
	}
	else if((slots[players[i].position - 1].occupied == true) && (players[i].position == slotNum - 1))
	{
		printf("You can't move anywhere. You must attack!\n");
		*choice = 2;
	}
	else if((slots[players[i].position + 1].occupied == true) && (players[i].position == 0))
	{
		printf("You can't move anywhere. You must attack!\n");
		*choice = 2;
	}
	else if((slots[players[i].position - 1].occupied == true) || (players[i].position == 0))
	{
		slots[players[i].position].occupied = false;
		players[i].position++;
		slots[players[i].position].occupied = true;
		printf("Cannot move left. You have moved to the right ( %s ).\n", slots[players[i].position].type);
	}
	else if((slots[players[i].position + 1].occupied == true) || (players[i].position == slotNum - 1))
	{
		slots[players[i].position].occupied = false;
		players[i].position--;
		slots[players[i].position].occupied = true;
		printf("Cannot move right. You have moved to the left ( %s ).\n", slots[players[i].position].type);
	}
	else
	{
		printf("[1] Left ( %s )\n[2] Right ( %s )\n", slots[players[i].position - 1].type, slots[players[i].position + 1].type);
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

void movePlayerStats(struct slot slots[], struct player players[], char* slotTypes[], int i)
{
	if(strcmp(slots[players[i].position].type, slotTypes[0]) == 0)
	{
		printf("Your stats remain unchanged.\n");
	}
	else if(strcmp(slots[players[i].position].type, slotTypes[1]) == 0)
	{
		if(players[i].dex < 50)
		{
			players[i].strength -= 10;
			statsCheck(&players[i].strength);
			printf("Lost 10 strength points! You now have %d.\n", players[i].strength);
		}
		else if(players[i].dex >= 60)
		{
			players[i].strength += 10;
			statsCheck(&players[i].strength);
			printf("Gained 10 strength points! You now have %d.\n", players[i].strength);
		}
		else
		{
			printf("Your stats remain unchanged.\n");
		}
	}
	else if(strcmp(slots[players[i].position].type, slotTypes[2]) == 0)
	{
		if(players[i].smart > 60)
		{
			players[i].magic += 10;
			statsCheck(&players[i].magic);
			printf("Gained 10 magic points! You now have %d.\n", players[i].magic);
		}
		else if(players[i].smart <= 50)
		{
			players[i].dex -= 10;
			statsCheck(&players[i].dex);
			printf("Lost 10 dexterity points! You now have %d.\n", players[i].dex);
		}
	}
}

void statsCheck(int *a)
{
	if(*a < 0)
	{
		*a = 0;
	}
	else if(*a > 100)
	{
		*a = 100;
	}
	else
	{
		//Do nothing
	}
	return;
}

void attackPlayer(struct player players[], struct slot slots[], int *choice, int i, int playerNum){

	_Bool playerLeft = false;
	_Bool playerRight = false;

	if(slots[players[i].position-1].occupied){
		playerLeft = true;
		//printf("l = true\n");
	}
	if(slots[players[i].position+1].occupied){
		playerRight = true;
		//printf("r = true\n");
	}

	if(playerLeft && !playerRight){		// Player to the left
		printf("You decided to attack the player to your left in slot %d\n", players[i].position-1+1);
		for(int k = 0; k < playerNum; k++){
			if(players[i].position-1 == players[k].position){
				if(players[k].strength <= 70){
					players[k].hp -= (players[k].strength*5)/10;
					if(players[k].hp <= 0){
						players[k].hp = 0;
						graveyard(players, slots, k);
					}
				}
				if(players[k].strength > 70){
					players[i].hp -= (players[k].strength*3)/10;
					if(players[i].hp <= 0){
						players[i].hp = 0;
						graveyard(players, slots, k);
					}
				}
			}
		}
	}
	if(!playerLeft && playerRight){		// Player to the right
		printf("You decided to attack the player to your right in slot %d\n", players[i].position+1+1);
		for(int k = 0; k < playerNum; k++){
			if(players[i].position+1 == players[k].position){
				if(players[k].strength <= 70){
					players[k].hp -= (players[k].strength*5)/10;
					if(players[k].hp <= 0){
						players[k].hp = 0;
						graveyard(players, slots, k);
					}
				}
				if(players[k].strength > 70){
					players[i].hp -= (players[k].strength*3)/10;
					if(players[i].hp <= 0){
						players[i].hp = 0;
						graveyard(players, slots, k);
					}
				}
			}
		}
	}
	if(playerLeft && playerRight){		// Players to both left and right
		int lrchoice = 0;
		printf("You have a choice between attacking the player to your left (slot %d) and to your right (slot %d)\n", players[i].position-1+1, players[i].position+1+1);
		printf("[1]Left\n[2]Right\n");
		scanf("%d", &lrchoice);
		if(lrchoice == 1){
			printf("You decided to attack the player to your left in slot %d\n", players[i].position-1);
			for(int k = 0; k < playerNum; k++){
				if(players[i].position-1 == players[k].position){
					if(players[k].strength <= 70){
						players[k].hp -= (players[k].strength*5)/10;
						if(players[k].hp <= 0){
							players[k].hp = 0;
							graveyard(players, slots, k);
						}
					}
					if(players[k].strength > 70){
						players[i].hp -= (players[k].strength*3)/10;
						if(players[i].hp <= 0){
							players[i].hp = 0;
							graveyard(players, slots, k);
						}
					}
				}
			}
		}
		if(lrchoice == 2){
			printf("You decided to attack the player to your right in slot %d\n", players[i].position+1+1);
			for(int k = 0; k < playerNum; k++){
				if(players[i].position+1 == players[k].position){
					if(players[k].strength <= 70){
						players[k].hp -= (players[k].strength*5)/10;
						if(players[k].hp <= 0){
							players[k].hp = 0;
							graveyard(players, slots, k);
						}
					}
					if(players[k].strength > 70){
						players[i].hp -= (players[k].strength*3)/10;
						if(players[i].hp <= 0){
							players[i].hp = 0;
							graveyard(players, slots, k);
						}
					}
				}
			}
		}
	}
	if(!playerLeft && !playerRight){	// No players around
		printf("There are no players nearby for you to attack, you must move!\n");
		*choice = 3;
	}
}

void graveyard(struct player players[], struct slot slots[], int dead){

	//If the player is dead, move him to his own slot in the "Graveyard" and de-occupy his previous slot
	if(players[dead].hp <= 0){
		slots[players[dead].position].occupied = false;
		players[dead].position += 20+dead;
	}

}
