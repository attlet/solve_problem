#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int n;

int main() {
    cin >> n;

    vector<pair<int, int>> v(n);
    priority_queue<int, vector<int>, greater<int>>pq;

    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());

    pq.push(v[0].second);

    for (int i = 1; i < n; i++) {
        if (pq.top() > v[i].first) {
            pq.push(v[i].second);
        }
        else {
            pq.pop();
            pq.push(v[i].second);
        }
    }

    cout << pq.size() << '\n';
}
