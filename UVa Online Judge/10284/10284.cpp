#include <stdio.h>
#include <cstring>
using namespace std;

char a[9][9];
int main() {
	char fen[200];
	int px[2] = {1, 1};
	int py[2] = {-1, 1};
	int Px[2] = {-1, -1};
	int Py[2] = {-1, 1};
	int nx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
	int ny[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
	int bx[7] = {1, 2, 3, 4, 5, 6, 7/*, -1, -2, -3, -4, -5, -6, -7, 1, 2, 3, 4, 5, 6, 7, -1, -2, -3, -4, -5, -6, -7*/};
	int by[7] = {1, 2, 3, 4, 5, 6, 7/*, 1, 2, 3, 4, 5, 6, 7, -1, -2, -3, -4, -5, -6, -7, -1, -2, -3, -4, -5, -6, -7*/};
	int rx1[7] = {0, 0, 0, 0, 0, 0, 0/*, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, -1, -2, -3, -4, -5, -6, -7*/};
	int ry1[7] = {1, 2, 3, 4, 5, 6, 7/*, -1, -2, -3, -4, -5, -6, -7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0*/};
	int rx2[7] = {1, 2, 3, 4, 5, 6, 7};
	int ry2[7] = {0, 0, 0, 0, 0, 0, 0};
	int kx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
	int ky[8] = {-1, 1, -1, 0, 1, -1, 0, 1};
	/*int qx[56], qy[56];
	for (int i = 0; i < 28; i++) {
		qx[i] = rx[i];
		qx[i + 28] = bx[i];
		qy[i] = ry[i];
		qy[i + 28] = by[i];
	}*/
	while (true) {
		if (scanf("%s", fen) == EOF) {
			return 0;
		}
		int rowCount = 0;
		int columnCount = 0;
		for (int i = 0; i < strlen(fen); i++) {
			if (fen[i] == '/') {
				rowCount ++;
				columnCount = 0;
			}
			else if ((fen[i] >= '1') && (fen[i] <= '9')) {
				for (int j = columnCount; j < (columnCount + ((int)fen[i] - 48)); j++) {
					a[rowCount][j] = '0';
				}
				columnCount = columnCount + (int)fen[i] - 48;
			}
			else {
				a[rowCount][columnCount] = fen[i];
				columnCount ++;
			}
		}
		/*for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				printf("%c ", a[i][j]);
			}
			printf("\n");
		}*/
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (a[i][j] == '1') {
					continue;
				}
				else if (a[i][j] == '0') {
					continue;
				}
				else if (a[i][j] == 'p') {
					for (int k = 0; k < 2; k++) {
						if (((i + px[k]) >= 0) && ((i + px[k]) < 8) && ((j + py[k]) >= 0) && ((j + py[k]) < 8)) {
							if (a[i + px[k]][j + py[k]] == '0') {
								a[i + px[k]][j + py[k]] = '1';
							}
						}
					}
				}
				else if (a[i][j] == 'P') {
					for (int k = 0; k < 2; k++) {
						if (((i + Px[k]) >= 0) && ((i + Px[k]) < 8) && ((j + Py[k]) >= 0) && ((j + Py[k]) < 8)) {
							if (a[i + Px[k]][j + Py[k]] == '0') {
								a[i + Px[k]][j + Py[k]] = '1';
							}
						}
					}
				}
				else if ((a[i][j] == 'n') || (a[i][j] == 'N')) {
					for (int k = 0; k < 8; k++) {
						if (((i + nx[k]) >= 0) && ((i + nx[k]) < 8) && ((j + ny[k]) >= 0) && ((j + ny[k]) < 8)) {
							if (a[i + nx[k]][j + ny[k]] == '0') {
								a[i + nx[k]][j + ny[k]] = '1';
							}
						}
					}
				}
				else if ((a[i][j] == 'b') || (a[i][j] == 'B')) {
					for (int k = 0; k < 7; k++) {
						if (((i + bx[k]) >= 0) && ((i + bx[k]) < 8) && ((j + by[k]) >= 0) && ((j + by[k]) < 8)) {
							if ((a[i + bx[k]][j + by[k]] == '0') || (a[i + bx[k]][j + by[k]] == '1')) {
								a[i + bx[k]][j + by[k]] = '1';
							}
							else {
								break;
							}
						}
					}
					for (int k = 0; k < 7; k++) {
						if (((i + bx[k]) >= 0) && ((i + bx[k]) < 8) && ((j - by[k]) >= 0) && ((j - by[k]) < 8)) {
							if ((a[i + bx[k]][j - by[k]] == '0') || (a[i + bx[k]][j - by[k]] == '1')) {
								a[i + bx[k]][j - by[k]] = '1';
							}
							else {
								break;
							}
						}
					}
					for (int k = 0; k < 7; k++) {
						if (((i - bx[k]) >= 0) && ((i - bx[k]) < 8) && ((j + by[k]) >= 0) && ((j + by[k]) < 8)) {
							if ((a[i - bx[k]][j + by[k]] == '0') || (a[i - bx[k]][j + by[k]] == '1')) {
								a[i - bx[k]][j + by[k]] = '1';
							}
							else {
								break;
							}
						}
					}
					for (int k = 0; k < 7; k++) {
						if (((i - bx[k]) >= 0) && ((i - bx[k]) < 8) && ((j - by[k]) >= 0) && ((j - by[k]) < 8)) {
							if ((a[i - bx[k]][j - by[k]] == '0') || (a[i - bx[k]][j - by[k]] == '1')) {
								a[i - bx[k]][j - by[k]] = '1';
							}
							else {
								break;
							}
						}
					}
				}
				else if ((a[i][j] == 'r') || (a[i][j] == 'R')) {
					/*for (int k = 0; k < 28; k++) {
						if (((i + rx[k]) >= 0) && ((i + rx[k]) < 8) && ((j + ry[k]) >= 0) && ((j + ry[k]) < 8)) {
							if (a[i + rx[k]][j + ry[k]] == '0') {
								a[i + rx[k]][j + ry[k]] = '1';
							}
						}
					}*/
					for (int k = 0; k < 7; k++) {
						if (((i + rx1[k]) >= 0) && ((i + rx1[k]) < 8) && ((j + ry1[k]) >= 0) && ((j + ry1[k]) < 8)) {
							if ((a[i + rx1[k]][j + ry1[k]] == '0') || (a[i + rx1[k]][j + ry1[k]] == '1')) {
								a[i + rx1[k]][j + ry1[k]] = '1';
							}
							else {
								break;
							}
						}
					}
					for (int k = 0; k < 7; k++) {
						if (((i + rx1[k]) >= 0) && ((i + rx1[k]) < 8) && ((j - ry1[k]) >= 0) && ((j - ry1[k]) < 8)) {
							if ((a[i + rx1[k]][j - ry1[k]] == '0') || (a[i + rx1[k]][j - ry1[k]] == '1')) {
								a[i + rx1[k]][j - ry1[k]] = '1';
							}
							else {
								break;
							}
						}
					}
					for (int k = 0; k < 7; k++) {
						if (((i + rx2[k]) >= 0) && ((i + rx2[k]) < 8) && ((j + ry2[k]) >= 0) && ((j + ry2[k]) < 8)) {
							if ((a[i + rx2[k]][j + ry2[k]] == '0') || (a[i + rx2[k]][j + ry2[k]] == '1')) {
								a[i + rx2[k]][j + ry2[k]] = '1';
							}
							else {
								break;
							}
						}
					}
					for (int k = 0; k < 7; k++) {
						if (((i - rx2[k]) >= 0) && ((i - rx2[k]) < 8) && ((j + ry2[k]) >= 0) && ((j + ry2[k]) < 8)) {
							if ((a[i - rx2[k]][j + ry2[k]] == '0') || (a[i - rx2[k]][j + ry2[k]] == '1')) {
								a[i - rx2[k]][j + ry2[k]] = '1';
							}
							else {
								break;
							}
						}
					}
				}
				else if ((a[i][j] == 'q') || (a[i][j] == 'Q')) {
					for (int k = 0; k < 7; k++) {
						if (((i + bx[k]) >= 0) && ((i + bx[k]) < 8) && ((j + by[k]) >= 0) && ((j + by[k]) < 8)) {
							if ((a[i + bx[k]][j + by[k]] == '0') || (a[i + bx[k]][j + by[k]] == '1')) {
								a[i + bx[k]][j + by[k]] = '1';
							}
							else {
								break;
							}
						}
					}
					for (int k = 0; k < 7; k++) {
						if (((i + bx[k]) >= 0) && ((i + bx[k]) < 8) && ((j - by[k]) >= 0) && ((j - by[k]) < 8)) {
							if ((a[i + bx[k]][j - by[k]] == '0') || (a[i + bx[k]][j - by[k]] == '1')) {
								a[i + bx[k]][j - by[k]] = '1';
							}
							else {
								break;
							}
						}
					}
					for (int k = 0; k < 7; k++) {
						if (((i - bx[k]) >= 0) && ((i - bx[k]) < 8) && ((j + by[k]) >= 0) && ((j + by[k]) < 8)) {
							if ((a[i - bx[k]][j + by[k]] == '0') || (a[i - bx[k]][j + by[k]] == '1')) {
								a[i - bx[k]][j + by[k]] = '1';
							}
							else {
								break;
							}
						}
					}
					for (int k = 0; k < 7; k++) {
						if (((i - bx[k]) >= 0) && ((i - bx[k]) < 8) && ((j - by[k]) >= 0) && ((j - by[k]) < 8)) {
							if ((a[i - bx[k]][j - by[k]] == '0') || (a[i - bx[k]][j - by[k]] == '1')) {
								a[i - bx[k]][j - by[k]] = '1';
							}
							else {
								break;
							}
						}
					}
					for (int k = 0; k < 7; k++) {
						if (((i + rx1[k]) >= 0) && ((i + rx1[k]) < 8) && ((j + ry1[k]) >= 0) && ((j + ry1[k]) < 8)) {
							if ((a[i + rx1[k]][j + ry1[k]] == '0') || (a[i + rx1[k]][j + ry1[k]] == '1')) {
								a[i + rx1[k]][j + ry1[k]] = '1';
							}
							else {
								break;
							}
						}
					}
					for (int k = 0; k < 7; k++) {
						if (((i + rx1[k]) >= 0) && ((i + rx1[k]) < 8) && ((j - ry1[k]) >= 0) && ((j - ry1[k]) < 8)) {
							if ((a[i + rx1[k]][j - ry1[k]] == '0') || (a[i + rx1[k]][j - ry1[k]] == '1')) {
								a[i + rx1[k]][j - ry1[k]] = '1';
							}
							else {
								break;
							}
						}
					}
					for (int k = 0; k < 7; k++) {
						if (((i + rx2[k]) >= 0) && ((i + rx2[k]) < 8) && ((j + ry2[k]) >= 0) && ((j + ry2[k]) < 8)) {
							if ((a[i + rx2[k]][j + ry2[k]] == '0') || (a[i + rx2[k]][j + ry2[k]] == '1')) {
								a[i + rx2[k]][j + ry2[k]] = '1';
							}
							else {
								break;
							}
						}
					}
					for (int k = 0; k < 7; k++) {
						if (((i - rx2[k]) >= 0) && ((i - rx2[k]) < 8) && ((j + ry2[k]) >= 0) && ((j + ry2[k]) < 8)) {
							if ((a[i - rx2[k]][j + ry2[k]] == '0') || (a[i - rx2[k]][j + ry2[k]] == '1')) {
								a[i - rx2[k]][j + ry2[k]] = '1';
							}
							else {
								break;
							}
						}
					}
				}
				else if ((a[i][j] == 'k') || (a[i][j] == 'K')) {
					for (int k = 0; k < 8; k++) {
						if (((i + kx[k]) >= 0) && ((i + kx[k]) < 8) && ((j + ky[k]) >= 0) && ((j + ky[k]) < 8)) {
							if (a[i + kx[k]][j + ky[k]] == '0') {
								a[i + kx[k]][j + ky[k]] = '1';
							}
						}
					}
				}
			}
		}
		int count = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (a[i][j] == '0') {
					count ++;
				}
			}
		}
		printf("%d\n", count);
		/*for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				printf("%c ", a[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/
	}
}
