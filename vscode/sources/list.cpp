#include "list.h"
#include "../utils/widgets.h"

void createList_103012400118(List &L) {
    L.first = nullptr;
}

adrHakim createElmHakim_103012400118(string nama) {
    adrHakim P = new elmHakim;
    P->info.nama = nama;
    P->next = nullptr;
    P->firstTerdakwa = nullptr;
    P->info.jumlahKasusSelesai = 0;
    return P;
}

adrTerdakwa createElmTerdakwa_103012400248(string nama, string kasus) {
    adrTerdakwa P = new elmTerdakwa;
    P->info.nama = nama;
    P->info.kasus = kasus;
    P->info.status = "Sidang";
    P->info.vonisTahun = 0;
    P->next = nullptr;
    return P;
}

void insertFirstHakim(List &L, adrHakim P) {
    P->next = L.first;
    L.first = P;
}

void insertLastHakim(List &L, adrHakim P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        adrHakim Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfterHakim(List &L, int id, adrHakim P) {
    adrHakim Prec = L.first;
    int i = 1;
    while (Prec != nullptr && i < id) {
        Prec = Prec->next;
        i++;
    }
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
        cout << "[Sukses] Hakim ditambahkan setelah urutan ke-" << id << endl;
    } else {
        cout << "[!] Urutan Hakim tidak valid (melebihi jumlah data)." << endl;
    }
}

void deleteChildrenOfHakim(adrHakim P) {
    if (P == nullptr) return;
    adrTerdakwa C = P->firstTerdakwa;
    while (C != nullptr) {
        adrTerdakwa temp = C;
        C = C->next;
        delete temp;
    }
    P->firstTerdakwa = nullptr;
}

void deleteFirstHakim(List &L) {
    if (L.first == nullptr) {
        cout << "[!] List Hakim Kosong." << endl;
        return;
    }
    adrHakim P = L.first;
    L.first = P->next;
    deleteChildrenOfHakim(P);
    delete P;
    cout << "[Sukses] Hakim urutan pertama berhasil dihapus." << endl;
}

void deleteLastHakim(List &L) {
    if (L.first == nullptr) {
        cout << "[!] List Hakim Kosong." << endl;
        return;
    }
    if (L.first->next == nullptr) {
        deleteFirstHakim(L);
        return;
    }
    adrHakim Q = L.first;
    while (Q->next->next != nullptr) {
        Q = Q->next;
    }
    adrHakim P = Q->next;
    Q->next = nullptr;
    deleteChildrenOfHakim(P);
    delete P;
    cout << "[Sukses] Hakim urutan terakhir berhasil dihapus." << endl;
}

void deleteAfterHakim(List &L, int id) {
    adrHakim Prec = L.first;
    int i = 1;
    while (Prec != nullptr && i < id) {
        Prec = Prec->next;
        i++;
    }
    if (Prec != nullptr && Prec->next != nullptr) {
        adrHakim P = Prec->next;
        Prec->next = P->next;
        deleteChildrenOfHakim(P);
        delete P;
        cout << "[Sukses] Hakim setelah urutan ke-" << id << " berhasil dihapus." << endl;
    } else {
        cout << "[!] Gagal. Urutan tidak ditemukan atau tidak ada elemen setelahnya." << endl;
    }
}

void insertFirstTerdakwa(List &L, int idHakim, adrTerdakwa C) {
    adrHakim P = searchHakim_103012400248(L, idHakim);
    if (P != nullptr) {
        C->next = P->firstTerdakwa;
        P->firstTerdakwa = C;
        cout << "[Sukses] Terdakwa ditambahkan di awal list hakim " << P->info.nama << endl;
    } else {
        cout << "[!] Hakim tidak ditemukan." << endl;
    }
}

void insertLastTerdakwa(List &L, int idHakim, adrTerdakwa C) {
    adrHakim P = searchHakim_103012400248(L, idHakim);
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
        cout << "[Sukses] Terdakwa ditambahkan di akhir list hakim " << P->info.nama << endl;
    } else {
        cout << "[!] Hakim tidak ditemukan." << endl;
    }
}

