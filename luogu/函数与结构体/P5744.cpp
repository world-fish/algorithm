#include <bits/stdc++.h>

using namespace std;

/*
 * P5744 【深基7.习9】培训
 * */

int main() {
    int n;
    cin >> n;
    string name;
    int age;
    int score;
    while (n--) {
        cin >> name >> age >> score;
        age++;
        score = min((int) (score * 1.2), 600);
        cout << name << " " << age << " " << score << endl;
    }
    return 0;
}