#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"
#include "boolean.h"
#include "listpos.h"

void load_data (char* filename){

    //KAMUS
    int row = 0;int col = 0;int countChar = 0;int countPattern = 0; 
    startWord(filename);
    if (!fileFound) {
        printf("file tidak ditemukan");
        return;
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
        words[i][j] = KataToChar(currentWord);
        advWord();
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
    CreateListPos(&pattern);
    while (currentChar != MARK){
        countPattern++;
        insertLast(&pattern, KataToString(currentWord));
        if (currentChar == NEWLINE) {
            skipNewline();
        }
        advWord();
    }
    printf("patterns:%d\n", countPattern);
    displayList(pattern);

}

int main (){

    char* filename;
    load_data("puzzle.txt");
    return 0;
}