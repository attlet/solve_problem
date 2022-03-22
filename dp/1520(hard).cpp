#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstring>

using namespace std;

int graph[501][501];
long long dp[501][501];
int m, n;

int Next[4][2] = {
	{ 0 , 1} , {1, 0} , { 0 , -1} , { -1, 0}
};

bool isRange(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= m;
}

int dfs(int x, int y) {


	if (x == n - 1 && y == m - 1)
		return 1;

	else if(dp[y][x] == -1){
		dp[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			if (!isRange(x + Next[i][0], y + Next[i][1])) {
				if(graph[y][x] > graph[y+ Next[i][1]][x+Next[i][0]])
				    dp[y][x] += dfs(x + Next[i][0], y + Next[i][1]);
			}
		}
	}
	
	return dp[y][x];
	
    
}
int main() {
	
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
			dp[i][j] = -1;
		}
	}
	

	int ret = dfs(0, 0);
	cout << ret << '\n';
}

