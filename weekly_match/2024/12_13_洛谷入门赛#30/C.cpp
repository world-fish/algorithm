#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    vector<pair<ll, ll>> submissions(n);
    for (int i = 0; i < n; i++) {
        cin >> submissions[i].first >> submissions[i].second;
    }

    ll total_penalty = 0;
    ll incorrect_submissions = 0;

    for (int i = 0; i < n; i++) {
        ll time = submissions[i].first;
        ll is_passed = submissions[i].second;

        if (is_passed == 0) {
            incorrect_submissions++;
        } else {
            total_penalty += time + incorrect_submissions * 20;
            incorrect_submissions = 0;
        }
    }
    if (incorrect_submissions != 0)
        total_penalty += incorrect_submissions * 20;

    cout << total_penalty << endl;
    return 0;
}