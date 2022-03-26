#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int map[101][101];
int visit[101];
int n, edge;

int bfs(int x) {
	queue<int> q;
	q.push(x);
	visit[x] = 1;
	int Count = 0;

	while (!q.empty()) {
		int cur_x = q.front();
		q.pop();

		for (int i = 1; i <= n ; i++) {
			if (visit[i] == 0 && map[cur_x][i] == 1) {
				visit[i] = 1;
				q.push(i);
				Count++;
			}
		}
	}
	return Count;
}

int main() {
	
	cin >> n;
	cin >> edge;

	for (int i = 0; i < edge; i++) {
		int a, b;
		cin >> a >> b;

		map[a][b] = map[b][a] = 1;
	}
		
	cout<<bfs(1)<<'\n';
}
