#include "menu.h"

void menuUser(List &L) {
    int choice, subChoice, tahun;
    string nTerdakwa;

    do {
        clearScreen();
        printLine('-');
        printCenter("MENU USER");
        printLine('-');
        cout << "|  [1] Lihat Data                                                      |" << endl;
        cout << "|  [2] Keputusan Sidang                                                |" << endl;
        cout << "|  [3] Laporan Hakim Tersibuk                                          |" << endl;
        cout << "|  [0] Logout                                                          |" << endl;
        printLine('-');
        cout << " >> Pilih menu: ";
        cin >> choice;

        switch(choice) {
            case 1:
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
                cout << "\nTekan Enter untuk kembali..."; cin.ignore(); cin.get();
                break;

            case 2:
                showAllData_103012400118(L);
                headerTitle("KETOK PALU HAKIM");
                cout << "Masukkan Nama Terdakwa yang divonis : "; cin >> nTerdakwa;
                cout << "Lama Hukuman (Tahun)                : "; cin >> tahun;
                updateVonis_103012400248(L, nTerdakwa, tahun); 
                cout << "\nTekan Enter untuk kembali..."; cin.ignore(); cin.get();
                break;

            case 3:
                clearScreen();
                showHakimTersibuk_103012400118(L); 
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