#include <stdio.h>
#include <cstring>
#include <cstdlib>

int main() {
	int count = 1;
	while (true) {
		int n, p;
		int maxFeatures = -1;
		double bestPrice = 1 << 16;
		scanf("%d %d\n", &n, &p);
		if ((n == 0) && (p == 0)) {
			break;
		}
		//printf("n=%d&p=%d.\n", n, p);
		char* final = (char*)malloc(85 * sizeof(char));
		for (int i = 0; i < n; i ++) {
			char* s = (char*)malloc(85 * sizeof(char));
			fgets(s, 85, stdin);
		}
		for (int i = 0; i < p; i ++) {
			char* name = (char*)malloc(85 * sizeof(char));
			fgets(name, 85, stdin);
			double price = 0.0;
			int features = 0;
			//char* s = (char*) malloc (100);
			//fgets(s, 100, stdin);
			//printf("%s", s);
			//sscanf(s, "%lf %d\n", &price, &features);
			scanf("%lf %d\n", &price, &features);
			//printf("%lf %d\n", price, features);
			if (features >= maxFeatures) {
				if ((features > maxFeatures) || ((features == maxFeatures) && (price < bestPrice))) {
					//printf("I am here\n");
					maxFeatures = features;
					bestPrice = price;
					strcpy (final, name);
					//printf("%s\n", final);
					//printf("I am here\n");
				}
			}
			//printf("features = %d\n", features);
			//printf("I am here \n");
			for (int j = 0; j < features; j++) {
				char* nameFeature = (char*)malloc(500 * sizeof(char));
				fgets(nameFeature, 500, stdin);
				//printf("%s", nameFeature);
			}
		}
		printf("RFP #%d\n", count);
		printf("%s", final);
		count ++;
	}
}
