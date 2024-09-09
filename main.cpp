#include<bits/stdc++.h>
#include "carl/stacksAndQueues.h"

using namespace std;

int main() {

    StacksAndQueues obj;
    vector<int> v = {1, -1};
    vector<int> ans = obj.maxSlidingWindow(v, 1);
    for (int i: ans) {
        cout << i << endl;
    }

    return 0;
}