#include <stdio.h>
#include <cmath>

using namespace std;

// int max_length;
int N;
// int rowInc = {-1, -1, -1, 0, 0, 1, 1, 1};
// int colInc = {-1, -1, -1, 0, 0, 1, 1, 1};

// int dfs (int node, ) {
// 	for (int i = 0; i < 8)
// }

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &N);
		if (N == 1) {
			printf("0.000\n");
			if (i != (t - 1)) {
				printf("\n");
			}
			continue;
		}
		// float sum = (N - 1) * N / 2 + (N - 2) * (N - 1) / 2;
		// sum = sum + 1.414f * (float)((N - 1) / 2);
		// sum = sum + 1.414f * (float)((N - 2) / 2);
		// sum = sum + ((N - 1) - (N - 1) / 2) + ((N - 2) - (N - 2) / 2);
		// sum = sum + 2;
		double sum = (N * N - (N - 2) * (N - 2)) + (N - 2) * (N - 2) * sqrt(2.0);
		printf("%.3lf\n", sum);
		if (i != (t - 1)) {
			printf("\n");
		}
		// bool visited[N * N] = {0};
		// dfs(0, visited);
	}
}