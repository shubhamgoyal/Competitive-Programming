#include <stdio.h>

int main() {
	while(true) {
		int t;
		if (scanf("%d", &t) == EOF) {
			break;
		};
		int a[t];
		for (int i = 0; i < t; i++) {
			a[i] = 0;
		}
		int b, c;
		int flag = 0;
		scanf("%d", &c);
		for (int i = 0; i < (t - 1); i++) {
			b = c;
			scanf("%d", &c);
			int diff = b - c;
			if (diff < 0) {
				diff = - diff;
			}
			if ((diff == 0) || (diff >= t)) {
				printf("Not jolly\n");
				int d;
				for (int j = i + 1; j < (t - 1); j++) {
					scanf("%d", &d);
				}
				flag = 1;
				break;
			}
			else if (a[diff] == 1) {
				printf("Not jolly\n");
				int d;
				for (int j = i + 1; j < (t - 1); j++) {
					scanf("%d", &d);
				}
				flag = 1;
				break;
			}
			else {
				a[diff] = 1;
			}
		}
		if (flag == 0) {
			printf("Jolly\n");
		}
	}
}
