#include <stdio.h>

int main() {
	double H, D, F;
	double U;
	while (true) {
		scanf("%lf %lf %lf %lf", &H, &U, &D, &F);
		if (H == 0) {
			break;
		}
		int count = 1;
		double fatigue =  F * U / 100;
		double distance = H - U;
		while ((distance >= 0) && (distance < H)) {
			//printf("%lf\n", distance);
			if ((U - fatigue) < 0) {
				distance = distance + D;
				if (distance > H) {
					break;
				}
				count ++;
			}
			else {
				distance = distance + D;
				if (distance > H) {
					break;
				}
				count ++;
				distance = distance - (U - fatigue);
			}
			U = U - fatigue;
		}
		if (distance < 0) {
			printf("success on day %d\n", count);
		}
		else {
			printf("failure on day %d\n", count);
		}
	}
}
