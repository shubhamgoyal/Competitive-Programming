#include <stdio.h>
using namespace std;

int main() {
	int z = 0;
	while(true) {
		z++;
		int n;
		scanf("%d", &n);
		if (n == 0) {
			break;	
		}
		int a;
		int count = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			if (a > 0) {
				count ++;
			}
			else {
				count --;
			}
		}
		printf("Case %d: %d\n", z, count);
	}
}
