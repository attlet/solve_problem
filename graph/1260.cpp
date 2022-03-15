#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstring>

using namespace std;

bool map[1001][1001];
bool visit[1001];
int n, m ,v;

void dfs(int v) {
	visit[v] = 1;
	cout << v << ' ';

	for (int i = 1; i <= n; i++) {
		if (map[v][i] == 1 && visit[i] == 0) {
			dfs(i);
		}
	}
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	visit[v] = 1;
	

	while(!q.empty()) {
		int vertex = q.front();
		q.pop();
        cout << vertex << ' ';

		for (int i = 1; i <= n; i++) {
			if (map[vertex][i] == 1 && visit[i] == 0) {
				visit[i] = 1;
				q.push(i);
			}
		}

		
	}
}

int main() {
	
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	dfs(v);
	cout << endl;

	memset(visit, 0, sizeof(visit));

	bfs(v);
	cout << endl;

}

