#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int r, c;
char map[21][21];
bool visit[21][21];
bool alpha[26];

int Next[4][2] = {
	{1,0},{-1,0},{0,-1},{0,1}
};
bool isRange(int x, int y) {
	if (x >= 0 && y >= 0 ) {
		if (x < c && y < r) {
			return true;
		}
	}
	return false;
}
int dfs(int x, int y) {
	int ret = 1, counting = 0;
	visit[y][x] = true;
	alpha[map[y][x] - 'A'] = true;

	for (int i = 0; i < 4; i++) {
		int dx = x + Next[i][0];
		int dy = y + Next[i][1];
		if (isRange(dx, dy)) {
			if (!alpha[map[dy][dx] - 'A']) {
				counting = max(counting, dfs(dx, dy));
			}
		}
	}
	alpha[map[y][x] - 'A'] = false;
	return ret + counting;
}
int main() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		cin >> map[i];
	}

	cout << dfs(0, 0) << '\n';
}
