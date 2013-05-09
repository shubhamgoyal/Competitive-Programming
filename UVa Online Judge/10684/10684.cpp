#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

long int N;
long int DP[10000];
long int A[10000];

int main() {
	while (true) {
		scanf("%ld", &N);
		if (N == 0) {
			break;
		}
		//memset(DP, -1, sizeof(long int) * N);
		for (int i = 0; i < N; i++) {
			scanf("%ld", &A[i]);
		}
		if (N == 1) {
			if (A[0] > 0) {
				printf("The maximum winning streak is %ld.\n", A[0]);
			}
			else {
				printf("Losing streak.\n");
			}
		}
		else {
			DP[0] = A[0];
			long int maxi = DP[0];
			for (int i = 1; i < N; i++) {
				DP[i] = max(DP[i - 1] + A[i], A[i]);
				if (DP[i] > maxi) {
					maxi = DP[i];
				}
			}
			if (maxi > 0) {
				printf("The maximum winning streak is %ld.\n", maxi);
			}
			else {
				printf("Losing streak.\n");
			}
		}
	}
}
