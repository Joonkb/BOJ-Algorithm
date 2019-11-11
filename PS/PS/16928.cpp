#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int nextt[101];
int dist[101];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= 100; i++) {
		nextt[i] = i;
	}
	while (n--) {
		int x, y;
		scanf("%d %d", &x, &y);
		nextt[x] = y;
	}
	while (m--) {
		int x, y;
		scanf("%d %d", &x, &y);
		nextt[x] = y;
	}
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(1); dist[1] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 1; i <= 6; i++) {
			int nx = x + i;
			if (nx > 100)continue;
			nx = nextt[nx];
			if (dist[nx] == -1) {
				dist[nx] = dist[x] + 1;
				q.push(nextt[nx]);
			}
		}
	}
	printf("%d\n", dist[100]);
}