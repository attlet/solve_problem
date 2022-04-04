#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main() {
	int n, k;
	long long ret = 0;
	cin >> n >> k;

	vector<pair<int, int>> jewer(n);
	vector<int> backpack(k);
	priority_queue<int> pq;

	for (int i = 0; i < n; i++) 
		cin >> jewer[i].first >> jewer[i].second;
	
	for (int i = 0; i < k; i++) 
		cin >> backpack[i];
	
	sort(jewer.begin(), jewer.end());
	sort(backpack.begin(), backpack.end());

	int j = 0;

	for (int i = 0; i < k; i++) {
		while (j < n && backpack[i] >= jewer[j].first) {
			pq.push(jewer[j].second);
			j++;
		}
		if (!pq.empty()) {
			ret += pq.top();
			pq.pop();
		}
	}

	cout << ret << '\n';
}
