#include <stdio.h>
#include <windows.h>
#include"printmap.h"

void textcolor(int color) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, color);
}

void printMap(int x,int y,char A[17][17]) {
    //function for print game map
    int i, j;
    for(i=0; i<x; i++) {
        for(j=0; j<y; j++) {
            if(A[i][j]=='C')
                textcolor(6);
            else if(A[i][j]=='X')
                textcolor(4);
            else if(A[i][j]=='V')
                textcolor(10);
            else if(A[i][j]=='R')
                textcolor(8);
            else textcolor(11);
            printf("%c ", A[i][j]);
        }
        printf("\n");
    }
}