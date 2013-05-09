#include <stdio.h>
#include <stack>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string str;
	int flag = 0;
	while(getline(cin, str)) {
		flag = 0;
		istringstream numbers(str);
		if (str.length() == 0) {
			continue;
		}
		int n;
		stack<int> nums;
		while (numbers >> n) {
			if (n < 0) {
				nums.push(n);
			}
			else {
				if (nums.empty()) {
					flag = 1;
					break;
				}
				else {
					int sum = 0;
					while(nums.top() != -n) {
						sum = sum + nums.top();
						nums.pop();
						if (nums.empty()) {
							flag = 1;
							break;
						}
					}
					int a;
					if (flag == 1) {
						break;
					}
					if (sum >= n) {
						flag = 1;
						break;
					}
					nums.pop();
					nums.push(n);
				}
			}
		}
		while(!nums.empty()) {
			if (nums.top() < 0) {
				flag = 1;
				break;
			}
			nums.pop();
		}
		if (flag == 1) {
			printf(":-( Try again.\n");
		}
		else {
			printf(":-) Matrioshka!\n");
		}
	}
}
