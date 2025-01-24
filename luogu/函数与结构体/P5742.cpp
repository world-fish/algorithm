#include <bits/stdc++.h>

using namespace std;

/*
 * P5742 【深基7.例11】评等级
 * */

struct Student {
    int number;
    int score;
    int quality;

    int getSum() {
        return score + quality;
    }
};

void judgment(Student student) {
    if (student.score * 7 + student.quality * 3 >= 800 && student.getSum() > 140) {
        cout << "Excellent" << endl;
    } else {
        cout << "Not excellent" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    Student student;
    while (n--) {
        cin >> student.number >> student.score >> student.quality;
        judgment(student);
    }

    return 0;
}