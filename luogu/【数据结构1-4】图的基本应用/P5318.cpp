#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
 * P5318 【深基18.例3】查找文献
 * */

// 深度搜索
void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &result) {

    visited[node] = true;
    result.push_back(node);

    for (int neighbor: graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, result);
        }
    }
}

// 广度搜索
void bfs(int start, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &result) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor: graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}


int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<int> dfs_result;
    fill(visited.begin(), visited.end(), false);
    dfs(1, graph, visited, dfs_result);

    for (int i = 0; i < dfs_result.size(); ++i) {
        cout << dfs_result[i] << " ";
    }
    cout << endl;

    vector<int> bfs_result;
    fill(visited.begin(), visited.end(), false);
    bfs(1, graph, visited, bfs_result);

    for (int i = 0; i < bfs_result.size(); ++i) {
        cout << bfs_result[i] << " ";
    }
    cout << endl;

    return 0;
}
