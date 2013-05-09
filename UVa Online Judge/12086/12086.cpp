#include <stdio.h>
#include <vector>
using namespace std;

int N;
vector<int> ft;

int rsq(int x) {
	int sum = 0;
	for (; x != 0; x = x - (x & (- x))) {
		sum = sum + ft[x];
	}
	return sum;
}

int main() {
	int count = 0;
	while (true) {
		count ++;
		scanf("%d", &N);
		if (N == 0)
			break;
		if (count > 1) {
			printf("\n");
		}
		printf ("Case %d:\n", count);
		ft.assign(N + 1, 0);
		for (int i = 1; i <= N; i++) {
			int temp;
			scanf("%d", &temp);
			int j = i;
			for (; j <= N; j += (j & (- j))) {
				ft[j] = ft[j] + temp;
			}
		}
		char action[10];
		while (true) {
			scanf("%s", action);
			if ((action[0] == 'E') && (action[1] == 'N') && (action[2] == 'D')) {
				break;
			}
			int x, y;
			scanf("%d", &x);
			scanf("%d", &y);
			int prev = rsq(x) - rsq(x - 1);
			if (action[0] == 'S') {
				for (; x <= N; x += (x & (- x))) {
					ft[x] = ft[x] + (y -prev);
				}
			}
			else {
				printf("%d\n", rsq(y) - rsq(x - 1));
			}
		}
	}
}

