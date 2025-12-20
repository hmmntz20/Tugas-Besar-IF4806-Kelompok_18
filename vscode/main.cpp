#include "sources/list.h"
#include "utils/widgets.h"
#include "menus/menu.h"

int main() {
    List L;
    createList_103012400118(L);

    insertLastHakim_103012400118(L, createElmHakim_103012400118("Hamam_Nashiruddin"));
    insertLastHakim_103012400118(L, createElmHakim_103012400118("Faza_Fawzan"));
    insertLastHakim_103012400118(L, createElmHakim_103012400118("Boboiboy"));
    insertLastHakim_103012400118(L, createElmHakim_103012400118("Gatau"));
    insertLastTerdakwa_103012400248(L, 1, createElmTerdakwa_103012400248(L, "Zukowee", "Korupsi"));
    insertLastTerdakwa_103012400248(L, 1, createElmTerdakwa_103012400248(L, "Megalodon", "Korupsi"));
    insertLastTerdakwa_103012400248(L, 1, createElmTerdakwa_103012400248(L, "Bwahahalil", "Korupsi"));
    insertLastTerdakwa_103012400248(L, 2, createElmTerdakwa_103012400248(L, "Asep", "Mencuri"));
    insertLastTerdakwa_103012400248(L, 2, createElmTerdakwa_103012400248(L, "Cecep", "Mencuri"));
    insertLastTerdakwa_103012400248(L, 2, createElmTerdakwa_103012400248(L, "Tatang", "Mencuri"));
    insertLastTerdakwa_103012400248(L, 3, createElmTerdakwa_103012400248(L, "Rachel", "Berbohong"));
    insertLastTerdakwa_103012400248(L, 3, createElmTerdakwa_103012400248(L, "Gufron", "Pelecehan"));
    insertLastTerdakwa_103012400248(L, 3, createElmTerdakwa_103012400248(L, "Miftah", "Guz_Palsu"));

    int choice;

    do {
        printMenu("SISTEM MANAJEMEN PENGADILAN", {
            "[1] Login as Admin",
            "[2] Login as User",
            "[0] Exit"
        });
        // printCenter("Created by 103012400118 & 103012400248");
        cout << endl;

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