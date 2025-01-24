#include <bits/stdc++.h>

using namespace std;

vector<string> arr;
int n, m;

string processRow(string row) {
    int aCount = 0, bCount = 0;
    int wallPos = -1;

    for (int i = 0; i < m; i++) {
        if (row[i] == 'A') aCount++;
        else if (row[i] == 'B') bCount++;
        else if (row[i] == 'H') wallPos = i;
    }

    if (wallPos != -1) {
        string newRow(m, '#');
        for (int i = 0; i < aCount; i++) newRow[i] = 'A';
        newRow[wallPos] = 'H';
        for (int i = m - 1; i > m - 1 - bCount; i--) newRow[i] = 'B';
        return newRow;
    } else {
        if (aCount > bCount) {
            string newRow(m, '#');
            for (int i = m - 1; i > m - 1 - aCount; i--) newRow[i] = 'A';
            return newRow;
        } else if (bCount > aCount) {
            string newRow(m, '#');
            for (int i = 0; i < bCount; i++) newRow[i] = 'B';
            return newRow;
        } else {
            return string(m, '#');
        }
    }
}

vector<string> removeAB(vector<string> &arr) {
    vector<string> result = arr;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'A' || arr[i][j] == 'B') {
                if ((i > 0 && arr[i - 1][j] == arr[i][j]) || // 上方
                    (i < n - 1 && arr[i + 1][j] == arr[i][j])) { // 下方
                    result[i][j] = '#';
                }
            }
        }
    }
    return result;
}

void solve() {
    cin >> n >> m;
    arr.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = processRow(arr[i]);
    }

    arr = removeAB(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    solve();
    return 0;
}