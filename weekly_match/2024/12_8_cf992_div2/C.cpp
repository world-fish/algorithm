#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long calculate_S(const vector<int> &p) {
    long long S = 0;
    int n = p.size();
    for (int l = 0; l < n; l++) {
        int min_val = p[l];
        for (int r = l; r < n; r++) {
            min_val = min(min_val, p[r]);
            S += min_val;
        }
    }
    return S;
}

void solve(int n, long long k) {
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
    }

    vector<vector<int>> valid_permutations;
    long long max_S = 0;

    do {
        long long current_S = calculate_S(p);
        if (current_S > max_S) {
            max_S = current_S;
            valid_permutations.clear();
            valid_permutations.push_back(p);
        } else if (current_S == max_S) {
            valid_permutations.push_back(p);
        }
    } while (next_permutation(p.begin(), p.end()));

    if (valid_permutations.size() < k) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << valid_permutations[k - 1][i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        solve(n, k);
    }

    return 0;
}