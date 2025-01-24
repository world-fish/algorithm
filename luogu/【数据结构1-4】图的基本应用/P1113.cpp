#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
 * P1113 杂务
 * */

void dfs() {

}

int main() {

    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    vector<int> time(n + 1);
    while (n--) {
        int i;
        cin >> i >> time[i];

        int pre;
        while (cin >> pre && pre != 0) {
            graph[i].push_back(pre);
        }
    }
    for (int i = 1; i < graph.size(); ++i) {
        int maxn = 0;
        for (int j = 0; j < graph[i].size(); ++j) {
            maxn = max(maxn, time[graph[i][j]]);
        }
        time[i] += maxn;
    }
    sort(time.begin(), time.end());
    cout << time[time.size() - 1] << endl;

    return 0;
}