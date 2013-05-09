#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int sum;
	for (;;) {
		scanf("%d", &sum);
		if (sum == -1) {
			break;
		}
		int max_n = static_cast<int>(floor(sqrt(float(2 * sum))));
		int i;
		for (i = max_n; i > 0; i--) {
			int remainder = (2 * sum + i - i * i) % (2 * i);
			if (remainder == 0) {
				break;
			}
		}
		int a = (2 * sum + i - i * i) / (2 * i);
		int b = a + i - 1;
		printf("%d = %d + ... + %d\n", sum, a, b);
	}	
}