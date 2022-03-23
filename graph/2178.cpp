#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
char map[101][101];
int visit[101][101];
int dp[101][101];
int ret = 1;

int Next[4][2] = {
	{ 1, 0}, {-1, 0}, {0, 1}, {0 , -1}
};

void bfs(int x, int y) {
	
	visit[y][x] = 1;

	queue<pair<int, int>> q;

	q.push(make_pair(x, y));
	dp[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + Next[i][0];
			int dy = y + Next[i][1];

			if (dx >= 0 && dy >= 0 && dx < m && dy < n) {
				if (map[dy][dx] == '1' && visit[dy][dx] == 0) {
					dp[dy][dx] = dp[y][x] + 1;
					visit[dy][dx] = 1;
					q.push(make_pair(dx, dy));
				}
			}
		}
	}

	
}


int main() {
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	bfs(0, 0);

	cout << dp[n - 1][m - 1] << '\n';

}
