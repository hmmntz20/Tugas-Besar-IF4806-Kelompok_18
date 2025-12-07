#include "list.h"
#include "../utils/widgets.h"

void createList_103012400118(List &L) {
    L.first = nullptr;
}

adrHakim createElmHakim_103012400118(string nama, string nip) {
    adrHakim P = new elmHakim;
    P->info.nama = nama;
    P->info.NIP = nip;
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

void insertHakim_103012400118(List &L, adrHakim P) {
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

adrHakim searchHakim_103012400248(List L, string nama) {
    adrHakim P = L.first;
    while (P != nullptr) {
        if (P->info.nama == nama) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void insertTerdakwa_103012400248(List &L, string namaHakim, adrTerdakwa C) {
    adrHakim P = searchHakim_103012400248(L, namaHakim);

    if (P == nullptr) {
        cout << "[Error] Hakim dengan nama " << namaHakim << " tidak ditemukan." << endl;
    } else {
        if (P->firstTerdakwa == nullptr) {
            P->firstTerdakwa = C;
        } else {
            adrTerdakwa Q = P->firstTerdakwa;
            while (Q->next != nullptr) {
                Q = Q->next;
            }
            Q->next = C;
        }
        cout << "[Sukses] Terdakwa " << C->info.nama << " ditambahkan ke Hakim " << namaHakim << endl;
    }
}

void deleteTerdakwa_103012400248(List &L, string namaHakim, string namaTerdakwa) {
    adrHakim P = searchHakim_103012400248(L, namaHakim);
    if (P == nullptr) {
        cout << "[!] Hakim tidak ditemukan." << endl;
        return;
    }

    adrTerdakwa C = P->firstTerdakwa;
    adrTerdakwa prev = nullptr;

    while (C != nullptr && C->info.nama != namaTerdakwa) {
        prev = C;
        C = C->next;
    }

    if (C == nullptr) {
        cout << "[!] Terdakwa tidak ditemukan pada hakim ini." << endl;
        return;
    }

    if (C == P->firstTerdakwa) {
        P->firstTerdakwa = C->next;
    } else {
        prev->next = C->next;
    }
    
    delete C;
    cout << "[Sukses] Data terdakwa " << namaTerdakwa << " berhasil dihapus." << endl;
}

void deleteHakim_103012400118(List &L, string namaHakim) {
    adrHakim P = L.first;
    adrHakim prev = nullptr;

    while (P != nullptr && P->info.nama != namaHakim) {
        prev = P;
        P = P->next;
    }

    if (P == nullptr) {
        cout << "[Info] Hakim tidak ditemukan." << endl;
        return;
    }

    adrTerdakwa C = P->firstTerdakwa;
    while (C != nullptr) {
        adrTerdakwa temp = C;
        C = C->next;
        delete temp;
    }

    if (P == L.first) {
        L.first = P->next;
    } else {
        prev->next = P->next;
    }
    delete P;
    cout << "[Sukses] Hakim " << namaHakim << " dan seluruh kasusnya telah dihapus." << endl;
}

void showAllData_103012400118(List L) {
    clearScreen();
    headerTitle("LIST DATA HAKIM DAN TERDAKWA");
    cout << endl;
    if (L.first == nullptr) {
        cout << "|                          DATA MASIH KOSONG                           |" << endl;
        cout << "+======================================================================+" << endl;
        return;
    }

    cout << "+====+==========================================+======================+" << endl;
    cout << "| NO | " << cell("NAMA HAKIM", 40) << " | " << cell("NIP", 20) << " |" << endl;
    cout << "+====+==========================================+======================+" << endl;

    adrHakim P = L.first;
    int i = 1;

    while (P != nullptr) {
        cout << "| " << cell(to_string(i), 2) << " | " 
             << cell(P->info.nama, 40) << " | " 
             << cell(P->info.NIP, 20) << " |" << endl;
        
        cout << "|    +-------------------------+----------------+----------------------+" << endl;

        adrTerdakwa C = P->firstTerdakwa;

        if (C == nullptr) {
            cout << "|    | " << center("BELUM ADA KASUS YANG DITANGANI", 61) << " |" << endl;
        } else {
            cout << "|    | NO | " << cell("NAMA TERDAKWA", 19) 
                 << " | " << cell("JENIS KASUS", 14) 
                 << " | " << cell("STATUS VONIS", 18) << " |" << endl;
            
            cout << "|    +----+---------------------+----------------+--------------------+" << endl;

            int j = 1;
            while (C != nullptr) {
                string statusStr = C->info.status;
                if (C->info.status == "Vonis") {
                    statusStr += " (" + to_string(C->info.vonisTahun) + " Thn)";
                }

                cout << "|    | " << cell(to_string(j), 2) << " | "
                     << cell(C->info.nama, 19) << " | "
                     << cell(C->info.kasus, 14) << " | "
                     << cell(statusStr, 18) << " |" << endl;

                C = C->next;
                j++;
            }
        }

        cout << "+====+==========================================+======================+" << endl;
        
        P = P->next;
        i++;
    }
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
    cout << "| " << " [-] NIP         :  "<< cell(champion->info.NIP, 48) << " |" << endl;
    cout << "| " << " [-] Total Kasus :  "<< cell(to_string(champion->info.jumlahKasusSelesai), 48) << " |" << endl;
    printLine('=');
    // cout << "Nama  : " << champion->info.nama << endl;
    // cout << "NIP  : " << champion->info.NIP << endl;
    // cout << "Total : " << champion->info.jumlahKasusSelesai << " Kasus" << endl;
}