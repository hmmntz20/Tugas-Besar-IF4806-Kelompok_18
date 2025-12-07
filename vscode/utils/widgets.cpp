#include "widgets.h"

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

string cell(string teks, int lebar) {
    if (teks.length() > lebar) {
        return teks.substr(0, lebar - 2) + ".."; 
    }
    string hasil = teks;
    while (hasil.length() < lebar) hasil += " ";
    return hasil;
}

string center(string teks, int lebar) {
    if (teks.length() >= lebar) return teks;
    int sisa = lebar - teks.length();
    int kiri = sisa / 2;
    string hasil = "";
    for(int i=0; i<kiri; i++) hasil += " ";
    hasil += teks;
    while (hasil.length() < lebar) hasil += " ";
    return hasil;
}

void garis() {
    cout << "+------+----------------------+-----------------+----------------------+" << endl;
}

void printLine(char k) {
    for (int i = 0; i < UI_WIDTH; i++) cout << k;
    cout << endl;
}

void headerTitle(string title) {
    cout << endl;
    cout << "+======================================================================+" << endl;
    cout << "|" << center(title, 70) << "|" << endl;
    cout << "+======================================================================+" << endl;
}

void printCenter(string teks) {
    int len = teks.length();
    int boxWidth = UI_WIDTH - 4;
    
    if (len >= boxWidth) {
        cout << "| " << teks.substr(0, boxWidth) << " |" << endl;
        return;
    }
    
    cout << "| " << center(teks, boxWidth) << " |" << endl;
}