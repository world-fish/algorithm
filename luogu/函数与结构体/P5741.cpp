#include <bits/stdc++.h>

using namespace std;

/*
 * P5741 【深基7.例10】旗鼓相当的对手 - 加强版
 * */

struct Student {
    string name;
    int chinese;
    int math;
    int english;
    int sum;
};

int main() {
    int n;
    cin >> n;
    vector<Student> students(n);

    for (int i = 0; i < n; ++i) {
        cin >> students[i].name >> students[i].chinese >> students[i].math >> students[i].english;
        students[i].sum = students[i].chinese + students[i].math + students[i].english;
    }

    sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.name < b.name;
    });

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (abs(students[i].chinese - students[j].chinese) <= 5 &&
                abs(students[i].math - students[j].math) <= 5 &&
                abs(students[i].english - students[j].english) <= 5 &&
                abs(students[i].sum - students[j].sum) <= 10) {
                cout << students[i].name << " " << students[j].name << endl;
            }
        }
    }

    return 0;
}