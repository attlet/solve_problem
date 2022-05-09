#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
char matrix1[51][51];
char matrix2[51][51];

void change(int x, int y) {
	for (int i = y; i < y + 3; i++) {
		for (int j = x; j < x + 3; j++) {
			if (matrix1[i][j] == '0') matrix1[i][j] = '1';
			else if (matrix1[i][j] == '1') matrix1[i][j] = '0';
		}
	}
}

int main() {
	int ret = 0;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> matrix1[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> matrix2[i];	
	}

	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < m-2; j++) {
			if (matrix1[i][j] != matrix2[i][j]) {
				change(j, i);
				ret++;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix1[i][j] != matrix2[i][j]) {
				cout << -1 << '\n';
				return 0;
			}
			
		}
	}
	cout << ret << '\n';

}
