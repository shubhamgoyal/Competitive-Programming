#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

double minim[1<<16];
long long maxi;
double dist[16][16];
int N;

double minDistance(long long bitmap) {
	if (bitmap == maxi) {
		return 0;
	}
	else if (minim[bitmap] != -1) {
		return minim[bitmap];
	}
	else {
		double mini = 1 << 30;
		for (int i = 0; i < 2*N; i++) {
			if (!(bitmap & (1 << i))) {
				for (int j = 0; j < 2 * N; j ++) {
					if ((!(bitmap & (1 << j))) && (i != j)) {
						mini = min(mini, dist[i][j] + minDistance((bitmap | (1 << i)) | (1 << j)));
					}
				}
			}
		}
		minim[bitmap] = mini;
		return mini;
	}
}

int main() {
	int count = 0;;
	scanf("%d",&N);
	while (N != 0) {
		maxi = (1 << (2 * N)) - 1;
		for (int i = 0; i < maxi; i++) {
			minim[i] = -1;
		}
		count ++;
		char* name[2 * N];
		int x[2 * N];
		int y[2 * N];
		for (int i = 0; i < 2 * N; i ++) {
			scanf("%s %d %d\n", &name[i], &x[i], &y[i]);
			//cin >> name[i];
			//cin >> x[i];
			//cin >> y[i];
		}
		/*int indices[2 * N];
		for (int i = 0; i < 2 * N; i++) {
			indices[i] = i;
		}
		double largestSum = 99999999999999999999999.0;*/
		for (int i = 0; i < 2*N; i++) {
			for(int j = 0; j < 2*N; j ++) {
				dist[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
			}
		}
		/*do {
			double sum = 0;
			for (int i = 0; i < 2 * N; i = i + 2) {
				sum = sum + dist[indices[i]][indices[i + 1]];
			}
			if (sum < largestSum) {
				largestSum = sum;
			}
		} while (next_permutation(indices, indices + 2 * N));
		//cout.setf(ios::fixed);
		//cout.precision(2);*/
		//printf("Case %d: %.2f\n", count, floor(largestSum * 100 + 0.5)/100);
		printf("Case %d: %.2f\n", count, minDistance(0));			
		//cout << "Case " << count << ": " << floor(largestSum * 100 + 0.5)/100 << "\n";
		//cin >> N;
		scanf("%d", &N);

	}
}
