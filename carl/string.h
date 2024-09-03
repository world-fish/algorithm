#include <vector>
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include<bits/stdc++.h>
#include <string>
#include <sstream>

using namespace std;

class String {
public:
    // 344. 反转字符串
    void reverseString(vector<char> &s) {
        reverse(s.begin(), s.end());
//        int len = s.size();
//        for (int i = 0; i < len / 2; ++i) {
//            swap(s[i], s[len - i - 1]);
//        }
    }

    // 541. 反转字符串 II
    string reverseStr(string s, int k) {
        int groups = s.size() / (2 * k);
        for (int i = 0; i < groups; i++) {
            reverse(s.begin() + i * 2 * k, s.begin() + i * 2 * k + k);
        }
        if (s.size() - groups * 2 * k >= k) {
            reverse(s.begin() + groups * 2 * k, s.begin() + groups * 2 * k + k);
        } else {
            reverse(s.begin() + groups * 2 * k, s.end());
        }
        return s;
    }

    // 卡码网 54. 替换数字（第八期模拟笔试）
    void string1() {
        string s;
        string number = "number";
        cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                s.replace(i, 1, number);
                i += number.size() - 1;
            }
        }
        cout << s << endl;
    }

    // 151. 反转字符串中的单词
    string reverseWords(string s) {
        regex spaceRegex("\\s+");
        s = regex_replace(s, spaceRegex, " ");
        reverse(s.begin(), s.end());

        vector<string> str;
        stringstream ss(s);
        string token;
        while (getline(ss, token, ' ')) {
            reverse(token.begin(), token.end());
            str.push_back(token);
        }

        string ans;
        for (int i = 0; i < str.size(); ++i) {
            ans += str[i] + " ";
        }
        if (ans[0] == ' ') {
            ans.erase(0, 1);
        }
        ans.erase(ans.size() - 1, 1);
        return ans;
    }

    // 卡码网 55. 右旋字符串（第八期模拟笔试）
    void string2() {
        string s;
        int k;
        cin >> k;
        cin >> s;
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + k);
        reverse(s.begin() + k, s.end());
        cout << s << endl;
    }

    // 28. 找出字符串中第一个匹配项的下标
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.size(); ++i) {
            for (int j = 0; j < needle.size(); ++j) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
                if (j == needle.size() - 1) {
                    return i;
                }
            }
        }
        return -1;
    }

    // 459. 重复的子字符串
    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i <= s.size() / 2; ++i) {
            if (s.size() % i == 0) {
                bool b = true;
                for (int j = i; j < s.size(); ++j) {
                    if (s[j] != s[j - i]) {
                        b = false;
                        break;
                    }
                }
                if (b) {
                    return true;
                }
            }
        }
        return false;
    }

    // 获取next数组
    void getNext(int *next, const string &s) {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) { // 注意i从1开始
            while (j >= 0 && s[i] != s[j + 1]) { // 前后缀不相同了
                j = next[j]; // 向前回退
            }
            if (s[i] == s[j + 1]) { // 找到相同的前后缀
                j++;
            }
            next[i] = j; // 将j（前缀的长度）赋给next[i]
        }
    }

};