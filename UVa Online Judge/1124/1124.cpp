#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
	char c;
	do {
		int result = scanf("%c", &c);
		if (result != EOF) {
			printf("%c", c);
		}
		else {
			break;
		}
	} while(1);
}
