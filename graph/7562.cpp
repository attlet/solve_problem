#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;
int visit[301][301];
int Next[8][2] = {
	{2, 1}, {1,2}, {-1,2}, {-2,1}, {-2,-1},{-1,-2},{1,-2}, {2,-1}
};

void bfs(int l, int x, int y, int ex, int ey) {
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		if (cur_x == ex && cur_y == ey) break;

		for (int i = 0; i < 8; i++) {
			int dx = cur_x + Next[i][0];
			int dy = cur_y + Next[i][1];

			if (dx >= 0 && dy >= 0 && dx < l && dy < l) {
				if (visit[dy][dx] == 0) {
					visit[dy][dx] = visit[cur_y][cur_x] + 1;
					q.push({ dx, dy });
				}
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int l;
		pair<int, int> start;
		pair<int, int> end;

		cin >> l;
		cin >> start.first >> start.second;
		cin >> end.first >> end.second;

		bfs(l, start.first, start.second, end.first, end.second);

		cout << visit[end.second][end.first] << '\n';
		memset(visit, 0, sizeof(visit));
	}
}
