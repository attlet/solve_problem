#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


int n;
vector<int> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
		
	sort(v.begin(), v.end());

	int ret = 1;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] > ret)
			break;
		ret += v[i];
	}
	cout << ret << '\n';
}
