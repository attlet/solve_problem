#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int n, m;
int ret = 987654321;
int map[52][52];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> sel_chik;

int cal_chik() {
	int ret = 0;

	for (int i = 0; i < house.size(); i++) {
		int dist = 987654321;
		int hx = house[i].first;
		int hy = house[i].second;

		for (int j = 0; j < sel_chik.size(); j++) {
			int x = sel_chik[j].first;
			int y = sel_chik[j].second;
			dist = min(dist, abs(hx - x) + abs(hy - y));
		}

		ret += dist;
	}

	return ret;
}

void select(int cnt, int idx) {

	if (cnt == m) {
		ret = min(ret, cal_chik());
		return;
	}

	for (int i = idx; i < chicken.size(); i++) {
		sel_chik.push_back({ chicken[i].first, chicken[i].second });
		select(cnt + 1, i + 1);
		sel_chik.pop_back();
	}
	
	
}
int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) house.push_back({ i,j });
			else if (map[i][j] == 2) chicken.push_back({ i,j });
		}
	}
	
	select(0, 0);

	cout << ret << '\n';
}
