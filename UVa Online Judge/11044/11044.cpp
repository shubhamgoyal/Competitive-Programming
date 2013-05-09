#include <stdio.h>

int main() {
	int t;
	scanf("%d\n", &t);
	for(int i = 0; i < t; i++) {
		int n, m;
		scanf("%d %d", &n, &m);
		int r, c;
		if ((n - 2) % 3 == 0) {
			r = (n - 2) / 3;
		}
		else {
			r = (n - 2) / 3 + 1;
		}
		if ((m - 2) % 3 == 0) {
			c = (m - 2) / 3;
		}
		else {
			c = (m - 2) / 3 + 1;
		}
		printf("%d\n", r * c);
	}
}
