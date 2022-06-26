#include<iostream>

using namespace std;

int r, c;
int Count = 0;
char map[100001][501];
bool visit[100001][501];

int Next[3] = { -1, 0, 1 };
	
bool dfs(int x, int y) {
	visit[y][x] = true;

	if (x == c-1) {
		Count++;
		return true;
	}

	for (int i = 0; i < 3; i++) {
		int next_x = x + 1;
		int next_y = y + Next[i];

		if (next_x >= 0 && next_y >= 0 && next_x < c && next_y < r) {
			if (map[next_y][next_x] == '.' && visit[next_y][next_x] == false) {
				if (dfs(next_x, next_y)) return true;
			}
		}
	}
	return false;
}
int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < r; i++) {
		dfs(0, i);
	}

	cout << Count << '\n';
}
