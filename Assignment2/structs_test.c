/*
 * structs_test.c
 *
 *  Created on: 25 Feb 2017
 *      Author: Kacper Twardowski
 */

//APPARENTLY THE CONVENTION IS TO PUT THE STRUCTURES IN HEADER FILES

//SOME RANDOM PSEUDO CODE, DW ABOUT IT

/*
 *
int main() {
	int original[10];
	newarr = modify(&original, 200);

}

int* modify(int * arr, int incremental) {
	res = (int*)malloc(sizeof(arr) + incremental);
	// do stuff with res
	return res;
}

int search(Player* arr, int numOfPlayers, char c) {
	int i;
	for (i = 0; i < numOfPlayers, i++) {

		Player PlayerCopy = arr[i];

		// i want the name
		if (PlayerCopy.name[2] == c) {
			// do stuff
			return i;
		}

	}
 *
 *
 */


//		fgets(players[i].name, ASIZE, stdin);
//		char * name = NULL;
//		size_t len;
//		if (getline(&name, &len, stdin) != -1) {
//			strcpy(players[i].name,name);
//		} else {
//			printf("this is error, break your programme!");
//		}
