#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
 * P3916 图的遍历
 * */

void dfs(int start, vector<vector<int>> &graph, vector<int> &visited, int maxn) {
    if (visited[start]) return;
    visited[start] = maxn;
    for (int i = 0; i < graph[start].size(); i++) dfs(graph[start][i], graph, visited, maxn);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> visited(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        graph[y].push_back(x);
    }
    for (int i = n; i; i--) dfs(i, graph, visited, i);
    for (int i = 1; i <= n; ++i) {
        cout << visited[i] << " ";
    }

    return 0;
}