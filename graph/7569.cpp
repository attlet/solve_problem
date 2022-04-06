#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int m, n, h;
int map[101][101][101];
bool visit[101][101][101];
queue<pair<pair<int, int>, int>> q;
int Next[6][3] = {
	{1,0,0},{-1,0,0},{0,-1,0},{0,1,0},{0,0,-1}, {0,0,1}
};
bool isRange(int x, int y, int z) {
	if (x >= 0 && y >= 0 && z >= 0) {
		if (x < m && y < n && z < h) {
			return true;
		}
	}
	return false;
}
void bfs() {
	while (!q.empty()) {
		int cur_x = q.front().first.first;
		int cur_y = q.front().first.second;
		int cur_z = q.front().second;
		q.pop();
		visit[cur_z][cur_y][cur_x] = true;

		for (int i = 0; i < 6; i++) {
			int dx = cur_x + Next[i][0];
			int dy = cur_y + Next[i][1];
			int dz = cur_z + Next[i][2];
			if (isRange(dx, dy, dz)) {
				if (map[dz][dy][dx] == 0 && visit[dz][dy][dx] == false) {
					q.push(make_pair(make_pair(dx, dy), dz));
					map[dz][dy][dx] = map[cur_z][cur_y][cur_x] + 1;
				}
			}
		}
	}
}
int main() {
	int Count = 0;
	cin >> m >> n >> h;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < m; z++) {
				cin >> map[i][j][z];
				if(map[i][j][z] == 1) q.push(make_pair(make_pair(z, j), i));
			}
		}
	}
	bfs();

	int Max = -1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < m; z++) {
				if (map[i][j][z] == 0) {
					cout << -1 << '\n';
					return 0;
				}
				if (Max < map[i][j][z]) Max = map[i][j][z];
			}
		}
	}
	if (Max == 1)
		cout << 0 << '\n';
	else
		cout << Max-1 << '\n';

}
