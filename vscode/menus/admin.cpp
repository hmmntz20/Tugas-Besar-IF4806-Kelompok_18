#include "menu.h"

void menuAdmin(List &L) {
    int choice, subChoice, idHakim, idTerdakwa;
    string nHakim, nTerdakwa, kasus;
    
    do {
        printMenu("MENU ADMIN", {
            "[1] Tambah Hakim Baru",
            "[2] Hapus Data Hakim",
            "[3] Tambah Terdakwa Baru",
            "[4] Hapus Data Terdakwa",
            "[5] Lihat Data",
            "[0] Logout"
        });

        cout << " >> Pilih menu: ";
        cin >> choice;

        switch(choice) {
            case 1:
                printMenu("TAMBAH HAKIM BARU", {
                    "[1] Insert First",
                    "[2] Insert Last",
                    "[3] Insert After"
                }, 50);
                cout << ">> Pilihan: "; cin >> subChoice;

                if (subChoice == 1) {
                    cout << "\n[+] Masukkan Nama Hakim Baru : "; cin >> nHakim;
                    insertFirstHakim_103012400248(L, createElmHakim_103012400118(nHakim));
                } else if (subChoice == 2) {
                    cout << "\n[+] Masukkan Nama Hakim Baru : "; cin >> nHakim;
                    insertLastHakim_103012400118(L, createElmHakim_103012400118(nHakim));
                } else if (subChoice == 3) {
                    showDataHakim_103012400248(L);
                    cout << "\n[+] Masukkan Nama Hakim Baru : "; cin >> nHakim;
                    cout << "Insert setelah Hakim urutan ke-: "; cin >> idHakim;
                    insertAfterHakim_103012400248(L, idHakim, createElmHakim_103012400118(nHakim));
                }
                break;

            case 2:
                printMenu("HAPUS DATA HAKIM", {
                    "[1] Delete First",
                    "[2] Delete Last",
                    "[3] Delete After"
                }, 50);
                cout << ">> Pilihan: "; cin >> subChoice;

                if (subChoice == 1) deleteFirstHakim_103012400118(L);
                else if (subChoice == 2) deleteLastHakim_103012400248(L);
                else if (subChoice == 3) {
                    showDataHakim_103012400248(L);
                    cout << "Hapus Hakim setelah urutan ke-: "; cin >> idHakim;
                    deleteAfterHakim_103012400118(L, idHakim);
                }
                break;

            case 3:
                showDataHakim_103012400248(L);
                cout << "\n[+] Masukkan ID Hakim Penanggung Jawab : "; cin >> idHakim;
                if (searchHakim_103012400118(L, idHakim) != nullptr) {
                    printMenu("METODE INSERT TERDAKWA", {
                        "[1] Insert First",
                        "[2] Insert Last",
                        "[3] Insert After"
                    }, 50);
                    cout << ">> Pilihan: "; cin >> subChoice;

                    cout << "\n[+] Nama Terdakwa : "; cin >> nTerdakwa;
                    cout << "[+] Jenis Kasus   : "; cin >> kasus;
                    adrTerdakwa C = createElmTerdakwa_103012400248(L, nTerdakwa, kasus);

                    if (subChoice == 1) insertFirstTerdakwa_103012400118(L, idHakim, C);
                    else if (subChoice == 2) insertLastTerdakwa_103012400248(L, idHakim, C);
                    else if (subChoice == 3) {
                        cout << "Insert setelah Terdakwa ID : "; cin >> idTerdakwa;
                        insertAfterTerdakwa_103012400118(L, idHakim, idTerdakwa, C);
                    }
                } else {
                    cout << "[!] Hakim tidak ditemukan!" << endl;
                }
                break;

            case 4:
                showDataHakim_103012400248(L);
                cout << "\n[-] Masukkan ID Hakim : "; cin >> idHakim;
                if (searchHakim_103012400118(L, idHakim) != nullptr) {
                    printMenu("METODE DELETE TERDAKWA", {
                        "[1] Delete First",
                        "[2] Delete Last",
                        "[3] Delete After"
                    }, 50);
                    cout << ">> Pilihan: "; cin >> subChoice;

                    if (subChoice == 1) deleteFirstTerdakwa_103012400248(L, idHakim);
                    else if (subChoice == 2) deleteLastTerdakwa_103012400118(L, idHakim);
                    else if (subChoice == 3) {
                        cout << "Hapus Terdakwa ID: "; cin >> idTerdakwa;
                        deleteAfterTerdakwa_103012400248(L, idHakim, idTerdakwa);
                    }
                } else {
                    cout << "[!] Hakim tidak ditemukan!" << endl;
                }
                break;

            case 5:
                printMenu("PILIH TAMPILAN DATA", {
                    "[1] Data Hakim",
                    "[2] Data Terdakwa",
                    "[3] Semua Data (Detail)"
                }, 50);
                
                cout << " >> Pilih tampilan: "; cin >> subChoice;
                if (subChoice == 1) showDataHakim_103012400248(L);
                else if (subChoice == 2) showDataTerdakwa_103012400118(L);
                else {
                    clearScreen();
                    headerTitle("DASHBOARD SEMUA DATA");
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