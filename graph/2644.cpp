#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n, m;
int sear_a, sear_b;
int ret = 0;
bool list[101][101];
int visit[101];

void bfs(int v) {
	queue<int> q;
	visit[v] = 1;
	q.push(v);

	while (!q.empty()) {
		int pre_v = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0 && list[pre_v][i]) {
				visit[i] = visit[pre_v] + 1;
				q.push(i);
			}
		}
	}
}
int main() {
	cin >> n;
	cin >> sear_a >> sear_b;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		list[a][b] = list[b][a] = true;
	}



	bfs(sear_b);
	if(visit[sear_a])
	    cout << visit[sear_a]-1 << '\n';
	else {
		cout << -1 << '\n';
	}
}
