#include <iostream>
#include <regex>
#include <string>

using namespace std;


bool isValidEmail(const string &email) {

    const regex pattern(
            R"(^[a-zA-Z0-9](\.?[a-zA-Z0-9]){0,63}@[a-zA-Z0-9]([a-zA-Z0-9\-]*[a-zA-Z0-9])?(\.[a-zA-Z0-9]([a-zA-Z0-9\-]*[a-zA-Z0-9])?)*$)"
    );
    const regex pattern2(
            R"(^[a-zA-Z0-9]([a-zA-Z0-9\.]{0,62}[a-zA-Z0-9])?@[a-zA-Z0-9]([a-zA-Z0-9\.-]{0,253}[a-zA-Z0-9])?$)");

    return regex_match(email, pattern);
}

int main() {
    int t;
    cin >> t;
    vector<string> emails(t);
    for (int i = 0; i < t; ++i) {
        cin >> emails[i];
    }

    for (string email: emails) {
        if (isValidEmail(email)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

}