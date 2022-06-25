#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int n, far_d, far_n;
vector<pair<int, int>> tree[10001];
bool visit[10001];

void dfs(int pre_v, int dist) {
	visit[pre_v] = true;
	
	if (dist > far_d) {
		far_d = dist;
		far_n = pre_v;
	}
	for (int i = 0; i < tree[pre_v].size(); i++) {
		int next_n = tree[pre_v][i].first;
		int next_d = tree[pre_v][i].second + dist;
		if (!visit[next_n]) {
			dfs(next_n, next_d);
		}
	}
}

//연결리스트는 인접행렬과는 다르게 연결상태 체크할 필요x. 연결된 노드들만 들어가 있기에.
int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({ b, c });
		tree[b].push_back({ a, c });

	}

	dfs(1, 0);
	memset(visit, false, sizeof(visit));
	far_d = 0;
	dfs(far_n, 0);

	cout << far_d << '\n';

}
