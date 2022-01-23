/* File : listpos.c */
/* Nama : Aloysius Gilang Pramudya */
/* NIM : 13520147 */

/* MODUL LIST INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer dengan elemen 
   positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori array statik */

#include "boolean.h"
#include "listpos.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPos(ListPos *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPL */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
{
   // Kamus 
   int i;

   // Algoritma 
   for (i = 0; i < CAPL; i++){
      (*l).contents[(i)] = VAL_UNDEF;
   }

}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListPos l)
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
{
   // Kamus
   boolean flag = false;
   int count = 0;
   int i = 0;
   
   // Algoritma
   while (!flag && i<CAPL)
   {
      if ((l).contents[(i)] != VAL_UNDEF){
         count++;
         i++;
      } else {
         flag = true;
      }
   }

   return count;
   
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListPos l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
   return(i>=0 && i<CAPL);
}

boolean isIdxEff(ListPos l, int i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
{
   return(i>=0 && i<=(length(l)-1));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListPos l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
{
   // Kamus
   boolean empty = true;
   int i = 0;

   // Algoritma
   while(empty && (i < CAPL)){
      if ((l).contents[(i)] != VAL_UNDEF){
         empty = false;
      } else 
      {
         i++;
      }
   }

   return empty;
}

boolean isFull(ListPos l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
   // Kamus 
   boolean full = true;
   int i = 0;

   while (full && (i < CAPL))
   {
      if ((l).contents[(i)] == VAL_UNDEF){
         full = false;
      } else {
         i++;
      }
   }

   return full;
   
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */


void displayList(ListPos l)
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
{
   // Kamus 
   int i;

   // Algoritma
   if (isEmpty(l)) {
      printf("\n");
   } else {
   
      for (i = 0; i < length(l); i++){
         if(i == length(l)-1){
            printf("%s", (l).contents[(i)]);
         } else {
            printf("%s,",(l).contents[(i)]);
         }
      }
      printf("\n");
   }
}


/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListPos l1, ListPos l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
{
   // Kamus 
   boolean sama = true;
   int i = 0;

   // Algoritma
   if (length(l1) == length(l2)){
      while (sama && i <length(l1))
      {
         if (l1.contents[i] != l2.contents[i]) {
            sama = false;
         }
         else {
            i++;
         }
      }  
   } else {
      sama = false;
   }

   return sama;

}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListPos l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
{
   // skema search dengan boolean 
   // Kamus
   int i = 0;
   int idx;
   boolean found = false;

   // Algoritma
   while ( !found && i < length(l) ){
      if (l.contents[i] == val){
         found = true;
      } else {
         i++;
      }
   }

   if (found){
      idx = i;
   } else {
      idx = IDX_UNDEF;
   }

   return idx;
}


/* ********** SORTING ********** */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPos *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
   (*l).contents[(length(*l))] = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListPos *l, ElType *val)
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
   *val = (*l).contents[length(*l)-1];
   (*l).contents[(length(*l))-1] = VAL_UNDEF;
}
