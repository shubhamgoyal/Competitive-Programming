#include <stdio.h>
#include <cstring>
#include <limits.h>
using namespace std;

int flag[10000000 + 1];

int N;

int pow(int a, int b) {
	if (b == 0) {
		return 1;
	}
	return ((a % (N + 1)) * (pow(a, b - 1) % (N + 1))) % (N + 1);
}

int main() {
	int M;
	while (true) {
		scanf("%d %d", &N, &M);
		if ((N == 0) && (M == 0)) {
			break;
		}
		int k;
		scanf("%d", &k);
		int a[k + 1];
		for (int i = 0; i < (k + 1); i++) {
			scanf("%d", &a[i]);
		}
		memset(flag, 0, (N + 1) * sizeof(int));
		for (int i = 0; i <= M; i++) {
			long int sum = 0;
			for (int j = 0; j < (k + 1); j++) {
				sum = sum + a[j] * pow(i, j);
			}
			int mod = sum % (N + 1);
			flag[mod] = 1;
		}
		int count = 0;
		for (int i = 0; i < (N + 1); i++) {
			if (flag[i]) {
				count ++;
			}
		}
		printf("%d\n", count);
	}
}
