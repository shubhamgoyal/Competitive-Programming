#include <stdio.h>

int main() {
	int p, b, h, w;
	while (scanf("%d %d %d %d", &p, &b, &h, &w) != EOF) {
		int best = b + 1;
		for (int i = 0; i < h; i++) {
			int price;
			scanf("%d", &price);
			for (int j = 0; j < w; j++) {
				int vacancy;
				scanf("%d", &vacancy);
				if (vacancy >= p) {
					if (price * p < best) {
						best = price * p;
					}
				}
			}
		}
		if (best <= b) {
			printf("%d\n", best);
		}
		else {
			printf("stay home\n");
		}
	}
}
