#ifndef WIDGETS_H_INCLUDED
#define WIDGETS_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

string center(string content, int width);

void printBorder(vector<int> widths, string prefix = "");
void printRow(vector<string> cols, vector<int> widths, string prefix = "");

void printMenu(string title, vector<string> options, int width = 75);

void headerTitle(string title);
void clearScreen();
void printCenter(string content);
void printLine(char c);

#endif