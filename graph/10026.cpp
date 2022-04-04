#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

char map[101][101];
bool visit[101][101];

int Next[4][2] = {
	{-1,0}, {1,0}, {0,-1}, {0, 1}
};
int n;

void bfs(int x, int y, char color, bool rg) {
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
				if (!rg) {
					if (visit[dy][dx] == false && map[dy][dx] == color) {
					    visit[dy][dx] = true;
					    q.push(make_pair(dx, dy));
				    }
				}
				else {
					if (color == 'R' || color == 'G') {
						if (visit[dy][dx] == false && ((map[dy][dx] == 'R')||(map[dy][dx] == 'G'))) {
							visit[dy][dx] = true;
							q.push(make_pair(dx, dy));
						}
				    }
					else {
						if (visit[dy][dx] == false && map[dy][dx] == color) {
							visit[dy][dx] = true;
							q.push(make_pair(dx, dy));
						}
					}
				}
			}
		}
	}
}
int main() {
	int ret1 = 0, ret2 = 0;
	cin >> n;

	for (int i = 0; i < n; i++) 
		cin >> map[i];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				bfs(j, i, map[i][j], false);
				ret1++;
			}
		}
	}
	
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				bfs(j, i, map[i][j], true);
				ret2++;
			}
		}
	}

	cout << ret1 <<' '<< ret2 << '\n';
}
