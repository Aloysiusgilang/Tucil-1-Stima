#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"
#include "boolean.h"

void load_data (char* filename){

    //KAMUS
    int row = 0;
    int col = 0;

    startWord(filename);
    if (!fileFound) {
        printf("file tidak ditemukan");
        return;
    }

    while (currentChar != NEWLINE && eot != 1 && currentChar != MARK) {
        row++;
        advWord();
        if (currentChar == NEWLINE) {
            skipNewline();
            col++;
        }
    }

    printf("rows: %d",row);
    printf("rows: %d",col);
   
}

int main (){

    char* filename;
    load_data("puzzle.txt");
    return 0;
}