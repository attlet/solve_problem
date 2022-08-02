#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int n, l, cnt = 0;
int map[101][101];
bool visit[101][101];

int main() {
	cin >> n >> l;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> map[i][j];
	
	for (int i = 0; i < n; i++) {   //가로
		bool equal = true;
		bool stair = true;
		bool end_point = true;
		int isEnd = 0;
		int standard = map[i][0];

		for (int j = 0; j < n; j++) {
			isEnd++;
			if (standard != map[i][j]) {
				equal = false;

				if ((map[i][j] - standard) * (map[i][j] - standard) == 1) {
					if (standard < map[i][j]) {
						if (j - l >= 0) {
							for (int z = j - l; z < j; z++) {
							    if (map[i][z] != standard || visit[i][z]) {
								    stair = false;
									break;
							    }
								visit[i][z] = true;
						    }
						}
						else {
							standard = 11;
							break;
						}
					}
					else {
						int small_std = map[i][j];
						for (int z = j ; z < j + l; z++) {
							if (map[i][z] != small_std || visit[i][z]) {
								stair = false;
								break;
							}
							visit[i][z] = true;
						}
					}
				}
				else {
					standard = 11;
					break;
				}
				
				if (stair)
					standard = map[i][j];
				else {
					standard = 11;
					break;
				}
			}
			
			
		}
		if (equal || standard != 11) {
			cnt++;
		}
		
	}
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < n; i++) {   //세로
		bool equal = true;
		bool stair = true;
		bool end_point = true;
		int isEnd = 0;
		int standard = map[0][i];

		for (int j = 0; j < n; j++) {
			isEnd++;
			if (standard != map[j][i]) {
				equal = false;

				if ((map[j][i] - standard) * (map[j][i] - standard) == 1) {
					if (standard < map[j][i]) {
						if (j - l >= 0) {
							for (int z = j - l; z < j; z++) {
								if (map[z][i] != standard || visit[z][i]) {
									stair = false;
									break;
								}
								visit[z][i] = true;
							}
						}
						else {
							standard = 11;
							break;
						}
					}
					else {
						int small_std = map[j][i];
						for (int z = j; z < j + l; z++) {
							if (map[z][i] != small_std || visit[z][i]) {
								stair = false;
								break;
							}
							visit[z][i] = true;
						}
					}
				}
				else {
					standard = 11;
					break;
				}

				if (stair)
					standard = map[j][i];
				else {
					standard = 11;
					break;
				}
			}


		}
		if (equal || standard != 11) {
			cnt++;
		}
	}
	cout << cnt << '\n';
}
