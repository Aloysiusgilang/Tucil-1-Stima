#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"
#include "boolean.h"
#include "listpos.h"
#include "listOfPoint.h"
#include <string.h>
#include <stdlib.h>

char* reversedString(char *string)
{
    int length = strlen(string);
    char* reversed = (char*)malloc((length+1) * sizeof(char));
    for(int i=0;i<length;i++)
    {
      reversed[(length-1)-i]=string[i];
    }
    reversed[length] = '\0';
    return reversed;
}

int main (){

    char* filename = "puzzle.txt";
    int row = 0;int col = 0;int countChar = 0;int countPattern = 0; 
    startWord(filename);
    if (!fileFound) {
        printf("file tidak ditemukan");
        return 0;
    }
    while (currentChar != NEWLINE && eot != 1 && currentChar != MARK) {
        countChar++;
        advWord();
        if (currentChar == NEWLINE) {
            skipNewline();
            row++;
        }
    }
    col = countChar /row;
    printf("rows: %d\n",row);printf("cols: %d\n",col);
    char words[row][col];
    startWord(filename);
    int i = 0; int j = 0;
    while (currentChar != NEWLINE){
        advWord();
        words[i][j] = KataToChar(currentWord);
        if (currentChar == NEWLINE) {
            skipNewline();
            j = 0;
            i++;
        } else {
            j++;
        }
    }
    //printing words
    for (i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%c ", words[i][j]);
        }
        printf("\n");
    }
    skipNewline();
    advWord();
    ListPos pattern;
    ListPoint arrPoint;
    CreateListPoint(&arrPoint);
    CreateListPos(&pattern);
    while (currentChar != MARK){
        countPattern++;
        insertLast(&pattern, KataToString(currentWord));
        // insertLast(&pattern, reversedString(KataToString(currentWord)));
        if (currentChar == NEWLINE) {
            skipNewline();
        }
        advWord();
    }
    printf("patterns:%d\n", countPattern);
    displayList(pattern);
    printf("\n");

    // element checking
    printf("%c\n",words[0][7]);
    printf("%s\n", pattern.contents[0]);
    printf("%c\n", pattern.contents[0][1]);
    printf("%c\n", patternAt(pattern,0,1));
    printf("%d\n", wordLength(pattern,1));

    return 0;


}

void searchAtasBawah (char* words[], char* pattern, Point P){

}