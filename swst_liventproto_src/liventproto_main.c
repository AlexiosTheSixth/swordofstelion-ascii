#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/*
Prototype to iterate on and test the living entity systems.
*/

char mainmap[10][10] = {{6,6,6,6,2,2,2,6,6,6}, {2,2,2,2,2,2,2,2,2,6}, {1,1,1,1,1,1,1,2,2,2}, {1,1,1,1,9,9,9,9,9,9},
{1,1,9,9,9,9,11,11,11,11}, {1,1,9,9,9,11,11,11,11,11}, {1,1,9,9,9,11,11,11,11,11}, {1,1,9,9,9,11,11,11,11,11},
{5,1,1,9,9,9,11,11,11,11}, {5,5,1,1,9,9,9,11,11,11}};


// Formerly cameraman
int adthinikos[2] = {4,2};

int gamestate;

// Text commands
char input[50];



void adthinikosstand() {

// Get terrain the adthinikos is standing on

switch(mainmap[adthinikos[0]][adthinikos[1]]) {
case 1:
printf("You are standing on some short grass.");
break;
case 2:
printf("You are standing in some tall grass.");
break;
case 3:
printf("You are standing on a patch of dirt.");
break;
case 4:
printf("You are standing in mud.");
break;
case 5:
printf("You are standing in a very small stream.");
break;
case 6:
printf("You are wading in waist deep water.");
break;
case 7:
printf("You are wading in neck deep water.");
break;
case 8:
printf("You are swimming in water too deep to stand in.");
break;
case 9:
printf("You are standing on some very rough rocky terrain.");
break;
case 10:
printf("You are standing on gravel.");
break;
case 11:
printf("How did you get here? Get down!");
break;
case 12:
printf("You are standing inside of a tree trunk somehow.");
break;
case 0:
printf("You are standing in the void... turn... back...");
break;
default:
printf("You don't know what you are standing on.");}
}

void printmap_kiverian() {
printf("=[O]========================================[0]=\n");
printf("  | [%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d] | \n",mainmap[0][0],mainmap[0][1],mainmap[0][2],mainmap[0][3],mainmap[0][4],mainmap[0][5],mainmap[0][6],mainmap[0][7],mainmap[0][8],mainmap[0][9]);
printf("  | [%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d] | \n",mainmap[1][0],mainmap[1][1],mainmap[1][2],mainmap[1][3],mainmap[1][4],mainmap[1][5],mainmap[1][6],mainmap[1][7],mainmap[1][8],mainmap[1][9]);
printf("  | [%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d] | \n",mainmap[2][0],mainmap[2][1],mainmap[2][2],mainmap[2][3],mainmap[2][4],mainmap[2][5],mainmap[2][6],mainmap[2][7],mainmap[2][8],mainmap[2][9]);
printf("  | [%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d] | \n",mainmap[3][0],mainmap[3][1],mainmap[3][2],mainmap[3][3],mainmap[3][4],mainmap[3][5],mainmap[3][6],mainmap[3][7],mainmap[3][8],mainmap[3][9]);
printf("  | [%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d] | \n",mainmap[4][0],mainmap[4][1],mainmap[4][2],mainmap[4][3],mainmap[4][4],mainmap[4][5],mainmap[4][6],mainmap[4][7],mainmap[4][8],mainmap[4][9]);
printf("  | [%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d] | \n",mainmap[5][0],mainmap[5][1],mainmap[5][2],mainmap[5][3],mainmap[5][4],mainmap[5][5],mainmap[5][6],mainmap[5][7],mainmap[5][8],mainmap[5][9]);
printf("  | [%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d] | \n",mainmap[6][0],mainmap[6][1],mainmap[6][2],mainmap[6][3],mainmap[6][4],mainmap[6][5],mainmap[6][6],mainmap[6][7],mainmap[6][8],mainmap[6][9]);
printf("  | [%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d] | \n",mainmap[7][0],mainmap[7][1],mainmap[7][2],mainmap[7][3],mainmap[7][4],mainmap[7][5],mainmap[7][6],mainmap[7][7],mainmap[7][8],mainmap[7][9]);
printf("  | [%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d] | \n",mainmap[8][0],mainmap[8][1],mainmap[8][2],mainmap[8][3],mainmap[8][4],mainmap[8][5],mainmap[8][6],mainmap[8][7],mainmap[8][8],mainmap[8][9]);
printf("  | [%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d][%2d] | \n",mainmap[9][0],mainmap[9][1],mainmap[9][2],mainmap[9][3],mainmap[9][4],mainmap[9][5],mainmap[9][6],mainmap[9][7],mainmap[9][8],mainmap[9][9]);
printf("=[O]========================================[0]=\n");
}




void inputcommand() {
printf("\n>");
scanf("%s", &input);

if(strcmp(input, "lookaround") == 0) {
printf("You look around...\n");
adthinikosstand();
printf(" To your east: %d, your west: %d, your north: %d, and your south: %d.", mainmap[(adthinikos[0] - 1)][adthinikos[1]], mainmap[(adthinikos[0] + 1)][adthinikos[1]], mainmap[adthinikos[0]][(adthinikos[1] - 1)], mainmap[adthinikos[0]][(adthinikos[1] + 1)]);
}


else if (strcmp(input, "quit") == 0) {
gamestate = 0;}


else if (strcmp(input, "goeast") == 0) {
--adthinikos[0];
adthinikosstand();}

else if (strcmp(input, "gowest") == 0) {
++adthinikos[0];
adthinikosstand();}

else if (strcmp(input, "gonorth") == 0) {
--adthinikos[1];
adthinikosstand();}

else if (strcmp(input, "gosouth") == 0) {
++adthinikos[1];
adthinikosstand();}

else if (strcmp(input, "map") == 0) {
printmap_kiverian();}

else {
printf("What??\n");}

}




int main() {

// Rendering to the user

gamestate = 1;

while(gamestate == 1) {
inputcommand();
}
return 0;
}
