#include <stdio.h>

int main() {
	while (true) {
		char input[13][3];
		if (scanf("%s", input[0]) == EOF) {
			return 0;
		}
		for (int i = 1; i <= 12; i++) {
			scanf("%s", input[i]);
		}
		int points = 0;
		int suits[4];
		int stopped[4];
		for (int i = 0; i < 4; i ++) {
			suits[i] = 0;
			stopped[i] = 0;
		}
		int cards[13][4];
		for (int i = 0; i < 13; i ++) {
			for (int j = 0; j < 4; j++) {
				cards[i][j] = 0;
			}
		}
		int a[13];
		for (int i = 0; i < 13; i++) {
			int b, c;
			if(input[i][1] == 'S') {
				c = 3;
				suits[3] += 1;
			}
			else if (input[i][1] == 'H') {
				c = 2;
				suits[2] += 1;
			}
			else if (input[i][1] == 'D') {
				c = 1;
				suits[1] += 1;
			}
			else {
				c = 0;
				suits[0] += 1;
			}
			if (input[i][0] == 'A') {
				b = 12;
				points += 4;
				stopped[c] = 1;
			}
			else if (input[i][0] == 'K') {
				b = 11;
				points += 3;
			}
			else if (input[i][0] == 'Q') {
				b = 10;
				points += 2;
			}
			else if (input[i][0] == 'J') {
				b = 9;
				points += 1;
			}
			else if (input[i][0] == 'T') {
				b = 8;
			}
			else {
				b = ((int)input[i][0]) - 50;
			}
			a[i] = c * 13 + b;
			cards[b][c] = 1;
		}
		int maxSuit = 0;
		int morePoints = 0;
		for (int i = 0; i < 4; i++) {
			if ((cards[11][i] == 1) && (suits[i] == 1)) {
				points = points - 1;
			}
			if ((cards[11][i] == 1) && (suits[i] > 1)) {
				stopped[i] = 1;
			}
			if ((cards[10][i] == 1) && (suits[i] <= 2)) {
				points = points - 1;
			}
			if ((cards[10][i] == 1) && (suits[i] > 2)) {
				stopped[i] = 1;
			}
			if ((cards[9][i] == 1) && (suits[i] <= 3)) {
				points --;
			}
			if (suits[i] == 2) {
				points ++;
				morePoints ++;
			}
			if (suits[i] == 1) {
				points = points + 2;
				morePoints = morePoints + 2;
			}
			if (suits[i] == 0) {
				points = points + 2;
				morePoints = morePoints + 2;
			}
			if (suits[i] >= suits[maxSuit]) {
				maxSuit = i;
			}
		}
		char s[] = "CDHS";
		if (points < 14) {
			printf("PASS\n");
		}
		else if (((points - morePoints) >= 16) && (stopped[0] == 1) && (stopped[1] == 1) && (stopped[2] == 1) && (stopped[3] == 1)) {
			printf("BID NO-TRUMP\n");
		}
		else {
			printf("BID %c\n", s[maxSuit]);
		}
	}
}
