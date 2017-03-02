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

void removeChar(char *str, char cremove){

	printf("Removal function entered\n");

	char *pr = str, *pw = str;
	while(*pr){
		*pw = *pr++;
		pw += (*pw != cremove);
	}
	*pw = '\0';

	return;
}
