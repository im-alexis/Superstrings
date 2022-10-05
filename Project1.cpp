// superstrings <Project1.cpp>
// EE 312 Project 1 submission by
// Alexis Torres
// at39625
// Slip days used: <0>
// Spring 2022
// Include the contents of this file at the top of every file that you submit, replacing the fields within <>.  Do not keep the <>.

/*
 * Project1.cpp
 *
 * Name: Alexis Torres
 * EE312 Spring 2022
 * SuperStrings
 */



#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types
//#include "header.h"
/*
All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)

You must write this function (printSuperStrings). Do not change the way the function is declared (i.e., it has
exactly two parameters, each parameter is a standard (mundane) C string (see Instruction).
*/

char *targetTracker;
char *candidateTracker;

int checkWordLenghtTarg ( char *letterAddyT){ // counts characters specifically for target
    int letterTCount = 0;
    while (*letterAddyT == ' '|| *letterAddyT  == '\n'|| *letterAddyT == '\t'){
        letterAddyT++;
        targetTracker = letterAddyT;
    }
    while(1) {
        letterTCount++;
        letterAddyT ++;
        if (*letterAddyT == '\n' || *letterAddyT  == '\0' || *letterAddyT  == ' ' || *letterAddyT == '\t') {
            break;
        }
    }
    return letterTCount;
}

int checkWordLenghtCand (char *letterAddyC){ // counts letters in candidates specifically
    int letterCCount = 0;

    while (*letterAddyC == ' '|| *letterAddyC == '\n' || *letterAddyC == '\t'){
        letterAddyC++;
        candidateTracker = letterAddyC;
    }
    while(1) {
        letterCCount ++;
        letterAddyC ++; //increment this pointer to move through the char array
        if (*letterAddyC== '\n' || *letterAddyC == '\0' || *letterAddyC == ' ' || *letterAddyC == '\t') { // if it reaches one of these chars then you reached the end of a word
            break;
        }
    }

    return letterCCount;

}

void actuallyGettingPrinted(int letCount, char *whereItAt) { // prints a word character by character using the length and a pointer at the first letter
    int printTracker;
    for ( printTracker = 0; printTracker < letCount; printTracker++){
        printf("%c", *(whereItAt + printTracker));
    }
    printf("\n");
}


int howManyWords(char firstString[]){  //counts the amount of words in an array passed through
    int amntWords = 0;
    int b = 0;
    //for (int i=0; i<10000; i++) {
      while(firstString[b] != '\0') {
        b++;
        if((firstString[b] == ' ' && firstString[b+1] != '\0' && firstString[b+1]!= '\n' && firstString[b+1]!= ' ' && firstString[b+1] != '\t')
        || (firstString[b] == '\n' && firstString[b+1] != '\0'&& firstString[b+1]!= ' ' && firstString[b+1]!= '\n' && firstString[b+1] != '\t' )
        || firstString[b] == '\0' || (firstString[b] == '\t'&& firstString[b+1] != '\0' && firstString[b+1]!= ' '
        && firstString[b+1]!= '\n' && firstString[b+1] != '\t')
        ){

            amntWords++;
        }
        if (firstString[b] == '\0'){
            break;
        }
    }
    return amntWords;
}



void printSuperStrings(char targets [], char candidates []) {

    targetTracker = targets;
    candidateTracker = candidates;

    int amountWordsTarg = howManyWords(targets);
    int amountWordsCand = howManyWords(candidates);
    int targWordCnt;
    int candWordCnt;
    for (targWordCnt = 0; targWordCnt < amountWordsTarg; targWordCnt++ ){ // based on the amount of words in target
        for ( candWordCnt =0; candWordCnt < amountWordsCand; candWordCnt++){ // based on the amount of words in candidate
            int lettTargCnt = 0;
            int lettCandCnt = 0;
            while(*candidateTracker == ' ' || *candidateTracker  == '\n' ||*candidateTracker  == '\t'   ){//skips over spaces, tabs and newlines
                candidateTracker ++;
            }
            while (1){
                if(*(targetTracker+lettTargCnt) == *(candidateTracker+lettCandCnt)){
                    lettTargCnt++;
                    if(lettTargCnt == checkWordLenghtTarg( targetTracker) ){// prints the words in candidate and increaments to the next word if it is a match
                        actuallyGettingPrinted(checkWordLenghtCand( candidateTracker), candidateTracker);
                        candidateTracker = candidateTracker + (checkWordLenghtCand( candidateTracker) + 1 );
                        break;
                    }
                }

                if (lettCandCnt == (checkWordLenghtCand(candidateTracker)-1) && lettTargCnt < checkWordLenghtTarg(targetTracker) ){
                    candidateTracker = candidateTracker + (checkWordLenghtCand( candidateTracker) + 1);//increments into the next word in candidate if not a match
                    break;
                }
                lettCandCnt++;
            }
        }

        while(*targetTracker == ' ' || *targetTracker == '\n' || *targetTracker == '\t'  ){ // skips new line, tabs, and spaces
            targetTracker++;
        }
        printf("\n");
        targetTracker = targetTracker +(checkWordLenghtTarg(targetTracker)+1); // increaments to the next word in target and resets the candidate pointer
        candidateTracker = candidates;

    }
 }




