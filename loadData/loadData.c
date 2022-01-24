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

void printOutput(ListPoint L, int row, int col,char words[row][col]){
    
    int i; int j;
    for (i = 0; i < row; i++){
        for (j = 0; j<col; j++){
            if (inList(L, i,j)){
                printf(" %c ", words[i][j]);
            } else {
                printf(" - ");
            }
        } printf("\n");
    }
    printf("\n \n");
}

void searchKiriKanan (int row,int col,char words[row][col], char* pattern, Point P, int* comparison){

    ListPoint l;
    CreateListPoint(&l);
    int a = P.x; int b = P.y; int c = 0;
    if (b + strlen(pattern) -1 < col ){
        boolean equal = true;
        while (b < (P.y + strlen(pattern)) && equal){
            if (words[a][b] == pattern[c]){
                insertLastPoint(&l,makePoint(a,b));
                b++; c++;
            } else {
                equal = false;
            }
            *comparison++;
        }
        if (equal){
            printOutput(l,row,col,words);
        }
    }
}

void searchAtasBawah (int row, int col,char words[row][col], char* pattern, Point P, int* comparison){

    ListPoint l;
    CreateListPoint(&l);
    int a = P.x; int b = P.y; int c = 0;
    if (a + strlen(pattern) -1 < row ){
        boolean equal = true;
        while (a < (P.x + strlen(pattern)) && equal){
            if (words[a][b] == pattern[c]){
                insertLastPoint(&l,makePoint(a,b));
                a++; c++;
            } else {
                equal = false;
            }
            *comparison++;
        }
        if (equal){
            printOutput(l,row,col,words);
        }
    }
}

void searchKiriAtasKananBawah (int row, int col,char words[row][col], char* pattern, Point P, int* comparison){

    ListPoint l;
    CreateListPoint(&l);
    int a = P.x; int b = P.y; int c = 0;
    if (a + strlen(pattern) -1 < row && b + strlen(pattern) -1 < col){
        boolean equal = true;
        while (a < (P.x + strlen(pattern))&& b < (P.y + strlen(pattern)) && equal){
            if (words[a][b] == pattern[c]){
                insertLastPoint(&l,makePoint(a,b));
                a++; c++; b++;
            } else {
                equal = false;
            }
            *comparison++;
        }
        if (equal){
            printOutput(l,row,col,words);
        }
    }
}

void searchKiriBawahKananAtas (int row, int col,char words[row][col], char* pattern, Point P, int* comparison){

    ListPoint l;
    CreateListPoint(&l);
    int a = P.x; int b = P.y; int c = 0;
    if (a - strlen(pattern) +1 <= 0 && b + strlen(pattern) -1 <= col){
        boolean equal = true;
        while (a >= (P.x - strlen(pattern) + 1)&& b < (P.y + strlen(pattern)) && equal){
            if (words[a][b] == pattern[c]){
                insertLastPoint(&l,makePoint(a,b));
                a--; c++; b++;
            } else {
                equal = false;
            }
            *comparison++;
        }
        if (equal){
            printOutput(l,row,col,words);
        }
    }
}


// ini di loop sebanyak pattern
void searchSameFirstChar (int row, int col, char words[row][col], char* pattern,int* comparison){
    Point P;
    int i = 0; int j = 0;
    boolean match = false;
    for (i = 0; i < row; i++){
        for(j = 0; j < col;j++){
            *comparison++;
            if (words[i][j] == pattern[0]) {
                P.x = i;
                P.y = j;
                match = true;
                // return P;
                searchKiriKanan(row,col,words,pattern,P,comparison);
                searchAtasBawah(row,col,words,pattern,P,comparison);
                searchKiriAtasKananBawah(row,col,words,pattern,P,comparison);
                searchKiriBawahKananAtas(row,col,words,pattern,P,comparison);
                // tinggal arah lainnya
            }
        }
    }

}




int main (){

    char* filename = "puzzle.txt";
    int row = 0;int col = 0;int countChar = 0;int countPattern = 0;int comparison =0;
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
        insertLast(&pattern, reversedString(KataToString(currentWord)));
        if (currentChar == NEWLINE) {
            skipNewline();
        }
        advWord();
    }
    printf("patterns:%d\n", countPattern);
    displayList(pattern);
    printf("\n");

    // element checking
    for (i = 0; i < length(pattern);i++){
        searchSameFirstChar(row,col,words,pattern.contents[i],&comparison);
    }
    printf("total comparison : %d ",comparison);
    printf("\n");

    // searchKiriKanan(row,col,words,pattern.contents[4],A,&comparison);

    return 0;


}

