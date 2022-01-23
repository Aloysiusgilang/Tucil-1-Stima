/* File : ListPoint.c */
/* Nama : Aloysius Gilang Pramudya */
/* NIM : 13520147 */

/* MODUL LIST INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer dengan elemen 
   positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori array statik */

#include "boolean.h"
#include "listOfPoint.h"
#include <string.h>
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPoint(ListPoint *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPP */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF_P_P */
{
   // Kamus 
   int i;

   // Algoritma 
   for (i = 0; i < CAPP; i++){
      (*l).contents[(i)].x = VAL_UNDEF_P;
      (*l).contents[(i)].y = VAL_UNDEF_P;
   }

}
int lengthPoint(ListPoint l){
    // Kamus
   boolean flag = false;
   int count = 0;
   int i = 0;
   
   // Algoritma
   while (!flag && i<CAPP)
   {
      if ((l).contents[(i)].x != VAL_UNDEF_P && (l).contents[(i)].y != VAL_UNDEF_P){
         count++;
         i++;
      } else {
         flag = true;
      }
   }

   return count;
   
}

/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

void CreatePoint(Point *P, int a, int b){
    P->x = a;
    P->y = b;
}

Point makePoint(int x, int y){
    Point P;
    P.x = x;
    P.y = y;
    return P;
}

void displayListPoint(ListPoint l)
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

    for (i = 0; i < lengthPoint(l); i++){
        if(i == lengthPoint(l)-1){
          printf("(%d %d)", (l).contents[(i)].x,(l).contents[(i)].y);
        } else {
           printf("(%d %d),",(l).contents[(i)].x, (l).contents[(i)].y);
     }
    }
      printf("\n");
}



/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */


/* ********** SORTING ********** */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastPoint(ListPoint *l, EltypePoint val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
   (*l).contents[(lengthPoint(*l))] = val;
}

