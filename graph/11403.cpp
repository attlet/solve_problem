#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n;
int adj[101][101];
int ret[101][101];
bool visit[101];

void dfs(int v) {
	
	for (int i = 0; i < n; i++) {
		if (visit[i] == 0 && adj[v][i] == 1) {
			visit[i] = true;
			dfs(i);
		}
	}
	
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		memset(visit, 0, sizeof(visit));
		dfs(i);
		for (int j = 0; j < n; j++) {
			if (visit[j]) ret[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ret[i][j] <<' ';
		}
		cout << '\n';
	}
	
}
