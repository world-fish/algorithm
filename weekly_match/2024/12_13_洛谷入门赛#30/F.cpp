#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Submission {
    int tid, pid, state;
};

int main() {
    int n, t, p, k;
    cin >> n >> t >> p >> k;

    vector<Submission> submissions(n);
    for (int i = 0; i < n; i++) {
        cin >> submissions[i].tid >> submissions[i].pid >> submissions[i].state;
    }

    vector<unordered_set<int>> teamSolved(t + 1);
    vector<int> passedCount(t + 1, 0);
    vector<bool> hasMedal(t + 1, false);

    int lastAC = -1, lastValidAC = -1, lastNonMedalValidAC = -1, lastFirstSolve = -1;
    unordered_set<int> hasFirstSolved;

    for (int i = 0; i < n; i++) {
        int tid = submissions[i].tid;
        int pid = submissions[i].pid;
        int state = submissions[i].state;

        if (state == 1) {

            lastAC = tid;


            if (teamSolved[tid].find(pid) == teamSolved[tid].end()) {

                teamSolved[tid].insert(pid);
                passedCount[tid]++;
                lastValidAC = tid;

                if (passedCount[tid] >= k) {
                    hasMedal[tid] = true;
                }

                if (passedCount[tid] == 1 && hasFirstSolved.find(tid) == hasFirstSolved.end()) {
                    hasFirstSolved.insert(tid);
                    lastFirstSolve = tid;
                }
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        int tid = submissions[i].tid;
        int pid = submissions[i].pid;
        int state = submissions[i].state;

        if (state == 1 && !hasMedal[tid] && teamSolved[tid].find(pid) != teamSolved[tid].end()) {
            lastNonMedalValidAC = tid;
            break;
        }
    }

    cout << (lastAC == -1 ? -1 : lastAC) << " "
         << (lastValidAC == -1 ? -1 : lastValidAC) << " "
         << (lastNonMedalValidAC == -1 ? -1 : lastNonMedalValidAC) << " "
         << (lastFirstSolve == -1 ? -1 : lastFirstSolve) << endl;

    return 0;
}