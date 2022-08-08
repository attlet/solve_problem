#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int r, c, k;
int ret = 0;
int cnt[101];
int A[101][101];
int row_num = 3;
int col_num = 3;

bool cmp(pair<int,int> a, pair<int,int> b) {
	if (a.second == b.second)
		return (a.first < b.first);
	else
		return (a.second < b.second);
}
void Row_cal() {

	int max_len = -1;

	for (int i = 1; i <= row_num; i++) {
		memset(cnt, 0, sizeof(cnt));
		vector<pair<int, int>> temp;

		for (int j = 1; j <= col_num; j++) {
			if (A[i][j] == 0) continue;
			cnt[A[i][j]]++;
			A[i][j] = 0;
		}
		for (int j = 1; j < 101; j++) {
			if (cnt[j] != 0) {
				temp.push_back({ j, cnt[j] });
			}
		}

		
		sort(temp.begin(), temp.end(), cmp);
		int arr = 1;
		int len_cnt = 0;
		for(int j = 0 ; j < temp.size();j++) {
			A[i][arr] = temp[j].first;
			A[i][arr + 1] = temp[j].second;
			arr += 2;
		}

		max_len = max(max_len, arr);
	}
	
	col_num = max_len;

	
	
}

void Col_cal() {
	int max_len = -1;

	for (int i = 1; i <= col_num; i++) {
		memset(cnt, 0, sizeof(cnt));
		vector<pair<int, int>> temp;

		for (int j = 1; j <= row_num; j++) {
			if (A[j][i] == 0) continue;
			cnt[A[j][i]]++;
			A[j][i] = 0;
		}
		for (int j = 1; j < 101; j++) {
			if (cnt[j] != 0) {
				temp.push_back({ j, cnt[j] });
			}
		}


		sort(temp.begin(), temp.end(), cmp);
		int arr = 1;
		int len_cnt = 0;
		for (int j = 0; j < temp.size(); j++) {
			A[arr][i] = temp[j].first;
			A[arr + 1][i] = temp[j].second;
			arr += 2;
		}

		max_len = max(max_len, arr);
	}

	row_num = max_len;

	
	
}
int main() {
	

	cin >> r >> c >> k;
	memset(A, 0, sizeof(A));
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> A[i][j];
		}
	}

	while (1) {
		if (ret > 100) {
			cout << -1 << '\n';
			return 0;
		}

		if (A[r][c] == k) break;

		if (row_num >= col_num)
			Row_cal();
		else
			Col_cal();

		ret++;
	}
	cout << ret << '\n';
}
