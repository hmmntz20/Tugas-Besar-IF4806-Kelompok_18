#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct infoHakim {
    string nama;
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
adrHakim createElmHakim_103012400118(string nama);
adrTerdakwa createElmTerdakwa_103012400248(string nama, string kasus);

void insertFirstHakim(List &L, adrHakim P);
void insertLastHakim(List &L, adrHakim P);
void insertAfterHakim(List &L, int id, adrHakim P);

void deleteFirstHakim(List &L);
void deleteLastHakim(List &L);
void deleteAfterHakim(List &L, int id);

void insertFirstTerdakwa(List &L,  int idHakim, adrTerdakwa C);
void insertLastTerdakwa(List &L, int idHakim, adrTerdakwa C);
void insertAfterTerdakwa(List &L, int idHakim, int id, adrTerdakwa C);

void deleteFirstTerdakwa(List &L, int idHakim);
void deleteLastTerdakwa(List &L, int idHakim);
void deleteAfterTerdakwa(List &L, int idHakim, int id);

adrHakim searchHakim_103012400248(List L, int id);
void showAllData_103012400118(List L);
void showDataHakim(List L);
void showDataTerdakwa(List L);
void updateVonis_103012400248(List &L, string namaTerdakwa, int tahun);
void showHakimTersibuk_103012400118(List L);

#endif