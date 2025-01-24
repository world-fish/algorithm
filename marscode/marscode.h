#include <bits/stdc++.h>

using namespace std;

// 寻找最大葫芦
//vector<int> solution(int n, int max, const vector<int> &array) {
//    unordered_map<int, int> myMap;
//    for (int card: array) {
//        myMap[card]++;
//    }
//    myMap[14] = myMap[1];
//
//    vector<int> triples;
//    vector<int> pairs;
//
//    for (const auto &[card, count]: myMap) {
//        if (count >= 3) {
//            triples.emplace_back(card);
//        }
//        if (count >= 2) {
//            pairs.emplace_back(card);
//        }
//    }
//
//    sort(triples.begin(), triples.end(), greater<>());
//    sort(pairs.begin(), pairs.end(), greater<>());
//
//    for (auto a: triples) {
//        if (a == 14) {
//            a = 1;
//        }
//        int aaa = a * 3;
//        for (auto b: pairs) {
//            if (b == 14) {
//                b = 1;
//            }
//            if (a != b) {
//                int bb = b * 2;
//                int sum = aaa + bb;
//                if (sum <= max) {
//                    return {a, b};
//                }
//            }
//        }
//    }
//    return {0, 0};
//}

// 我好想逃却逃不掉
//void solve(int i, int j, int N, int M, vector<vector<char>> &data, int &sum) {
//    if (i < 0 || i >= N || j < 0 || j >= M || data[i][j] == 'O') {
//        return;
//    }
//    if (data[i][j] == '.') {
//        sum++;
//        data[i][j] = 'O';
//        solve(i - 1, j, N, M, data, sum);
//        solve(i + 1, j, N, M, data, sum);
//        solve(i, j - 1, N, M, data, sum);
//        solve(i, j + 1, N, M, data, sum);
//        return;
//    } else {
//        bool b = false;
//        switch (data[i][j]) {
//            case 'U':
//                if (i >= 1 && data[i - 1][j] == 'O') {
//                    b = true;
//                }
//                break;
//            case 'L':
//                if (j >= 1 && data[i][j - 1] == 'O') {
//                    b = true;
//                }
//                break;
//            case 'R':
//                if (j < M - 1 && data[i][j + 1] == 'O') {
//                    b = true;
//                }
//                break;
//            case 'D':
//                if (i < N - 1 && data[i + 1][j] == 'O') {
//                    b = true;
//                }
//                break;
//        }
//        if (b) {
//            data[i][j] = 'O';
//            sum++;
//            solve(i - 1, j, N, M, data, sum);
//            solve(i + 1, j, N, M, data, sum);
//            solve(i, j - 1, N, M, data, sum);
//            solve(i, j + 1, N, M, data, sum);
//        }
//    }
//}
//
//int solution(int N, int M, vector<vector<char>> data) {
//    int sum = 0;
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < M; ++j) {
//            if (data[i][j] == 'O') {
//                data[i][j] = '.';
//                solve(i, j, N, M, data, sum);
//                return M * N - sum;
//            }
//        }
//    }
//    return 0;
//}



// 蛇形填充n阶方阵
//vector<vector<int>> solution(int n) {
//    vector<vector<int>> res(n, vector<int>(n, 0));
//    int x = 0, y = n - 1, flag = 0;
//    for (int i = 1; i <= n * n; ++i) {
//        switch (flag % 4) {
//            case 0:
//                res[x++][y] = i;
//                if (x >= n || x < 0 || res[x][y]) {
//                    x--;
//                    y--;
//                    flag++;
//                }
//                break;
//            case 1:
//                res[x][y--] = i;
//                if (y >= n || y < 0 || res[x][y]) {
//                    x--;
//                    y++;
//                    flag++;
//                }
//                break;
//            case 2:
//                res[x--][y] = i;
//                if (x >= n || x < 0 || res[x][y]) {
//                    x++;
//                    y++;
//                    flag++;
//                }
//                break;
//            case 3:
//                res[x][y++] = i;
//                if (y >= n || y < 0 || res[x][y]) {
//                    x++;
//                    y--;
//                    flag++;
//                }
//                break;
//        }
//    }
//    return res;
//}

// 充电总时间计算
//string solution(int n, int x, vector<int> a) {
//    double total_time = 0;
//    for (auto item: a) {
//        total_time += item;
//    }
//    total_time /= 4 * x;
//    stringstream ss;
//    ss << fixed << setprecision(2) << total_time;
//    return ss.str();
//}

// 数列差异的最小化 (未完成) todo
//int solution(int n, int m, int k, vector<int> &a, vector<int> &b) {
//
//    set<int> s;
//    for (auto i: a) {
//        for (auto j: b) {
//            s.insert(abs(i - j));
//        }
//    }
//    int minVal = INT_MAX;
//    for (auto i: s) {
//        minVal = min(minVal, abs(i * i - k * k));
//    }
//
//    return minVal;
//
//}

// 补给站最优花费问题
//int solution(int m, int n, vector<vector<int>> p) {
//    int sum = 0;
//    int minVal = INT_MAX;
//    for (int i = 0; i < p.size(); ++i) {
//        minVal = min(minVal, p[i][1]);
//        int next;
//        if (i == p.size() - 1) {
//            next = m - p[i][0];
//        } else {
//            next = p[i + 1][0] - p[i][0];
//        }
//        sum += minVal * next;
//    }
//    return sum;
//}

// 红包运气排行榜
//struct RedPacket {
//    string name;
//    int money;
//
//    RedPacket(string name, int money) : name(name), money(money) {}
//};
//
//vector<string> solution(int n, vector<string> s, vector<int> x) {
//    list<RedPacket> myList;
//    map<string, int> myMap;
//    for (int i = 0; i < n; ++i) {
//        string name = s[i];
//        if (myMap.find(name) != myMap.end()) {
//            myMap[name] += x[i];
//        } else {
//            myList.emplace_back(name, x[i]);
//            myMap[name] = x[i];
//        }
//    }
//
//    for (auto &item: myList) { // 使用引用以避免不必要的复制
//        item.money = myMap[item.name];
//    }
//
//    myList.sort([](const auto &a, const auto &b) {
//        return a.money > b.money;
//    });
//
//    std::vector<std::string> result;
//    for (const auto &item: myList) {
//        result.push_back(item.name);
//    }
//    return result;
//}








//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//