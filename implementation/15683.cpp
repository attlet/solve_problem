#include<iostream>
#include<vector>

using namespace std;

int n, m;
int map[8][8];
int ret = 987654321;
int cctv = 0;
vector<pair<pair<int, int>, int>> v;

void change_map(int x , int y, int point) {
	switch (point) {
	case 0:                               //오른쪽으로 
		for (int i = x + 1; i < m; i++) {
			if (map[y][i] == 6) break;
			else if (map[y][i] != 0) continue; 
			else map[y][i] = 7;       
		}
		break;
	case 1:                              //위쪽으로
		for (int i = y - 1; i >= 0; i--) {
			if (map[i][x] == 6) break;
			else if (map[i][x] != 0) continue;
			else map[i][x] = 7;
		}
		break;
	case 2:                               //왼쪽으로
		for (int i = x - 1; i >= 0; i--) {
			if (map[y][i] == 6) break;
			else if (map[y][i] != 0) continue;
			else map[y][i] = 7;
		}
		break;
	case 3:
		for (int i = y + 1; i < n; i++) {     //아래쪽
			if (map[i][x] == 6) break;
			else if (map[i][x] != 0) continue;
			else map[i][x] = 7;
		}
		break;
	}
}

void return_map(int temp[9][9]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = temp[i][j];
		}
	}
}

int cal_safe() {
	int cnt_safe = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) cnt_safe++;
		}
	}

	return cnt_safe;
}
void dfs(int cnt) {
	if (cnt >= v.size()) {
		ret = min(ret, cal_safe());
		return;
	}
	int temp[9][9];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = map[i][j];
		}
	}
	int cur_x = v[cnt].first.first;
	int cur_y = v[cnt].first.second;
	int cctv_n = v[cnt].second;

	switch (cctv_n) {
	case 1:
		for (int i = 0; i < 4; i++) {
			change_map(cur_x, cur_y, i);
			dfs(cnt + 1);
			return_map(temp);
		}
		break;
	case 2:
		for (int i = 0; i <= 1; i++) {
			change_map(cur_x, cur_y, i);
			change_map(cur_x, cur_y, i + 2);
			dfs(cnt + 1);
			return_map(temp);
		}
		break;
	case 3:
		for (int i = 0; i <= 2; i += 2) {
			for (int j = 1; j <= 3; j += 2) {
				change_map(cur_x, cur_y, i);
				change_map(cur_x, cur_y, j);
				dfs(cnt + 1);
				return_map(temp);
			}
		}
		break;
	case 4:
		change_map(cur_x, cur_y, 0);
		change_map(cur_x, cur_y, 1);
		change_map(cur_x, cur_y, 2);
		dfs(cnt + 1);
		return_map(temp);
		
		change_map(cur_x, cur_y, 0);
		change_map(cur_x, cur_y, 1);
		change_map(cur_x, cur_y, 3);
		dfs(cnt + 1);
		return_map(temp);
		
		change_map(cur_x, cur_y, 0);
		change_map(cur_x, cur_y, 2);
		change_map(cur_x, cur_y, 3);
		dfs(cnt + 1);
		return_map(temp);
		
		change_map(cur_x, cur_y, 1);
		change_map(cur_x, cur_y, 2);
		change_map(cur_x, cur_y, 3);
		dfs(cnt + 1);
		return_map(temp);
		break;
	case 5:
		
		for (int i = 0; i < 4; i++) 
			change_map(cur_x, cur_y, i);
		dfs(cnt + 1);
		return_map(temp);
		break;
	}

}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 6 && map[i][j] != 0) {
				cctv++;
				v.push_back({ {j,i}, map[i][j] });
			}
		}
	}

	dfs(0);

	cout << ret << '\n';
}
