#include <stdio.h>
#include <stdlib.h>
#include "road.h"

extern char A[17][17];

void croadtov(int xc, int yc, int Villx[], int Villy[], int i, int x, int y){
    int a, b;
			a = xc;//xR
			b = yc;//yRs
			int count = 0;
			if(xc < Villx[i]) {
				for(a++; a<(Villx[i]-1); a++) {
					if(b == 0 && A[a+2][b] == 'X' && A[a+1][b+1] == 'X'){
						A[a][b] = 'R';
						b++;
						A[a][b] = 'R';
						b++;
						A[a][b] = 'R';
					}
					if(b == (y-1) && A[a+2][b] == 'X' && A[a+1][b-1] == 'X'){
						A[a][b] = 'R';
						b--;
						A[a][b] = 'R';
						b--;
						A[a][b] = 'R';
					}
					if(A[a][b] == 'X'){
						a--;
						if(A[a][b+1] == 'X') {
							if(A[a][b-1] == 'X') a--;
							b--;
						}
						else if(A[a][b-1] == 'X') b++;
						if(!b) b++;
						else if(b==y) b--;
						else if(b < Villy[i]) b++;
						else b--;
					}
					A[a][b]='R';
				}
			}
			else if(xc > Villx[i]) {
				for(a--; a>(Villx[i]+1); a--) {
					if(b == 0 && A[a-2][b] == 'X' && A[a-1][b+1] == 'X'){
						A[a][b] = 'R';
						b++;
						A[a][b] = 'R';
						b++;
						A[a][b] = 'R';
					}
					if(b == (y-1) && A[a-2][b] == 'X' && A[a-1][b-1] == 'X'){
						A[a][b] = 'R';
						b--;
						A[a][b] = 'R';
						b--;
						A[a][b] = 'R';
					}
					if(A[a][b] == 'X'){
						a--;
						if(A[a][b+1] == 'X') {
							if(A[a][b-1] == 'X') a--;
							b--;
						}
						else if(A[a][b-1] == 'X') b++;
						if(!b) b++;
						else if(b==y) b--;
						else if(b < Villy[i]) b++;
						else b--;
					}
					A[a][b]='R';
				}
			}
			else if(yc < Villy[i]) b++;
			else b--;

			if(b < Villy[i]) {
				for(; b<=Villy[i]; b++) {
					if(a == 0 && A[a][b+2] == 'X' && A[a+1][b+1] == 'X'){
						A[a][b] = 'R';
						a++;
						count++;
						A[a][b] = 'R';
						a++;
						count++;
						A[a][b] = 'R';
					}
					if(a == (x-1) && A[a][b+2] == 'X' && A[a-1][b+1] == 'X'){
						A[a][b] = 'R';
						a--;
						count--;
						A[a][b] = 'R';
						a--;
						count--;
						A[a][b] = 'R';
					}
					if(A[a][b] == 'X'){
						b--;
						if(A[a+1][b] == 'X') {
							if(A[a-1][b] == 'X') b--;
							a--;
						}
						else if(A[a-1][b] == 'X') a++;
						if(!a) {a++;count++;}
						else if(a==x) {a--;count--;}
						else if(a < Villx[i]) {a++;count++;}
						else {a--;count--;}
					}
					if(A[a][b] == 'V') break;
					A[a][b]='R';
				}
			}
			else {
				for(; b>=Villy[i]; b--) {
					if(a == 0 && A[a][b-2] == 'X' && A[a+1][b-1] == 'X'){
						A[a][b] = 'R';
						a++;
						count++;
						A[a][b] = 'R';
						a++;
						count++;
						A[a][b] = 'R';
					}
					if(a == (x-1) && A[a][b-2] == 'X' && A[a-1][b-1] == 'X'){
						A[a][b] = 'R';
						a--;
						count--;
						A[a][b] = 'R';
						a--;
						count--;
						A[a][b] = 'R';
					}
					if(A[a][b] == 'X'){
						b--;
						if(A[a+1][b] == 'X') {
							if(A[a-1][b] == 'X') b--;
							a--;
						}
						else if(A[a-1][b] == 'X') a++;
						if(!a) {a++;count++;}
						else if(a==x) {a--;count--;}
						else if(a < Villx[i]) {a++;count++;}
						else {a--;count--;}
					}
					if(A[a][b] == 'V') break;
					A[a][b]='R';
				}
			}
			b = Villy[i];
			if (count<0){
				for(count++;count<0;count++) {a++;A[a][b] = 'R';}
			}
			else if (count>0){
				for(count--;count>0;count--) {a--;A[a][b] = 'R';}
            } 
		}