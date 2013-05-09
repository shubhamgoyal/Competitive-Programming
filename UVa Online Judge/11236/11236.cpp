#include <stdio.h>
#include <limits.h>
using namespace std;

int main() {
	for (long int i = 8; i <= 125; i++) {
		for (long int j = i; j <= 592; j++) {
			if (j < 50) {
				break;
			}
			if ((i + j) >= 2000) {
				break;
			}
			if ((i * j) > 200000) {
				break;
			}
			for (long int k = j; k <= 884; k++) {
				/*if (k < 120) {
					break;
				}
				if ((i + j + k) >= 2000) {
					break;
				}
				if ((i * j * k) > 20000000) {
					break;
				}
				for (long int l = k; l <= 1650; l++) {
					if (l < 184) {
						break;
					}
					if ((i + j + k + l) > 2000) {
						break;
					}
					if ((i + j + k + l) * 1000000 == (i * j * k * l)) {
						printf("%.2f %.2f %.2f %.2f\n", i/100.0, j/100.0, k/100.0, l/100.0);
					}
				}
			}
		}
	}
}
