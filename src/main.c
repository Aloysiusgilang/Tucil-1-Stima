#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"
#include "boolean.h"
#include "listpos.h"
#include "listOfPoint.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

int searchKiriKanan (int row,int col,char words[row][col], char* pattern, Point P){

    ListPoint l;
    int comparison = 0;
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
            comparison++;
        }
        if (equal){
            printOutput(l,row,col,words);
        }
    }
    return comparison;
}

int searchAtasBawah (int row, int col,char words[row][col], char* pattern, Point P){

    ListPoint l;
    int comparison = 0;
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
            comparison++;
        }
        if (equal){
            printOutput(l,row,col,words);
        }
    }
    return comparison;
}

int searchKiriAtasKananBawah (int row, int col,char words[row][col], char* pattern, Point P){

    ListPoint l;
    int comparison = 0;
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
            comparison++;
        }
        if (equal){
            printOutput(l,row,col,words);
        }
    }
    return comparison;
}

int searchKiriBawahKananAtas (int row, int col,char words[row][col], char* pattern, Point P){

    ListPoint l;
    int comparison = 0;
    CreateListPoint(&l);
    int a = P.x; int b = P.y; int c = 0; int d = a - strlen(pattern) + 1;
    if ((d >= 0) && b + strlen(pattern) -1 <= col){
        boolean equal = true;
        while (a >= (P.x - strlen(pattern) + 1)&& b < (P.y + strlen(pattern)) && equal){
            if (words[a][b] == pattern[c]){
                insertLastPoint(&l,makePoint(a,b));
                a--; c++; b++;
            } else {
                equal = false;
            }
            comparison++;
        }
        if (equal){
            printOutput(l,row,col,words);
        }
    }
    return comparison;
}

// ini di loop sebanyak pattern
int searchSameFirstChar (int row, int col, char words[row][col], char* pattern){
    Point P;
    int i = 0; int j = 0;
    boolean match = false;
    int comparison = 0;
    for (i = 0; i < row; i++){
        for(j = 0; j < col;j++){
            comparison++;
            if (words[i][j] == pattern[0]) {
                P.x = i;
                P.y = j;
                match = true;
                // return P;
                comparison += searchKiriKanan(row,col,words,pattern,P);
                comparison += searchAtasBawah(row,col,words,pattern,P);
                comparison += searchKiriAtasKananBawah(row,col,words,pattern,P);
                comparison += searchKiriBawahKananAtas(row,col,words,pattern,P);
            }
        }
    }
    return comparison;
}

int main (){

  
    char title[100] ={' '};
    printf("Word Search Puzzle by Aloysius Gilang\n");
    printf("Masukan nama file (small1, small2, small3, medium1, medium2, medium3, large1,large2, large3) + .txt\n");
    // scanf("%s",title);
    char str1[100] = "../test/", str2[100];
    scanf("%s",str2);
    char filename[100];
    int v = 0, w = 0;
  
    // Insert the first string in the new string
    while (str1[v] != '\0') {
        filename[w] = str1[v];
        v++;
        w++;
    }
  
    // Insert the second string in the new string
    v = 0;
    while (str2[v] != '\0') {
        filename[w] = str2[v];
        v++;
        w++;
    }
    filename[w] = '\0';
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
    printf("Rows: %d\n",row);printf("Cols: %d\n",col);
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
    // displayList(pattern);
    printf("\n");

    // element checking
    clock_t start = clock();
    int sumComparison = 0;
    for (i = 0; i < length(pattern);i++){
        sumComparison += searchSameFirstChar(row,col,words,pattern.contents[i]);
    }
    clock_t end = clock();
    float time =  (float)(end - start) / CLOCKS_PER_SEC;
    // printf("total comparison : %d ",comparison);
    printf("Time elapsed : %f\n", time);
    printf("Total comparison : %d\n", sumComparison);
    printf("\n");

    // searchKiriKanan(row,col,words,pattern.contents[4],A,&comparison);

    return 0;


}
 
