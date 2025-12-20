#include "list.h"
#include "../utils/widgets.h"

void createList_103012400118(List &L) {
    L.first = nullptr;
}

adrHakim createElmHakim_103012400118(string nama) {
    adrHakim P = new elmHakim;
    P->info.nama = nama;
    P->next = nullptr;
    P->prev = nullptr;
    P->firstTerdakwa = nullptr;
    P->info.jumlahKasusSelesai = 0;
    return P;
}

int getNewTerdakwaId(List L) {
    int maxId = 0;
    adrHakim P = L.first;
    while (P != nullptr) {
        adrTerdakwa C = P->firstTerdakwa;
        while (C != nullptr) {
            if (C->info.id > maxId) {
                maxId = C->info.id;
            }
            C = C->next;
        }
        P = P->next;
    }
    return maxId + 1;
}
adrTerdakwa createElmTerdakwa_103012400248(List L, string nama, string kasus) {
    adrTerdakwa P = new elmTerdakwa;
    P->info.id = getNewTerdakwaId(L);
    P->info.nama = nama;
    P->info.kasus = kasus;
    P->info.status = "Sidang";
    P->info.vonisTahun = 0;
    P->next = nullptr;
    return P;
}

void insertFirstHakim_103012400248(List &L, adrHakim P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastHakim_103012400118(List &L, adrHakim P) {
    if (L.first == nullptr) {
        insertFirstHakim_103012400248(L, P);
    } else {
        adrHakim Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
        P->prev = Q;
    }
}

void insertAfterHakim_103012400248(List &L, int id, adrHakim P) {
    adrHakim Prec = searchHakim_103012400118(L, id);

    if (Prec != nullptr) {
        P->next = Prec->next;
        P->prev = Prec;
        
        if (Prec->next != nullptr) {
            Prec->next->prev = P;
        }
        Prec->next = P;
        cout << "[Sukses] Hakim ditambahkan setelah urutan ke-" << id << endl;
    } else {
        cout << "[!] Hakim referensi tidak ditemukan." << endl;
    }
}



void deleteFirstHakim_103012400118(List &L) {
    if (L.first == nullptr) {
        cout << "[!] Data kosong." << endl;
    } else {
        adrHakim P = L.first;
        if (P->next == nullptr) {
            L.first = nullptr;
        } else {
            L.first = P->next;
            L.first->prev = nullptr;
            P->next = nullptr;
        }
        delete P;
        cout << "[Sukses] Hakim pertama dihapus." << endl;
    }
}

void deleteLastHakim_103012400248(List &L) {
    if (L.first == nullptr) {
        cout << "[!] Data kosong." << endl;
        return;
    }

    adrHakim P = L.first;
    if (P->next == nullptr) {
        deleteFirstHakim_103012400118(L);
        return;
    }

    while (P->next != nullptr) {
        P = P->next;
    }
    P->prev->next = nullptr;
    P->prev = nullptr;
    
    delete P;
    cout << "[Sukses] Hakim terakhir dihapus." << endl;
}

void deleteAfterHakim_103012400118(List &L, int id) {
    adrHakim Prec = searchHakim_103012400118(L, id);
    
    if (Prec != nullptr && Prec->next != nullptr) {
        adrHakim P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = Prec;
        }
        
        P->next = nullptr;
        P->prev = nullptr;
        delete P;
        cout << "[Sukses] Hakim setelah urutan ke-" << id << " dihapus." << endl;
    } else {
        cout << "[!] Gagal. Target tidak ditemukan atau list hanya satu elemen." << endl;
    }
}

void insertFirstTerdakwa_103012400118(List &L, int idHakim, adrTerdakwa C) {
    adrHakim P = searchHakim_103012400118(L, idHakim);
    if (P != nullptr) {
        C->next = P->firstTerdakwa;
        P->firstTerdakwa = C;
        P->info.jumlahKasusSelesai++;
        cout << "[Sukses] Terdakwa (ID: " << C->info.id << ") ditambahkan di awal list hakim ." << endl;
    } else {
        cout << "[!] Hakim tidak ditemukan." << endl;
    }
}

void insertLastTerdakwa_103012400248(List &L, int idHakim, adrTerdakwa C) {
    adrHakim P = searchHakim_103012400118(L, idHakim);
    if (P != nullptr) {
        if (P->firstTerdakwa == nullptr) {
            P->firstTerdakwa = C;
        } else {
            adrTerdakwa Q = P->firstTerdakwa;
            while (Q->next != nullptr) {
                Q = Q->next;
            }
            Q->next = C;
        }
        P->info.jumlahKasusSelesai++;
        cout << "[Sukses] Terdakwa (ID: " << C->info.id << ") ditambahkan di akhir list hakim." << endl;
    } else {
        cout << "[!] Hakim tidak ditemukan." << endl;
    }
}

