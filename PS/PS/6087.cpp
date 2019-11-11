#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

const int MAX = 100;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int dist[MAX][MAX];
int main() {

	int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
	int n, m;
	cin >> n >> m;
	vector<string> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 'C') {
				if (x1 == -1) {
					x1 = i, y1 = j;
				}
				else if (x2 == -1) {
					x2 = i, y2 = j;
				}
			}
			if (a[i][j] == '.') {
				dist[i][j] = -1;
			}
		}
	}
	queue<pair<int, int>> q;
	q.push({ x1, y1 });
	dist[x1][y1] = 0;
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front(); q.pop();
		if (x == x2 && y == y2) break;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < m && 0 <= ny && ny < n && dist[nx][ny] == -1) {
				while (true) {
					// 거울 갯수의 최솟값을 구하여라.
					if (a[nx][ny] == '.') {
						if (0 > nx || nx >= m || 0 > ny || ny >= n || a[nx][ny] == '*') break;
						if (dist[nx][ny] == -1)
							dist[nx][ny] = dist[x][y] + 1;
						q.push({ nx, ny });
						nx = nx + dx[i];
						ny = ny + dy[i];
					}
				}
			}
		}
	}
	cout << dist[x2][y2] << '\n';
	return 0;
}