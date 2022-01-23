// Nama : Aloysius Gilang Pramudya
// NIM : 13520147 
// Topik : Mesin karakter
// Deskripsi : Implementasi header wordmachine.h

#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"
#include <stdio.h>
#include <stdlib.h>


/* Word Engine State */
boolean endWord;
Word currentWord;

void ignoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
   if (currentChar == BLANK ) {
      adv();
   }
   
}

void skipNewline(){
   if (currentChar == NEWLINE){
      adv();
   }
}

void startWord(char *filename)
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
   start(filename);
   endWord = false;
   if(currentChar == MARK) {
      endWord = true;
   } else {
      ignoreBlank();
      copyWord();
   }
}

void advWord()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
{
   endWord =false;
   if (currentChar == MARK){
      endWord = true;
   } else {
      copyWord();
      ignoreBlank();
   }
}

void copyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
{

   //kamus lokal
   int i;

   //Algoritma
   i = 0;
   while (currentChar != MARK && currentChar != BLANK && currentChar != NEWLINE && i< CAPACITY){
      currentWord.contents[i] = currentChar;
      adv();
      i++;
   }
   currentWord.length = i;
}

char KataToChar (Word K)
{
      if (K.length > 1) {
         return '@';
      } else {
         return (K.contents[0]);
      }
}

char* KataToString (Word K){
   char* toret = (char*)malloc(sizeof(char)*(CAPACITY)); 
   int i = 0;
   for (i = 0; i < K.length; i++) {
         toret[i] = K.contents[i];
   }
   toret[i] = '\0';
   return toret;
}

char* KataToStringReversed (Word K){
   char* toret = (char*)malloc(sizeof(char)*(CAPACITY)); 
   int i ;
   for (i = K.length - 1; i > 0; i--) {
         toret[i] = K.contents[i];
   }
   toret[i] = '\0';
   return toret;
}