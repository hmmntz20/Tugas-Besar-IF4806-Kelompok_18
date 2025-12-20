#include "menu.h"

void menuUser(List &L) {
    int choice, subChoice, tahun;

    do {
        printMenu("MENU USER", {
            "[1] Lihat Data",
            "[2] Vonis Terdakwa",
            "[3] Komputasi Hakim Tersibuk",
            "[4] Komputasi Hukuman Terdakwa Terlama",
            "[0] Kembali"
        });

        cout << " >> Pilih menu: ";
        cin >> choice;

        switch(choice) {
            case 1:
                printMenu("MENU TAMPILKAN DATA", {
                    "[1] Data Hakim",
                    "[2] Data Terdakwa",
                    "[3] Semua Data"
                }, 50);

                cout << ">> Pilihan: "; cin >> subChoice;
                if (subChoice == 1) showDataHakim_103012400248(L);
                else if (subChoice == 2) showDataTerdakwa_103012400118(L);
                else {
                    clearScreen();
                    headerTitle("DASHBOARD SEMUA DATA");
                    showAllData_103012400118(L);
                }
                cout << "\nTekan Enter untuk kembali..."; cin.ignore(); cin.get();
                break;

                case 2: {
                    clearScreen();
                    headerTitle("VONIS TERDAKWA");
                    showAllData_103012400118(L);
    
                    bool adaTerdakwa = false;
                    adrHakim P = L.first;
                    
                    // Cek ada terdakwa gak
                    while (P != nullptr) {
                        if (P->firstTerdakwa != nullptr) {
                            adaTerdakwa = true;
                            break;
                        }
                        P = P->next;
                    }
    
                    if (!adaTerdakwa) {
                        if (L.first != nullptr) {
                            cout << "\n[!] Data Kosong." << endl;
                        }
                        cout << "\nTekan Enter untuk kembali..."; cin.ignore(); cin.get();
                    } else {
                        int idTerdakwa;
                        cout << "\n[-] Masukkan ID Terdakwa yang ingin divonis : "; cin >> idTerdakwa;
                        cout << "Lama Hukuman (Tahun)                : "; cin >> tahun;
                        
                        updateVonis_103012400248(L, idTerdakwa, tahun); 
                        
                        cout << "\nTekan Enter untuk kembali..."; 
                        cin.ignore(); 
                        cin.get();
                    }
                    break;
            }

            case 3:
                clearScreen();
                showHakimTersibuk_103012400118(L); 
                cout << "\nTekan Enter untuk kembali..."; cin.ignore(); cin.get();
                break;

            case 4:
                showTerdakwaHukumanTerlama_103012400248(L);
                cout << "\nTekan Enter untuk kembali..."; cin.ignore(); cin.get();
                break;

            case 0:
                cout << "Kembali ke menu utama..." << endl;
                break;
                
            default:
                cout << "[!] Pilihan tidak valid." << endl;
        }
    } while (choice != 0);
}