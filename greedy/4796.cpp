#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


int main() {
	int L, P, V;
	int i = 1;
	while (1) {
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)break;

		int last;

		if (V % P > L) {
			last = L;
		}
		else {
			last = V % P;
		}
		
		int ret = (V / P) * L + last;
		cout << "Case " << i << ": " << ret << '\n';
		i++;
	}

}
