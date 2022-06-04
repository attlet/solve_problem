#include<iostream>
#include<vector>

using namespace std;

int n, k;


int main() {
	int ret = 0;
	cin >> n >> k;
	vector<int> con(n);  //콘센트 자리
	vector<int> seq(k);
	vector<bool> appear(n); //등장했었는지 표시

	for (int i = 0; i < k; i++) {
		cin >> seq[i];
	}

	for (int i = 0; i < k; i++) {
		bool exist = false;
		for (int j = 0; j < n; j++) {
			if (con[j] == 0) {
				con[j] = seq[i];   //빈곳에는 꽂음.
				exist = true;
				break;
			}
			else if (con[j] == seq[i]) {
				exist = true;
				break;
			}
		}

		if (exist) {
			continue;
		}
		else {
			ret++;
			int index = 0;
			int max_count = 0;

			for (int j = 0; j < n; j++) {
				int count = 101;
				
				for (int z = i + 1; z < k; z++) {
					if (con[j] == seq[z]) {
						count = z;
						break;
					}
				}

				if (max_count < count) {
					max_count = count;
					index = j;
				}
			}

			con[index] = seq[i];

		}
	}

	cout << ret << '\n';

}
