#include "menu.h"

void menuUser(List &L) {
    int choice, tahun;
    string nTerdakwa;

    do {
        clearScreen();
        printLine('-');
        printCenter("MENU USER");
        printLine('-');
        cout << "|  [1] Lihat Semua Data                                 |" << endl;
        cout << "|  [2] Keputusan Sidang                                          |" << endl;
        cout << "|  [3] Laporan Hakim Tersibuk                             |" << endl;
        cout << "|  [0] Kembali ke Main Menu                                            |" << endl;
        printLine('-');
        cout << " >> Pilih menu: ";
        cin >> choice;

        switch(choice) {
            case 1:
                showAllData_103012400118(L); 
                cout << "\nTekan Enter kembali..."; cin.ignore(); cin.get();
                break;

            case 2:
                showAllData_103012400118(L);
                headerTitle("KETOK PALU HAKIM");
                cout << "Masukkan Nama Terdakwa yang divonis : "; cin >> nTerdakwa;
                cout << "Lama Hukuman (Tahun)                : "; cin >> tahun;
                updateVonis_103012400248(L, nTerdakwa, tahun); 
                cout << "\nTekan Enter kembali..."; cin.ignore(); cin.get();
                break;

            case 3:
                clearScreen();
                showHakimTersibuk_103012400118(L); 
                cout << "\nTekan Enter kembali..."; cin.ignore(); cin.get();
                break;

            case 0:
                cout << "Kembali ke menu utama..." << endl;
                break;
                
            default:
                cout << "[!] Pilihan tidak valid." << endl;
        }
    } while (choice != 0);
}