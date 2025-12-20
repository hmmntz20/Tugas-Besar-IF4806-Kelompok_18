#include "widgets.h"

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

string center(string content, int width) {
    if ((int)content.length() >= width) return content;
    int padding = (width - content.length()) / 2;
    return string(padding, ' ') + content + string(width - content.length() - padding, ' ');
}

void printBorder(vector<int> widths, string prefix) {
    cout << prefix << "+";
    for (int w : widths) {
        cout << string(w + 2, '=') << "+";
    }
    cout << endl;
}

void printRow(vector<string> cols, vector<int> widths, string prefix) {
    cout << prefix << "|";
    for (size_t i = 0; i < cols.size(); i++) {
        string content = cols[i];
        
        if ((int)content.length() > widths[i]) {
            if (widths[i] > 2) {
                content = content.substr(0, widths[i] - 2) + "..";
            } else {
                content = content.substr(0, widths[i]);
            }
        }
        
        cout << " " << left << setw(widths[i]) << content << " |";
    }
    cout << endl;
}

void printMenu(string title, vector<string> options, int width) {
    clearScreen();
    headerTitle(title);
    cout << endl;
    vector<int> w = {width};
    printBorder(w);
    for (string opt : options) printRow({opt}, w);
    printBorder(w);
}

void headerTitle(string title) {
    printLine('=');
    printCenter(title);
    printLine('=');
}


void printCenter(string content) {
    int width = 80;
    int padding = (width - content.length()) / 2;
    cout << string(padding, ' ') << content << endl;
}

void printLine(char c) {
    cout << string(80, c) << endl;
}