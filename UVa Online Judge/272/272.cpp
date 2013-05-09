#include <string>
#include <iostream>
using namespace std;

int main() {
	string line;
	int flag = 0;
	string output = "";
	while(getline(cin, line)) {
		string outputLine = "";
		for (string::size_type i = 0; i < line.size(); i++) {
			char c = line[i];
			if (c == '"') {
				if (flag == 0) {
					outputLine = outputLine + "``";
					flag = 1;
				}
				else {
					outputLine = outputLine + "''";
					flag = 0;
				}
			}
			else {
				outputLine = outputLine + c;
			}
		}
		output = output + outputLine + "\n";
	}
	cout << output;
}
