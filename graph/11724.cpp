#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
int map[1001][1001];
int visit[1001];

void dfs(int v) {
	visit[v] = 1;

	for (int i = 1; i <= n; i++) {
		if (visit[i] == 0 && map[v][i] == 1) {
			dfs(i);
		}
	}
}

int main() {
	int Count = 0;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i] == 0) {
			dfs(i);
			Count++;
		}
	}

	cout << Count << '\n';

}
