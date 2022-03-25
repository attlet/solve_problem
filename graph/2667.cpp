#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

char map[26][26];
int visit[26][26];
int Next[4][2] = {
	{-1, 0}, {1, 0}, {0 , -1}, {0, 1}
};

int Count = 0;
vector<int> v;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x,y));
	visit[x][y] = 1;
	int apart_count = 1;
	
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = cur_x + Next[i][0];
			int dy = cur_y + Next[i][1];
			if (visit[dx][dy] == 0 && map[dx][dy] == '1') {
				visit[dx][dy] = 1;
				q.push(make_pair(dx, dy));
				apart_count++;
			}
		}
	}
	v.push_back(apart_count);
	
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) 
		cin >> map[i];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '0') continue;
			else if(map[i][j] == '1') {
				if (visit[i][j] == 0) {
					bfs(i, j);
					Count++;
				}
				    

			}
		}
	}
	sort(v.begin(), v.end());

	cout << Count << '\n';
	for (int i = 0; i < v.size(); i++) 
		cout << v[i] << '\n';
	
	

}
