#include "iostream"

using namespace std;

int main() {
    int z;
    cin >> z;
    int arr[z][2];
    for (int i = 0; i < z; ++i) {
        cin >> arr[i][0];
        cin >> arr[i][1];
    }
    int ans[z];
    for (int i = 0; i < z; ++i) {
        if (arr[i][0] == 0 && arr[i][1] == 0) {
            ans[i] = 0;
            continue;
        }
        int a1 = (arr[i][1] - 1) / 2 + 1;
        int a2 = (arr[i][0] + arr[i][1] * 4 - 1) / 15 + 1;
        ans[i] = max(a1, a2);
    }
    for (int v: ans) {
        cout << v << endl;
    }
}