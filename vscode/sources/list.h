#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct elmHakim* adrHakim;
typedef struct elmTerdakwa* adrTerdakwa;

struct infoHakim {
    string nama;
    int jumlahKasusSelesai;
};

struct infoTerdakwa {
    int id;
    string nama;
    string kasus;
    string status;
    int vonisTahun;
};


struct elmTerdakwa {
    infoTerdakwa info;
    adrTerdakwa next;
};

struct elmHakim {
    infoHakim info;
    adrHakim next;
    adrHakim prev;
    adrTerdakwa firstTerdakwa;
};

struct List {
    adrHakim first;
};

void createList_103012400118(List &L);
adrHakim createElmHakim_103012400118(string nama);
adrTerdakwa createElmTerdakwa_103012400248(List L, string nama, string kasus);

void insertFirstHakim_103012400248(List &L, adrHakim P);
void insertLastHakim_103012400118(List &L, adrHakim P);
void insertAfterHakim_103012400248(List &L, int id, adrHakim P);

void deleteFirstHakim_103012400118(List &L);
void deleteLastHakim_103012400248(List &L);
void deleteAfterHakim_103012400118(List &L, int id);
// TAMBAHIN DELETE UNTUK LANGSUNG MERUJUK KE ID TSB

void insertFirstTerdakwa_103012400118(List &L,  int idHakim, adrTerdakwa C);
void insertLastTerdakwa_103012400248(List &L, int idHakim, adrTerdakwa C);
void insertAfterTerdakwa_103012400118(List &L, int idHakim, int id, adrTerdakwa C);

void deleteFirstTerdakwa_103012400248(List &L, int idHakim);
void deleteLastTerdakwa_103012400118(List &L, int idHakim);
void deleteAfterTerdakwa_103012400248(List &L, int idHakim, int id);
// TAMBAHIN DELETE UNTUK LANGSUNG MERUJUK KE ID TSB

adrHakim searchHakim_103012400118(List L, int id);
adrTerdakwa searchTerdakwa_103012400248(List L, int idTerdakwa);

void showAllData_103012400118(List L);
void showDataHakim_103012400248(List L);
void showDataTerdakwa_103012400118(List L);
void updateVonis_103012400248(List &L, int idTerdakwa, int tahun);
void showHakimTersibuk_103012400118(List L);
void showTerdakwaHukumanTerlama_103012400248(List L);

#endif