void insertAfterTerdakwa_103012400118(List &L, int idHakim, int idTerdakwa, adrTerdakwa C) {
    adrHakim P = searchHakim_103012400118(L, idTerdakwa);
    if (P == nullptr) {
        cout << "[!] Hakim tidak ditemukan." << endl;
        return;
    }
    adrTerdakwa Prec = P->firstTerdakwa;
    int i = 1;
    while (Prec != nullptr && Prec->info.id != idTerdakwa) {
        Prec = Prec->next;
    }
    if (Prec != nullptr) {
        C->next = Prec->next;
        Prec->next = C;
        P->info.jumlahKasusSelesai++;
        cout << "[Sukses] Terdakwa (ID: " << C->info.id << ") ditambahkan setelah ID " << idTerdakwa << endl;
    } else {
        cout << "[!] Urutan Terdakwa tidak valid." << endl;
    }
}

void deleteFirstTerdakwa_103012400248(List &L, int idHakim) {
    adrHakim P = searchHakim_103012400118(L, idHakim);
    if (P == nullptr || P->firstTerdakwa == nullptr) {
        cout << "[!] Gagal. Hakim tidak ditemukan atau list terdakwa kosong." << endl;
        return;
    }
    adrTerdakwa C = P->firstTerdakwa;
    P->firstTerdakwa = C->next;
    P->info.jumlahKasusSelesai--;
    delete C;
    cout << "[Sukses] Terdakwa pertama dihapus dari hakim " << P->info.nama << endl;
}

void deleteLastTerdakwa_103012400118(List &L, int idHakim) {
    adrHakim P = searchHakim_103012400118(L, idHakim);
    if (P == nullptr || P->firstTerdakwa == nullptr) {
        cout << "[!] Gagal." << endl;
        return;
    }

    P->info.jumlahKasusSelesai--;
    
    if (P->firstTerdakwa->next == nullptr) {
        adrTerdakwa C = P->firstTerdakwa;
        P->firstTerdakwa = nullptr;
        delete C;
        cout << "[Sukses] Terdakwa terakhir dihapus." << endl;
        return;
    }

    adrTerdakwa Q = P->firstTerdakwa;
    while (Q->next->next != nullptr) {
        Q = Q->next;
    }
    adrTerdakwa C = Q->next;
    Q->next = nullptr;
    delete C;
    cout << "[Sukses] Terdakwa terakhir dihapus dari hakim " << P->info.nama << endl;
}

void deleteAfterTerdakwa_103012400248(List &L, int idHakim, int idTerdakwa) {
    adrHakim P = searchHakim_103012400118(L, idHakim);
    if (P == nullptr) {
        cout << "[!] Hakim tidak ditemukan." << endl;
        return;
    }
    adrTerdakwa Prec = P->firstTerdakwa;
    int i = 1;
    while (Prec != nullptr && Prec->info.id != idTerdakwa) {
        Prec = Prec->next;
    }
    if (Prec != nullptr && Prec->next != nullptr) {
        adrTerdakwa C = Prec->next;
        Prec->next = C->next;
        P->info.jumlahKasusSelesai--;
        delete C;
        cout << "[Sukses] Terdakwa setelah ID " << idTerdakwa << " dihapus." << endl;
    } else {
        cout << "[!] Gagal. Urutan tidak ketemu atau ini elemen terakhir." << endl;
    }
}

adrHakim searchHakim_103012400118(List L, int id) {
    adrHakim P = L.first;
    int i = 1;
    while (P != nullptr && i < id) {
        P = P->next;
        i++;
    }
    if (i == id && P != nullptr) {
        return P;
    }
    return nullptr;
}

adrTerdakwa searchTerdakwa_103012400248(List L, int idTerdakwa) {
    adrHakim P = L.first;
    while (P != nullptr) {
        adrTerdakwa C = P->firstTerdakwa;
        while (C != nullptr) {
            if (C->info.id == idTerdakwa) {
                return C;
            }
            C = C->next;
        }
        P = P->next;
    }
    return nullptr;
}

void showAllData_103012400118(List L) {
    cout << endl;
    if (L.first == nullptr) {
        cout << "[!] Data Kosong." << endl;
        return;
    }

    vector<int> wHakim = {2, 53, 15}; vector<int> wTerdakwa = {2, 30, 15, 15}; vector<int> wEmpty = {71};
    printBorder(wHakim); printRow({"ID", "NAMA HAKIM", "KASUS"}, wHakim); printBorder(wHakim);

    adrHakim P = L.first;
    int i = 1;

    while (P != nullptr) {
        printRow({
            to_string(i), 
            P->info.nama, 
            to_string(P->info.jumlahKasusSelesai)
        }, wHakim);

        string indent = "|   "; printBorder(wTerdakwa, indent + " "); printRow({"ID", "NAMA TERDAKWA", "JENIS KASUS", "STATUS"}, wTerdakwa, indent + " "); printBorder(wTerdakwa, indent + " ");
        
        adrTerdakwa C = P->firstTerdakwa;
        if (C == nullptr) {
            printRow({
                center("[!] Belum Ada Kasus", wEmpty[0])
            }, wEmpty, indent + " ");
        } else {
            while (C != nullptr) {
                string statusStr = (C->info.status == "Vonis") ? "Vonis" : "Sidang";
                
                printRow({
                    to_string(C->info.id), 
                    C->info.nama, 
                    C->info.kasus, 
                    statusStr
                }, wTerdakwa, indent + " ");

                C = C->next;
            }
        }

        printBorder(wEmpty, indent + " "); printBorder(wHakim);
        
        P = P->next;
        i++;
    }
}

