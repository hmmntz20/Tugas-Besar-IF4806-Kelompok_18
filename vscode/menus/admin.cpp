#include "menu.h"

void menuAdmin(List &L) {
    int choice, subChoice, idHakim, idTerdakwa;
    string nHakim, nTerdakwa, kasus;
    char confirm;

    do {
        clearScreen();
        printLine('-');
        printCenter("MENU ADMIN");
        printLine('-');
        // cout << "|  [1] Tambah Hakim Baru                               |" << endl;
        cout << "| " << cell(" [1] Tambah Hakim", 68) << " |" << endl;
        cout << "|  [2] Hapus Hakim                                        |" << endl;
        cout << "|  [3] Tambah Terdakwa                                             |" << endl;
        cout << "|  [4] Hapus Data Terdakwa                                |" << endl;
        cout << "|  [5] Lihat Data                                         |" << endl;
        cout << "|  [0] Logout                                             |" << endl;
        printLine('-');
        cout << " >> Pilih menu: ";
        cin >> choice;

        switch(choice) {
            case 1:
                clearScreen();
                headerTitle("TAMBAH HAKIM BARU");
                cout << "\nPilih metode insert:" << endl;
                cout << "[1] Insert First" << endl;
                cout << "[2] Insert Last" << endl;
                cout << "[3] Insert After" << endl;
                cout << ">> Pilihan: "; cin >> subChoice;

                if (subChoice == 1) {
                    cout << "\n[+] Masukkan Nama Hakim Baru : "; cin >> nHakim;
                    adrHakim P = createElmHakim_103012400118(nHakim);
                    insertFirstHakim(L, P);
                } else if (subChoice == 2) {
                    cout << "\n[+] Masukkan Nama Hakim Baru : "; cin >> nHakim;
                    adrHakim P = createElmHakim_103012400118(nHakim);
                    insertLastHakim(L, P);
                } else if (subChoice == 3) {
                    showDataHakim(L);
                    cout << "\n[+] Masukkan Nama Hakim Baru : "; cin >> nHakim;
                    cout << "Insert setelah Hakim ke-: "; cin >> idHakim;
                    adrHakim P = createElmHakim_103012400118(nHakim);
                    insertAfterHakim(L, idHakim, P);
                } else {
                    cout << "[!] Metode tidak valid. Batal." << endl;
                }
                break;

            case 2:
                clearScreen();
                headerTitle("HAPUS DATA HAKIM");
                cout << "Pilih metode delete:" << endl;
                cout << "[1] Delete First" << endl;
                cout << "[2] Delete Last" << endl;
                cout << "[3] Delete After" << endl;
                cout << ">> Pilihan: "; cin >> subChoice;

                if (subChoice == 1) {
                    deleteFirstHakim(L);
                } else if (subChoice == 2) {
                    deleteLastHakim(L);
                } else if (subChoice == 3) {
                    showDataHakim(L);
                    cout << "Hapus Hakim setelah urutan ke-: "; cin >> idHakim;
                    deleteAfterHakim(L, idHakim);
                } else {
                        cout << "[!] Metode tidak valid. Batal." << endl;
                }
                break;

            case 3:
                showDataHakim(L);
                cout << "\n[+] Masukkan ID Hakim Penanggung Jawab : "; cin >> idHakim;
                if (searchHakim_103012400248(L, idHakim) != nullptr) {
                    cout << "Pilih metode insert Terdakwa:" << endl;
                    cout << "[1] Insert First" << endl;
                    cout << "[2] Insert Last" << endl;
                    cout << "[3] Insert After" << endl;
                    cout << ">> Pilihan: "; cin >> subChoice;

                    cout << "\n[+] Nama Terdakwa : "; cin >> nTerdakwa;
                    cout << "[+] Jenis Kasus   : "; cin >> kasus;
                    adrTerdakwa C = createElmTerdakwa_103012400248(nTerdakwa, kasus);

                    if (subChoice == 1) insertFirstTerdakwa(L, idHakim, C);
                    else if (subChoice == 2) insertLastTerdakwa(L, idHakim, C);
                    else if (subChoice == 3) {
                        cout << "Insert setelah Terdakwa ke-: "; cin >> idTerdakwa;
                        insertAfterTerdakwa(L, idHakim, idTerdakwa, C);
                    }
                } else {
                    cout << "[!] Hakim tidak ditemukan!" << endl;
                }
                break;

            case 4:
                showDataHakim(L);
                cout << "\n[-] Masukkan Nama Hakim : "; cin >> idHakim;
                if (searchHakim_103012400248(L, idHakim) != nullptr) {
                    cout << "Pilih metode delete Terdakwa:" << endl;
                    cout << "[1] Delete First" << endl;
                    cout << "[2] Delete Last" << endl;
                    cout << "[3] Delete After" << endl;
                    cout << ">> Pilihan: "; cin >> subChoice;

                    if (subChoice == 1) deleteFirstTerdakwa(L, idHakim);
                    else if (subChoice == 2) deleteLastTerdakwa(L, idHakim);
                    else if (subChoice == 3) {
                        cout << "Hapus Terdakwa ke-: "; cin >> idTerdakwa;
                        deleteAfterTerdakwa(L, idHakim, idTerdakwa);
                    }
                } else {
                    cout << "[!] Hakim tidak ditemukan!" << endl;
                }
                break;

            case 5:
                clearScreen();
                printLine('-');
                printCenter("PILIH TAMPILAN DATA");
                printLine('-');
                cout << "|  [1] Data Hakim                                                      |" << endl;
                cout << "|  [2] Data Terdakwa                                                   |" << endl;
                cout << "|  [3] Semua Data                                                      |" << endl;
                printLine('-');
                cout << " >> Pilih tampilan: ";
                cin >> subChoice;
                if (subChoice == 1) {
                    showDataHakim(L);
                } else if (subChoice == 2) {
                    showDataTerdakwa(L);
                } else {
                    showAllData_103012400118(L);
                }
                cout << "\nTekan Enter kembali..."; cin.ignore(); cin.get();
                break;
                
            case 0:
                cout << "Kembali ke menu utama..." << endl;
                break;

            default:
                cout << "[!] Pilihan tidak valid." << endl;
        }
        
        if(choice != 0 && choice != 5) {
            cout << "\nTekan Enter untuk lanjut...";
            cin.ignore(); cin.get();
        }

    } while (choice != 0);
}