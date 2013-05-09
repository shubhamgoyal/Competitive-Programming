#include <stdio.h>
#include <vector>
#include <limits.h>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

pair<int, pair<string,string> > list[100];
int dist[1 << 20];
int n, m;
bool visited[1 << 20];

int main() {
	int count = 0;
	while(true) {
		count++;
		scanf("%d %d", &n, &m);
		//cin >> n >> m;
		if ((n == 0) && (m == 0)) {
			break;
		}
		printf("Product %d\n", count);
		for (int i = 0; i < m; i++) {
			int edgeWeight;
			scanf("%d", &edgeWeight);
			char str1[n + 1];
			char str2[n + 1];
			scanf("%s", str1);
			scanf("%s", str2);
			//printf("%d %s %s\n", edgeWeight, str1, str2);
			/*cin >> edgeWeight;
			string str1, str2;
			cin >> str1;
			cin >> str2;*/
			list[i].first = edgeWeight;
			list[i].second.first = str1;
			list[i].second.second = str2;
		}
		//printf("I am here\n");
		for (long int i = 0; i < 1 << n; i++) {
			dist[i] = INT_MAX;
			visited[i] = false;
		}
		dist[(1 << n) - 1] = 0;
		priority_queue<pair<int, long int>, vector<pair<int, long int> >, greater<pair<int, long int> > > pq;
		pq.push(pair<int, long int>(0, (1 << n) - 1));
		while (!pq.empty()) {
			pair<int, long int> front = pq.top();
			pq.pop();
			int d = front.first;
			long int u = front.second;
			if (!visited[u]) {
				visited[u] = true;
				if (u == 0) {
					break;
				}
				//printf("%d %ld\n", d, u);
				if (d == dist[u]) {
					for (int i = 0; i < m; i++) {
						string source = list[i].second.first;
						//cout << source << "\n";
						int flag = 0;
						for (int j = 0; j < n; j++) {
							char c = source[j];
							if (((c == '+') && !(u & (1 << (n - j - 1)))) || ((c == '-') && (u & (1 << (n - j - 1))))) {
								flag = 1;
								//printf("flag = 1 at i = %d, j = %d, c = %c\n", i, j, c);
								break;
							}
						}
						if (flag == 0) {
							string destination = list[i].second.second;
							long int dest_node = 0;
							for (int j = 0; j < n; j++) {
								if (destination[j] == '+') {
									dest_node = dest_node + (1 << (n - 1 - j));
								}
								else if (destination[j] == '-') {
									dest_node = dest_node + 0;
								}
								else {
									dest_node = dest_node + (u & (1 << (n - 1 - j)));
								}
							}
							if ((dist[u] + list[i].first) < dist[dest_node]) {
								dist[dest_node] = dist[u] + list[i].first;
								pq.push(pair<int, long int>(dist[dest_node], dest_node));
							}
						}
					}
				}
			}
		}
		if (dist[0] < INT_MAX) {
			printf("Fastest sequence takes %d second", dist[0]);
			if (dist[0] <= 1) {
				printf(".\n");
			}
			else {
				printf("s.\n");
			}
		}
		else {
			printf("Bugs cannot be fixed.\n");
		}
	}
}
