#include <iostream>

using namespace std;

int solution(int xPosition, int yPosition) {
    // Please write your code here
    int differ = abs(xPosition - yPosition);
    int digits = 0;
    int num = 1;
    while (differ > 0) {
        differ -= num;
        digits++;
        if (digits % 2 == 0) num++;
    }
    return digits;
}

int main() {
    //  You can add more test cases here
    cout << (solution(12, 6) == 4) << endl;
    cout << (solution(34, 45) == 6) << endl;
    cout << (solution(50, 30) == 8) << endl;
    return 0;
}