void showDataHakim_103012400248(List L) {
    clearScreen();
    headerTitle("DATA HAKIM");
    cout << endl;

    if (L.first == nullptr) {
        cout << "[!] Data Kosong." << endl;
        return;
    }

    vector<int> widths = {2, 53, 15};
    printBorder(widths);
    printRow({"NO", "NAMA HAKIM", "TOTAL"}, widths);
    printBorder(widths);

    adrHakim P = L.first;
    int i = 1;
    while (P != nullptr) {
        printRow({to_string(i), P->info.nama, to_string(P->info.jumlahKasusSelesai)}, widths);
        P = P->next;
        i++;
    }
    printBorder(widths);
}

void showDataTerdakwa_103012400118(List L) {
    clearScreen();
    headerTitle("DATA TERDAKWA");
    cout << endl;

    bool isEmpty = true;
    adrHakim P = L.first;
    while(P != nullptr){ if(P->firstTerdakwa) isEmpty = false; P=P->next; }

    if (isEmpty) { cout << "[!] Data Kosong." << endl; return; }

    vector<int> widths = {2, 35, 15, 15};
    printBorder(widths);
    printRow({"ID", "NAMA TERDAKWA", "KASUS", "STATUS"}, widths);
    printBorder(widths);

    P = L.first;
    while (P != nullptr) {
        adrTerdakwa C = P->firstTerdakwa;
        while (C != nullptr) {
            string stat = (C->info.status == "Vonis") ? "Vonis" : "Sidang";
            printRow({to_string(C->info.id), C->info.nama, C->info.kasus, stat}, widths);
            C = C->next;
        }
        P = P->next;
    }
    printBorder(widths);
}

void updateVonis_103012400248(List &L, int idTerdakwa, int tahun) {
    adrTerdakwa C = searchTerdakwa_103012400248(L, idTerdakwa);
    if (C != nullptr) {
        C->info.status = "Vonis";
        C->info.vonisTahun = tahun;
        cout << "[Sukses] Status updated menjadi Vonis (" << tahun << " Tahun)." << endl;
    } else {
        cout << "[Error] Terdakwa dengan ID " << idTerdakwa << " tidak ditemukan." << endl;
    }
}

void showHakimTersibuk_103012400118(List L) {
    clearScreen();
    headerTitle("DASHBOARD HAKIM TERSIBUK");
    cout << endl;

    if (L.first == nullptr) {
        cout << "[!] Data Kosong." << endl;
        return;
    }

    adrHakim P = L.first;
    adrHakim champion = P;

    while (P != nullptr) {
        if (P->info.jumlahKasusSelesai > champion->info.jumlahKasusSelesai) {
            champion = P;
        }
        P = P->next;
    }

    vector<int> wDash = {20, 53};
    printBorder(wDash);
    printRow({"Kategori", "Detail Informasi"}, wDash);
    printBorder(wDash);
    printRow({"Nama Hakim", champion->info.nama}, wDash);
    printRow({"Total Kasus", to_string(champion->info.jumlahKasusSelesai) + " Kasus"}, wDash);
    printBorder(wDash);
}

void showTerdakwaHukumanTerlama_103012400248(List L) {
    clearScreen();
    headerTitle("TERDAKWA HUKUMAN TERBERAT");
    cout << endl;

    if (L.first == nullptr) {
        cout << "[!] Data Kosong." << endl;
        return;
    }

    adrHakim P = L.first;
    adrTerdakwa maxC = nullptr;
    adrHakim hakimPemberiVonis = nullptr;
    int maxVonis = -1;

    while (P != nullptr) {
        adrTerdakwa C = P->firstTerdakwa;
        while (C != nullptr) {
            if (C->info.status == "Vonis" && C->info.vonisTahun > maxVonis) {
                maxVonis = C->info.vonisTahun;
                maxC = C;
                hakimPemberiVonis = P;
            }
            C = C->next;
        }
        P = P->next;
    }

    if (maxC != nullptr) {
        vector<int> wDash = {20, 40};
        printBorder(wDash);
        printRow({"Kategori", "Detail Informasi"}, wDash);
        printBorder(wDash);
        printRow({"Nama Terdakwa", maxC->info.nama}, wDash);
        printRow({"Kasus", maxC->info.kasus}, wDash);
        printRow({"Lama Vonis", to_string(maxC->info.vonisTahun) + " Tahun"}, wDash);
        printRow({"Divonis Oleh", hakimPemberiVonis->info.nama}, wDash);
        printBorder(wDash);
    } else {
        cout << "[!] Belum ada terdakwa yang mendapatkan vonis." << endl;
    }
}