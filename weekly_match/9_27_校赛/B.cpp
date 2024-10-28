#include "iostream"
#include<bits/stdc++.h>

using namespace std;

string decode(string b) {
    set<char> s(b.begin(), b.end());
    vector<char> v(s.begin(), s.end());
    map<char, char> m;
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        m[v[i]] = v[n - i - 1];
    }
    for (int i = 0; i < b.size(); ++i) {
        b[i] = m[b[i]];
    }
    return b;
}

int main() {
    int z;
    cin >> z;
    string arr[z];
    for (int i = 0; i < z; ++i) {
        int temp;
        cin >> temp;
        cin >> arr[i];
    }
    for (int i = 0; i < z; ++i) {
        cout << decode(arr[i]) << endl;
    }
}