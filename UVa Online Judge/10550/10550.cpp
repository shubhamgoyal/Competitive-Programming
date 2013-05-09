#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int i, j, k, l;
	
	do {
		scanf("%d %d %d %d\n", &i, &j, &k, &l);
		if ((i == 0) && (j == 0) && (k == 0) && (l == 0)) {
			break;
		}
		int angle = 720 + 360;
		if (k >= j) {
			angle = angle + (k - j) * 9;
		}
		else {
			angle = angle + (40 - j + k) * 9;
		}
		if (j >= i) {
			angle = angle + (i + 40 - j) * 9;
		}
		else {
			angle = angle + (i - j) * 9;
		}
		if (l >= k) {
			angle = angle + (k + 40 - l) * 9;
		}
		else {
			angle = angle + (k - l) * 9;
		}
		printf("%d\n", angle);
	} while (true);
}
