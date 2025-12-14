#include "sources/list.h"
#include "utils/widgets.h"
#include "menus/menu.h"


int main() {
    List L;
    createList_103012400118(L);

    insertLastHakim(L, createElmHakim_103012400118("Dedy_Corbuzier"));
    insertLastHakim(L, createElmHakim_103012400118("Corbuzier_Dedy"));
    insertLastTerdakwa(L, 1, createElmTerdakwa_103012400248("Rina_Nose", "Pencurian"));

    int choice;
    do {
        clearScreen();
        headerTitle("SISTEM MANAJEMEN PENGADILAN");
        printCenter("Created by 103012400118 & 103012400248");
        printLine('=');
        cout << "|  [1] Login as Admin                                                  |" << endl;
        cout << "|  [2] Login as User                                                   |" << endl;
        cout << "|  [0] Exit                                                            |" << endl;
        printLine('=');
        cout << " >> Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                menuAdmin(L); 
                break;
            case 2: 
                menuUser(L); 
                break;
            case 0: 
                cout << "\nEnd." << endl; 
                break;
            default: 
                cout << "[!] Pilihan tidak valid." << endl;
        }
    } while (choice != 0);

    return 0;
}