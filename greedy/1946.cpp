#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int a, b;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, counter = 1;
		cin >> n;
		vector<pair<int, int>> A(n);
		vector<pair<int, int>> B(n);

		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			A[i].first = a;
			A[i].second = b;
		}

		sort(A.begin(), A.end());
		
		int stand1 = A[0].second;

		for (int i = 1; i < n; i++) {
			if (stand1 > A[i].second) {
				counter++;
				stand1 = A[i].second;
			}
			
				
		}
		cout << counter << '\n';
	}

}
