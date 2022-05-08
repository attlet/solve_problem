#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int coord[101][4];
int map[101][101];
bool visit[101][101];

vector<int> v;

int Next[4][2] = {
	{-1, 0}, { 1, 0}, {0, -1}, { 0, 1}
};
int n, m, k;

int bfs(int x, int y) {
	int Count = 0;
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = cur_x + Next[i][0];
			int dy = cur_y + Next[i][1];
			if (dx >= 0 && dy >= 0 && dx < n && dy < m) {
				if (map[dy][dx] == 0 && !visit[dy][dx]) {
					visit[dy][dx] = true;
					q.push({ dx, dy });
					Count++;
			    }
			}
		}
	}
	if (!Count) Count = 1;
	return Count;
}

int main() {
	int num = 0;
	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> coord[i][0] >> coord[i][1] >> coord[i][2] >> coord[i][3];
	}

	for (int i = 0; i < k; i++) {
		int row = coord[i][3] - coord[i][1];
		int col = coord[i][2] - coord[i][0];

		for (int j = coord[i][1]; j < coord[i][1] + row; j++) {
			for (int z = coord[i][0]; z < coord[i][0] + col; z++) {
				map[j][z] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == false && map[i][j] == 0) {
				v.push_back(bfs(j, i));
				num++;
			}
		}
	}

	sort(v.begin(), v.end());

	cout << num << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i]<<' ';
	}
	cout << '\n';

	
	


}
