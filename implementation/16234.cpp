#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int n, l, r;
int cnt = 0;
int A[51][51];
bool visit[51][51];

vector<pair<int, int>> v;

int Next[4][2] = {
    {-1,0},{1,0},{0,1},{0,-1}
};

bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int z = 0; z < 4; z++) {
                int dx = j + Next[z][0];
                int dy = i + Next[z][1];
                if (dx < 0 || dy < 0 || dx >= n || dy >= n) continue;

                if (abs(A[i][j] - A[dy][dx]) >= l && abs(A[i][j] - A[dy][dx]) <= r) {
                    return false;
                }
            }
        }
    }
    return true;
}
bool population_differ(int x, int y, int dx, int dy) {
    if (abs(A[y][x] - A[dy][dx]) >= l && abs(A[y][x] - A[dy][dx]) <= r)
        return true;
    else
        return false;
}

void bfs(int x ,int y, int cnt) {

    int country = 1;
    int population = A[y][x];

    visit[y][x] = true;

    queue<pair<int, int>> q;

    q.push({ x, y });
    v.push_back({ x,y });

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int dx = cur_x + Next[i][0];
            int dy = cur_y + Next[i][1];

            if (dx < n && dy < n && dx >= 0 && dy >= 0) {
                if (visit[dy][dx] == false && population_differ(cur_x, cur_y, dx, dy)) {
                    visit[dy][dx] = true;
                    q.push({ dx, dy });
                    v.push_back({ dx,dy });
                    country++;
                    population += A[dy][dx];
                }
            }
        }
    }

    int avg = population / country;

    for (int i = 0; i < v.size(); i++) {
        A[v[i].second][v[i].first] = avg;
       
    }
    v.clear();
   
}

int main() {
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    while (!check()) {
        int crowd = 0;
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visit[i][j] == false) { 
                    bfs(j, i, crowd);
                    crowd++;
                }
            }
        }
       
        cnt++;

    }

    
    cout << cnt << '\n';

}
