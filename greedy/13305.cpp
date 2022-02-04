#include<iostream>
#include<vector>

using namespace std;

int n;
long long ret = 0;

int main() {
	cin >> n;

	vector<long long> distance(n -1);
	vector<long long> cost(n);

	for (auto& d : distance)
		cin >> d;

    for (auto& c : cost)
		cin >> c;


	

	long long min = cost[0];

	for (int i = 0; i < n-1; i++) {
		if (cost[i] < min) {
			min = cost[i];
		}
		ret += min * distance[i];
	}
	cout << ret << '\n';
}
