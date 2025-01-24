#include <iostream>
#include <string>

using namespace std;

int main() {
    int q;
    cin >> q;
    cin.ignore();

    while (q--) {
        string question;
        getline(cin, question);

        size_t pos = question.find(" or ");
        string A = question.substr(0, pos);
        string B = question.substr(pos + 4);
//        B = B.substr(0, B.size() - 1);
        B.pop_back();

        if (A == "eat" && B == "eat") {
            cout << "or" << endl;
        } else if (A == "eat") {
            cout << B << endl;
        } else {
            cout << A << endl;
        }
    }

    return 0;
}