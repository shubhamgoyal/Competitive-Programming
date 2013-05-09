#include <stdio.h>

int main() {
	int q;
	while (true) {
		scanf("%d", &q);
		if (q == 0) {
			break;
		}
		int dx, dy;
		scanf("%d %d", &dx, &dy);
		for (int i = 0; i < q; i ++) {
			int x, y;
			scanf("%d %d", &x, &y);
			if ((x == dx) || (y == dy)) {
				printf("divisa\n");
			}
			else if ((x < dx) && (y < dy)) {
				printf("SO\n");
			}
			else if ((x < dx) && (y > dy)) {
				printf("NO\n");
			}
			else if ((x > dx) && (y < dy)) {
				printf("SE\n");
			}
			else {
				printf("NE\n");
			}
		}
	}
}