void insertAfterTerdakwa(List &L, int idHakim, int id, adrTerdakwa C) {
    adrHakim P = searchHakim_103012400248(L, id);
    if (P == nullptr) {
        cout << "[!] Hakim tidak ditemukan." << endl;
        return;
    }
    adrTerdakwa Prec = P->firstTerdakwa;
    int i = 1;
    while (Prec != nullptr && i < id) {
        Prec = Prec->next;
        i++;
    }
    if (Prec != nullptr) {
        C->next = Prec->next;
        Prec->next = C;
        cout << "[Sukses] Terdakwa ditambahkan setelah urutan ke-" << id << endl;
    } else {
        cout << "[!] Urutan Terdakwa tidak valid." << endl;
    }
}

void deleteFirstTerdakwa(List &L, int idHakim) {
    adrHakim P = searchHakim_103012400248(L, idHakim);
    if (P == nullptr || P->firstTerdakwa == nullptr) {
        cout << "[!] Gagal. Hakim tidak ditemukan atau list terdakwa kosong." << endl;
        return;
    }
    adrTerdakwa C = P->firstTerdakwa;
    P->firstTerdakwa = C->next;
    delete C;
    cout << "[Sukses] Terdakwa pertama dihapus dari hakim " << P->info.nama << endl;
}

