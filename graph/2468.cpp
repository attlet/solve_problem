#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int map[101][101];
bool visit[101][101];

int Next[8][2] = {
	{-1,0}, {1,0}, {0,-1}, {0, 1}
};
int n;

void bfs(int x, int y, int rain) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[y][x] = true;

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = cur_x + Next[i][0];
			int dy = cur_y + Next[i][1];
			if (dx >= 0 && dy >= 0 && dx < n && dy < n) {
				if (visit[dy][dx] == false && map[dy][dx] > rain) {
					visit[dy][dx] = true;
					q.push(make_pair(dx, dy));
				}
			}
		}
	}
}
int main() {
	int Max = -1, Min = 101;
	int ret = -1;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (Max < map[i][j]) Max = map[i][j];
			if (Min > map[i][j]) Min = map[i][j];
		}
	}
	bool one_land = false;
	for (int i = Min; i <= Max; i++) {
		int Count = 0;
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < n; z++) {
				if (map[j][z] > i && visit[j][z] == false) {
					bfs(z, j, i);
					Count++;
					one_land = true;
				}
			}
			
		}
		if (ret < Count) ret = Count;
		memset(visit, false, sizeof(visit));
	}
	if (one_land == false) ret = 1;
	cout << ret << '\n';
}
