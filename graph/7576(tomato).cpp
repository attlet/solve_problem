#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int map[1001][1001];
int visit[1001][1001];
int Next[4][2] = {
	{-1, 0}, {1, 0}, {0, -1}, {0, 1}
};
int m, n, day = 0;
queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
		    int dx = cur_x + Next[i][0];
		    int dy = cur_y + Next[i][1];

		    if (dx >= 0 && dy >= 0 && dx < m && dy < n) {
			    if (map[dy][dx] == 0 && visit[dy][dx] == 0) {
			    	visit[dy][dx] = 1;
				    map[dy][dx] = map[cur_y][cur_x] + 1;
					q.push(make_pair(dx, dy));
			    }
		    }
	    }
	}
}

int main() {
	int tomato = 0;
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push(make_pair(j, i));
			}
		}
	}

	bfs();
		
	int Max = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cout << -1 << '\n';
				return 0;
			}
			if (map[i][j] > Max) {
				Max = map[i][j];
			}
		}
	}
	cout << Max-1 << '\n';
	
}
