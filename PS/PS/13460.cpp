#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int rx, ry, bx, by;
int n, m;

int mainI() {

	cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'R') {
				rx = i, ry = j;
			}
			else if (a[i][j] == 'B') {
				bx = i, by = j;
			}
		}
	}






}