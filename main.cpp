#include <vector>
#include "iostream"
#include "carl/array.h"
#include "carl/list.h"
#include "carl/hash.h"

using namespace std;

int main() {

    Hash hash;
    vector<int> arr = {0};
    int target = 0;
    vector<vector<int>> a = hash.fourSum(arr, 0);
    for (vector<int> temp: a) {
        for (int i: temp) {
            cout << i << endl;
        }
    }


    return 0;
}