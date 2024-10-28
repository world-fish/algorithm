#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> n(t);
    vector<vector<int>> arr(t);

    for (int i = 0; i < t; i++) {
        cin >> n[i];
        arr[i].resize(n[i]);
        for (int j = 0; j < n[i]; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < t; i++) {
        if (n[i] < 3) {
            cout << "NO" << endl;
            continue;
        }

        map<int, int> myMap;
        for (int j = 0; j < n[i]; j++) {
            myMap[arr[i][j]]++;
        }

        long long m = LLONG_MAX;
        bool found = false;

        for (const auto &it: myMap) {
            if (it.second >= 3) {
                found = true;
                long long perimeter = it.first * 3;
                if (perimeter < m) {
                    m = perimeter;
                }
            }
        }

        if (!found) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << m << endl;
        }
    }

    return 0;
}