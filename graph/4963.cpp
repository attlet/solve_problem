#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int map[51][51];
bool visit[51][51];

int Next[8][2] = {
	{-1,0}, {1,0}, {0,-1}, {0, 1}, {1, 1}, {1, -1}, { -1, 1}, {-1, -1}
};

void bfs(int x, int y, int w, int h) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[y][x] = true;

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int dx = cur_x + Next[i][0];
			int dy = cur_y + Next[i][1];
			if (dx >= 0 && dy >= 0 && dx < w && dy < h) {
				if (visit[dy][dx] == false && map[dy][dx] == 1) {
					visit[dy][dx] = true;
					q.push(make_pair(dx, dy));
				}
			}
		}
	}
}
int main() {
	while (1) {
		int w, h, land = 0;
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && visit[i][j] == false) {
					bfs(j, i, w, h);
					land++;
				}
			}
		}
		memset(visit, false, sizeof(visit));
		cout << land << '\n';
	}
}
