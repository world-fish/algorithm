#include <bits/stdc++.h>

using namespace std;

/*
 *
 * */

struct Student {
    string name;
    int chinese;
    int math;
    int english;
};

int main() {
    int n;
    cin >> n;

    Student student, temp;
    int maxi = numeric_limits<int>::min();
    int sum;
    string name;
    int chinese, math, english;
    while (n--) {
        temp;
        cin >> temp.name >> temp.chinese >> temp.math >> temp.english;

        sum = temp.chinese + temp.math + temp.english;

        if (sum > maxi) {
            maxi = sum;
            student = temp;
        }
    }
    cout << student.name << " "
         << student.chinese << " "
         << student.math << " "
         << student.english
         << endl;

    return 0;
}