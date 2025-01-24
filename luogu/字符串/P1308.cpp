#include <bits/stdc++.h>

using namespace std;

int main() {
    string word, text;
    getline(cin, word);
    getline(cin, text);
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    transform(text.begin(), text.end(), text.begin(), ::tolower);

    regex word_regex("\\b" + word + "\\b");
    auto words_begin = sregex_iterator(text.begin(), text.end(), word_regex);
    auto words_end = sregex_iterator();

    int count = distance(words_begin, words_end);
    if (count == 0) {
        cout << -1 << endl;
    } else {
        int first_pos = words_begin->position();
        cout << count << " " << first_pos << endl;
    }

    return 0;
}