void deleteLastTerdakwa(List &L, int idHakim) {
    adrHakim P = searchHakim_103012400248(L, idHakim);
    if (P == nullptr || P->firstTerdakwa == nullptr) {
        cout << "[!] Gagal." << endl;
        return;
    }
    
    if (P->firstTerdakwa->next == nullptr) {
        deleteFirstTerdakwa(L, idHakim);
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

void deleteAfterTerdakwa(List &L, int idHakim, int id) {
    adrHakim P = searchHakim_103012400248(L, idHakim);
    if (P == nullptr) {
        cout << "[!] Hakim tidak ditemukan." << endl;
        return;
    }
    adrTerdakwa Prec = P->firstTerdakwa;
    int i = 1;
    while (Prec != nullptr && i < id) {
        Prec = Prec->next;
        i++;
    }
    if (Prec != nullptr && Prec->next != nullptr) {
        adrTerdakwa C = Prec->next;
        Prec->next = C->next;
        delete C;
        cout << "[Sukses] Terdakwa setelah urutan ke-" << id << " dihapus." << endl;
    } else {
        cout << "[!] Gagal. Urutan tidak ketemu atau ini elemen terakhir." << endl;
    }
}

adrHakim searchHakim_103012400248(List L, int id) {
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

void showAllData_103012400118(List L) {
    clearScreen();
    headerTitle("DASHBOARD MONITORING PERSIDANGAN");
    cout << endl;

    if (L.first == nullptr) {
        cout << "|                          DATA MASIH KOSONG                           |" << endl;
        cout << "+======================================================================+" << endl;
        return;
    }

    cout << "+====+=========================================================+=======+" << endl;
    cout << "| Id | " << cell("NAMA HAKIM", 53) << " | " << cell("KASUS", 5) << " |" << endl;
    cout << "+====+=========================================================+=======+" << endl;

    adrHakim P = L.first;
    int i = 1;

    while (P != nullptr) {
        cout << "| " << cell(to_string(i), 2) << " | " 
             << cell(P->info.nama, 53) << " | "
             << cell(to_string(P->info.jumlahKasusSelesai), 5) << " |" << endl;
        
        cout << "|    +---------------------------+-------------------+-----------------+" << endl;

        adrTerdakwa C = P->firstTerdakwa;

        if (C == nullptr) {
            cout << "|    | " << center("BELUM ADA KASUS YANG DITANGANI", 59) << " |" << endl;
        } else {
            cout << "|    | Id | " << cell("NAMA TERDAKWA", 23) 
                 << " | " << cell("JENIS KASUS", 15) 
                 << " | " << cell("STATUS", 13) << " |" << endl;
            
            cout << "|    +----+-------------------------+-----------------+-----------------+" << endl;

            int j = 1;
            while (C != nullptr) {
                string statusStr = C->info.status;
                if (C->info.status == "Vonis") {
                    statusStr += " (" + to_string(C->info.vonisTahun) + " Thn)";
                }

                cout << "|    | " << cell(to_string(j), 2) << " | "
                     << cell(C->info.nama, 23) << " | "
                     << cell(C->info.kasus, 15) << " | "
                     << cell(statusStr, 13) << " |" << endl;

                C = C->next;
                j++;
            }
        }
        cout << "+====+=========================================================+=======+" << endl;
        
        P = P->next;
        i++;
    }
}

void showDataHakim(List L) {
    clearScreen();
    headerTitle("DATA HAKIM TERDAFTAR");
    cout << endl;

    if (L.first == nullptr) {
        cout << "|                          DATA MASIH KOSONG                           |" << endl;
        cout << "+======================================================================+" << endl;
        return;
    }

    cout << "+====+======================================================+==========+" << endl;
    cout << "| ID | " << cell("NAMA HAKIM", 50) << " | " 
         << cell("PERFORMA", 8) << " |" << endl;
    cout << "+====+======================================================+==========+" << endl;

    adrHakim P = L.first;
    int i = 1;
    while (P != nullptr) {
        cout << "| " << cell(to_string(i), 2) << " | " 
             << cell(P->info.nama, 50) << " | "
             << cell(to_string(P->info.jumlahKasusSelesai), 8) << " |" << endl;
        P = P->next;
        i++;
    }
    cout << "+====+======================================================+==========+" << endl;
}

void showDataTerdakwa(List L) {
    clearScreen();
    headerTitle("DAFTAR SELURUH TERDAKWA");
    cout << endl;

    bool isEmpty = true;
    adrHakim P = L.first;
    while(P != nullptr){
        if(P->firstTerdakwa != nullptr) isEmpty = false;
        P = P->next;
    }

    if (isEmpty) {
        cout << "|                     BELUM ADA DATA TERDAKWA                          |" << endl;
        cout << "+======================================================================+" << endl;
        return;
    }

    cout << "+====+=============================+====================+==============+" << endl;
    cout << "| ID | " << cell("NAMA TERDAKWA", 27) << " | " 
         << cell("KASUS", 18) << " | " 
         << cell("STATUS", 12) << " |" << endl;
    cout << "+====+=============================+====================+==============+" << endl;

    P = L.first;
    int i = 1;
    
    while (P != nullptr) {
        adrTerdakwa C = P->firstTerdakwa;
        while (C != nullptr) {
            string stat = (C->info.status == "Vonis") ? "Vonis" : "Sidang";
            
            cout << "| " << cell(to_string(i), 2) << " | " 
                 << cell(C->info.nama, 27) << " | " 
                 << cell(C->info.kasus, 18) << " | "
                 << cell(stat, 12) << " |" << endl;
            
            C = C->next;
            i++;
        }
        P = P->next;
    }
    cout << "+====+=============================+====================+==============+" << endl;
}

void updateVonis_103012400248(List &L, string namaTerdakwa, int tahun) {
    adrHakim P = L.first;
    bool found = false;

    while (P != nullptr && !found) {
        adrTerdakwa C = P->firstTerdakwa;
        while (C != nullptr) {
            if (C->info.nama == namaTerdakwa) {
                if (C->info.status != "Vonis") { 
                    P->info.jumlahKasusSelesai++;
                }
                
                C->info.status = "Vonis";
                C->info.vonisTahun = tahun;
                cout << "[Sukses] Vonis updated. Performa Hakim " << P->info.nama << " +1." << endl;
                found = true;
                break;
            }
            C = C->next;
        }
        P = P->next;
    }
    if (!found) cout << "[Error] Terdakwa tidak ditemukan." << endl;
}

void showHakimTersibuk_103012400118(List L) {
    if (L.first == nullptr) return;

    adrHakim P = L.first;
    adrHakim champion = P;

    while (P != nullptr) {
        if (P->info.jumlahKasusSelesai > champion->info.jumlahKasusSelesai) {
            champion = P;
        }
        P = P->next;
    }

    headerTitle("HAKIM TERSIBUK");
    cout << "| " << " [-] Nama        :  "<< cell(champion->info.nama, 48) << " |" << endl;
    cout << "| " << " [-] Total Kasus :  "<< cell(to_string(champion->info.jumlahKasusSelesai), 48) << " |" << endl;
    printLine('=');
    // cout << "Nama  : " << champion->info.nama << endl;
    // cout << "Total : " << champion->info.jumlahKasusSelesai << " Kasus" << endl;
}