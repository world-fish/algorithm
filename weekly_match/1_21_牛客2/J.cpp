#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, h, m;
    cin >> n >> h >> m;
    string date = to_string(h) + "-";
    if (m < 10) {
        date += "0" + to_string(m);
    } else {
        date += to_string(m);
    }
    set<string> a, b, c;
    for (int i = 0; i < n; ++i) {
        string id, day, time;
        cin >> id >> day >> time;
        if (day.substr(0, 7) != date) {
            continue;
        }
        string hour = time.substr(0, 2);
        if (hour == "07" || hour == "08" || time == "09:00:00" ||
            hour == "18" || hour == "19" || time == "20:00:00") {
            a.insert(id);
        } else if (hour == "11" || hour == "12" || time == "13:00:00") {
            b.insert(id);
        } else if (hour == "22" || hour == "23" || hour == "00" || time == "01:00:00") {
            c.insert(id);
        }
    }
    cout << a.size() << " " << b.size() << " " << c.size() << endl;
    return 0;
}

//int main() {
//    int n, h, m;
//    cin >> n >> h >> m;
//    unordered_map<int, unordered_set<ll>> myMap;
//
//    for (int i = 0; i < n; ++i) {
//        ll id;
//        int year, month, day, hour, minute, second;
//        scanf("%lld %d-%d-%d %d:%d:%d", &id, &year, &month, &day, &hour, &minute, &second);
//        if (year == h && month == m) {
//            if (hour == 7 || hour == 8 || (hour == 9 && minute == 0 && second == 0)) {
//                myMap[7].insert(id);
//            } else if (hour == 18 || hour == 19 || (hour == 20 && minute == 0 && second == 0)) {
//                myMap[7].insert(id);
//            } else if (hour == 11 || hour == 12 || (hour == 13 && minute == 0 && second == 0)) {
//                myMap[11].insert(id);
//            } else if (hour == 22 || hour == 23 || hour == 0 || (hour == 1 && minute == 0 && second == 0)) {
//                myMap[22].insert(id);
//            }
//        }
//    }
//    cout << myMap[7].size() << " " << myMap[11].size() << " " << myMap[22].size();
//    return 0;
//}