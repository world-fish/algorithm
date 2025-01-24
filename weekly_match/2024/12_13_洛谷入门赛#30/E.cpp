#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    vector<bool> passed(p + 1, false);

    for (int i = 0; i < n; i++) {
        int pid, state;
        cin >> pid >> state;

        if (state == 1) {
            passed[pid] = true;
        }
    }

    int result = 0;
    for (int i = 1; i <= p; i++) {
        if (passed[i]) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}