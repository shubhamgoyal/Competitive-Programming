#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i ++) {
		long int a, b;
		scanf("%ld %ld", &a, &b);
		if (a < b) {
			printf("<\n", a, b);
		}
		if (a > b) {
			printf(">\n", a, b);
		}
		if (a == b) {
			printf("=\n", a, b);
		}
	}
}
