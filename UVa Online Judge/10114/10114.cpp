#include <stdio.h>

int main() {
	int d, n;
	double dp, la;
	while (true) {
		scanf("%d %lf %lf %d", &d, &dp, &la, &n);
		double dep[102];
		if (d < 0) {
			break;
		}
		else {
			double depData[n + 1];
			int depMonth[n + 1];
			int lastFilled = -1;
			for (int i = 0; i < n; i++) {
				scanf("%d %lf", &depMonth[i], &depData[i]);
			}
			depMonth[n] = 1000;
			int count = 0;
			for (int i = 0; i < 101; i++) {
				if (depMonth[count] == i) {
					dep[i] = depData[count];
					count++;
				}
				else {
					dep[i] = depData[count - 1];
				}
			}
			double interestPayment = la / d;
			double amountOwed = la;	
			double carValue = (dp + la) * (1 - dep[0]);
			count = 0;
			while (carValue < amountOwed) {
				count ++;
				carValue = carValue * (1 - dep[count]);
				amountOwed = amountOwed - interestPayment;
			}
			printf("%d month", count);
			if (count == 1) {
				printf("\n");
			}
			else {
				printf("s\n");
			}
		}
	}

}
