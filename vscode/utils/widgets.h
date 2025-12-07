#ifndef WIDGETS_H
#define WIDGETS_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const int UI_WIDTH = 72;

void clearScreen();
string cell(string teks, int lebar);
string center(string teks, int lebar);
void garis();
void printLine(char k);
void headerTitle(string title);
void printCenter(string teks);

#endif