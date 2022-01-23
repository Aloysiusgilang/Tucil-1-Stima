/* MODUL LIST INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer dengan elemen 
   positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori array statik */

#ifndef LISTPOINT_H
#define LISTPOINT_H

#include "boolean.h"

/*  Kamus Umum */
#define CAPP 1000
/* Kapasitas penyimpanan */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define VAL_UNDEF_P -999
/* Nilai elemen tak terdefinisi*/
typedef struct {
   int x; /* memori tempat penyimpan elemen (container) */
   int y; /* memori tempat penyimpan elemen (container) */
} Point;
/* Definisi elemen dan koleksi objek */
typedef Point EltypePoint;  /* type elemen List */
typedef struct {
   Point contents[CAPP]; /* memori tempat penyimpan elemen (container) */
} ListPoint;
/* Indeks yang digunakan [0..CAPP-1] */
/* Jika l adalah ListPoint, cara deklarasi dan akses: */
/* Deklarasi : l : ListPoint */
/* Maka cara akses: 
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
   List kosong: semua elemen bernilai VAL_UNDEF_P
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ELMTP(l, i) (l).contents[(i)]
#define ELMT_X(l, i) (l).contents[(i)][0]
#define ELMT_Y(l, i) (l).contents[(i)][1]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPoint(ListPoint *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPP */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF_P */

void CreatePoint(Point *P, int x, int y);

Point makePoint(int x,int y);
int lengthPoint(ListPoint l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */


/*    Jika n = 0; hanya terbentuk List kosong */
void displayListPoint(ListPoint l);
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */


/* ***  Perhatian : List boleh kosong!! *** */
int indexOfPoint(ListPoint l, EltypePoint val);
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* *** Menambahkan elemen terakhir *** */
void insertLastPoint(ListPoint *l, EltypePoint val);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */

#endif