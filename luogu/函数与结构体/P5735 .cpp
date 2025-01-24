#include <bits/stdc++.h>

using namespace std;

/*
 * P5735 【深基7.例1】距离函数
 * */

int main() {
    double x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    double dis = 0;
    dis += sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    dis += sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    dis += sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    printf("%.2f", dis);
    return 0;
}