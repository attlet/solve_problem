#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int n, m;
int map[9][9];
int copyMap[9][9];
int visit[9][9];
int ans = -1;

int Next[4][2] = {
	{-1,0},{1,0},{0,-1},{0,1}
};


void copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copyMap[i][j] = map[i][j];
		}
	}
}

int zero() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copyMap[i][j] == 0) ret++;
		}
	}
	return ret;
}
void bfs() {
	queue<pair<int, int>> q;
	copy();
	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copyMap[i][j] == 2) q.push(make_pair(j, i));
		}
	}
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = cur_x + Next[i][0];
			int dy = cur_y + Next[i][1];
			if (dx >= 0 && dy >= 0 && dx < m && dy < n) {
				if (copyMap[dy][dx] == 0 && visit[dy][dx] == 0) {
					copyMap[dy][dx] = 2;
					visit[dy][dx] == 1;
					q.push(make_pair(dx, dy));
				}
			}
		}
	}
}

void wall(int cnt) {
	if (cnt == 3) {
		bfs();
		int temp = zero();
		ans = max(ans, temp);
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				wall(cnt + 1);
				map[i][j] = 0;
			}
		}
	}

}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	wall(0);
	cout << ans << '\n';


}
