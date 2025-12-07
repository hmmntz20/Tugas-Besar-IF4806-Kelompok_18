#include "menu.h"

void menuAdmin(List &L) {
    int choice;
    string nHakim, nip, nTerdakwa, kasus;
    char confirm;

    do {
        clearScreen();
        printLine('-');
        printCenter("MENU ADMIN");
        printLine('-');
        // cout << "|  [1] Tambah Hakim Baru                               |" << endl;
        cout << "| " << cell(" [1] Tambah Hakim Baru", 68) << " |" << endl;
        cout << "|  [2] Hapus Hakim                  |" << endl;
        cout << "|  [3] Registrasi Terdakwa Baru                        |" << endl;
        cout << "|  [4] Hapus Data Terdakwa                             |" << endl;
        cout << "|  [5] Lihat Semua Data                |" << endl;
        cout << "|  [0] Kembali ke Main Menu                            |" << endl;
        printLine('-');
        cout << " >> Pilih menu: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "\n[+] Masukkan Nama Hakim : "; cin >> nHakim;
                cout << "[+] Masukkan NIP Hakim  : "; cin >> nip;
                insertHakim_103012400118(L, createElmHakim_103012400118(nHakim, nip));
                cout << "[INFO] Hakim berhasil didaftarkan." << endl;
                break;

            case 2:
                showAllData_103012400118(L);
                cout << "\n[-] Masukkan Nama Hakim yg dihapus : "; cin >> nHakim;
                cout << "WARNING: Data terdakwa di bawahnya akan hilang. Yakin? (y/n): ";
                cin >> confirm;
                if(confirm == 'y' || confirm == 'Y') {
                    deleteHakim_103012400118(L, nHakim);
                } else {
                    cout << "[INFO] Dibatalkan." << endl;
                }
                break;

            case 3:
                showAllData_103012400118(L); 
                cout << "\n[+] Masukkan Nama Hakim Penanggung Jawab : "; cin >> nHakim;
                if (searchHakim_103012400248(L, nHakim) != NULL) {
                    cout << "[+] Nama Terdakwa : "; cin >> nTerdakwa;
                    cout << "[+] Jenis Kasus   : "; cin >> kasus;
                    insertTerdakwa_103012400248(L, nHakim, createElmTerdakwa_103012400248(nTerdakwa, kasus));
                } else {
                    cout << "[!] Hakim tidak ditemukan!" << endl;
                }
                break;

            case 4:
                showAllData_103012400118(L); 
                cout << "\n[-] Masukkan Nama Hakim    : "; cin >> nHakim;
                cout << "[-] Masukkan Nama Terdakwa : "; cin >> nTerdakwa;
                deleteTerdakwa_103012400248(L, nHakim, nTerdakwa); 
                break;

            case 5:
                showAllData_103012400118(L);
                cout << "\nTekan Enter kembali..."; 
                cin.ignore(); cin.get();
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