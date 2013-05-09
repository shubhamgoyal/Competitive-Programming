#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	while (true) {
		int a[3], b[3];
		scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &b[0], &b[1]);
		if ((a[0] == 0) && (a[1] == 0) && (a[2] == 0) && (b[0] == 0) && (b[1] == 0)) {
			break;
		}
		int flag = 0;
		int index = 2;
		b[2] = 0;
		for (int i = 1; i <= 52; i++) {
			if ((a[0] != i) && (a[1] != i) && (a[2] != i) && (b[0] != i) && (b[1] != i) && (b[2] != i)) {
				b[index] = i;
				flag = 0;
				for (int j = 0; j < 6; j++) {
					for (int k = 0; k < 6; k++) {
						int count = 0;
						if (b[0] > a[0]) {
							count ++;
						}
						if (b[1] > a[1]) {
							count ++;
						}
						if (b[2] > a[2]) {
							count ++;
						}
						if (count < 2) {
							flag = 1;
							break;
						}
						next_permutation(&b[0], &b[3]);
					}
					if (flag == 1) {
						break;
					}
					next_permutation(&a[0], &a[3]);
				}
				if (flag == 0) {
					//printf("%d %d %d %d %d %d\n", a[0], a[1], a[2], b[0], b[1], b[2]);
					printf("%d\n", i);
					break;
				}
				if (b[0] == i) {
					index = 0;
				}
				if (b[1] == i) {
					index = 1;
				}
				if (b[2] == i) {
					index = 2;
				}
			}
		}
		if (flag != 0) {
			printf("-1\n");
		}
	}
}
