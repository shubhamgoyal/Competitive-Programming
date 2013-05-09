#include <stdio.h>

int main() {
	while(true) {
		int N, n;
		scanf("%d %d", &N, &n);
		int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
		int flag = 0;
		if ((N == 0) && (n == 0)) {
			return 0;
		}
		char a[N][N + 1];
		char b[n][n + 1];
		for (int i = 0; i < N; i++) {
			scanf("%s", &a[i][0]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%s", &b[i][0]);
		}
		for (int i = 0; i < (N - n + 1); i++) {
			for (int j = 0; j < (N - n + 1); j++) {
				for (int k = 0; k < n; k++) {
					for (int l = 0; l < n; l++) {
						if (a[i + k][j + l] != b[k][l]) {
							flag = 1;
						}
					}
				}
				if (flag == 0) {
					count1 ++;
				}
				flag = 0;
				for (int k = 0; k < n; k++) {
					for (int l = 0; l < n; l++) {
						if (a[i + k][j + l] != b[l][n - k - 1]) {
							flag = 1;
						}
					}
				}
				if (flag == 0) {
					count4 ++;
				}
				flag = 0;
				for (int k = 0; k < n; k++) {
					for (int l = 0; l < n; l++) {
						if (a[i + k][j + l] != b[n - k - 1][n - l - 1]) {
							flag = 1;
						}
					}
				}
				if (flag == 0) {
					count3 ++;
				}
				flag = 0;
				for (int k = 0; k < n; k++) {
					for (int l = 0; l < n; l++) {
						if (a[i + k][j + l] != b[n - l - 1][k]) {
							flag = 1;
						}
					}
				}
				if (flag == 0) {
					count2 ++;
				}
				flag = 0;
			}
		}
		printf("%d %d %d %d\n", count1, count2, count3, count4);
	}
}
