#include <stdio.h>
#include <stdlib.h>
#include "printmap.h"
#include "generateArray.h"
#include "road.h"


char A[17][17]; //main array

const int maxv=10;

int main() {
		int n, i;
		int x, y;
		printf("enter x and y for map:");//game map
		scanf("%d %d", &x, &y);
		generate_array(x,y);
		int xc, yc;
		printf("enter location of teriory:");
		scanf("%d %d", &xc, &yc);
		xc--;
		yc--;
		A[xc][yc] = 'C';

		int v;
		printf("enter number of villages:");
		scanf("%d", &v);
		int Villx[maxv], Villy[maxv];
		for(i=0; i<v; i++) {
			int pi, qi;
			printf("enter location of village %d:", i+1);
			scanf("%d %d", &pi, &qi);
			Villx[i] = pi - 1;
			Villy[i] = qi - 1;
			A[pi-1][qi-1] = 'V';
		}

		printf("enter number of blocked houses:");
		scanf("%d", &n);
		for(i=0; i<n; i++) {
			int pi, qi;
			printf("enter location of blocked house %d:", i+1);
			scanf("%d %d", &pi, &qi);
			A[pi-1][qi-1] = 'X';
		}

		printMap(x,y);

		printf("do you want to continue To see the roads?\n0 for No\n1 for Yes\n");
		scanf("%d", &i);
		if(!i) return 0;//finish

		for(i=0; i<v; i++) croadtov(xc, yc, Villx, Villy, i, x, y);
		printMap(x,y);

		printf("message for finnish\npress any key to exit");
		scanf("%d", &i);

		return 0;
	}
