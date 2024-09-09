#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

class StacksAndQueues {
public:
    // 20. 有效的括号
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '[') st.push(']');
            else if (s[i] == '{') st.push('}');
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop();
        }
        return st.empty();
    }

    // 1047. 删除字符串中的所有相邻重复项
    string removeDuplicates(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (!st.empty() && s[i] == st.top()) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    // 150. 逆波兰表达式求值
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (tokens[i] == "+") {
                    st.push(a + b);
                } else if (tokens[i] == "-") {
                    st.push(b - a);
                } else if (tokens[i] == "*") {
                    st.push(a * b);
                } else if (tokens[i] == "/") {
                    st.push(b / a);
                }
            } else {
                int temp = stoi(tokens[i]);
                st.push(temp);
            }
        }
        return st.top();
    }

    // 239. 滑动窗口最大值
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> ans;
        deque<int> deq;
        for (int i = 0; i < nums.size(); ++i) {
            if (!deq.empty() && deq.front() == i - k) {
                deq.pop_front();
            }
            while (!deq.empty() && nums[deq.back()] < nums[i]) {
                deq.pop_back();
            }
            deq.push_back(i);
            if (i >= k - 1) {
                ans.push_back(nums[deq.front()]);
            }
        }
        return ans;
    }

    // 347. 前 K 个高频元素
    vector<int> topKFrequent(vector<int> &nums, int k) {
        typedef pair<int, int> pii;
        priority_queue<pii, vector<pii>, greater<pii> > Q;
        unordered_map<int, int> M;
        vector<int> res(k);
        for (int i: nums) M[i]++;
        for (auto it: M) {
            Q.push({it.second, it.first});
            if (Q.size() > k) Q.pop();
        }
        for (int i = k - 1; i >= 0; i--) {
            res[i] = Q.top().second;
            Q.pop();
        }
        return res;
    }
};

// 232. 用栈实现队列
class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;

    MyQueue() {

    }

    void push(int x) {
        stIn.push(x);
    }

    int pop() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int ans = stOut.top();
        stOut.pop();
        return ans;
    }

    int peek() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        return stOut.top();
    }

    bool empty() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        return stOut.empty();
    }
};

// 225. 用队列实现栈
class MyStack {
public:
    queue<int> que;

    MyStack() {

    }

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int size = que.size() - 1;
        while (size--) {
            int temp = que.front();
            que.pop();
            que.push(temp);
        }
        int ans = que.front();
        que.pop();
        return ans;
    }

    int top() {
        int ans = this->pop();
        que.push(ans);
        return ans;
    }

    bool empty() {
        return que.empty();
    }
};