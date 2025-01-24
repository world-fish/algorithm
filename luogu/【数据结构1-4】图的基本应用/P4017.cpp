#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 80112002;
const int N = 5e3 + 2;  // 定义常量 N，表示最大点数，5002

/*
 * P4017 最大食物链计数
 * */

// 快速读入函数
inline int read() {
    int X = 0, w = 0;
    char ch = 0;
    while (!isdigit(ch)) {
        w |= ch == '-'; // 标记负数
        ch = getchar();
    }
    while (isdigit(ch)) {
        X = (X << 3) + (X << 1) + (ch ^ 48); // 读入数字
        ch = getchar();
    }
    return w ? -X : X; // 返回读入的数字
}

// 快速输出函数
char F[20]; // 存储数字的字符数组
inline void write(ll x) {
    if (x == 0) {
        putchar('0'); // 输出0
        return;
    }
    if (x < 0) {
        putchar('-'); // 输出负号
        x = -x;
    }
    int cnt = 0;
    while (x > 0) {
        F[cnt++] = x % 10 + '0'; // 存储各位数字
        x /= 10; // 除以10以得到下位
    }
    while (cnt > 0) {
        putchar(F[--cnt]); // 反向输出
    }
}

// 定义邻接列表和其他必要的变量
vector<vector<int>> a; // 存储边的邻接列表
queue<int> q; // 存储出度为0的点
vector<int> len; // 存储路径长度
ll sum = 0; // 存储最终结果
vector<int> in(N); // 存储入度
vector<int> out(N); // 存储出度

// 递归添加路径长度
void add(int v) {
    if (out[v] == 0) { // 如果没有邻接点
        sum += len[v]; // 累加到结果
        sum %= mod; // 取模
        len[v] = 0; // 清空长度
        return;
    }
    for (int i = 0; i < a[v].size(); ++i) {
        len[a[v][i]] += len[v]; // 更新邻接点的路径长度
        len[a[v][i]] %= mod; // 取模
        --in[a[v][i]]; // 减少入度
        if (in[a[v][i]] == 0) { // 如果入度为0
            q.push(a[v][i]); // 入队
        }
    }
}

int main() {
    int n = read(), m = read(); // 读取点和边的数量
    a.resize(n + 1, vector<int>(0)); // 初始化邻接列表
    for (int i = 0; i < m; ++i) {
        int eaten = read(), eat = read(); // 读取每条边
        a[eaten].push_back(eat); // 构建邻接图
        ++out[eaten], ++in[eat];
    }

    len.resize(n + 1, 0); // 初始化路径长度
    for (int i = 1; i <= n; ++i) { // 遍历所有点
        if (in[i] == 0) { // 如果入度为0
            q.push(i); // 入队
            len[i] = 1; // 初始化此路径长度为1
        }
    }

    while (!q.empty()) { // 队列不为空
        add(q.front());
        q.pop();
    }

    write(sum); // 输出结果
    return 0; // 结束程序
}
