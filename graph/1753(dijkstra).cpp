#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

#define INF 987654321

using namespace std;

bool visit[20001];
int d[20001];
vector<pair<int, int>> a[20001];


void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		for (int i = 0; i < a[current].size(); i++) {
			int cost = distance + a[current][i].second;
			int next = a[current][i].first;

			if (cost < d[next]) {
				d[next] = cost;
				pq.push(make_pair(-cost, next));
			}
		}


	}
}

int main() {
	int V, E, K;
	cin >> V >> E;
	cin >> K;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u].push_back(make_pair(v, w));
	}
	for (int i = 1; i <= V; i++)
		d[i] = INF;
	
	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (d[i] == INF)
			cout << "INF" << "\n";
		else
			cout << d[i] << '\n';
	}
}
