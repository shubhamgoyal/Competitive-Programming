#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	while (true) {
		int f, r;
		scanf("%d", &f);
		if (f == 0) {
			break;
		}
		scanf("%d", &r);
		float a[f];
		float b[r];
		for (int i = 0; i < f; i++) {
			scanf("%f", &a[i]);
		}
		for (int i = 0; i < r; i++) {
			scanf("%f", &b[i]);
		}
		float c[f * r];
		for (int i = 0; i < f; i++) {
			for (int j = 0; j < r; j++) {
				c[i * r + j] = b[j] / a[i];
			}
		}
		sort(&c[0], &c[f * r]);
		float max = 0;
		for (int i = 0; i < (f*r - 1); i++) {
			if ((c[i + 1] / c[i]) > max) {
				max = c[i + 1] / c[i];
			}
		}
		printf("%.2f\n", max);
	}
}
