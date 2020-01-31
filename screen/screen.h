#ifndef SCREEN_H
#define SCREEN_H

#include <windows.h> 
const int Black=0; 
const int Blue=1;
const int Green=2;
const int Cyan=3;
const int Red=4; 
const int Magenta=5;
const int Brown=6;
const int Lightgray=7;
const int Darkgray=8;
const int Lightblue=9;
const int Lightgreen=10;
const int Lightcyan=11;
const int Lightred=12;
const int Lightmagenta=13;
const int Yellow=14;
const int White=15;

void ClrScr(); 
void ClrEol();
void ClrEoscr();
void Gotoxy(int x, int y);
void TextColor(int fontcolor);
void TextBackground(int background);

#endif