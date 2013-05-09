#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		int a[n];
		int min = 99;
		int max = 0;
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[j]);
			if (a[j] < min) {
				min = a[j];
			}
			if (a[j] > max) {
				max = a[j];
			}
		}
		printf("%d\n", 2 * (max - min));
	}
}
