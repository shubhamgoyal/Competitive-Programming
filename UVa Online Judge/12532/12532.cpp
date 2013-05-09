#include <stdio.h>
#include <cstring>
using namespace std;

int a[100010];
int neg[100010];
int zer[100010];
int main() {
	int N, K;
	a[0] = 0;
	while (scanf("%d %d\n", &N, &K) != EOF) {
		//printf("%d %d", N, K);
		memset(neg, 0, (N + 1) * sizeof(int));
		memset(zer, 0, (N + 1) * sizeof(int));
		for (int i = 1; i <= N; i++) {
			//printf("i = %d\n", i);
			int temp;
			int j = i;
			scanf("%d", &temp);
			a[i] = temp;
			if (temp == 0) {
				for (; j <= N; j = j + (j & (- j))) {
					zer[j] ++;
				}
			}
			else if (temp < 0) {
				for (; j <= N; j = j + (j & (- j))) {
					neg[j] ++;
				}
			}
		}
		char cmdType;
		int I, J;
		for (int i = 0; i < K; i++) {
			//printf("i = %d\n", i);
			scanf("%c %d %d", &cmdType, &I, &J);
			scanf("%c %d %d", &cmdType, &I, &J);
			//printf("%c %d %d\n", cmdType, I, J);
			int temp = I;
			if (cmdType == 'C') {
				for (int j = I; j <= N; j = j + (j & (- j))) {
					if (a[temp] != J) {
						if (J == 0) {
							zer[j] ++;
						}
						else if (J < 0) {
							neg[j]++;
						}
						if (a[temp] == 0) {
							zer[j] --;
						}
						else if (a[temp] < 0) {
							neg[j] --;
						}
					}
				}
				a[temp] = J;
			}
			else {
				int sum0J = 0, sumNegJ = 0, sum0I = 0, sumNegI = 0;
				for (int j = J; j != 0; j = j - (j & (- j))) {
					sum0J = sum0J + zer[j];
					sumNegJ = sumNegJ + neg[j];
				}
				for (int j = I - 1; j != 0; j = j - (j & (- j))) {
					sum0I = sum0I + zer[j];
					sumNegI = sumNegI + neg[j];
				}
				if ((sum0J - sum0I) >= 1) {
					printf("0");
				}
				else if (((sumNegJ - sumNegI) % 2) == 0) {
					printf("+");
				}
				else {
					printf("-");
				}
			}
		}
		printf("\n");
	}
}
