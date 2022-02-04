#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
	if (a[1] == b[1])
		return a[0] < b[0];
	else return a[1] < b[1];
}

int main() {
	int n, count = 1;
	cin >> n;

	vector<vector<int>> A(n, vector<int>(2));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> A[i][j];
		}
	}
	
	sort(A.begin(), A.end(), cmp);

	int next = A[0][1];
	
	for(int i = 1 ; i < n ; i++) {
		if (next > A[i][0]) continue;
		next = A[i][1];
		count++;
	}
	cout << count << '\n';
}
