#include <stdio.h>
using namespace std;

int main() {
	long int S;
	long int B;
	long int a[2][100010];
	while (true) {
		scanf("%ld %ld", &S, &B);
		if ((S == 0) && (B == 0)) {
			break;	
		}
		for (long int i = 1; i <= S; i++) {
			a[0][i] = i - 1;
			a[1][i] = i + 1;
		}
		a[0][1] = S;
		a[1][S] = 0;
		for (long int i = 0; i < B; i++) {
			long int l, r;
			scanf("%ld %ld", &l, &r);
			a[0][a[1][r]] = a[0][l];
			a[1][a[0][l]] = a[1][r];
			if (a[0][l] >= l) {
				printf("* ");
			}
			else {
				printf("%ld ", a[0][l]);
			}
			if (a[1][r] <= r) {
				printf("*\n");
			}
			else {
				printf("%ld\n", a[1][r]);
			}
		}
		printf("-\n");
	}
}
