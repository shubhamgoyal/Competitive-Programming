#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	char str[51];
	while (scanf("%s", &str[0])) {
		int length = strlen(str);
		if (str[0] == '#') {
			return 0;
		}
		if (next_permutation(str, str + length * sizeof(char))) {
			printf("%s\n", str);
		}
		else {
			printf("No Successor\n");
		}
	}
}
