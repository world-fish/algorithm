#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//int main() {
//    int n;
//    cin >> n;
//    vector<int> vec(n);
//    for (int &i: vec) {
//        cin >> i;
//    }
//    if (n == 1) {
//        cout << 0 << endl;
//        return 0;
//    }
//    sort(vec.begin(), vec.end());
//    vec[0] *= 2;
//    int stop = vec[0];
//    int maxn = max(vec[0], vec[n - 1]);
//    int minn = min(vec[0], vec[1]);
//    int ans = abs(maxn - minn);
//    for (int i = 1; i < n - 1 && vec[i] < stop; ++i) {
//        vec[i] *= 2;
//        maxn = max(maxn, vec[i]);
//        minn = min(vec[i + 1], vec[i]);
//        ans = min(ans, maxn - minn);
//    }
//    cout << ans << endl;
//    return 0;
//}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int &i: vec) {
        cin >> i;
    }
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    sort(vec.begin(), vec.end());
    vec[0] *= 2;
    int stop = vec[0];
    int minn = min(vec[0], vec[1]);
    int maxn = max(vec[0], vec[n - 1]);
    int ans = abs(maxn - minn);
    while (vec[0] < stop) {
        vec[0] *= 2;
        minn = min(vec[0], vec[1]);
        maxn = max(vec[0], vec[n - 1]);
        ans = min(ans, abs(maxn - minn));
    }
    cout << ans << endl;
    return 0;
}