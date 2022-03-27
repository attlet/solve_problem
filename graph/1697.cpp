#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int visit[100001];
int n, k;

int bfs(int v) {
	queue<pair<int, int>> q;
	q.push(make_pair(v,0));
	visit[v] = 1;

	while (!q.empty()) {
		int vertex = q.front().first;
		int ret = q.front().second;
		q.pop();
		if (vertex == n) return ret;
	    
		
		if (vertex % 2 == 0 && visit[vertex / 2] == 0) {
			q.push(make_pair(vertex / 2, ret+1));
			visit[vertex / 2] = 1;
		}
			
		if (visit[vertex + 1] == 0) { 
			q.push(make_pair(vertex + 1, ret + 1));
			visit[vertex + 1] = 1;
		}
		   
		if (visit[vertex - 1] == 0) {
			q.push(make_pair(vertex - 1, ret + 1));
			visit[vertex - 1] = 1;
		}
	}
}

int main() {
	cin >> n >> k;
	
	cout << bfs(k) << '\n';
}
