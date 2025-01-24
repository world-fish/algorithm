#include <bits/stdc++.h>

using namespace std;

/*
 * P5738 【深基7.例4】歌唱比赛
 * */

int main() {
    int n, m;
    cin >> n >> m;
    double maxV = numeric_limits<double>::min();
    vector<double> vec(m);
    while (n--) {
        for (double &v: vec) {
            cin >> v;
        }
        sort(vec.begin(), vec.end());
        maxV = max(maxV, accumulate(vec.begin() + 1, vec.end() - 1, 0.0));
    }
    printf("%.2f", maxV / (m - 2));
    return 0;
}