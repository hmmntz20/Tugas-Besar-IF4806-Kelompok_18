#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct infoHakim {
    string nama;
    string NIP;
    int jumlahKasusSelesai;
};

struct infoTerdakwa {
    string nama;
    string kasus;
    string status;
    int vonisTahun;
};

typedef struct elmHakim* adrHakim;
typedef struct elmTerdakwa* adrTerdakwa;

struct elmTerdakwa {
    infoTerdakwa info;
    adrTerdakwa next;
};

struct elmHakim {
    infoHakim info;
    adrHakim next;
    adrTerdakwa firstTerdakwa;
};

struct List {
    adrHakim first;
};

void createList_103012400118(List &L);
adrHakim createElmHakim_103012400118(string nama, string nip);
adrTerdakwa createElmTerdakwa_103012400248(string nama, string kasus);
void insertHakim_103012400118(List &L, adrHakim P); //insertLast
void deleteHakim_103012400118(List &L, string namaHakim); //
adrHakim searchHakim_103012400248(List L, string nama);
void insertTerdakwa_103012400248(List &L, string namaHakim, adrTerdakwa C);
void deleteTerdakwa_103012400248(List &L, string namaHakim, string namaTerdakwa);
void showAllData_103012400118(List L);
void updateVonis_103012400248(List &L, string namaTerdakwa, int tahun);
void showHakimTersibuk_103012400118(List L);

#endif