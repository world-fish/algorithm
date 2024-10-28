#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

// Base32 字符表（标准 Base32）
const string base32Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";

// 获取字符在 Base32 字符表中的索引
int getBase32Index(char c) {
    return base32Chars.find(c);
}

// 编码函数
string encodeBase32(const string &rawStr) {
    string binaryStr = "";

    // 将每个字符转换为 8-bit 的二进制表示，并拼接到一起
    for (char c: rawStr) {
        binaryStr += bitset<8>(c).to_string();  // 每个字符生成 8 位二进制
    }

    // 在最后补齐 0，保证二进制长度是 5 的倍数
    while (binaryStr.size() % 5 != 0) {
        binaryStr += "0";
    }

    string encodedStr = "";

    // 每 5 位二进制对应一个 Base32 索引
    for (size_t i = 0; i < binaryStr.size(); i += 5) {
        int index = bitset<5>(binaryStr.substr(i, 5)).to_ulong();  // 转换为 Base32 索引
        encodedStr += base32Chars[index];  // 通过索引查表获得对应字符
    }

    // 根据长度补上 `=`
    while (encodedStr.size() % 8 != 0) {
        encodedStr += "=";
    }

    return encodedStr;
}

// 解码函数
string decodeBase32(const string &encodedStr) {
    string binaryStr = "";

    // 将每个 Base32 字符转换为 5-bit 的二进制表示，并拼接到一起
    for (char c: encodedStr) {
        if (c == '=') break;  // 跳过补位符号
        int index = getBase32Index(c);  // 获取 Base32 字符对应的索引
        binaryStr += bitset<5>(index).to_string();  // 转换为 5 位二进制并拼接
    }

    string decodedStr = "";

    // 每 8 位二进制转换为一个字符
    for (size_t i = 0; i < binaryStr.size(); i += 8) {
        if (i + 8 <= binaryStr.size()) {
            char c = static_cast<char>(bitset<8>(binaryStr.substr(i, 8)).to_ulong());  // 转换为字符
            decodedStr += c;
        }
    }

    return decodedStr;
}

// 解决方案
std::string solution(std::string rawStr, std::string encodedStr) {
    // 编码
    string encodedResult = encodeBase32(rawStr);

    // 解码
    string decodedResult = decodeBase32(encodedStr);

    return encodedResult + ":" + decodedResult;
}

int main() {
    // 测试用例
    std::cout << (solution("foo", "b0zj5+++") == "bljhy+++bar") << std::endl;  // 应该根据实际编码结果
    std::cout << (solution("Hello World", "JBSWY3DPEBLKWID") == "NBSWY3DP:Hello World") << std::endl; // 根据标准 Base32
    return 0;
}