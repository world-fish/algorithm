#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

int n, m;
long long a[MAXN], b[MAXN];
map<long long, long long> freq;        // 记录每个数出现的频率
map<long long, long long> freqCount;  // 记录频率的计数

void addFreq(long long val, long long cnt) {
    if (freq[val] > 0) {
        freqCount[freq[val]] -= val;
        if (freqCount[freq[val]] == 0) {
            freqCount.erase(freq[val]);
        }
    }
    freq[val] += cnt;
    freqCount[freq[val]] += val;
}

long long calcWeight(int idx) {
    auto it = freqCount.rbegin();  // 获取最大频率的迭代器
    return it->first * a[idx];     // 最大频率 * 当前 a[idx]
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        addFreq(b[i], a[i]);
    }
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            addFreq(b[x], y);
            a[x] += y;
        } else if (op == 2) {
            long long q;
            cin >> q;
            long long res = 0, xorSum = 0;
            for (int i = n; i >= 1; --i) {
                xorSum ^= calcWeight(i);
                if (xorSum == q) {
                    res = n - i + 1;
                    break;
                }
            }
            cout << res << '\n';
        }
    }
    return 0;
}